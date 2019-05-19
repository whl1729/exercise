CC = gcc
CP = g++
CFLAGS = -g
PROGS = 01 02 03

all: $(PROGS)

01: 01_atexit.o
	$(CC) $(CFLAGS) $^ -o $@

02: 02_crazy_printf.o
	$(CC) $(CFLAGS) $^ -o $@

03: 03_hello.o
	$(CP) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o a.out $(PROGS)
