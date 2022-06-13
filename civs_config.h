#ifndef CIVS_CONFIG_H
#define CIVS_CONFIG_H 1

/* The maximum length of a filename */
#define CIVS_NAMELEN 16

/* The HTTP document path to this file 
 * This is relative to the HTTP server's document root path.
 * So, if your document root is /srv/http, this path expands to
 * /srv/http/civs/gallery.
 */
#define CIVS_BASEPATH "/civs/gallery/"

/* The filesystem path, same as the HTTP server's document root directory. */
#define CIVS_FSPATH "/srv/http"

/* HTTP root-relative path to the stylesheet */
#define CIVS_CSS "/civs/civs_style.css"

/* Valid file suffixes */
const char* civs_suffixes[] = {
	"png",
	"gif",
	"jpg",
	"webp",
	"jpeg"
};

/* Maximum length of a suffix */
#define CIVS_SUFFIXLEN 5

/* Width of each image */
#define CIVS_IMGWIDTH 300

/* Images per line -- 4 is a 1080p display */
#define CIVS_IMGLINEBRK 4

#endif
