/* Copyright (C) Zara 2020. See the LICENSE file for details */
#include "hashfunction.h"

#include<stdlib.h>

/* hash function ctor and dtor */

_HashFunctionPtr make_hashfunction(_HashFunctionPtr hfp)
{
#ifdef _HASH_FUNCTION_MODULUS
//FIXME
#endif	
#ifdef _HASH_FUNCTION_CHAOS0
//FIXME
#else
	hfp->func = (long)(*)(unsigned long)(&(hash_with_modulus));
#endif
}
_HashFunctionPtr free_hashfunction(_HashFunctionPtr hfp)
{
	hfp->func = NULL;
}

/* hashing functionality */

long hashf(unsigned long size, _HashFunctionPtr hfp)
{
//NOTE : maybe #ifdef's
	return hfp->func(size);
}

long hash_with_modulus(unsigned long size = LONG_MAX)
{
	return (random() % size);
}