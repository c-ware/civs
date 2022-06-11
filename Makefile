CC=cc

OBJS=civs_gallery.o civs_pick.o 
PROGS=civs_gallery.cgi civs_pick.cgi

all: $(PROGS)

.SUFFIXES: .c .o .cgi

.c.o:
	$(CC) -c $< -o $@

.o.cgi:
	$(CC) -o $@ $<

.PHONY: clean

clean:
	rm -f $(OBJS) $(PROGS)
