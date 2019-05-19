CC = g++
CFLAGS = -g
PROGS = 01 02

01_OBJ = 01_multi_inherit.o
02_OBJ = 02_ptr_to_member_func.o

all: $(PROGS)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $^ -o $@

01: $(01_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

02: $(02_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

r%:
	rm -rf $* $($*_OBJ)

clean:
	rm -rf *.o a.out $(PROGS)
