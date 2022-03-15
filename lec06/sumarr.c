#include <stdio.h>

int sumArray3(int *a, int sum)
{
	/*
	a[3] = a[0] + a[1] + a[2];
	sum = a[3];
	*/
	sum = *a;
	a++;
	sum += *a;
	a++;
	sum += *a;
	fprintf(stdout, "%d : %lld %llx\n", sum, &sum, &sum);
	return a[3];
}
	
int main()
{
	int a = 100;
	int b = 200;
	int c = 999;
	int arr[4] = {100, 200, 300, 400};
	int *parr;
	parr = arr;
	parr++;
	fprintf(stdout, "%d : %lld %llx\n", *parr, parr, arr);

	c = sumArray3(arr, b);	
	
	fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
	fprintf(stdout, "%d : %lld %llx\n", arr, arr, arr);
	fprintf(stdout, "%d : %lld %llx\n", *arr, *arr, *arr);
	fprintf(stdout, "%d : %lld %llx\n", &arr, &arr, &arr);
	fprintf(stdout, "%d : %lld %llx\n", arr[2], &arr[2], &arr[2]);
	fprintf(stdout, "%d : %lld %llx\n", arr[3], &arr[3], &arr[3]);
	fprintf(stdout, "%d : %lld %llx\n", arr[4000], &arr[4000], &arr[4000]);
	
/*	
-419713568 : 140728478707168 7ffde6fbade0
100 : 100 64
-419713568 : 140728478707168 7ffde6fbade0 -> 오류
300 : 140728478707176 7ffde6fbade8
-419713312 : 140728478707184 7ffde6fbadf0
*/
}
/*
-852377696 : 140732341010336 7ffecd31bfa0
100 : 100 64
-852377696 : 140732341010336 7ffecd31bfa0
300 : 140732341010344 7ffecd31bfa8
600 : 140732341010348 7ffecd31bfac
-852377440 : 140732341010352 7ffecd31bfb0
*/
