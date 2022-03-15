#include <stdio.h>

int main()
{
	int a = 100;
	int b = 200;
	// int * == long long
	
	
	fprintf(stdout, "%d : %lld %llx\n", a, &a, &a);
	fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
	*&b = 500;
	fprintf(stdout, "%d : %lld %llx\n", *&b, &b, &b);
}
