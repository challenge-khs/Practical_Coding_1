#include <stdio.h>
// #### #### #### #### . #### #### #### ####
// S 15 . 16
#define FX_Q_NUM 16
#define FX_2_MINUS_16 1.52587890625e-05F
#define FX_2_PLUS_16 (1<<16)
#define FX_S_15_16 11516
#define FX_SYSTEM FX_S_15_16

typedef long long fixed32;

#define fromFloat(fa) ((fixed32)((fa) * FX_2_PLUS_16))
#define toFloat(fa) (((float)(xa)) * FX_2_MINUS_16)
fixed32 fromFloat_fn(float fa)
{
	return (fixed32) (fa * FX_2_PLUS_16);
}

float toFloat_fn(fixed32 xa)
{
	return ((float) (xa)) * FX_2_MINUS_16;
}

fixed32 fxAdd(fixed32 a, fixed32 b)
{
	//return fromFloat(toFloat(a) + toFloat(b));
	return (fixed32) (FX_2_PLUS_16 * ((((float) (a)) * FX_2_MINUS_16) + (((float) (b)) * FX_2_MINUS_16)));
}

fixed32 fxAdd2(fixed32 a, fixed32 b)
{
	return a + b;

}
int main() 
{
	long long i = 0;
	int ia, ib, ic, ic2;
	float fa;
	//fscanf(stdin, "%d %d", &ia, &ib);
	for(i = 0; i < (long long) 256*256*256*256; i += 25)
	{
		ic = fxAdd(i, i);
		ic2 = fxAdd2(i, i);
		//fprintf(stdout, "%f + %f : %f, %f diff = %d\n", toFloat(i), toFloat(i), toFloat(ic), toFloat(ic2), ic - ic2);
	}

}
