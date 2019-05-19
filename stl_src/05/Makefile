CC = g++
CFLAGS = -g
PROGS = 01 02 03 04 05 06 07

all: $(PROGS)

01: 01_test_rbtree.cpp
	$(CC) $(CFLAGS) $^ -o $@

02: 02_test_set.cpp
	$(CC) $(CFLAGS) $^ -o $@

03: 03_test_map.cpp
	$(CC) $(CFLAGS) $^ -o $@

04: 04_test_unordered_set.cpp
	$(CC) $(CFLAGS) $^ -o $@

05: 05_test_unordered_multiset.cpp
	$(CC) $(CFLAGS) $^ -o $@

06: 06_test_str_set.cpp
	$(CC) $(CFLAGS) $^ -o $@

07: 07_test_unordered_map.cpp
	$(CC) $(CFLAGS) $^ -o $@

r%:
	rm -rf $*

clean:
	rm -rf *.o a.out tags $(PROGS)
