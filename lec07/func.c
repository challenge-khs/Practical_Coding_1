#include "func.h"

extern int func1(int x);
extern int func2(int x);

#if FUNCION_NEGATIVE == 1

int func1(int a)
{
	return (a*10);
}

#else

int func1(int a)
{
	return (DF(a+1)*20);
}

#endif
