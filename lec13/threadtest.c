#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int bbb = 0; 

void fn_s()
{
	static int a = 0; 
    printf("== %d %d ==",a++, bbb++);
}


void *run (void *arg)
{
    printf("Hello world of POSXI threads.%d\n", (int) pthread_self() );
	for (int i = 0; i < 100; i++)
	{
		usleep(1000); 
		fn_s(); 
	}
    return 0;

}

int main()
{
	pthread_t thread1;
	//pthread_t thread2;
	//pthread_t thread3;
	int result1;
	//int result2;
	pthread_create(&thread1, NULL, run, NULL );
	//pthread_create(&thread2, NULL, run, NULL );
	//pthread_create(&thread3, NULL, run, NULL );
	pthread_join(thread1, &result1);
	//pthread_join(thread2, &result2);
	printf("Thread return %d at the end\n", result1);
	//printf("Thread return %d at the end\n", result2);
}

