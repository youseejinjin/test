#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<unistd.h>
#include<time.h>

#include<pthread.h>

pthread_mutex_t mutex;

void *threadFun(void *arg) //B线程
{
	int i = 0;
	for(;i < 5;i++)
	{
		pthread_mutex_lock(&mutex);
		printf("B");
		fflush(stdout);
		int n = rand() % 3;
		sleep(n);

		printf("B");
		fflush(stdout);
		pthread_mutex_unlock(&mutex);

		n = rand() % 3;
		sleep(n);
	}	
}

void threadMain() //A线程
{
	int i = 0;
	for(;i < 5;i++)
	{
		pthread_mutex_lock(&mutex);
		printf("A");
		fflush(stdout);
		int n = rand() % 3;
		sleep(n);

		printf("A");
		fflush(stdout);
		pthread_mutex_unlock(&mutex);

		n = rand() % 3;
		sleep(n);
	} 
}

int main()
{
	srand((unsigned int)time(NULL));

	pthread_mutex_init(&mutex,NULL);

	pthread_t id;
	int res = pthread_create(&id,NULL,threadFun,NULL);
	assert(res == 0);

	threadMain();

	pthread_join(id,NULL);
	pthread_mutex_destroy(&mutex);
	exit(0);
}


