#include "my.h"
/*#define NUM_THREADS 4//四个线程
void hello(void * t)
{
	pthread_t my_tid;
	my_tid=pthread_self();
	printf("\t Thread %d:my tid is %lx,Hello world\n",t,my_tid);
}
int main()
{
	pthread_t tid;
	int rv,t;
	for(t=0;t<NUM_THREADS;t++)
	{
		rv=pthread_create(&tid,NULL,(void*(*)())hello,(void*)t);
		if(rv!=0)
		{
			printf("thread create failed!\n");
			return -1;
		}
		printf("Create thread %lx\n",tid);
pthread_join(tid,NULL);
	}
	printf("Good bey!\n");
	
}


int main()
{
	pthread_t tid;
	int rv,t;
	for(t=0;t<NUM_THREADS;t++)
	{
		rv=pthread_create(&tid,NULL,(void*(*)())hello,(void*)t);
		rv=pthread_create(&tid,NULL,(void*(*)())add,(void*)t);
		if(rv!=0)
		{
			printf("thread create failed!\n");
			return -1;
		}
		printf("Create thread %lx\n",tid);
	}
	printf("Good bey!\n");
	pthread_exit(NULL);//也可以用join，但是要循环四次
}*/
#define NUM_THREADS 4//四个线程
struct info
{
	int no;
	int n;
};
void hello(void * t)
{
	pthread_t my_tid;
	struct info *y;
	int s=0;
	y=(struct info *)(t);
	for(int i=0;i<y->n;i++)
	{
		s+=i;
	}
	my_tid=pthread_self();
	printf("\t Thread %d:my tid is %lx,Hello world\n",(int)y->no,my_tid);
	printf("\t sum 1 t0 %d is %d\n",(int)y->no,(int)y->n,s);
}



int main()
{
	pthread_t tid;
	struct info a[4];
	int rv,t;
	for(t=0;t<NUM_THREADS;t++)
	{
		a[t].no=t;
		a[t].n=100*(t+1);
		rv=pthread_create(&tid,NULL,(void*(*)())hello,(void*)&a[t]);
		
		if(rv!=0)
		{
			printf("thread create failed!\n");
			return -1;
		}
		printf("Create thread %lx\n",tid);
	}
	printf("Good bey!\n");
	pthread_exit(NULL);//也可以用join，但是要循环四次
}
