#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *func(void *thread_id) {
	long t_id;
	t_id = (long) thread_id;
	printf("Thread ID: %ld\n", t_id);
	pthread_exit(NULL);
}

int main() {
	// 线程指针数组
	pthread_t threads[NUM_THREADS];
	int rc;
	int i;
	void *arg;
	for(i = 0; i < NUM_THREADS; i++) {
		printf("Main(): creating thread %d\n", i);
		// rc = pthread_create(&(threads[i]), NULL, func, (void *)i);
		rc = pthread_create(&(threads[i]), NULL, func, arg);
		if(rc) {
			printf("Error: unable to create thread %d\n", rc);
			exit(-1);
		}
	}
	pthread_exit(NULL);
}
