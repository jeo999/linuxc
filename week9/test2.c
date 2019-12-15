#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int global1=0;
int global2;
int main(){
	int i=10;
	static int k=20;
	int pid=fork();
	pid->TASK_STOPPED;
	if(pid<0){
		perror("创建子进程失败");
		exit;
	}
	else if(pid==0){
		printf("child:pid=%d,ppid=%d;address:i=%d,global1=%d,global2=%d\n",pid,getppid(),&i,&global1,&global2);
		global1=999;
		global2=1000;
		i=12;
		k=19;
		sleep(10);
		//printf("address:global1=%d,global2=%d;i=%d,k=%d\n",global1,global2,i,k);
		exit(0);

	}else{
		printf("parent:pid=%d,ppid=%d;address:i=%d,global1=%d,global2=%d\n",pid,getppid(),&i,&global1,&global2);
		
		printf("address:global1=%d,global2=%d;i=%d,k=%d\n",global1,global2,i,k);
	}

}
