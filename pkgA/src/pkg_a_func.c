// a function exported by pkgA

#include <R.h>
#include <Rinternals.h>

#include "pkg_a.h"

void pkgA_func() {
  Rprintf("This is a function from pkgA");
  return;
}
