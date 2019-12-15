/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	printf("test:pid=%d,ppid=%d\n",getpid(),getppid());
}*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int arge,char *argv[]){
	int i;
	printf("test:pid=%d,ppid=%d\n",getpid(),getppid());
	for(i=0;i<arge;i++){
		printf("%s\n",argv[i]);
	}

}

