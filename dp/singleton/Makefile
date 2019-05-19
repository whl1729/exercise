CC = g++
CFLAGS = -g
PROGS = 01 02 03 04 05

all: $(PROGS)

01: 01_singleton.cpp
	$(CC) $(CFLAGS) $^ -o $@

02: 02_two_singleton.cpp
	$(CC) $(CFLAGS) $^ -o $@

03: 03_main.cpp 03_b_singleton.cpp 03_a_singleton.cpp
	$(CC) $(CFLAGS) $^ -o $@

04: 04_main.cpp 04_a_singleton.cpp 04_b_singleton.cpp
	$(CC) $(CFLAGS) $^ -o $@

05: 05_two_singleton.cpp
	$(CC) $(CFLAGS) $^ -o $@

r%:
	rm -rf $*

clean:
	rm -rf *.o a.out $(PROGS)
