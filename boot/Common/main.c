#include "Typedef.h"
#include "s3c24xxreg.h"
#include "Uart.h"
#include "util.h"
#define THRunBH() do{((void (*)())BH_START_ADDRESS_MEM)();}while(0)

#define THINIT_FLASH() init_flash()


int LoadFromFlash (void)
{
  return 0;
}


int LoadFromUart (void)
{
  ULONG *p;
  v_bios_serial_load((void *)BH_START_ADDRESS_MEM);
  p=(ULONG *)BH_START_ADDRESS_MEM;
  if(p[0]!=0x55AA55AA)//Wrong BH
  {
      ShowString("\r\nWrong Botton Harf!\r\n");
  }
  return 0;
}
void Delay (int t)
{
  while (t--)
    ;
}

void
THLoadBH (void)
{
  char ch;
  ShowString ("Load Botton Haft From (0:flash 1:Serial)\n\r");
  while (1)
    {
      ch = Uart0GetChar();
      switch (ch)
	{
	case '0':
	  Uart0PrintChar('0');
	  LoadFromFlash ();
	  break;
	case '1':
	  Uart0PrintChar('1');
	  LoadFromUart ();
	  Delay(0xffff);
	  THRunBH();
	  break;
	default:
	  ShowString ("Wrong Choise!!(0:flash 1:Serial)\n\r");
	  break;
	}
    }
}

void
THInitClock (void)
{
}
void
THInitnUart (void)
{

}
void
THInitFlash (void)
{
}

void
THInitSDRAM (void)
{
  /*static WORD SdramInit[]={\
  0x220dd000,\
  0x00000700,\
  0x00000700,\
  0x00000700,\
  0x00000700,\
  0x00000700,\
  0x00000700,\
  0x00018009,\
  0x00018009,\
  0x00ac03f4,\
  0x000000B2,\
  0x00000030,\
  0x00000030};
   volatile ULONG *p=(ULONG *)MEMCON_BASE;
   int i;
   for (i = 0; i < 13; ++i)
   {
       p[i]=SdramInit[i];
   }
   for (i = 0; i < 256; ++i)
   {

   }*/
}



int main (void)
{
  const char *banner = "V-bios Rev 0.0 \n\r";
  Delay (0xFFFF);
  ShowString (banner);
  THInitClock ();
  THInitnUart ();
  THInitFlash ();
  THInitSDRAM ();
  THINIT_FLASH();
  THLoadBH ();
  THRunBH()
  ;
  return 0;
}
