CC = gcc
CFLAGS = -g -Wall
PROGS = 01

all: $(PROGS)

01: 01_insert_sort.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o a.out $(PROGS)
