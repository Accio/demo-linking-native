#include <R.h>
#include <Rinternals.h>

SEXP(*pkgOut_func)(SEXP);
int(*pkgOut_version)();

SEXP pkgIn_func();
