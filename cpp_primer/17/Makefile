CC = g++
CFLAGS = -g
PROGS = hello 1701 1702 1703 1704 1705 1706 1708 1709 1710 \
		1711 1713 1714 1715 1716 1717 1718 1720 1721 1722  \
		1723 1724 1725 1726 1727 1728 1729 1730 1732 1734  \
		1735 1736 1737 1738 1739

all: $(PROGS)

1701_OBJ = 17_01_int_tuple.o
1702_OBJ = 17_02_str_tuple.o
1703_OBJ = 17_03_text_query.o
1704_OBJ = 17_04_find_book.o Sales_data.o
1705_OBJ = 17_05_find_book.o Sales_data.o
1706_OBJ = 17_06_find_book.o Sales_data.o
1708_OBJ = 17_08_find_book.o Sales_data.o
1709_OBJ = 17_09_bitset.o
1710_OBJ = 17_10_init_bitset.o
1711_OBJ = 17_11_quiz.o
1713_OBJ = 17_13_grade.o
1714_OBJ = 17_14_regex_error.o
1715_OBJ = 17_15_iec.o
1716_OBJ = 17_16_iec.o
1717_OBJ = 17_17_all_iec.o
1718_OBJ = 17_18_all_iec.o
1720_OBJ = 17_20_validate_phone.o
1721_OBJ = 17_21_validate_phone.o
1722_OBJ = 17_22_validate_phone.o
1723_OBJ = 17_23_zip_code.o
1724_OBJ = 17_24_trans_phone.o
1725_OBJ = 17_25_trans_phone.o
1726_OBJ = 17_26_trans_phone.o
1727_OBJ = 17_27_zip_code.o
1728_OBJ = 17_28_uniform_rand.o
1729_OBJ = 17_29_uniform_rand.o
1730_OBJ = 17_30_uniform_rand.o
1732_OBJ = 17_32_game.o
1734_OBJ = 17_34_iomanip.o
1735_OBJ = 17_35_sqrt_two.o
1736_OBJ = 17_36_sqrt_two.o
1737_OBJ = 17_37_getline.o
1738_OBJ = 17_38_print_word.o
1739_OBJ = 17_39_seek.o

%.o: %.cpp
	$(CC) -c $(CFLAGS) $^ -o $@

hello: hello.o
	$(CC) $(CFLAGS) $^ -o $@

1701: $(1701_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1702: $(1702_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1703: $(1703_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1704: $(1704_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1705: $(1705_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1706: $(1706_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1708: $(1708_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1709: $(1709_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1710: $(1710_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1711: $(1711_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1713: $(1713_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1714: $(1714_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1715: $(1715_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1716: $(1716_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1717: $(1717_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1718: $(1718_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1720: $(1720_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1721: $(1721_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1722: $(1722_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1723: $(1723_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1724: $(1724_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1725: $(1725_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1726: $(1726_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1727: $(1727_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1728: $(1728_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1729: $(1729_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1730: $(1730_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1732: $(1732_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1734: $(1734_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1735: $(1735_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1736: $(1736_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1737: $(1737_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1738: $(1738_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1739: $(1739_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

r%:
	rm -rf $($*_OBJ) $*

clean:
	rm -rf *.o $(PROGS) a.out
