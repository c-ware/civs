# CIVS

**NOTE: This program is NOT for production use yet! Do not trust it to be secure yet, either!**
CGI Image Viewing System -- a CGI (not to be confused with computer-generated 
imagery) photo gallery system written in C.

This is a web app that uses the Common Gateway Interface to dynamically
produce HTML. Compiling it is very simple, but actually deploying it is very
difficult. 

To properly install CIVS, you will need to configure your HTTP server to 
load and run CGI modules.

## Configuration


## Deployment 
First, run `make` to compile everything. Decide on a HTTP server root path.
This documentation uses `/srv/http`, with the actual CIVS files at `/srv/http/civs`.
You can use `make install` to install the files to the default directory.


### lighttpd

To configure this to run with lighttpd, make sure your lighttpd.conf file has
these lines in it:

```
server.document-root = "/srv/http"

server.modules = ( "mod_alias", "mod_cgi", "mod_redirect", "mod_setenv" )

$HTTP["url"] =~ "^/civs/" {
        cgi.assign = ( ".cgi" => "" )
}
```

### apache2

Append this to your httpd.conf:

```
<IfModule mpm_prefork_module>
    LoadModule cgi_module modules/mod_cgi.so
</IfModule>
<IfModule !mpm_prefork_module>
    #LoadModule cgid_module modules/mod_cgid.so
</IfModule>

DocumentRoot "/srv/http/root"
<Directory "/srv/http">
    Options Indexes FollowSymLinks
    AllowOverride None
    Require all granted
</Directory>

<Directory "/srv/http/civs">
    AllowOverride None
    Options None
    Require all granted
    Options +ExecCGI
    AddHandler cgi-script .cgi .pl .py .perl .exe
</Directory>
```

Now, place the HTML, CSS, and compiled CGI binary files into `/srv/http/civs`,
and browse to your server's address. You can rename `civs_menu.html` to
`index.html` if you have directory browsing disabled.
If you renamed `civs_menu.html`, you will need to update the links
on ALL of the pages, some of which are CGI-generated. It is recommended that you do NOT
rename it. You can automate the install using `make install`.

## Loading images
Place some images into `/srv/http/civs/gallery`. You will most likely want to run
the `rename_images.sh` script in that directory, such that the images have sequential
filenames. Once you have done that, head to the indexer page (`civs_gallery.cgi`) and
refresh. You should now see a variety of images. 

## Getting to CIVS
After you've started your HTTP server (search online to figure this one out), go to
`http://localhost:80/civs/civs_menu.html` to access CIVS. Click
on the Gallery button and see what you get.
