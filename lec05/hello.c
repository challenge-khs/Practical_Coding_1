#include <stdio.h>

int main()
{
	signed int siA;
	unsigned int unA;
	signed int sumS;
	unsigned int sumU;

	signed short shortS;
	unsigned short ushortS;

	fscanf(stdin, "%d", &siA);
	fprintf(stdout, "Signed Integer : %d\n", siA); 
	unA = siA;
	fprintf(stdout, "Unsigned Integer : %u\n", unA); 
	fprintf(stdout, "Unsigned Integer %%d : %d\n", unA); 
	fprintf(stdout, "Signed Integer %%u : %u\n", siA); 
	/* -1
	* Signed Integer : -1
	* Unsigned Integer : 4294967295
	* Unsigned Integer %d : -1
	* Signed Integer %u : 4294967295
	*/
	/*
	fscanf(stdin, "%u", &unA);
	fprintf(stdout, "Unsigned Integer : %u\n", unA); 
	siA = unA;
	fprintf(stdout, "Signed Integer : %d\n", siA); 
	*/

	sumS = siA + (signed int) unA;
	sumU = (unsigned int) siA + unA;
	fprintf(stdout, "sumS %%d : %d\n", sumS); 
	fprintf(stdout, "sumS %%u : %u\n", sumS); 
	fprintf(stdout, "sumU %%d : %d\n", sumU); 
	fprintf(stdout, "sumU %%u : %u\n", sumU); 

	shortS = (short) siA + (short) unA;
	ushortS = (unsigned short) siA + (unsigned short) unA;
	fprintf(stdout, "sumS %%d : %d\n", shortS); 
	fprintf(stdout, "sumS %%u : %u\n", shortS); 
	fprintf(stdout, "sumU %%d : %d\n", ushortS); 
	fprintf(stdout, "sumU %%u : %u\n", ushortS); 
	
	shortS = siA + unA;
	ushortS = siA + unA;
	fprintf(stdout, "sumS %%d : %d\n", shortS); 
	fprintf(stdout, "sumS %%u : %u\n", shortS); 
	fprintf(stdout, "sumU %%d : %d\n", ushortS); 
	fprintf(stdout, "sumU %%u : %u\n", ushortS); 


}
