
#include "common.hpp"
#include "plugin_interface.hpp"

class PlugC2 : public IPlug
{
public:
    PlugC2()
    {
        fprintf(stdout,"PlugC2 construct. \n");
    }
    ~PlugC2()
    {
        fprintf(stdout,"PlugC2 destruct. \n");
    }
    
    int Init()
    {
        fprintf(stdout,"PlugC2 Init. \n");
        return 0;
    }
    int Run()
    {
        fprintf(stdout,"PlugC2 Run. \n");
        return 0;
    }
    int Final()
    {
        fprintf(stdout,"PlugC2 Final. \n");
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
            p =new PlugC2();
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
