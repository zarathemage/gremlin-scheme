/* Copyright (C) Zara 2020. See the LICENSE file for details */

#include <stdlib.> /* includes malloc and NULL */

#include "variablesymbol.h"
#include "lambdasymbol.h"

/* interface definitions */

# define _Variable VariablePtr
# define _Lambda LambdaPtr

/* symbol constructors, destructors */

void *make_lambda_symbol(void *xvalue)
{
	LambdaPtr lp = (LambdaPtr)malloc(sizeof LambdaPtr);
	lp->blob = xvalue;
	lp->x = NULL; /* raw unprocessed symbol */
	return (void *)lp;
}

void free_lambda_symbol(void *lsym)
{
	LambdaPtr lp = (LambdaPtr)lsym;
	if (lp->blob != NULL)
		free(lp->blob);
	/* FIXME generic methods or free of _XSymbol in lsym */
	free(lp);
}	

void *make_variable_symbol(void *xvalue)
{
	Variable vp = (Variable)malloc(sizeof Variable);
	vp->blob = xvalue;
	vp->typeid = NULL; /* raw unprocessed symbol */
	return (void *)vp;
}
	
void free_variable_symbol(void *vsym)
{
	VariablePtr vp = (VariablePtr)vsym;
	if (vp->blob != NULL)
		free(vp->blob);
	/* FIXME generic methods or free of _XSymbol in vsym */
	free(vp);
}


/* symbol accessors*/

void *get_lambda_symbol_value(void *lsym)
{
	LambdaPtr lp = (LambdaPtr)lsym;
	return lp->blob;
}

int get_variable_symbol_type(void *vsym)
{
	VariablePtr vp = (VariablePtr)lsym;
	return vp->typeid;
}

void *get_variable_symbol_value(void *vsym)
{
	VariablePtr vp = (VariablePtr)lsym;
	return vp->blob;
}

/* processor builds a variable with raw data */
void process_symbol(void *preraw)
{
	/* FIXME */
}

/* This dispatches the variable to the system, after processing.
 * The symbol enters an environment and can be manipulated further on.
 */

void dispatch_symbol(void *new_symbol)
{
	/* FIXME */
}
