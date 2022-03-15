#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int a = 0; 
	pid_t pid ,pid2;
       	pid = fork(); 
	pid2 = fork(); 
	for (int i = 0; i < 100; i++)
	{
		sleep(1); 
		printf("PID %d : PID2 %d : A = %d : i = %d \n", pid, pid2, a++, i);
	}
}
