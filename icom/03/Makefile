CC = g++
CFLAGS = -g
PROGS = 01 02 03 05 07

all: $(PROGS)

01_OBJ = 01_sizeof_class.o
02_OBJ = 02_point3d.o
03_OBJ = 03_multi_access_sections.o
04_OBJ = 04_access_order.o
05_OBJ = 05_access_static_member.o
06_OBJ = 06_access_nonstatic_member.o
07_OBJ = 07_ptr_to_data_member.o

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

r%:
	rm -rf $* $($*_OBJ)

clean:
	rm -rf *.o a.out $(PROGS)
