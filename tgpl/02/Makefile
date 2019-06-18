GOBUILD = go build
PROGS = local_ptr echo4 temp cf 01_test_tempconv

all: $(PROGS)

$(PROGS):
	$(GOBUILD) $@.go

clean:
	rm -rf $(PROGS)
