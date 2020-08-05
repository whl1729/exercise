include ../Make.defines

PROGS =	daytimetcpcli1

all:	${PROGS}

daytimetcpcli1:	daytimetcpcli1.o
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}

clean:
	rm -rf ${PROGS} ${CLEANFILES}
