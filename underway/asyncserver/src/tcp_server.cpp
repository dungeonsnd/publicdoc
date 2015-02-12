
#include "netserver/cl_server.hpp"
#include "common.hpp"
#include "business.hpp"

class IOCompleteHandler : public cl::EventHandler
{
public:
    IOCompleteHandler():_headLen(4)
    {
    }
    ~IOCompleteHandler()
    {
    }
    cf_void AddClientfds(std::vector < cf_fd > fds)
    {
        for(std::vector < cf_fd >::const_iterator it =fds.begin(); it!=fds.end(); it++)
        {
            AddNewConn(*it,DBPROXYSERVER_IP,DBPROXYSERVER_PORT);
            _dbfds.insert(*it);
        }
    }
    
    cf_void OnAcceptComplete(cf::T_SESSION session)
    {
        CF_PRINT_FUNC;
#if 1
        fprintf (stderr, "OnAcceptComplete,fd=%d,addr=%s \n",
                 session->Fd(),session->Addr().c_str());
#endif
        AsyncRead(session->Fd(), _headLen);
        _recvHeader[session->Fd()] =true;
    }
    cf_void OnReadComplete(cf::T_SESSION session,
                           std::shared_ptr < cl::ReadBuffer > readBuffer)
    {
        CF_PRINT_FUNC;
#if 1
        fprintf (stderr, "OnReadComplete,fd=%d,addr=%s,total()=%d,buf=%s \n",
                 session->Fd(),session->Addr().c_str(),readBuffer->GetTotal(),
                 (cf_char *)(readBuffer->GetBuffer()));
#endif
        cf_uint32 totalLen =readBuffer->GetTotal();
        if(_recvHeader[session->Fd()])
        {
            if(_headLen!=totalLen)
            {
                fprintf (stderr, "OnReadComplete,fd=%d,_headLen{%u}!=totalLen{%u} \n",
                        session->Fd(),_headLen,totalLen);
            }
            else
            {
                cf_uint32 * p =(cf_uint32 *)(readBuffer->GetBuffer());
                cf_uint32 size =ntohl(*p);
                fprintf (stderr, "OnReadComplete,size{%u} \n",
                        size);
                _recvHeader[session->Fd()] =false;
                if(size>0)
                    AsyncRead(session->Fd(), size);
                else
                    _THROW(cf::ValueError, "size==0 !");
            }
        }
        else
        {
            _recvHeader[session->Fd()] =true;
            Entry(session->Fd(), (cf_cpstr)(readBuffer->GetBuffer()), totalLen);
            AsyncRead(session->Fd(), _headLen);
        }
    }
    cf_void OnWriteComplete(cf::T_SESSION session)
    {
        CF_PRINT_FUNC;
    }
    cf_void OnTimeoutComplete()
    {
        fprintf (stderr, "tcp_serverOnTimeoutComplete \n");
    }

    cf_void Entry(cf_fd fd,cf_cpstr data, cf_uint32 totalLen)
    {
        fprintf (stderr, "Entry,data=%s,totalLen=%u \n",
                data,totalLen );
        if(_dbfds.find(fd)!=_dbfds.end()) // db_proxy_server conn
        {
            //   Here need to parse data from db_proxy_server, 
            // find the client conn, send the db query result to it.
            //   To save time, we just choose the first conn to send result back.
            if(_recvHeader.size()>0)
            {
                cf_fd clientfd =_recvHeader.begin()->first;
                AsyncWrite(clientfd, data, totalLen);
            }
            else
                fprintf (stderr, "Entry,_recvHeader.size(){%u}<=0 \n",
                        cf_uint32(_recvHeader.size()) );
        }
        else // client conn
        {
            //   To save time, we just choose the first db_proxy conn to send query.
            if(_dbfds.size()>0)
            {
                // Here maybe has a lot of calculation.
                
                std::string len(4,'\0');
                cf_uint32 l =htonl(totalLen);
                memcpy(&len[0], &l,sizeof l);
                std::string tosend(data,totalLen);
                printf("len=%s,tosend=%s \n",len.c_str(), tosend.c_str());
                tosend =len+tosend;
                cf_fd dbfd =*(_dbfds.begin());
                AsyncWrite(dbfd, tosend.c_str(), tosend.size());
            }
            else
                fprintf (stderr, "Entry,_dbfds.size(){%u}<=0 \n",
                        cf_uint32(_dbfds.size()) );
        }
    }
private:
    std::map < cf_fd , bool > _recvHeader;
    const cf_uint32 _headLen;
    std::unordered_set < cf_fd > _dbfds;
};


cf_int main(cf_int argc,cf_char * argv[])
{
    fprintf(stdout,"tcp_server started\n------------\n");
    typedef cl::TcpServer < IOCompleteHandler > ServerType;
    cf_fd severfd =ServerType::CreateListenSocket(SERVER_PORT);
    IOCompleteHandler ioHandler;
    std::shared_ptr < ServerType > server(new ServerType(severfd,ioHandler,0,0,3000));
    std::vector<cf_fd> clientfds;
    int clientSum =1;
    cf::ConnectToServer(DBPROXYSERVER_IP,DBPROXYSERVER_PORT,clientSum,clientfds);
    ioHandler.AddClientfds(clientfds);
    server->Start();
    return 0;
}

