#include <stdio.h>

int main()
{
	int i;
	unsigned int in_a, in_b, in_c;
	fscanf(stdin, "%d %d", &in_a, &in_b);
	in_c = in_a / 4;
	fprintf(stdout, "%d :", in_a);
	for (i = 31; i >= 0; i--) 
	{
		fprintf(stdout, "%d", ((in_a >> i) & 1));
		if(i%4 == 0)
			fprintf(stdout, " ");
	}
	fprintf(stdout, "\n");
	fprintf(stdout, "%d :", in_b);
	for (i = 31; i >= 0; i--) 
	{
		fprintf(stdout, "%d", ((in_b >> i) & 1));
		if(i%4 == 0)
			fprintf(stdout, " ");
	}
	fprintf(stdout, "\n");
	fprintf(stdout, "%d :", in_c);
	for (i = 31; i >= 0; i--) 
	{
		fprintf(stdout, "%d", ((in_c >> i) & 1));
		if(i%4 == 0)
			fprintf(stdout, " ");
	}
	fprintf(stdout, "\n");

}
