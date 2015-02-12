
#include "common.hpp"
#include "plugin_interface.hpp"

class PlugC1 : public IPlug
{
public:
    PlugC1()
    {
        fprintf(stdout,"PlugC1 construct. \n");
    }
    ~PlugC1()
    {
        fprintf(stdout,"PlugC1 destruct. \n");
    }
    
    int Init()
    {
        fprintf(stdout,"PlugC1 Init. \n");
        return 0;
    }
    int Run()
    {
        fprintf(stdout,"PlugC1 Run. \n");
        return 0;
    }
    int Final()
    {
        fprintf(stdout,"PlugC1 Final. \n");
        return 0;
    }
};

#ifdef __cplusplus
extern "C" {
#endif

IPlug * p=NULL;

// Not thread-safe!
IPlug * GetInst()
{
    if(NULL==p)
    {
        try{
            p =new PlugC1();
        }catch(...){
            p=NULL;
        }
    }
    return p;
}

void ReleaseInst()
{
    delete p;
    p =NULL;
}

#ifdef __cplusplus
}
#endif
