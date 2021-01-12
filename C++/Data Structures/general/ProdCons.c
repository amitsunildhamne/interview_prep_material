/*
 * Author: Amit Sunil Dhamne
 * Demonstration example for Producer Consumer Problem with Threads.
 * Multiple consumer threads with a server thread. Server threads fills
 * buffer. Consumer thread reads and consumes the values in buffer
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

#define NUM_THREADS				5U

void *PrintHello(void *ThreadId)
{
	long tid;
	tid = (long)ThreadId;
	printf("Hello from %lu\n", tid);
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t threads[NUM_THREADS];
	int rc;
	uint32_t i;

	for (i = 0; i < NUM_THREADS; ++i) {
		rc = pthread_create(&threads[i], NULL, PrintHello, (void *)(uintptr_t)i);
		if (rc) {
			printf("ERROR: Return code from pthread_create() is %d\n", rc);
		}
	}

	pthread_exit(NULL);
}
