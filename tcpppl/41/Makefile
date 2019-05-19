CC = g++
CFLAGS = -g
PROGS = 01 02 03 04 05

all: $(PROGS)

01: 01_two_threads.cpp
	$(CC) $(CFLAGS) $^ -o $@ -lpthread

02: 02_two_threads_cout.cpp
	$(CC) $(CFLAGS) $^ -o $@ -lpthread

03: 03_share_data_without_mutex.cpp
	$(CC) $(CFLAGS) $^ -o $@ -lpthread

04: 04_share_data_with_mutex.cpp
	$(CC) $(CFLAGS) $^ -o $@ -lpthread

05: 05_waiting.cpp
	$(CC) $(CFLAGS) $^ -o $@ -lpthread

clean:
	rm -rf *.o $(PROGS)
