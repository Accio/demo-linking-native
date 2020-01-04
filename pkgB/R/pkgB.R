#' pkgB that links to native routines in pkgA
#' @docType package
#' @author Jitao David Zhang <jitao_david.zhang@roche.com>
#' @useDynLib pkgB, .registration=TRUE, .fixes="C_"
#' @name pkgB-package
NULL

#' A dummy function that shows linking to native routines in pkgA works
#' @return Side effect is used
#' @export
pkgBfunc <- function() {
  res <- .Call(C_pkgB_func)
  return(res)
}
