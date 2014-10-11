#include "Typedef.h"
#include "util.h"

void beep(unsigned char ctl)
{
  Writel(0x56000010,0x01);//Config beep output  01
  if(1==ctl)
  {
      Writel(0x56000014,0x01);//set beep output  01
  }
  else
  {
      Writel(0x56000014,0xFFFFFFFE);//off beep
  }
}

