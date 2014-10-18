#include "Typedef.h"
#include "shell.h"
#include "SysCall.h"
#include "util.h"
#define SET_VALUE(var,val) do{var=val;}while(0)

int
ReadCmd (char *buf, char *argv[]);
int
ExecCmd (int argc, char *argv[]);

fsm_rt_t read_params(int argc)
{
    char c;
    int i=0;
    do
    {
	c=UartGetChar(0);
	chByteCommandLine[argc][i]=c;
	if((0==i)&&((' '==c)||('\t'==c)))//spase in front
	{
	     continue;
	}
	else
	{
	    if(c!=KEY_ENTER)
	    {
    		UartPrintChar(0,c);
            if(0x08==c)
            {
                UartPrintChar(0,' ');
                UartPrintChar(0,c);
                i--;
                if(i<0)
                {
                    i=0;//return fsm_rt_back;
                }
            }
            else
            {
                i++;//for delete the enter key...
            }
	    }
	}
	if((' '==c)||('\t'==c))//space in back
	{
	  chByteCommandLine[argc][i-1]='\0';//(i-1) is the space
	  return fsm_rt_cpl;
	}
    }while(c!=KEY_ENTER);
    chByteCommandLine[argc][i]='\0';
    return fsm_rt_err;
}

int ReadCmd (char *buf, char *argv[])
{
  int argc,r_s;
  char  i;
  enum\
  {\
    READ_START,\
    READ_PARAMS,\
    READ_FINISH,\
  }s_state_read_cmd;
  s_state_read_cmd=READ_START;
  for (i = 0; i < CMD_ARG_MAX; ++i)//Init Pointer
  {
      argv[i] = chByteCommandLine[i];
      chByteCommandLine[i][0]='\0';//end line
  }
  printf("<v-gios>");
  while (1)
    {
      switch (s_state_read_cmd)
      {
	case READ_START:
	     argc=0;
	     s_state_read_cmd=READ_PARAMS;
	     break;
	case READ_PARAMS:
	      r_s=read_params(argc);
	      if(fsm_rt_cpl==r_s)
	      {
    		 s_state_read_cmd=READ_PARAMS;
    		 argc++;
	      }
          else if(fsm_rt_back==r_s)//Now Not Support Back
          {
             argc--;
             s_state_read_cmd=(argc>0)?READ_PARAMS:READ_START;
          }
	      else if(fsm_rt_err==r_s)
	      {
    		   s_state_read_cmd=READ_FINISH;
    		   argc++;
	      }
	      break;
	case READ_FINISH:
	      UartPrintChar(0, '\r');
	      UartPrintChar(0, '\n');
	      return argc;
	      break;
      }
    }
}
int ExecCmd (int argc, char *argv[])
{
  char *Name = argv[0];
  int i;
  TagSysCall *pCall;
  for (pCall = SYSCALL_BEGIN,i=0; pCall<SYSCALL_END; pCall++,i++)
  {
      if (0==strcmp (Name,(*pCall).Name))
	{
	  (*pCall).main(argc,argv);
	  return i;
	}
  }
  printf("Command not find\r\n");
  return -1;
}


