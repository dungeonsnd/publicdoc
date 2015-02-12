
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
       
#include <string>
#include <vector>
#include <tr1/memory>
#include <tr1/unordered_map>


int main(int argc,char * argv[])
{
    fprintf(stdout,"zdt1_fork_exec \n");
    if(argc<1)
    {
        fprintf(stdout,"Usage: %s \n",argv[0]);
        return 1;
    }  

    return 0;
}

