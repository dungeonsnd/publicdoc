
#include "netserver/cl_server.hpp"
#include "cppfoundation/cf_concurrency_queue.hpp"
#include "db_access_api.hpp"
#include "common.hpp"

std::string host ="127.0.0.1";
std::string user ="root";
std::string passwd ="tm";
std::string database ="test";
unsigned port =3306;

int g_numPipe =1;
const int g_threadsCntPerPipe =1;
typedef struct _tagQueueElement
{
    int fd;
    std::string pack;
}QueueElement;
typedef cf::TYPEQueue < QueueElement > ::Queue TYPE_Queue;
TYPE_Queue * g_inQueue =NULL;
TYPE_Queue * g_outQueue =NULL;

typedef std::map < pthread_t , int > TYPE_TID_PIPE;
TYPE_TID_PIPE g_tid_pipe;
typedef std::map < pthread_t , int > TYPE_TID_CLIENTFD;
TYPE_TID_CLIENTFD g_tid_fd;


class IOCompleteHandler : public cl::EventHandler
{
public:
    IOCompleteHandler():_headLen(4),_tid(pthread_self())
    {
    }
    ~IOCompleteHandler()
    {
    }
    cf_void OnAcceptComplete(cf::T_SESSION session)
    {
        CF_PRINT_FUNC;
#if 1
        fprintf (stderr, "OnAcceptComplete,fd=%d,addr=%s \n",
                 session->Fd(),session->Addr().c_str());
#endif
        if(session->Addr()=="127.0.0.1")
        {
            TYPE_TID_CLIENTFD::iterator it =g_tid_fd.begin();
            bool found =false;
            cf_uint32 tid =0;
            for(;it!=g_tid_fd.end();it++)
            {
                if(it->second==-1)
                {
                    tid =it->first;
                    found =true;
                    break;
                }
            }
            if(found)
            {
                printf( "g_tid_fd.size()=%u,g_tid_fd[%u]=%d \n", (cf_uint32)(g_tid_fd.size()),
                    tid,g_tid_fd[tid]);
                g_tid_fd[tid] =session->Fd();
                g_tid_fd[tid] =1234;
                printf( "g_tid_fd[%u]=%u , g_tid_fd.size()=%u \n",(cf_uint32)tid,(cf_uint32)(g_tid_fd[tid]), (cf_uint32)(g_tid_fd.size()) );
                AsyncRead(session->Fd(), 1);
            }
            else
                printf("ERROR! Idle element in g_tid_fd not found!");
            return;
        }
        
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
        TYPE_TID_CLIENTFD::const_iterator it =g_tid_fd.begin();
        bool found =false;
        for(;it!=g_tid_fd.end();it++)
        {
            printf( "for,tid=%u,fd=%d g_tid_fd.size()=%u\n",(cf_uint32)(it->first),it->second, (cf_uint32)(g_tid_fd.size()) );
            if(it->second==session->Fd())
            {
                found =true;
                break;
            }
        }
        if(found)
        {
            printf( "is db query. \n" );
            QueueElement qeOut =g_outQueue[_tid].Get();
            int clientfd =qeOut.fd;
            std::string output_data =qeOut.pack;
            
            AsyncWrite(clientfd, output_data.c_str(), output_data.size());           
            return;
        }
        printf( "recv query request \n" );
        
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
            //AsyncWrite(session->Fd(), readBuffer->GetBuffer(), totalLen);
            std::string packet((const char*)(readBuffer->GetBuffer()), size_t(totalLen));
            QueueElement qe;
            qe.fd =session->Fd();
            qe.pack =packet;
            g_inQueue[g_tid_pipe[_tid]].Put(qe);
            AsyncRead(session->Fd(), _headLen);
        }
    }

private:
    std::map < cf_fd , bool > _recvHeader;
    const cf_uint32 _headLen;
    pthread_t _tid;
};


