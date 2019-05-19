CC = g++
CFLAGS = -g
PROGS = 01 02 03 04 05 06 07 08

all: $(PROGS)

01: 01_test_vector.cpp
	$(CC) $(CFLAGS) $^ -o $@

02: 02_test_list.cpp
	$(CC) $(CFLAGS) $^ -o $@

03: 03_test_deque.cpp
	$(CC) $(CFLAGS) $^ -o $@

04: 04_test_stack.cpp
	$(CC) $(CFLAGS) $^ -o $@

05: 05_test_queue.cpp
	$(CC) $(CFLAGS) $^ -o $@

06: 06_test_heap.cpp
	$(CC) $(CFLAGS) $^ -o $@

07: 07_test_priority_queue.cpp
	$(CC) $(CFLAGS) $^ -o $@

08: 08_test_forward_list.cpp
	$(CC) $(CFLAGS) $^ -o $@

r%:
	rm -rf $*

clean:
	rm -rf *.o a.out tags $(PROGS)
