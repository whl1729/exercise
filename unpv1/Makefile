include Make.defines

DIRS = lib 01_intro \

all:
	for i in $(DIRS); do \
		(cd $$i && echo "making $$i" && $(MAKE) ) || exit 1; \
	done

clean:
	rm -rf $(CLEANFILES)
	for i in $(DIRS); do \
		(cd $$i && echo "cleaning $$i" && $(MAKE) clean) || exit 1; \
	done

distclean:
	rm -f $(CLEANFILES) config.cache config.log config.status config.h Make.defines Makefile
