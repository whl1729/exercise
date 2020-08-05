ROOT=..
include $(ROOT)/Make.defines

PROGS = ls1

all: $(PROGS)

$(PROGS): $(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAG) $(LDLIBS) 

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc