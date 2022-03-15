#include <stdio.h>

void add(int *a, int *b, int *c)
{
	*c = *a + *(a+1);
}
	
int main()
{
	int a = 100;
	int b = 200;
	long long c = 999;
	// int * == long long
	
	fprintf(stdout, "%d : %lld %llx\n", a, &a, &a);
	fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
	add(&a, &b, &c);
	// c = a + b;
	fprintf(stdout, "%d : %lld %llx\n", c, &c, &c);
	fprintf(stdout, "%d : %lld %llx\n", c, (&c)+1, &c+1);
	fprintf(stdout, "%d : %lld %llx\n", c, (&c)+2, &c+2);
}
