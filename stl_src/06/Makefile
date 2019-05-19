CC = g++
CFLAGS = -g
PROGS = 01 02 03 04 05 06 07

all: $(PROGS)

01: 01_numeric.cpp
	$(CC) $(CFLAGS) $^ -o $@

02: 02_algobase.cpp
	$(CC) $(CFLAGS) $^ -o $@

03: 03_copy_overlap.cpp
	$(CC) $(CFLAGS) $^ -o $@

04: 04_copy_backward_overlap.cpp
	$(CC) $(CFLAGS) $^ -o $@

05: 05_set_algorithms.cpp
	$(CC) $(CFLAGS) $^ -o $@

06: 06_data_process.cpp
	$(CC) $(CFLAGS) $^ -o $@

07: 07_other_algorithms.cpp
	$(CC) $(CFLAGS) $^ -o $@

r%:
	rm -rf $*

clean:
	rm -rf *.o a.out tags $(PROGS)
