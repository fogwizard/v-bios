
#define Readl(addr) *(volatile unsigned long *)(addr)
#define ReadByte(addr) *(volatile unsigned char *)(addr)
#define Writel(addr,n)     do{*((volatile unsigned long* )(addr))=n;}while(0)
#define WriteByte(addr,n)  do{*((volatile unsigned char* )(addr))=n;}while(0)
#define WRITESHORT(addr,n) do{*((volatile unsigned short*)(addr))=n;}while(0)

#define CMD_ARG_MAX 0x0a
#define KEY_ENTER   0x0d

#define KB(n) ((n)<<10)
#define MB(n) ((n)<<20)
#define GB(n) ((n)<<30)

#define MAGIC ('v'<<24)|('-'<<16)|('b'<<8)|'h'

extern void beep(unsigned char ctl);
extern void ShowString (const char *dat);
extern void v_bios_serial_load(void *pLoadAddr);

