#include "Typedef.h"
#include "util.h"
#include "SysCall.h"
#include "stdio.h"
static int main(int argc,char *argv[])
{
  printf("ls.c is Running\r\n");
  return 0;
}

INSTALLAPP(ls,main);
