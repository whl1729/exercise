CC = g++
CFLAGS = -g
PROGS = hello 1801 1803 1805 1806 1807 1809 1810 1820 i1820 1825 \
		1826 1827 1828 1829 1830

all: $(PROGS)

1801_OBJ = 18_01_throw_ptr.o
1803_OBJ = 18_03_exercise.o
1805_OBJ = 18_05_catch_exceptions.o
1806_OBJ = 18_06_throw_exceptions.o
1807_OBJ = 18_07_blob.o
1809_OBJ = 18_09_bookstore.o Sales_data.o
1810_OBJ = 18_10_bookstore.o Sales_data.o
1820_OBJ = 18_20_primerlib_outside.o
i1820_OBJ = 18_20_primerlib_inside.o
1825_OBJ = 18_25_print_delete.o
1826_OBJ = 18_26_mi_print.o
1827_OBJ = 18_27_mi_foo.o
1828_OBJ = 18_28_vmi.o
1829_OBJ = 18_29_final.o
1830_OBJ = 18_30_final.o

%.o: %.cpp
	$(CC) -c $(CFLAGS) $^ -o $@

hello: hello.o
	$(CC) $(CFLAGS) $^ -o $@

1801: $(1801_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1803: $(1803_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1805: $(1805_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1806: $(1806_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1807: $(1807_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1809: $(1809_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1810: $(1810_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1820: $(1820_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

i1820: $(i1820_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1825: $(1825_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1826: $(1826_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1827: $(1827_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1828: $(1828_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1829: $(1829_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1830: $(1830_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

r%:
	rm -rf $($*_OBJ) $*

clean:
	rm -rf *.o a.out tags $(PROGS)
