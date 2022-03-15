#include "fx_head.h"
#include <math.h>

#define FX_POINT		FX_S15_16

#define FX_Q_NUM		(FX_POINT & 0xFF)		// 16

// If you want calculate with high precision set 64
#define FX_SYSTEM_INTEGER 	32				// or 64 or 32
#define FX_SYSTEM_FLOAT		32				// or 64 or 32

#define FX_DATA_TYPE		signed int


typedef int fx_s15_16;
typedef fx_s15_16 fixed; 

#define  fromDouble(d)  	((fixed)((d)*DOUBLE_Q_VALUE))
#define  toDouble(d)    	((double)(d)*DOUBLE_1_Q_VALUE)

#if FX_SYSTEM_FLOAT==64
#define  fromFloat(d)  		((fixed)((d)*FLOAT_Q_VALUE))
#define  toFloat(d)    		((double)(d)*FLOAT_1_Q_VALUE)
#else // == 32
#define  fromFloat(d)  		((fixed)((d)*FLOAT_Q_VALUE))
#define  toFloat(d)    		((float)(d)*FLOAT_1_Q_VALUE)
#endif


// CONSTANTS
#define  FLOAT_Q_VALUE 		(float)(1<<FX_Q_NUM)		
#define  DOUBLE_Q_VALUE 	(double)(1<<FX_Q_NUM)
#define  FLOAT_1_Q_VALUE 	(float)(1.0f/FLOAT_Q_VALUE)
#define  DOUBLE_1_Q_VALUE 	(double)(1.0f/DOUBLE_Q_VALUE) 
#define  FX_PI			fromDOUBLE(M_PI)

// One of FX_OP_FLOAT, FX_OP_PRECISION, FX_OP_FAIR, FX_OP_PERFORMANCE 
#define FX_OP_PREFERENCE	FX_OP_FLOAT

extern fixed fxAdd_float(), fxAdd_precision(), fxAdd_fair(), fxAdd_performance(); 
extern fixed fxSub_float(), fxSub_precision(), fxSub_fair(), fxSub_performance(); 
extern fixed fxMul_float(), fxMul_precision(), fxMul_fair(), fxMul_performance(); 
extern fixed fxDiv_float(), fxDiv_precision(), fxDiv_fair(), fxDiv_performance();

