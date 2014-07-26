#include "Typedef.h"
#define SET_VALUE(var,val) do{var=val;}while(0)
void ReadCmd(char *buf);
void ExecCmd(char *buf);
static StrCmp(char *str1,char *str2);


static int s_g_argc=0;

void ReadCmd(char *buf)
{
	static char chByteReceive;
	static int  int32Len=0;;
	while(1){
		  chByteReceive=UartGetChar(0);
		  int32Len++;
		  if ((0x0a== chByteReceive)&&(0x0d==(*buf))){
			  s_g_argc=AnalysisCMD(buf,(int32Len-1));
		      return;
		  }else{
			*buf++=chByteReceive;
			UartPrintChar(0,chByteReceive);
		  }  
	}
}
void ExecCmd(char *buf)
{
	int i;
	int argc=s_g_argc;
	char * * argv=chByteCommandLine;
	char *Name;
	for ( i = 0 ;NULL!=SysCallTable[i].main; i++ ){
	    if(False!=StrCmp(Name,SysCallTable[i].Name){
			*(SysCallTable[i].main)(argc,argv);
	    }
	}
}
static StrCmp(char *str1,char *str2)
{
	while((*str1)&&(*str2)&&(*str1==*str2)){
		str1++;
		str2++;
	}
	return (*str1-*str2);
}

/*******************************************************
         函 数 名  : AnalysisCMD,此函数已经验证
*******************************************************/
static int AnalysisCMD(char *buf,int len)
{
	static enum{
		Command,
		Params,
	}s_Analysis;
	static enum{
		SpaceInFront,
		SpaceInBack,
	}s_SpaceFlag;
	int argc=0;
	char ch=0;
	char index=0;
	s_Analysis=Command;
	s_SpaceFlag=SpaceInFront;
	while(len--){
		ch=*buf;
		switch ( s_Analysis){
		    case Command:
		        if((' '==ch)||('\t'==ch)){
					if(SpaceInFront!=s_SpaceFlag){
						s_SpaceFlag=SpaceInFront;
						chByteCommandLine[argc][index]='\0';//end Charater
						argc++;
				        SET_VALUE(index,0);
						s_Analysis=Params;	
					}
					break;
			    }
				chByteCommandLine[argc][index++]=ch;
				s_SpaceFlag=SpaceInBack;
		        break;
		    case Params:
		        if((' '==ch)||('\t'==ch)){
					if(SpaceInFront!=s_SpaceFlag){
						s_SpaceFlag=SpaceInFront;
						argc++;	
						SET_VALUE(index,0);
					}
					break;
			    }
				chByteCommandLine[argc][index++]=ch;
				s_SpaceFlag=SpaceInBack;
		        break;
		    default:
		        break;
		}
		buf++;
	}
	return (argc+1);//the param is from 0 up to...
}



