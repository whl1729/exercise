CC = g++
CFLAGS = -g
PROGS = 01 02

all: $(PROGS)

01: 01_ctor_decl_no_def.o
	$(CC) $(CFLAGS) $^ -o $@

02: 02_destroy_static_obj.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf a.out *.o $(PROGS)
