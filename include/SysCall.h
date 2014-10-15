typedef struct
{
	int (*main)(int argc,char *argv[]);
	char *Name;
}TagSysCall;
extern TagSysCall SYSCALL_BEGIN[],SYSCALL_END[];

#define INSTALLAPP(name,func) static __attribute__((__used__)) __attribute__((section(".APP"))) TagSysCall App_##name={func,#name};
