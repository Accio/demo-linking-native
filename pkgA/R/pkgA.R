#' pkgA for demonstration purpose of linking native routines
#' @docType package
#' @author Jitao David Zhang <jitao_david.zhang@roche.com>
#' @useDynLib pkgA, .registration=TRUE, .fixes="C_"
#' @name pkgA
NULL

#' A dummy function exported for demonstration purposes
#' @export
pkgAfunc <- function() {
  .Call(C_pkgA_func)
}
