/*
 * CIVS
 *
 * CGI Indexed Viewer System
 *
 * civs_view - generate a "view an image at full size" page
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "civs_config.h"


int main() {
	/* Base variable declarations */
	char* filename;
	char* requested;
	char postheader[5];

	/* This has some padding for extra safety. */
	int sumLength = strlen(CIVS_BASEPATH) + CIVS_NAMELEN + 2;

	/* Send the header */
	printf("%s%c%c\n", "Content-Type:text/html;charset=iso-8859-1", 13, 10);

	/* Make room for the strings. */
	filename = malloc(sumLength);
	requested = malloc(CIVS_NAMELEN);

	/* Get the POST data. */
	fread(postheader, 1, 5, stdin);
	fread(requested, 1, CIVS_NAMELEN, stdin);
	
	/* Cut off the newline from the POST. */
	strtok(requested, "\n");

	/* Is it long enough? */
	if(strlen(requested) > CIVS_NAMELEN) {
		printf("<html><h1>ID (%s) was too long!</h1></body></html>\n", 
				requested);
	}
	else {	
		/* Build the filename. */
		strcpy(filename, CIVS_BASEPATH);
		strcat(filename, requested);

		/* Generate the resultant HTML. */
		printf("<html>\n<link rel=\"stylesheet\" href=\"%s\">\n",
				CIVS_CSS);
		printf("<body>\n<div class=\"imgbox\">\n");
		printf("<h1>Image %s</h1>\n", requested);
		printf("<img class=\"center-fit\" src=\"%s\"></div>\n", 
				filename);
		printf("</body>\n</html>\n");
	}
	return 0;
}
