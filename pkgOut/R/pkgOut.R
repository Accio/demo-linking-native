#' pkgOut for demonstration purpose of linking native routines
#' @docType package
#' @description A out-going package that exports a native routine
#' @author Jitao David Zhang <jitao_david.zhang@roche.com>
#' @useDynLib pkgOut, .registration=TRUE, .fixes="C_"
#' @name pkgOut
NULL

#' A dummy function exported for demonstration purposes
#' @param username Username in characters
#' @return A number generated in C
#' @export
pkgOutFunc <- function(username) {
  if(missing(username)) {
    username <- Sys.info()["user"]
  }
  res <- .Call(C_pkgOut_func, username)
  return(res)
}
