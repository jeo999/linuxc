#include"my.h"

#define	MAXNITEMS 		5      
struct 
{
	pthread_mutex_t lock;
	int key;
	int value;
	int buff[MAXNITEMS];
}shared = {
	PTHREAD_MUTEX_INITIALIZER
};

//这样对结构体初始化

void * create_producer1()
{
	for(;;)
	{
		pthread_mutex_lock(&shared.lock);
		if(shared.key >= MAXNITEMS)
		{
			pthread_mutex_unlock(&shared.lock);
			printf("producer1: my function is over~\n"); 
			pthread_exit(NULL);

		}
		shared.buff[shared.key] = shared.value;
		printf("producer1 have put the data: %d\n",shared.value);
		shared.key ++;
		shared.value ++;
		pthread_mutex_unlock(&shared.lock);

	}

}


void * create_producer2()
{

	for(;;)
	{
		pthread_mutex_lock(&shared.lock);
		if(shared.key >= MAXNITEMS)
		{
			pthread_mutex_unlock(&shared.lock);
			printf("producer2: my function is over~\n");
			pthread_exit(NULL);

		}
		shared.buff[shared.key] = shared.value;
		printf("producer2 have put the data: %d\n",shared.value);
		shared.key ++;
		shared.value ++;
		pthread_mutex_unlock(&shared.lock);

	}

	
}

void * create_consumer()
{

	for(int i = 0;i < 5;i++)
	{
		if(shared.buff[i] != i)
		{
			printf("buff[%d] = %d was wrong!\n", i , shared.buff[i]);
			
		}
	}


	printf("All have scanned!\n");
	return (NULL);
}



int main(int argc, char const *argv[])
{
	pthread_t tid1,tid2;
	pthread_t consumer_tid;



	printf("I will create two producers and one consumers\n");

	if(pthread_create(&tid1,NULL,create_producer1,NULL) != 0)
		printf("create producer1 failed!\n");
	else
		printf("producer1 has been create!\n");



	if(pthread_create(&tid2,NULL,create_producer2,NULL) != 0)
		printf("create producer2 failed!\n");
	else
		printf("producer2 has been create!\n");

//等待生产者线程结束
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

	if(pthread_create(&consumer_tid,NULL,create_consumer,NULL) != 0)
		printf("create consumer failed!\n");
	else
		printf("consumer has been create and begin check out the buff...\n");


	pthread_join(consumer_tid,NULL);


	return 0;
}
