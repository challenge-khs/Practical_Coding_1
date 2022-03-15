#include <stdio.h>

int main()
{
	char      a;
	short     b;
	int       c;
	long long d;

	scanf("%hhd %hd %d %lld", &a, &b, &c, &d);
	printf("%hhd %hd %d %lld\n", a, b, c, d);
}
