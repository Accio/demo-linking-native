// a function exported by pkgA

#include <R.h>
#include <Rinternals.h>

#include "pkg_a.h"

int pkgA_version() {
  return 1;
}

SEXP pkgA_func() {
  SEXP res = PROTECT(allocVector(INTSXP, 1));
  int v = pkgA_version();
  Rprintf("This is a function from pkgA version %d\n", v);
  INTEGER(res)[0]=v;
  UNPROTECT(1);
  return res;
}
