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
			EatingTheSpace(buf,int32Len);
		    return;
		}else{
			*buf++=chByteReceive;
		}
	}
}
void ExecCmd(char *buf)
{

}
static void EatingTheSpace(char *buf,char len)
{
	
}



