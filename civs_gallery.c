/*
 * CIVS
 *
 * CGI Indexed Viewer System
 *
 * civs_gallery - generate an index page
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#include "civs_config.h"


int main() {
	char* directoryPath;
	struct dirent* de;
	DIR* dr;
	char* name;
	int breakcounter = -2;

    directoryPath = malloc(strlen(CIVS_FSPATH) + strlen(CIVS_BASEPATH));
	sprintf(directoryPath, "%s%s", CIVS_FSPATH, CIVS_BASEPATH);

	/* The header */
	printf("%s%c%c\n", "Content-Type:text/html;charset=iso-8859-1", 13, 10);

	/* Open the path. */
	dr = opendir(directoryPath);

	/* Is it good? */
	if(dr == NULL) {
		printf("<html><h1>Error: can't open path %s</h1></html>\r\n", directoryPath);
		return 1;
	}

	/* Assuming yes, since it didn't exit */

	/* Print the rest of the page header */
	printf("<!DOCTYPE html>\n<html>\n<head>\n<link rel=\"stylesheet\" href=\"%s\">\n<title>CIVS Gallery</title>\n</head>\n",
			CIVS_CSS);
	printf("<body>\n<header><h1>CIVS Gallery</h1></header>\n<navbar>\n<center><navboxtitle>Navigation</navboxtitle></center>\n<navlink><a href=\"civs_menu.html\">Main menu</a></navlink><br>\n<navlink><a href=\"civs_gallery.cgi\">Gallery</a></navlink><br>\n</navbar>\n<textsection>\n");

	/* Okay, produce the gallery. */
	while((de = readdir(dr)) != NULL) {
		int i;
		/* This will double-check that the files are actually images.
		   strstr is reasonably fast, so no performance hits really happen here. */
		for(i = 0; i < CIVS_SUFFIXLEN; i++) {
			if(strstr(de->d_name, civs_suffixes[i]) != NULL) {
				printf("<a href=\"%s%s\">", CIVS_BASEPATH, de->d_name);
				//printf("<imgbox><img src=\"%s%s\" width=\"%d\">",
				//	CIVS_BASEPATH, de->d_name, CIVS_IMGWIDTH);

				printf("<div class=\"imgbox\"><img src=\"%s%s\" width=\"%d\">",
					CIVS_BASEPATH, de->d_name, CIVS_IMGWIDTH);

				printf("</div></a>\n");
			}
		}
		/* We only want a few images per line, so this is the "rollover counter" */
		breakcounter++;
		if(breakcounter == CIVS_IMGLINEBRK) {
			printf("<br>\n");
			breakcounter = 0;
		}
	}

	/* Finally, print the footer. */
	printf("</textsection>\n<footer>CIVS Test - 6/11/22</footer>\n</body>\n</html>\n");
	return 0;
}
