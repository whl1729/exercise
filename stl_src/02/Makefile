CC = g++
CFLAGS = -g
PROGS = 01

all: $(PROGS)

01: 01_jjalloc.cpp
	$(CC) $(CFLAGS) $^ -o $@

r%:
	rm -rf $*

clean:
	rm -rf *.o a.out tags $(PROGS)
