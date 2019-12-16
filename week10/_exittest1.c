#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	FILE *fp;
	char buf[] = "hello word";
	if((fp = fopen("test.txt","w")) == NULL)
	{
		perror("fail to fopen");
	}
	if(fputs(buf,fp) == EOF)
	{
		perror("fail to fputs");
		return -1;
	}
	_exit(0);
}
