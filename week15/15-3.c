#include"my.h"

void *watch_count(void *idp){
	int *my_id=idp;
	printf("Starting watch count():thread %d\n",*my_id);
	pthread_mutex_lock(&count_mutex);
	if(count<COUNT_LIMIT)
	{
		pthread_cond_wait(&count_threshold_cv,&count_mutex);
		printf("watch_count();thread %d Condition signal received.\n",*my_id);
	}
	pthread_mutex_unlock(&count_mutex);
	pthread_exit(NULL);
}
