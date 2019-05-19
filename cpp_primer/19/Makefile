CC = g++
CFLAGS = -g
PROGS = hello 1901 1902 1903 1904 1906 1907 1908 1909 1910 \
		 1912 1918 1919 1920 1921 1922 1923

all: $(PROGS)

1901_OBJ = 19_01_my_new_delete.o
1902_OBJ = 19_02_strvec.o
1903_OBJ = 19_03_dyn_cast.o
1904_OBJ = 19_04_dyn_cast.o
1906_OBJ = 19_06_andquery.o AndQuery.o NotQuery.o Query.o QueryResult.o 
1907_OBJ = 19_07_andquery.o AndQuery.o NotQuery.o Query.o QueryResult.o 
1908_OBJ = 19_08_query_base.o AndQuery.o NotQuery.o Query.o QueryResult.o 
1909_OBJ = 19_09_type_info.o
1910_OBJ = 19_10_abc.o
1912_OBJ = 19_12_screen_cursor.o
1918_OBJ = 19_18_count_empty_str.o
1919_OBJ = 19_19_find_avg_price.o Sales_data.o
1920_OBJ = 19_20_text_query.o
1921_OBJ = 19_21_token.o Token.o Sales_data.o
1922_OBJ = 19_22_token.o Token.o Sales_data.o
1923_OBJ = 19_23_token.o Token.o Sales_data.o

%.o: %.cpp
	$(CC) -c $(CFLAGS) $^ -o $@

hello: hello.o
	$(CC) $(CFLAGS) $^ -o $@

1901: $(1901_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1902: $(1902_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1903: $(1903_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1904: $(1904_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1906: $(1906_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1907: $(1907_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1908: $(1908_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1909: $(1909_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1910: $(1910_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1912: $(1912_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1918: $(1918_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1919: $(1919_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1920: $(1920_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1921: $(1921_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1922: $(1922_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

1923: $(1923_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

r%:
	rm $($*_OBJ) $*

clean:
	rm -rf *.o a.out $(PROGS)
