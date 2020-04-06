all: install-pkgOut install-pkgIn run-pkgOutFunc run-pkgInFunc dot

install-pkgOut: pkgOut
	cd pkgOut; R -q -e "library(devtools);load_all();document('.');install('.')"

run-pkgOutFunc:
	R -q -e "res <- pkgOut::pkgOutFunc()"

install-pkgIn: pkgIn
	cd pkgIn; R -q -e "library(devtools);load_all();document('.');install('.')"

run-pkgInFunc:
	R -q -e "res <- pkgIn::pkgInFunc()"

pkgOut:
	R -e "foo <- function() {}; package.skeleton(name='pkgOut', list=c('foo'))"

pkgIn:
	R -e "bar <- function() {}; package.skeleton(name='pkgIn', list=c('bar'))"

dot:
	cd dot; $(MAKE)

clean:
	rm -f *.tar.gz
	rm -rf *.Rcheck
	find . -type f -name *.so -name *.o -name *.swp -exec rm '{}' \;
