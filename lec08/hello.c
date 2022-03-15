#include <stdio.h>

void add(int *a, int *b, int *c)
{
	*c = *a + *b;
}
	
int main()
{
	int a = 100;
	int b = 200;
	int c = 999;
	// int * == long long
	
	fprintf(stdout, "%d : %lld %llx\n", a, (long long)&a, (long long)&a);
	fprintf(stdout, "%d : %lld %llx\n", b, (long long)&b, (long long)&b);
	add(&a, &b, &c);
	// c = a + b;
	fprintf(stdout, "%s %d : %d\n", __FILE__, __LINE__,c);
	fprintf(stdout, "%s %d : %d\n", __FILE__, __LINE__,c);
	fprintf(stdout, "%s %d : %d\n", __FILE__, __LINE__,c);
#define ERR_DATA 1000
#if ERR_DATA > 1000
#error 1024
#else
#warning ERR_DATA
#endif
	fprintf(stdout, "%s %d : %d\n", __FILE__, __LINE__,c);
}
