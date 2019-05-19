CC = g++
CFLAGS = -g
PROGS = 01 02 03 04 05 06 07 08

all: $(PROGS)

01: 01_thread_operations.o
	$(CC) $(CFLAGS) $^  -o $@ -lpthread

02: 02_join.o
	$(CC) $(CFLAGS) $^  -o $@ -lpthread

03: 03_cout_mutex.o
	$(CC) $(CFLAGS) $^  -o $@ -lpthread

04: 04_deadlock_output.o
	$(CC) $(CFLAGS) $^  -o $@ -lpthread

05: 05_deadlock_factional.o
	$(CC) $(CFLAGS) $^  -o $@ -lpthread

06: 06_two_locks.o
	$(CC) $(CFLAGS) $^  -o $@ -lpthread

07: 07_producer_consumer.o
	$(CC) $(CFLAGS) $^  -o $@ -lpthread

08: 08_producer_consumer_timeout.o
	$(CC) $(CFLAGS) $^  -o $@ -lpthread

clean:
	rm -rf *.o a.out tags $(PROGS)
