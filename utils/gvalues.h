#ifndef _GVALUES_H_
#define _GVALUES_H_

#ifdef LINUX
	#include <values.h>
#endif
#ifdef MACOSX
	#include <limits.h>
	#include <math.h>
	#define MAXDOUBLE 1e1000
	#define isnan(x) (x==FP_NAN)
#endif

#endif 

