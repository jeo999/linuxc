#include "my.h"
void * threadfun(void *arg)
{
	printf("thread pid =%d\n",getpid());
}

int main()
{
	pthread_t tipd;
	int error;
	error=pthread_create(&tipd,NULL,threadfun,NULL);
	if(error!=0)
	{
		printf("thread create failed!\n");
		return -1;
	}

	printf("main thread is ended!");
	pthread_join(tipd,NULL);
	return 0;
}

