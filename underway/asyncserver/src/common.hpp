#ifndef _HEADER_FILE_COMMON_HPP_
#define _HEADER_FILE_COMMON_HPP_

#include <errno.h>
#include <string.h>
#include "cppfoundation/cf_root.hpp"

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8601    
#define DBPROXYSERVER_IP "192.168.17.153"   
#define DBPROXYSERVER_PORT 8602   
#define SEC 1000000

#define ERR(msg) \
{ \
    printf("Failed of %s,errno=%d,%s \n",msg,errno,strerror(errno)); \
    exit(0); \
}

inline int ConnectToServer(const char * ip,unsigned port)
{
    int sockfd;
    struct sockaddr_in servaddr;
    sockfd=socket(AF_INET, SOCK_STREAM, 0);
    if(-1==sockfd)
        ERR("cf_socket");
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(port);
    inet_pton(AF_INET, ip, &servaddr.sin_addr);
    int rt =connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if(-1==rt)
    {
        ERR("cf_connect")
    }
    return sockfd;
}
#endif // _HEADER_FILE_COMMON_HPP_
