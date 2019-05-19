CC = g++
CFLAGS = -g
PROGS = 01 02 03 04 05 06

all: $(PROGS)

01: 01_iterator_adapter.cpp
	$(CC) $(CFLAGS) $^ -o $@

02: 02_compose.cpp
	$(CC) $(CFLAGS) $^ -o $@

03: 03_functor_adapter.cpp
	$(CC) $(CFLAGS) $^ -o $@

04: 04_reverse_iterator.cpp
	$(CC) $(CFLAGS) $^ -o $@

05: 05_istream_iterator.cpp
	$(CC) $(CFLAGS) $^ -o $@

06: 06_mem_fun.cpp
	$(CC) $(CFLAGS) $^ -o $@

r%:
	rm -rf $*

clean:
	rm -rf *.o a.out tags $(PROGS)
