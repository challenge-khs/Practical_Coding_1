#include <stdio.h>
#define VALUE_ONE 1
// Count number of 1 (binary)

int count_one(unsigned int a)
{
	int const con = 100;
	int static numCalls = 0;
	int i, count = 0;
	/*
	for (i = 31; i >= 0; i--) 
	{
		//if((a >> i) & 1);
		//	count ++;
		count += (a >> i) & 1;
	}
	i = 32;
	while(i > 0) 
	{
		count += a & VALUE_ONE;
		a >>= VALUE_ONE;
		i--;
	}
	*/
	while(a != 0)
	{
		count += a & 1;
		a >>= 1;
		// a는 unsigned int 여야함
	}
	
	fprintf(stderr, "Call : %d\n", numCalls);
	numCalls++;
	//con++;
	return count;
}

int main()
{
	int i;
	int in_a;
	fscanf(stdin, "%u", &in_a);
	fprintf(stdout, "%u \t : ", in_a);
	for (i = 31; i >= 0; i--) 
	{
		fprintf(stdout, "%d", ((in_a >> i) & 1));
		if(i%4 == 0)
			fprintf(stdout, " ");
	}
//	fprintf(stdout, "\n");
	fprintf(stdout, ": %d \n", count_one(in_a));
	fprintf(stdout, ": %d \n", in_a);
}
