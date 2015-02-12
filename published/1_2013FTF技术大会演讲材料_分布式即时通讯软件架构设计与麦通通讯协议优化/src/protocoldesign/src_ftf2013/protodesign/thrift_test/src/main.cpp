
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <string>
#include <vector>
#include "zlib.h"
#include "compress.hpp"
#include "util.hpp"

#include <thrift/transport/TSocket.h>  
#include <thrift/transport/TBufferTransports.h>  
#include <thrift/protocol/TBinaryProtocol.h>  

#include "gen-cpp/message_types.h"
#include "thrift_serialize.hpp"

using namespace apache::thrift;  
using namespace apache::thrift::protocol;  
using namespace apache::thrift::transport;  
using boost::shared_ptr; 

#define PRINT_RES 0
#define ENABLE_ZIP 1

#define GET_TIME(tv) \
    { \
        int rt =gettimeofday(&tv, NULL);  \
        if(0!=rt) \
        { \
            printf("Failed to invoke gettimeofday \n"); \
            return 1; \
        } \
    }

void SetFriendMessage(FriendMessage & fmsg,const std::string & msgContent)
{
	fmsg.__set_fromuid(5580);
	fmsg.__set_touid(5581);
	fmsg.__set_servermessageid(0);
	fmsg.__set_clientmessageid(100);
	fmsg.__set_servertime(123456);
	fmsg.__set_clienttime(123458);
	fmsg.__set_messagetype(3);
	
	fmsg.__set_content(msgContent);
	fmsg.__set_fontdefault(0);
	fmsg.__set_fontface("宋体");
	fmsg.__set_fontsize(20);
	fmsg.__set_fontcolor(0x0002FF);
	fmsg.__set_fontflag(4);
}

int main(int argc,char ** argv)
{
    if(argc<3)
	{
		printf("Usage: %s <times> <string length>\n",argv[0]);
		return 1;
	}
    int times =atoi(argv[1]);
    int stringLength =atoi(argv[2]);
    if(times<1||stringLength<1)
	{
		printf("times{%d}<1||stringLength{%d}<1 \n",times,stringLength);
		return 1;
	}
    
	srand(time(NULL));
    
    std::vector < std::string > vecMsgContent;
    for(int i=0;i<times;i++)
        vecMsgContent.push_back(GenerateRandString((unsigned int)stringLength));
    
    struct timeval tvStart;
    GET_TIME(tvStart)
    
    unsigned long long sizeUncompressed =0;
    unsigned long long sizeCompressed =0;
    
    for(int i=0;i<times;i++)
    {
        FriendMessage fmsg0;
        std::string originalData;
        SetFriendMessage(fmsg0,vecMsgContent[i]);
        if(false==ThriftToString(fmsg0, originalData))
        {
            printf("Failed to invoke encode \n");
            return 1;
        }
        sizeUncompressed +=originalData.size();
    #if PRINT_RES    
        printf("fromuid=%u,touid=%u \n",fmsg0.fromuid,fmsg0.touid);
        printf("content=%s \n",fmsg0.content.c_str());
        printf("Original data size=%u \n",(unsigned int)originalData.size());
        for(unsigned int i=0;i<originalData.size();i++)
        {
            printf("%02X,",0xFF&(originalData[i]));
        }
        printf("\n");
    #endif    

    #if ENABLE_ZIP
        std::string compData;
        unsigned long int destLen =0;
        if(Z_OK!=Compress(originalData.c_str(), originalData.size(), compData, destLen))
        {
            printf("Failed to invoke Compress \n");
            return 1;
        }        
        sizeCompressed +=destLen;
    #if PRINT_RES    
        printf("Compressed data size=%u \n",(unsigned int)destLen);
        for(unsigned int i=0;i<destLen;i++)
        {
            printf("%02X,",0xFF&(compData[i]));
        }
        printf("\n");
    #endif    
        
        std::string uncompData(originalData.size(),'\0');
        unsigned long int uncompressLen =originalData.size();
        if(Z_OK!=Uncompress(compData.c_str(), destLen, &uncompData[0], uncompressLen))
        {
            printf("Failed to invoke Uncompress \n");
            return 1;
        }
    #if PRINT_RES    
        printf("Uncompressed data size=%u \n",(unsigned int)uncompressLen);
        for(unsigned int i=0;i<uncompressLen;i++)
        {
            printf("%02X,",0xFF&(uncompData[i]));
        }
        printf("\n");
    #endif
    #endif // ENABLE_ZIP
    
    #if ENABLE_ZIP
        FriendMessage fmsg1;
        if(false==StringToThrift(fmsg1, uncompData.c_str(),int(uncompData.size())))
        {
            printf("Failed to invoke decode \n");
            return 1;
        }
    #else
        FriendMessage fmsg1;
        if(false==StringToThrift(fmsg1, originalData.c_str(),int(originalData.size())))
        {
            printf("Failed to invoke decode \n");
            return 1;
        }
    #endif // ENABLE_ZIP
    #if PRINT_RES    
        printf("fromuid=%u,touid=%u \n",fmsg1.fromuid,fmsg1.touid);
        printf("content=%s \n",fmsg1.content.c_str());
    #endif
    }
    
    struct timeval tvStop;
    GET_TIME(tvStop)
    unsigned long long usTotal =tvStop.tv_sec*1000000+tvStop.tv_usec -
                            (tvStart.tv_sec*1000000+tvStart.tv_usec);
    unsigned long long usTotalPerTime =usTotal/times;
	printf("time cost:%lluusec/task, compress/uncompess size=%d/%d, presscompression ratio:%.2f%% \n",
            usTotalPerTime,int(sizeCompressed/times),int(sizeUncompressed/times),
            double(sizeCompressed*100)/sizeUncompressed);
    
	return 0;
}
