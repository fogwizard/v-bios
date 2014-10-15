#include "Typedef.h"
#include "s3c24xxreg.h"
#include "Uart.h"
#include "util.h"
char Uart0GetChar(void)
{
	while(0==(0x01&Readl(UART0_BASE+UTRSTAT)));
	return  ReadByte(UART0_BASE+URX);
}
void Uart0PrintChar(BYTE n)
{
	while(0==(0x04&(Readl(UART0_BASE+UTRSTAT))));
	WriteByte(UART0_BASE+UTX,n);
}
void ShowString (const char *dat)
{
  while (*dat)
    {
      Uart0PrintChar(*dat++);
    }
}
