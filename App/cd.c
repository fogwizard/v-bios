#include "Typedef.h"
#include "util.h"
#include "SysCall.h"
#include "stdio.h"
static int main(int argc,char *argv[])
{
  printf("cd.c is Running\r\n");
  return 0;
}

INSTALLAPP(cd,main);
