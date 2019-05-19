CC = g++
CFLAGS = -g
PROGS = whl 1536 1539 

WHL_OBJ = my_text_query.cpp MyTextQuery.cpp MyQueryResult.cpp \
		  MyQueryCommand.cpp MyLine.cpp

1536_OBJ = 15_36_print_ctor_rep.cpp TextQuery.cpp QueryResult.cpp Query.cpp \
			AndQuery.cpp OrQuery.cpp NotQuery.cpp

1539_OBJ = 15_39_text_query.cpp TextQuery.cpp QueryResult.cpp Query.cpp \
			AndQuery.cpp OrQuery.cpp NotQuery.cpp

all: $(PROGS)

whl: $(WHL_OBJ)
	$(CC) $(CFLAGS) -o $@ $(WHL_OBJ)

1536: $(1536_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1536_OBJ)

1539: $(1539_OBJ)
	$(CC) $(CFLAGS) -o $@ $(1539_OBJ)

clean:
	rm -rf *.o  $(PROGS)
