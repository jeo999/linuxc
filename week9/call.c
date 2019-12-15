#include <stdio.h>
#include <unistd.h>
int main(){
	printf("call:pid=%d,ppid=%d\n",getpid(),getppid());
	//system("/home/rlk/linuxprogram/week9/code/test");
	char *args[]={"/home/rlk/linuxprogram/week9/code/test",NULL};
	execve("/home/rlk/linuxprogram/week9/code/test",args,NULL);
	printf("after calling\n");
}
