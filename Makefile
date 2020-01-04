install-pkgA: pkgA
	cd pkgA; R -q -e "library(devtools);load_all();document('.');install('.')"

run-pkgAfunc:
	R -q -e "res <- pkgA::pkgAfunc()"

pkgA:
	R -e "foo <- function() {}; package.skeleton(name='pkgA', list=c('foo'))"

pkgB:
	R -e "bar <- function() {}; package.skeleton(name='pkgB', list=c('bar'))"
