#include "my.h"

int main(){
	int pid,s;
	if(pid=fork()<0){
		perror("failes to fork!\n");
		return -1;
	}
	else if(pid == 0){
		printf("%d : child is running now!\n",getpid());
	
		printf("%d : child is exit now!\n",getpid());
		exit(120);
	}
	else{
		printf("%d:parent is waiting zombie now!\n",getpid());
		while((pid=wait(&s))!=1)
		{
			printf("%d:parent is exiting now!\n",getpid());
			if(WEXITSTATUS(s))
			{
				printf("child %d is exiting normally .exit code =%d\n",pid,WEXITSTATUS(s));
			}
			else if(WIFSIGNALED(s))
			{
				printf("child %d exit by signal.signal no = %d\n",pid,WTERMSIG(s));
			}
			else
			{
				printf("Not know !\n");
			}
			
		}
		
	}
	exit(0);

}
