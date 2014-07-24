void ReadCmd(char *buf);
void ExecCmd(char *buf);

void ReadCmd(char *buf)
{
	static char chByteReceive;
	static int  int32Len=0;;
	while(1){
		chByteReceive=GetChar();
		int32Len++;
		if ((0x0a== chByteReceive)&&(0x0d==(*buf))){
			EatingTheSpace(buf,(int32Len-1));
		    return;
		}else{
			*buf++=chByteReceive;
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
void ExecCmd(char *buf)
{
	int i;
	int argc;
	char * * argv;
	char *Name;
	for ( i = 0 ;NULL!=SysCallTable[i].main; i++ ){
	    if(TRUE==StrCmp(Name,SysCallTable[i].Name){
			*(SysCallTable[i].main)(argc,argv);
	    }
	}
}
static void StrMoveForward(char *buf,char len)
{
	char *from;
	char *to;
	char i;
	buf++;
	to=buf;
	from=buf+1;
	while((' '=(*buf))||(0x09=(*buf))){
		for ( i = 0 ; i <len ; i++ ){
		    *to++=*from++;
		}
	}
}
static void EatingTheSpace(char *buf,char len)
{
	while(len--){
		if(((*buf)>='0')&&(((*buf)>='0')){
			
		}else if(((*buf)>='A')&&(((*buf)>='z')){
		
		}else{
			if((' '=(*buf))||(0x09=(*buf))){
				StrMoveForward(buf,len);
			}
		}
		*buf++;
	}
}



