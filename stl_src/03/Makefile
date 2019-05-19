CC = g++
CFLAGS = -g
PROGS = 01 02 03

all: $(PROGS)

01: 01_test_mylist.cpp
	$(CC) $(CFLAGS) $^ -o $@

02: 02_return_tmpl_type.cpp
	$(CC) $(CFLAGS) $^ -o $@

03: 03_tag_types.cpp
	$(CC) $(CFLAGS) $^ -o $@

r%:
	rm -rf $*

clean:
	rm -rf *.o a.out tags $(PROGS)
