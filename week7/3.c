//流操作的缓冲区设置应用实例
//调用setbuf函数来修改标准输入stdin的缓冲方式
#include <stdio.h>
#include <stdlib.h>
#define SIZE 512//定义缓冲区大小
int main(int argc,char *argv[])
{
	
	char buf[SIZE];
	if(setvbuf(stdin,buf,_IONBF,SIZE)!=0)
	{
		perror("将标准输入stdin的输入设置为无缓冲失败!\n");
		return 1;
	}
	printf("\n");
	printf("\n");
	if(stdin->_flags& _IO_UNBUFFERED)
	{
		printf("\n");
	}else if(stdin->_flags & _IO_LINE_BUF)
	{
		printf("\n");
	}else
	{
		printf("\n");
	}
	printf("\n");
	printf("\n");
	if(setvbuf(stdin,buf,_iofbf,size)!=0)
	{
		printf("\n");
		return 2;
	}
	printf("\n");
	printf("\n");
	if(stdin-> flags & _IO_LINE_BUF)
	{
		printf("\n");
	}
	else if(stdin->_flags& _IO_LINE_BUF)
	{
		printf("\n");
	}else{
		printf("\n");
	}
	printf("");
	printf("\n");
	return 0;
}

