CC=g++
CFLAGS=-g -std=c++11
PROGS=binio

all: ${PROGS}

binio: binio.cpp
	${CC} ${CFLAGS} -o $@ $^

clean:
	rm -rf ${PROGS} *.o *.out
