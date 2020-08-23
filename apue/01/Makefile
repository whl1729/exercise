ROOT=..
include $(ROOT)/Make.defines

PROGS = ls1 stdin2stdout stdout2stdin cp_stdio stat getc_putc \
		print_pid shell1 strerror_perror strerror_perror2

all: $(PROGS)

$(PROGS): $(LIBAPUE) $(PROGS).c
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAG) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
