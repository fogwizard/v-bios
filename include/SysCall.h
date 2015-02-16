typedef struct
{
	int (*main)(int argc,char *argv[]);
	char *Name;
}TagSysCall;
extern TagSysCall SYSCALL_BEGIN[],SYSCALL_END[];

#define INSTALLAPP(name,func) static __attribute__((__used__)) __attribute__((section(".APP"))) TagSysCall App_##name={func,#name};


typedef struct
{
    bool (*init)(void);
}TagInitCall;
extern TagInitCall INIT_CALL_BEGIN[],INIT_CALL_END[];

#define INSTALLDEVICE(name,func) static __attribute__((__used__)) __attribute__((section(".INITSECT"))) TagInitCall Drive_##name={func};
#define INSTALLINIT(name,func) INSTALLDEVICE(name,func)