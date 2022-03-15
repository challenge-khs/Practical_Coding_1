#include <stdio.h>
#include <stdlib.h>

int main() 
{
	printf("System Call: %d\n", system("ls -li zzz"));
}
