#include "Typedef.h"
#include "plamform.h"
#include "util.h"
#include "flash.h"
#include "SysCall.h"
#include "net.h"

#define NET_ETH_MAX 8

tag_file_ops *net_ops_desc[NET_ETH_MAX]={0};

int  sock_alloc(void)
{
    byte i;
    for (i = 0; i < NET_ETH_MAX; ++i)//auto alloc,how I know the MastID?
    {
        if(NULL!=net_ops_desc[i])
        {
          return i;  
        }
    }
    return 0;
}
bool sock_close(int fd)
{
    return 0;
}
bool sendto(fd)
{
    net_ops_desc[fd]->sendto();
}
bool recvfrom(fd)
{
    net_ops_desc[fd]->recvfrom();
}
bool regist_net_device(int MastID,tag_file_ops *ops)
{   
    byte i;
    if((MastID!=0)&&(MastID<NET_ETH_MAX))
    {
        net_ops_desc[MastID]=ops; 
        return true; 
    }
    for (i = 0; i < NET_ETH_MAX; ++i)//auto alloc,how I know the MastID?
    {
        if(NULL==net_ops_desc[i])
        {
          net_ops_desc[i]=ops;
          return i;  
        }
    }
    return false;
}