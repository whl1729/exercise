CC = g++
CFLAGS = -g
PROGS = 01 02 03 04 05 06 07 08 09 10 11 12

all: $(PROGS)

01_OBJ = 01_member_default_ctor.o
02_OBJ = 02_member_default_ctor.o
03_OBJ = 03_multi_member_default_ctor.o
04_OBJ = 04_multi_member_default_ctor.o
05_OBJ = 05_base_default_ctor.o
06_OBJ = 06_base_default_ctor.o
07_OBJ = 07_base_default_ctor.o
08_OBJ = 08_base_default_ctor.o
09_OBJ = 09_multi_member_default_ctor.o
10_OBJ = 10_no_default_ctor.o
11_OBJ = 11_member_init_list.o
12_OBJ = 12_member_init_list.o

%.o: %.cpp
	$(CC) -c $(CFLAGS) $^ -o $@

01: $(01_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

02: $(02_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

03: $(03_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

04: $(04_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

05: $(05_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

06: $(06_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

07: $(07_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

08: $(08_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

09: $(09_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

10: $(10_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

11: $(11_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

12: $(12_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

r%:
	rm -rf $* $($*_OBJ)

clean:
	rm -rf *.o a.out $(PROGS)
