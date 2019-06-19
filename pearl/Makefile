CC = gcc
CFLAGS = -g
PROGS = 06

all: $(PROGS)

06: 06_byte_order.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf a.out *.o output
