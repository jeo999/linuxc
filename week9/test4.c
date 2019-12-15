#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void __attribute__((constructor)) befer_main(){
	printf("Running before main!\n");
}

static void callback1(){
	printf("1:Running after main!\n");
}
static void callback2(){
	printf("2:Running after main!\n");
}
static void callback3(){
	printf("3:Running after main!\n");
}

int main(int argc,char *argv[])
{
	atexit(callback1);
	atexit(callback1);
	atexit(callback1);
	printf("test1:pid=%d,ppid=%d\n",getpid(),getppid());
	for(int i=0;i<argc;i++){
		printf("test4:argv[%d]:%s\n",i,argv[i]);
	}
	sleep(2);
	printf("test4:finish running\n");
	return 0;
	
}