typedef cl::TcpServer < IOCompleteHandler > ServerType;
void * ThreadNetwork(void * arg)
{
    cf_fd * p =(cf_fd*)arg;
    cf_fd severfd =*p;
    IOCompleteHandler ioHandler;
    
    std::shared_ptr < ServerType > server(new ServerType(severfd,ioHandler,0,0,30000));
    printf("ThreadNetwork, tid=%u \n",(unsigned)(pthread_self()));
    server->Start();
    
    return NULL;
}

void * ThreadDBAccess(void * arg)
{  
    printf("ThreadDBAccess, tid=%u \n",(unsigned)(pthread_self()));
    pthread_t tid =pthread_self();
    MYSQL mysql;
    int rt =MyConnect(mysql,host.c_str(),user.c_str(),passwd.c_str(),database.c_str(),port);
    if(0!=rt)
        ERR("MyConnect");
    while(1)
    {
        QueueElement qe =g_inQueue[g_tid_pipe[tid]].Get();
        
        // db.Query()
        int rt =MyQuery(mysql, qe.pack.c_str(), qe.pack.size());
        T_TABLES v_tables;
        rt =MyGetResults(mysql,v_tables);
        if(0!=rt)
        {
            printf("Failed MyGetResults, tid=%u \n",(unsigned)(pthread_self()));
            continue;
        }
        
        std::string output_data;
        VectorSerialize::Serialize(v_tables,output_data);
        
        QueueElement qeOut;
        qeOut.fd =qe.fd;
        qeOut.pack =output_data;
        g_outQueue[g_tid_pipe[tid]].Put(qeOut);
        int notifyfd =g_tid_fd[tid];
        printf("tid=%u, notifyfd=%d \n",(cf_uint32)tid,notifyfd);
        std::string tmp("a");
        send(notifyfd,tmp.c_str(),1,0);
    }
    MyClose(mysql);
    return NULL;
}

cf_void Run()
{
    cf_fd severfd =ServerType::CreateListenSocket(DBPROXYSERVER_PORT);

    std::vector < pthread_t > tids_network;
    pthread_t tid =0;
    // net thread pool.
    for(int i=0; i<g_numPipe; i++)
    {
        int rt =pthread_create(&tid,NULL,ThreadNetwork,(void *)&severfd);
        if(0!=rt)
        {
            printf("pthread_create error,error=%s \n",strerror(errno));
            break;
        }
        tids_network.push_back(tid);
        g_tid_pipe[tid] =i;
    }

    g_inQueue =new TYPE_Queue[g_numPipe];
    g_outQueue =new TYPE_Queue[g_numPipe]; 

    std::vector < pthread_t > tids_dbaccess;
    // db access thread pool.
    for(int i=0; i<g_numPipe*g_threadsCntPerPipe; i++)
    {
        int rt =pthread_create(&tid,NULL,ThreadDBAccess,NULL);
        if(0!=rt)
        {
            printf("pthread_create error,error=%s \n",strerror(errno));
            break;
        }
        tids_dbaccess.push_back(tid);
        ConnectToServer("127.0.0.1",DBPROXYSERVER_PORT);
        g_tid_fd[tid] =-1;
        printf("-- %u->%d g_tid_fd.size()=%u--- \n",(cf_uint32)tid,-1,(cf_uint32)(g_tid_fd.size()));
    }
    
    
    for(int i=0; i<int(tids_network.size()); i++)
    {
        int rt = pthread_join(tids_network[i], NULL);
        if(0!=rt)
        {
            printf("pthread_join error,error=%s \n",strerror(errno));
            break;
        }
    }
    for(int i=0; i<int(tids_dbaccess.size()); i++)
    {
        int rt = pthread_join(tids_dbaccess[i], NULL);
        if(0!=rt)
        {
            printf("pthread_join error,error=%s \n",strerror(errno));
            break;
        }
    }
}

cf_int main(cf_int argc,cf_char * argv[])
{
    fprintf(stdout,"db_proxy_server started\n------------\n");
    if(argc<2)
    {
        printf("Usage:%s <threads count> \n",argv[0]);
        return 0;
    }
    g_numPipe =atoi(argv[1]);
    Run();
    return 0;
}

