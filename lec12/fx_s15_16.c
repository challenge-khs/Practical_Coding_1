#include "fx_head.h"
#include "fx_s15_16.h"

fixed fxMul_float(fixed a, fixed b) 
{
	return fromFloat(toFloat(a) * toFloat(b)); 
}
