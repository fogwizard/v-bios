#include "Typedef.h"
#include "util.h"
#include "SysCall.h"
#include "stdio.h"
#include "malloc.h"

struct test
{
    int a;
    int b;
    int c;
};
static int main(int argc,char *argv[])
{
  struct test *p[10];
  int i;
  printf("test malloc.c is Running\r\n");
  for (i = 0; i < 10; ++i)
  {
      p[i]=(struct test *)malloc(sizeof(struct test));
      if(NULL==p)
      {
        printf("Alloc Error(%d)\r\n",i);
      }
      printf("Alloc addr=[%x]\r\n",p[i]);
  }
  for (i = 0; i < 10; ++i)
  {
      printf("Free addr [%x]\r\n",p[i]);
      free(p[i]);
  }
  for (i = 0; i < 10; ++i)
  {
      p[i]=(struct test *)malloc(sizeof(struct test));
      if(NULL==p)
      {
        printf("Alloc Error(%d)\r\n",i);
      }
      printf("Alloc addr=[%x]\r\n",p[i]);
  }
  for (i = 0; i < 10; ++i)
  {
      printf("Free addr [%x]\r\n",p[i]);
      free(p[i]);
  }
  return 0;
}

INSTALLAPP(testmalloc,main);
