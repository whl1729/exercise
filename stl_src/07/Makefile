CC = g++
CFLAGS = -g
PROGS = 01 02 03

all: $(PROGS)

01: 01_arithmetic_functor.cpp
	$(CC) $(CFLAGS) $^ -o $@

02: 02_rational_functor.cpp
	$(CC) $(CFLAGS) $^ -o $@

03: 03_logical_functor.cpp
	$(CC) $(CFLAGS) $^ -o $@

r%:
	rm -rf $*

clean:
	rm -rf *.o a.out tags $(PROGS)
