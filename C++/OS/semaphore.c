#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaphore;

void thread_func()
{
	while(1)
	{
	 sem_wait(&semaphore);
	printf("Hi from threda \n");
	sem_post(&semaphore);
	sleep(1);
	}

}

int main()
{
	sem_init(&semaphore, 0, 1);
		pthread_t* mythread;
	 mythread = (pthread_t *)malloc(sizeof(*mythread));
	pthread_create(mythread, NULL, (void*)thread_func, NULL);
	getchar();
	sem_wait(&semaphore);
	printf("Semaphore locked\n");
	getchar();
	printf("Semaphore Unlocked\n");
	sem_post(&semaphore);
	get_char();
	return 0;
}
