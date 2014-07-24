typedef struct
{
	int (*main)(int argc,char **argv);
	char *Name;
}TagSysCall;
TagSysCall SysCallTable[]={0};
