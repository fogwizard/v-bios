#define UartGetChar(n)    Uart##n##GetChar()
#define UartPrintChar(n,ch)  Uart##n##PrintChar(ch)

extern char chByteCmdbuf[];
extern char chByteCommandLine[][32];
