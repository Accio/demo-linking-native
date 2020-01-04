#include <R.h>
#include <Rconfig.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>

#include "pkgB.h"

static const R_CallMethodDef callMethods[] = {
  {"pkgB_func", (DL_FUNC) &pkgB_func, 1},
  {NULL, NULL, 0}
};

void R_init_pkgB(DllInfo *info) {

  /* register routines to be called by R code */
  R_registerRoutines(info,
                     NULL, /* slot for .C */
                     callMethods, /* slot for .Call */
                     NULL, /* slot for .Fortran */
                     NULL); /* slot for .External */

    /* the line below says that the DLL is not to be searched
   * for entry points specified by character strings so
   * .C calls will only find registered symbols
   */  
  R_useDynamicSymbols(info, FALSE); 

  /* R_forceSymbols call only allows .C etc calls which 
   * specify entry points by R objects such as C_routineName
   * (and not by character strings)
   */ 
  R_forceSymbols(info, TRUE); 

  /* C functions implemented in pkgA */
  pkgA_func = (SEXP(*)(SEXP)) R_GetCCallable("pkgA", "pkgA_func");
  pkgA_version = (int(*)()) R_GetCCallable("pkgA", "pkgA_version");
}

