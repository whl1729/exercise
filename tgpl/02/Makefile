GOBUILD = go build
PROGS = local_ptr echo4

all: $(PROGS)

$(PROGS):
	$(GOBUILD) $@.go

clean:
	rm -rf $(PROGS)
