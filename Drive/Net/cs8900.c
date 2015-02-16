#include "Typedef.h"
#include "util.h"
#include "SysCall.h"
#include "net.h"

static bool cs8900_send(void)
{
    printf("Test send\r\n");
}
static bool cs8900_recv(void)
{
    printf("Test recv\r\n");
}

static tag_net_device eth0=\
{
    .Nip     =0,
    .Sip     =0,
};

static tag_file_ops ops=\
{
    .sendto  =cs8900_send,
    .recvfrom=cs8900_recv,
};


bool rst_cs8900(void)
{

}

static bool cs8900_init(void)
{
    rst_cs8900();
    regist_net_device(1,&ops);
    printf("Init Network...\r\n");
}

INSTALLDEVICE(cs8900,cs8900_init);