
#include "common.hpp"
#include "plugin_mgr.hpp"


int main(int argc,char * argv[])
{
    if(argc<3)
    {
        fprintf(stdout,"Usage: %s <plugin path> <plugin file> \n",argv[0]);
        return 1;
    }
    fprintf(stdout,"Please input plugin name(e.g. '100'), type q to exit ...\n");    
    PluginMgr pm(argv[1],argv[2]);    
    
    std::string rbuf(1024,'\0');
    while(1)
    {
        bzero(&rbuf[0],rbuf.size());
        read(0,&rbuf[0],rbuf.size());
        rbuf[strlen(rbuf.c_str())-1] ='\0';
        if(rbuf[0]=='Q' || rbuf[0]=='q')
        {
            break;
        }
        pm.Run(rbuf);
        fprintf(stdout,"\n");
    }    
    return 0;
}
