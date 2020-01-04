
install-pkgA: pkgA
	cd pkgA; R -q -e "library(devtools);load_all();document('.');install('.')"

run-pkgAfunc:
	R -q -e "res <- pkgA::pkgAfunc()"

install-pkgB: pkgB
	cd pkgB; R -q -e "library(devtools);load_all();document('.');install('.')"

run-pkgBfunc:
	R -q -e "res <- pkgB::pkgBfunc()"

pkgA:
	R -e "foo <- function() {}; package.skeleton(name='pkgA', list=c('foo'))"

pkgB:
	R -e "bar <- function() {}; package.skeleton(name='pkgB', list=c('bar'))"

clean:
	rm -f *.tar.gz
	rm -rf *.Rcheck
	find . -type f -name *.so -name *.o -name *.swp -exec rm '{}' \;
