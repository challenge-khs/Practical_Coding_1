#include "fx_head.h"
#include "fx_s15_16.h"
#include <stdio.h>

// 
int main()
{

	printf("%f : %d\n",1.0, fromDouble(1.0)); 
	printf("%f : %f\n",1.3*0.3, toFloat(fxMul_float(fromDouble(1.3),fromDouble(0.3)))) ; 

}
