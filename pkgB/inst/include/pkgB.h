#include <R.h>
#include <Rinternals.h>

SEXP(*pkgA_func)(SEXP);
int(*pkgA_version)();

SEXP pkgB_func();
