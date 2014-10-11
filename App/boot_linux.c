#include "Typedef.h"
#include "util.h"
#include "SysCall.h"
#include "stdio.h"
static int main(int argc,char *argv[])
{
  printf("boot_linux.c is Running\r\n");
  return 0;
}
static int main_ls(int argc,char *argv[])
{
  printf("boot_linux.c is Running\r\n");
  return 0;
}
static int main_cd(int argc,char *argv[])
{
  printf("boot_linux.c is Running\r\n");
  return 0;
}

__attribute__((__used__)) __attribute__((section(".APP"))) static TagSysCall aboot={main, "boot"};
__attribute__((__used__)) __attribute__((section(".APP"))) static TagSysCall bboot={main_ls,"ls"};
__attribute__((__used__)) __attribute__((section(".APP"))) static TagSysCall cboot={main_cd,"cd"};
