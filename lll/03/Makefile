CC = gcc
CFLAGS = -g -Wall
PROGS = 02

all: $(PROGS)

01: 01_foo.o
	$(CC) $(CFLAGS) $^ -o $@

02: 02_data_section.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf a.out *.o $(PROGS)
