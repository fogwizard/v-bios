typedef struct
{
	int (*main)(int argc,char *argv[]);
	char *Name;
}TagSysCall;
extern TagSysCall SYSCALL_BEGIN[],SYSCALL_END[];
