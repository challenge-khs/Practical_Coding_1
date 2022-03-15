#include <stdio.h>

int add(int *a, int *b)
{
	return *a+*(a+2);
}
	
int main()
{
	int a = 100;
	int b = 200;
	int c = 999;
	// int * == long long
	
	
	fprintf(stdout, "%d : %lld %llx\n", a, &a, &a);
	fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
	c = add(&a, &b);
	fprintf(stdout, "%d : %lld %llx\n", c, &c, &c);
}
