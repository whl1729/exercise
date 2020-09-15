ROOT=..
include $(ROOT)/Make.defines

PROGS = stat

all: $(PROGS)

$(PROGS): $(LIBAPUE) $(PROGS).c
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAG) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o *.out

include $(ROOT)/Make.libapue.inc
