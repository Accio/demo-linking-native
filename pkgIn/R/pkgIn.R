#' pkgIn that links to native routines in pkgOut
#' @docType package
#' @author Jitao David Zhang <jitao_david.zhang@roche.com>
#' @useDynLib pkgIn, .registration=TRUE, .fixes="C_"
#' @name pkgIn-package
#' @import pkgOut
NULL

#' A dummy function that shows linking to native routines in pkgOut works
#' @return Side effect is used
#' @export
pkgInFunc <- function() {
  res <- .Call(C_pkgIn_func)
  return(res)
}
