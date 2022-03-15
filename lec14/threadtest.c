#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int bbb = 0; 

void fn_s()
{
	static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    	static int a = 0; 
    	printf("<= %d %d =>",a, bbb);
    	pthread_mutex_lock(&mutex);
	a++; bbb++;
    	pthread_mutex_unlock(&mutex);
}


void *run (void *arg)
{
    printf("Hello world of POSXI threads.%d\n", (int) pthread_self() );
    for (int i = 0; i < 1000000; i++)
	{
		//usleep(10000); 
		fn_s(); 
	}
    return 0;

}

int main()
{
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	int result1, result2, result3;

	pthread_create(&thread1, NULL, run, NULL );
	pthread_create(&thread2, NULL, run, NULL );
	pthread_create(&thread3, NULL, run, NULL );
	run((void *) 0); 
	pthread_join(thread1, (void **) &result1);
	pthread_join(thread2, (void **) &result2);
	pthread_join(thread3, (void **) &result3);
	printf("\nThread return %d at the end\n", result1);
}

