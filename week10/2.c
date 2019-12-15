#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int g=999;
int main(){
	int i=888;
	static int k=30;
	pid_t pid;
	pid = vfork();
	if(pid<0){
		perror("fork failed!\n");
		return -1;
	}
	else if(pid == 0)
	{
		printf("child is running\n",getpid());
		printf("child pid=%d : \n&g=%16p\n&k=%16p&i=%16p\n",getpid(),&g,&k,&i);
		g=100;
		s=200;
		k=300;
		sleep(2);
		printf("child after g=%d,s=%d,k=%d\n",g,s,k);
		_exit(0);
		//return 0;
	}
	else
	{
		sleep(2);
		printf("parent pid=%d : \n&g=%16p\n&k=%16p&s=%16p\n",getpid(),&g,&k,&s);
		printf("after after g=%d,s=%d,k=%d\n",g,s,k);
		//return 0;
	}
}
