ROOT=..
include $(ROOT)/Make.defines

PROGS = stat lstat fstatat file_type access umask chmod truncate \
		link unlink unlinkat open_and_unlink remove rename symlink futimens \
		mkdir rmdir ftw chdir_getcwd

all: $(PROGS)

$(PROGS): $(LIBAPUE) $(PROGS).c
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAG) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o *.out foo bar

include $(ROOT)/Make.libapue.inc
