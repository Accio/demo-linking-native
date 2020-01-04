#include <R.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>

#include "pkg_a.h"

/* definitions of functions provided for .Call() */
static const R_CallMethodDef callMethods[] = {
  {"pkgA_func", (DL_FUNC) &pkgA_func, 1},
  {NULL, NULL, 0}
};

/* definition of functions to be exported */
void R_init_pkgA(DllInfo *info) {

  /* used by external packages linking to internal code from C,
   * see section 'Linking to native routines in other packages',
   * Writing R Extensions, */
  R_RegisterCCallable("pkgA", "pkgA_func",
		  (DL_FUNC) &pkgA_func);
  R_RegisterCCallable("pkgA", "pkgA_version",
		  (DL_FUNC) &pkgA_version);

  /* register routines to be called by R code */
  R_registerRoutines(info,
		     NULL, /* slot for .C */
		     callMethods, /* slot for .Call */
		     NULL, /* slot for .Fortran */
		     NULL); /* slot for .External */

    /* the line below says that the DLL is not to be searched
   * for entry points specified by character strings so
   * .C etc calls will only find registered symbols
   */  
  R_useDynamicSymbols(info, FALSE); 

  /* R_forceSymbols call only allows .C etc calls which 
   * specify entry points by R objects such as C_routineName
   * (and not by character strings)
   */ 
  R_forceSymbols(info, TRUE); 
}
