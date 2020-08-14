// a function exported by pkgOut

#include "pkgOut.h"

int pkgOut_version() {
  return 1;
}

SEXP pkgOut_func(SEXP username) {
  SEXP res = PROTECT(allocVector(INTSXP, 1));
  int v = pkgOut_version();
  Rprintf("Hello, %s! This is a function from pkgOut version %d\n", 
		  CHAR(STRING_ELT(username, 0)), 
		  v);
  INTEGER(res)[0]=v;
  UNPROTECT(1);
  return res;
}
