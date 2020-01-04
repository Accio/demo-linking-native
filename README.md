Linking to native routines in another package: a demo
===
Jitao David Zhang, 2020.01.04

![Linking to native routines in another package][./dot/vis.svg]

## Background

The package `pkgB` links to native routines `pkgA_func` and `pkg_version` in `pkgA`. Please check both packages out to see the details.

## Major notes

The examples were built by following the instructions given in the [*Writing R Extensions* manual](https://cran.r-project.org/doc/manuals/r-release/R-exts.html#Linking-to-native-routines-in-other-packages). 

A few details, however, may need highlighting, because I stumbled upon them on the first attempts. We use `out-going` to refer to pkgA and `in-coming` to refer to pkgB.

1. Use `R_RegisterCCallable` to register the function in the out-going package. They do not have to be registered routines called by .C/.Call/.Fortran/.External. Rather, they can be any C function. 
2. `import` or `importFrom` (or `@import` in roxygen2) must be called in the in-coming package so that the exported function from the out-going package can be found.
3. Add 'LinkingTo: OUT-GOING PACKAGE` in the DESCRIPTION file in the incoming package. This will allow linking native routines.
4. Use `(TYPE(\*)(PARAMETER TYPE)) R_GetCCallable("pkgA", "pkgA_func")` in `R_init_pkgB` to retrieve the function in the in-coming package.
5. *DO NOT* include the header file of outgoing package in the init file of incoming package. Otherwise, an error message complaining left-hand expression assignment will be raised.

## Minor notes

1. Only functions returning `SEXP` can be called by `.Call`, otherwise the memory will not be mapped and the R session will die ugly. This also apply to `void` functions.
2. Check `NAMESPACE` in case a `.Call` function cannot be found. Particularly when `package.skeleton` was used to generate the package structure and then roxygen2 was used, in which case the NAMESPACE file is *not* overwritten by default.
3. Use `SET_STRING_ELT(SEXP object, 0, mkChar(char \*))` to convert C strings to R strings, and `CHAR(STRING_ELT(SEXP object, 0))` to do the reverse, namely to convert R strings to const C strings.
