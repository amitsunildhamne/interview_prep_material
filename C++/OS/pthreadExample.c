/*This example contains sample for pthread mutexes conditionals*/
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUMBER_OF_THREADS 8

int done = 0;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void thread_entry(void *long)
{
  pthread_mutex_lock(&mutex);
  ++done;
  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&mutex);
}

int main()
{
  pthread_t thread[NUMBER_OF_THREADS];
  for (int i = 0; i < NUMBER_OF_THREADS; ++i)
  {
    pthread_create(&thread[i], NULL, thread_entry, (void *)(long) i);

  }

  while(done < NUMBER_OF_THREADS)
  {
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond, &mutex);

  }
  for (int i = 0; i < NUMBER_OF_THREADS; ++i)
  {
    pthread_join(&thread[i], NULL);
  }
  return 0;
}
