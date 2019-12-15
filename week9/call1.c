#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	int ret;
	printf("call1:pid=%d,ppid=%d", getpid(), getppid());
	ret = system("./test2 123 abc hello ncu edu");
	printf("after calling ret=%d", ret);
	return 0;
}
