#include "my.h"
int main(){
	int pid1,pid2;
	FILE *fp;
	fp=fopen("out.dat","w+");
	pid1=fork();
	pid2=fork();
	if(pid1<0||pid2<0){
		printf("子进程创建错误！");
		exit(0);
	}
	if(pid1==0){
		for(int i=0;i<10;i++){
			fprintf(fp,"pid1=%d : %d\n",getpid(),i);
		}
		printf("child1:finish!\n");	
	}
	if(pid2==0){
		for(int i=0;i<10;i++){
			fprintf(fp,"pid2=%d : %d\n",getpid(),i);
		}
		printf("child2:finish!\n");	
	}
	else{
		wait(1);
		printf("%d:parent is waiting now!\n",getpid());
		
	}
	exit(0);
}
