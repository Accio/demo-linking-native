#include "pkgB.h"

SEXP pkgB_func() {
   Rprintf("Internally, pkgB calls function from pkgA.");
   Rprintf("Installed pkgA version: %d", pkgA_version());
   pkgA_func("pkgB");
   return R_NilValue;
}

