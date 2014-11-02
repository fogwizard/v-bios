#include "Typedef.h"
#include "util.h"
#include "SysCall.h"
#include "stdio.h"
#include "string.h"
#include "kermit.h"

static void usase(void)
{
    printf("Use load address\r\n");
}
static int main(int argc, char *argv[])
{
    int i=0;
    UINT32 Addr;
    if ((2 != argc))
    {
        usase();
        return false;
    }
    Addr=atoi(argv[1]);
    printf("load the file to [%d]",Addr);
    v_bios_serial_load((void *)(Addr));
    return true;
}

INSTALLAPP(load, main);