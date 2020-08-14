#include <R.h>
#include <Rinternals.h>

// functions imported from pkgOut
// They are cast from DL_FUNC to the correct return types (SEXP, int)
extern SEXP(*pkgOut_func)(SEXP);
extern int(*pkgOut_version)();

SEXP pkgIn_func();
