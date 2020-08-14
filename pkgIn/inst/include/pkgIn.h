#include <R.h>
#include <Rinternals.h>

#ifndef _pkgIn
#define _pkgIn

// functions imported from pkgOut
// They are cast from DL_FUNC to the correct return types (SEXP, int)
extern SEXP(*pkgOut_func)(SEXP);
extern int(*pkgOut_version)();

extern SEXP pkgIn_func();

#endif

