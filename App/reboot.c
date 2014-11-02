#include "Typedef.h"
#include "util.h"
#include "SysCall.h"
#include "stdio.h"

static int main(int argc,char *argv[])
{
  typedef void (*reboot_entry)(void);
  reboot_entry pfReboot=(reboot_entry)0;
  pfReboot();
  return 0;
}

INSTALLAPP(reboot,main);
