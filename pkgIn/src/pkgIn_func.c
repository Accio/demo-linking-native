#include "pkgIn.h"

SEXP pkgIn_func() {
   Rprintf("Internally, pkgIn calls function from pkgOut.\n");
   Rprintf("Installed pkgOut version: %d\n", pkgOut_version());

   SEXP myUsername=PROTECT(allocVector(STRSXP, 1));
   SET_STRING_ELT(myUsername, 0, mkChar("pkgIn"));
   pkgOut_func(myUsername);
   UNPROTECT(1);

   return R_NilValue;
}

