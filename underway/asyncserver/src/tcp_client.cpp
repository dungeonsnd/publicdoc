
#include "cppfoundation/cf_root.hpp"
#include "cppfoundation/cf_utility.hpp"
#include "cppfoundation/cf_network.hpp"
#include "common.hpp"

int g_threadscnt =1;
int g_times =1;
std::string g_bufrecv;
std::vector < cf_fd > g_vecSock;
std::vector < std::string > g_vecStr;

#define HEADER_LEN 4
#define TID (unsigned)pthread_self()


cf_pvoid Run(void * p)
{
    CF_PRINT_FUNC;
    int index =*((int *)p);
    cf_fd sockfd=g_vecSock[index];
    //    printf("index=%d,sockfd=%d \n",index,sockfd);
    ssize_t hasSent =0;
    ssize_t hasRecv =0;
    ssize_t shouldRecv =0;
    bool peerClosedWhenRead =false;

    cf_uint64 seconds =0;
    cf_uint32 useconds =0;
    cf::Gettimeofday(seconds, useconds);

    for(int k=0; k<g_times; k++) // send times
    {
        std::string & body =g_vecStr[k];
        hasSent =0;
        bool succ =cf::SendSegmentSync(sockfd,body.c_str(), body.size(),hasSent,8000,
                                       body.size());
        if(succ)
        {
#if 1
            fprintf(stderr,"tid=%u,Sent succeeded ! hasSent=%d ,k=%d ",TID,int(hasSent),k);
            fprintf(stderr,"tid=%u,buff=%s \n",TID,body.c_str()+HEADER_LEN);
#endif
        }
        else
            fprintf(stderr,"tid=%u,Warning,Send timeout ! \n",TID);
        if(hasSent!=(cf_uint32)body.size())
            fprintf(stderr,"tid=%u,Warning,Recved len{%u}!=body.size(){%u}! \n",TID,
                    (cf_uint32)hasSent,(cf_uint32)(body.size()));

        peerClosedWhenRead =false;
        hasRecv =0;
        shouldRecv =hasSent-HEADER_LEN;
        succ =cf::RecvSegmentSync(sockfd,&g_bufrecv[0], shouldRecv,hasRecv,
                                  peerClosedWhenRead,8000);
        if(succ)
        {
#if 1
            fprintf(stderr,"tid=%u,Recv succeeded ! hasRecv=%d ,k=%d ,",TID,int(hasRecv),k);
            fprintf(stderr,"tid=%u,buff=%s \n",TID,g_bufrecv.c_str());
#endif
        }
        else
            fprintf(stderr,"tid=%u,Warning,Recv timeout ! \n",TID);
        if(hasRecv!=shouldRecv)
            fprintf(stderr,
                    "tid=%u,Warning,Recved hasRecv{%u}!=shouldRecv{%u}! peerClosedWhenRead=%u \n",
                    TID,
                    (cf_uint32)hasRecv,(cf_uint32)shouldRecv,cf_uint32(peerClosedWhenRead));
    }

#if 1
    fprintf(stderr,"tid=%u,cf_close!\n",TID);
#endif
    cf_close(sockfd);
    return NULL;
}

cf_int main(cf_int argc,cf_char * argv[])
{
    fprintf(stdout,"tcp_client started\n------------\n");
    if(argc<3)
    {
        printf("Usage: program <threads count> <times per thread> \n"
               "e.g. ./test_client 1 10 \n");
        return 1;
    }
    g_threadscnt =atoi(argv[1]);
    g_times =atoi(argv[2]);
    g_bufrecv.resize(8192);

    for(int i=0;i<g_times;i++)
    {
        std::string sql ="SELECT * FROM t;";
        std::string len(4,'\0');
        cf_uint32 l =htonl(sql.size());
        memcpy(&len[0], &l,sizeof l);
        g_vecStr.push_back(len+sql);
    }
        
    cf::ConnectToServer("192.168.17.153",SERVER_PORT,g_threadscnt,g_vecSock);

    pthread_t tid[512];
    void * res;
    int s,tnum;
    std::vector < int > index(g_threadscnt);

    for (tnum = 0; tnum < g_threadscnt; tnum++)
    {
        index[tnum] =tnum;
        s = pthread_create(&tid[tnum], NULL,&Run, &(index[tnum]));
        if (s != 0)
            perror("pthread_create");
    }
    for (tnum = 0; tnum < g_threadscnt; tnum++)
    {
        s = pthread_join(tid[tnum], &res);
        if (s != 0)
            perror("pthread_join");
        free(res);
    }
    return 0;
}

