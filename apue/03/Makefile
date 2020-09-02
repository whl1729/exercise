ROOT=..
include $(ROOT)/Make.defines

PROGS = open lseek file_hole file_nohole io_efficiency write_exceed_limit

all: $(PROGS)

$(PROGS): $(LIBAPUE) $(PROGS).c
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAG) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o *.out file.hole file.nohole

include $(ROOT)/Make.libapue.inc
