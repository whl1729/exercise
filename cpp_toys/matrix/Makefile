CC = g++
CFLAGS = -std=c++11
PROGS = matrix

all: $(PROGS)

matrix: matrix.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(PROGS) *.o a.out
