# CIVS
CGI Image Viewing System -- a CGI (not to be confused with computer-generated 
imagery) photo gallery system written in C.

This is a web app that uses the Common Gateway Interface to dynamically
produce HTML. Compiling it is very simple, but actually deploying it is very
difficult. 

To properly install CIVS, you will need to configure your HTTP server to 
load and run CGI modules.

## Configuration


## Deployment - lighttpd
To configure this to run with lighttpd, make sure your lighttpd.conf file has
these lines in it:

```
server.document-root = "/srv/http"

server.modules = ( "mod_alias", "mod_cgi", "mod_redirect", "mod_setenv" )

$HTTP["url"] =~ "^/civs/" {
        cgi.assign = ( ".cgi" => "" )
}
```

Now, place the HTML, CSS, and compiled CGI binary files into `/srv/http/civs`,
and browse to your server's address. You may want to rename `civs_menu.html` to
`index.html` if you have directory browsing disabled.
