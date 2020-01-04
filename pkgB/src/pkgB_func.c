#include "pkgB.h"

SEXP pkgB_func() {
   Rprintf("Internally, pkgB calls function from pkgA.\n");
   Rprintf("Installed pkgA version: %d\n", pkgA_version());

   SEXP myUsername=PROTECT(allocVector(STRSXP, 1));
   SET_STRING_ELT(myUsername, 0, mkChar("pkgB"));
   pkgA_func(myUsername);
   UNPROTECT(1);

   return R_NilValue;
}

