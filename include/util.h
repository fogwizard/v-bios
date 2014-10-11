
#define Readl(addr) *(unsigned long *)(addr)
#define ReadByte(addr) *(unsigned char *)(addr)
#define Writel(addr,n)    do{*((volatile unsigned long*)(addr))=n;}while(0)
#define WriteByte(addr,n) do{*((volatile unsigned char*)(addr))=n;}while(0)

#define CMD_ARG_MAX 0x0a
#define KEY_ENTER   0x0d

extern void beep(unsigned char ctl);
extern void v_bios_serial_load(void *pLoadAddr);

