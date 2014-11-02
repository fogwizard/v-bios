#include "Typedef.h"
#include "Uart.h"
#include "kermit.h"
#include "util.h"

#define KermitGetChar()  Uart0GetChar()    //for porting
#define KermitPutChar(n) Uart0PrintChar(n)  //for porting

#define CaculateCheck(n) (KERMIT_KEY_SPASE+(0x3f&(n+(0x03&(n>>6)))))

void v_bios_serial_load(void *pLoadAddr)
{
  enum{MARK,LEN,SEQ,KTYPE,KDATA,CHECK,ACK,NOACK,WRITEFILE,FINISH}s_state_recv=MARK;
  volatile TAG_KERMIT kermit;
  BYTE buf[6];
  BYTE c,i,check_sum;
  volatile BYTE *paddr=(BYTE *)pLoadAddr;
  while(1)
    {
      switch (s_state_recv)
      {
	case MARK:
	  if(MARK_START==KermitGetChar())
	    {
	      s_state_recv++;
	    }
	  break;
	case LEN:
	  c=KermitGetChar();
	  kermit.check=c;
	  kermit.len=KERM_DECODE(c);
	  s_state_recv++;
	  break;
	case SEQ:
	  c=KermitGetChar();
	  kermit.check+=c;
	  kermit.seq=KERM_DECODE(c);
	  s_state_recv++;
	  break;
	case KTYPE:
	  c=KermitGetChar();
	  kermit.check+=c;
	  kermit.type=c;//type char can print
	  s_state_recv++;
	  break;
	case KDATA:
	  i=0;
	  while(KERMIT_KEY_TERM!=(c=KermitGetChar()))
	    {
	      kermit.check+=c;
	      kermit.buf[i++]=c;
	    }
	  kermit.valid_data_len=(0==i)?0:(i-1);
	  s_state_recv++;
	  break;
	case CHECK:
	  c=kermit.buf[i-1];//recv check
	  kermit.check-=c; //it is the check
	  kermit.check_have_encode=CaculateCheck(kermit.check);
	  s_state_recv=(kermit.check_have_encode==c)?ACK:NOACK;
	  break;
	case ACK:
	   buf[0]=MARK_START;
	   buf[1]=KERM_ENCODE(3);
	   buf[2]=KERM_ENCODE(kermit.seq);
	   buf[3]=KERMIT_TYPE_ACK;
	   check_sum=0;
	   for (c = 1; c < 4; ++c) {
	       check_sum+=buf[c];
	   }
	   buf[4]=CaculateCheck(check_sum);
	   buf[5]=KERMIT_KEY_TERM;
	   for (c = 0; c < 6; ++c)
	   {
	       KermitPutChar(buf[c]);
	   }
	   s_state_recv=(kermit.type==KERMIT_TYPE_BREAK)?FINISH:WRITEFILE;
	   break;
	case NOACK://debug lateter
	   buf[0]=MARK_START;
	   buf[1]=KERM_ENCODE(3);
	   buf[2]=KERM_ENCODE(kermit.seq);
	   buf[3]=KERMIT_TYPE_NACK;
	   check_sum=0;
	   for (c = 1; c < 4; ++c) {
	       check_sum+=buf[c];
	   }
	   buf[4]=CaculateCheck(check_sum);
	   buf[5]=KERMIT_KEY_TERM;
	   for (c = 0; c < 6; ++c)
	   {
	       KermitPutChar(buf[c]);
	   }
	   s_state_recv=(kermit.type==KERMIT_TYPE_BREAK)?FINISH:MARK;
	   break;
	case WRITEFILE://write to the RAM
	  if(kermit.type==KERMIT_TYPE_DATA)
	    {
		for (i = 0; i < kermit.valid_data_len; ++i)
		{
		    c=kermit.buf[i];
		    if(KERMIT_KEY_SHARP==c)
		     {
			 ++i;
			 c=kermit.buf[i];
			 if(2==(0x03&(c>>5)))// X10X XXXX
			   {
			     c=c&(~0x40);
			   }
			 else if(0x3F==c)//del
			   {
			     c|=0x40;
			   }
			 else if(0xbf==c)//0xff
			   {
			     c|=0x40;
			   }
		     }
		    *paddr++=c;
		}
	    }
	   s_state_recv=MARK;
	  break;
	case FINISH:
	  return ;
	  break;
      }
    }
}
