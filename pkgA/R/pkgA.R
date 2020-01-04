#' pkgA for demonstration purpose of linking native routines
#' @docType package
#' @author Jitao David Zhang <jitao_david.zhang@roche.com>
#' @useDynLib pkgA, .registration=TRUE, .fixes="C_"
#' @name pkgA
NULL

#' A dummy function exported for demonstration purposes
#' @return A number generated in C
#' @export
pkgAfunc <- function() {
  res <- .Call(C_pkgA_func)
  return(res)
}
