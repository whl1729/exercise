CC = g++
CFLAGS = -g
PROGS = hello 1602 1603 1604 1605 1606 1607 1612 1615 1616 1619 1620 \
		1621 1622 1624 1637 1640 1641 1647 1648 1650 1651 1653 1656 1658 \
		1662 1663 1664 1665

all: $(PROGS)

1602_OBJ = 16_02_compare.o
1603_OBJ = 16_03_cmp_sales_data.o Sales_data.o
1604_OBJ = 16_04_find.o
1605_OBJ = 16_05_print_array.o
1606_OBJ = 16_06_begin_end.o
1607_OBJ = 16_07_size_of_array.o
1612_OBJ = 16_12_blob_blobptr.o
1615_OBJ = 16_15_screen.o
1616_OBJ = 16_16_vec.o
1619_OBJ = 16_19_print_container.o
1620_OBJ = 16_20_print_container.o
1621_OBJ = 16_21_debug_delete.o
1622_OBJ = 16_22_text_query.o
1624_OBJ = 16_24_blob.o
1637_OBJ = 16_37_max.o
1640_OBJ = 16_40_get_beg.o
1641_OBJ = 16_41_sum.o
1647_OBJ = 16_47_flip.o
1648_OBJ = 16_48_debug_rep.o
1650_OBJ = 16_50_template_overload.o
1651_OBJ = 16_51_foo.o
1653_OBJ = 16_53_print.o
1656_OBJ = 16_56_error_msg.o
1658_OBJ = 16_58_strvec.o
1662_OBJ = 16_62_hash_sales_data.o Sales_data.o
1663_OBJ = 16_63_count_elem.o
1664_OBJ = 16_64_count_const_char.o
1665_OBJ = 16_65_debug_rep.o

hello: hello.o
	$(CC) $(CFLAGS) -o $@ hello.o

1602: $(1602_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1602_OBJ)

1603: $(1603_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1603_OBJ)

1604: $(1604_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1604_OBJ)

1605: $(1605_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1605_OBJ)

1606: $(1606_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1606_OBJ)

1607: $(1607_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1607_OBJ)

1612: $(1612_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1612_OBJ)

1615: $(1615_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1615_OBJ)

1616: $(1616_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1616_OBJ)

1619: $(1619_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1619_OBJ)

1620: $(1620_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1620_OBJ)

1621: $(1621_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1621_OBJ)

1622: $(1622_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1622_OBJ)

1624: $(1624_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1624_OBJ)

1637: $(1637_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1637_OBJ)

1640: $(1640_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1640_OBJ)

1641: $(1641_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1641_OBJ)

1647: $(1647_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1647_OBJ)

1648: $(1648_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1648_OBJ)

1650: $(1650_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1650_OBJ)

1651: $(1651_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1651_OBJ)

1653: $(1653_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1653_OBJ)

1656: $(1656_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1656_OBJ)

1658: $(1658_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1658_OBJ)

1662: $(1662_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1662_OBJ)

1663: $(1663_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1663_OBJ)

1664: $(1664_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1664_OBJ)

1665: $(1665_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1665_OBJ)

r%:
	rm -rf $($*_OBJ) $*

clean:
	rm -rf *.o $(PROGS) a.out
