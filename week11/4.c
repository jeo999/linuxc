#include "my.h"

int main(){
	int pid1,pid2,s,p;
	if(((pid1=fork())&&(pid2=fork()))<0){
		perror("failes to fork!\n");
		return -1;
	}
	else if(pid1 == 0){
		printf("%d : child1 is running now!\n",getpid());
	
		printf("%d : child1 is exit now!\n",getpid());
		while(1);
		exit(120);
	}
	else if(pid2 == 0){
		printf("%d : child2 is running now!\n",getpid());
	
		printf("%d : child2 is exit now!\n",getpid());
		//while(1);
		exit(130);
	}
	else{
		printf("%d:parent is waiting zombie now!\n",getpid());
		while((p=waitpid(pid1,&s,WNOHANG))!=1)
		{
			printf("%d:parent is exiting now!\n",getpid());
			if(WEXITSTATUS(s))
			{
				printf("child %d is exiting normally .exit code =%d\n",p,WEXITSTATUS(s));
			}
			else if(WIFSIGNALED(s))
			{
				printf("child %d exit by signal.signal no = %d\n",p,WTERMSIG(s));
			}
			else
			{
				printf("Not know !\n");
			}
			
		}
		
	}
	exit(0);

}
