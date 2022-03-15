#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int bbb = 0; 

void fn_s()
{
    static int a = 0; 
    printf("== %d %d ==",a++, bbb++);
}


void *run (void *arg)
{
    printf("Hello world of POSIX threads.%d\n", (int) (0) );
    for (int i = 0; i < 10; i++)
	{
		sleep(1); 
		fn_s(); 
	}
    return 0;

}

int main()
{
	int result1;
	char bufff[10];
	run((void *) 0); 
	printf("Thread return %d at the end\n", result1);
}

