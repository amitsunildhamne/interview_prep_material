#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define BUF_MAX 3

struct Buffer
{
    int buffer[BUF_MAX];
    int size;
    int add;
    int rem;
};

struct Buffer Buf;
Buf.size = BUF_MAX;
Buf.rem  = -1;
Buf.add  =  0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t p_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t c_cond = PTHREAD_COND_INITIALIZER;

void *producer(void *param);
void *consumer(void *param);

int main()
{
  pthread_t pThread, cThread;
  if (pthread_create(&pThread, NULL, producer, NULL) != 0)
  {
    printf("Unable to create Producer Thread\n");
    exit(1);
  }
  if (pthread_create(&cThread, NULL, consumer, NULL) != 0)
  {
    printf("Unable to create Consumer Thread\n");
    exit(1);
  }

  pthread_join(&pThread, NULL);
  pthread_join(&cThread, NULL);

  exit(0);
}

void *producer(void *param)
{
  printf("Enter Producer\n");
  pthread_lock(&mutex);
  int itr = 0;
  for ( ; itr<BUF_MAX; i++itr)
  {
    while(buf.size >= BUF_MAX)
    {
      pthread_cond_wait(&p_cond, &mutex);
    }

    Buf[Buf.add] = i;
    Buf.add = Buf.add + 1 % Buf.size;
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&c_cond);
  }
}
