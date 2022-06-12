CC=cc

OBJS=civs_gallery.o civs_pick.o 
PROGS=civs_gallery.cgi civs_pick.cgi
HTML=civs_menu.html
CSS=civs_style.css

DESTDIR=/srv/http/civs

all: $(PROGS)

.SUFFIXES: .c .o .cgi

.c.o:
	$(CC) -c $< -o $@

.o.cgi:
	$(CC) -o $@ $<

.PHONY: clean install

clean:
	rm -f $(OBJS) $(PROGS)

install:
	mkdir -p $(DESTDIR)
	cp $(PROGS) $(HTML) $(CSS) $(DESTDIR)
