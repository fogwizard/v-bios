#include "Typedef.h"
#include "s3c24xxreg.h"
#include "Uart.h"
#include "util.h"
#include "flash.h"


#define THRUNBH() th_run_bh()
#define THINIT_FLASH() init_flash()

bool th_run_bh(void);

static bool check_bh_in_ram(byte *c)
{
  if((c[0]==c_VbiosMagic[0])&&(c[1]==c_VbiosMagic[1]))
  {
    if((c[2]==c_VbiosMagic[2])&&(c[3]==c_VbiosMagic[3]))
    {
      return true;
    }
  }
  return false;
}

bool LoadFromFlash (void)
{
    byte *p;
    p = (byte *)BH_START_ADDRESS_MEM;
    v_bios_flash_load((parttition_info_t *)&c_tPart.bh, (void *)BH_START_ADDRESS_MEM);
    return check_bh_in_ram(&p[4]);
}

void Delay (int t)
{
    while (t--)
        ;
}

bool LoadFromUart (void)
{
    byte *p;
    v_bios_serial_load((void *)BH_START_ADDRESS_MEM);
    Delay(0xffffff);
    p = (byte *)BH_START_ADDRESS_MEM;
    if (false==check_bh_in_ram((byte *)(&p[4]))) //Wrong BH
    {
        ShowString("\r\nWrong Botton Harf!\r\n");
        return false;
    }
    ShowString("\r\nDetect Botton Magic!\r\n");
    v_bios_flash_download((parttition_info_t *)&c_tPart.bh, (void *)BH_START_ADDRESS_MEM);
    return true;
}

void THLoadBH (void)
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
            if(LoadFromFlash())
            {
                Delay(0xffff);
                THRUNBH();
            }
            Delay(0xffff);
            ShowString ("Wrong bh in flash!!\r\n");
            break;
        case '1':
            Uart0PrintChar('1');
            if(LoadFromUart ())
            {
                THRUNBH();
            }
            break;
        default:
            ShowString ("Wrong Choise!!(0:flash 1:Serial)\r\n");
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
    THRUNBH()
    ;
    return 0;
}

bool th_run_bh(void)
{
    typedef void (*BottonHarf)(void);
    BottonHarf pBottonHarf = (BottonHarf)BH_START_ADDRESS_MEM;
    pBottonHarf();
}
