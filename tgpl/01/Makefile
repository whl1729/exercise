GOCMD = go
GOBUILD = go build
PROGS = echo1 echo2 echo3 01_echo_prog_name 02_echo_arg_kv \
		dup1 dup2 dup3 print_format 04_dup2_filename lissajous 05_lissajous 06_lissajous \
		fetch 07_fetch 08_fetch 09_fetch fetchall 10_fetchall server1 server2 server3 server4 \
		switch1 switch2

all: $(PROGS)

$(PROGS):
	$(GOBUILD) $@.go

clean:
	-rm -rf $(PROGS)
