CC = g++
CFLAGS = -g
PROGS = 01 02 03 04 05 06 08 09 10 11 12 13 14

all: $(PROGS)

01: 01_test_config.cpp
	$(CC) $(CFLAGS) $^ -o $@

02: 02_static_data_member.cpp
	$(CC) $(CFLAGS) $^ -o $@

03: 03_class_tmpl_partial.cpp
	$(CC) $(CFLAGS) $^ -o $@

04: 04_func_tmpl_partial.cpp
	$(CC) $(CFLAGS) $^ -o $@

05: 05_member_tmpl.cpp
	$(CC) $(CFLAGS) $^ -o $@

06: 06_limited_def_tmpl.cpp
	$(CC) $(CFLAGS) $^ -o $@

08: 08_friend_tmpl.cpp
	$(CC) $(CFLAGS) $^ -o $@

09: 09_partial_tmpl.cpp
	$(CC) $(CFLAGS) $^ -o $@

10: 10_temp_obj.cpp
	$(CC) $(CFLAGS) $^ -o $@

11: 11_namespace.cpp
	$(CC) $(CFLAGS) $^ -o $@

12: 12_in_class_static_const.cpp
	$(CC) $(CFLAGS) $^ -o $@

13: 13_inc_dec_deref.cpp
	$(CC) $(CFLAGS) $^ -o $@

14: 14_func_call.cpp
	$(CC) $(CFLAGS) $^ -o $@

r%:
	rm -rf $*

clean:
	rm -rf *.o a.out $(PROGS)
