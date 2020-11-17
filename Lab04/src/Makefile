CC = gcc
CFLAGS = -g -Wall

OBJECTS = adjmatrix.o pg1.o

OBJECTS2 = LinkedList.o pg2.o

pg1 : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

adjmatrix.o : adjmatrix.c adjmatrix.h
	$(CC) $(CFLAGS) -c $<

pg1.o : pg1.c
	$(CC) $(CFLAGS) -c $<


pg2 : $(OBJECTS2)
	$(CC) $(CFLAGS) -o $@ $^

pg2.o : pg2.c
	$(CC) $(CFLAGS) -c $<

LinkedList.o : LinkedList.c LinkedList.h listest.c defs.h
	$(CC) $(CFLAGS) -c $<

FILES2 = $(shell ls ../test/*.edge)

VALG = valgrind --leak-check=full -s

FILES1 = $(shell ls ../test/*.adj)

t1 :
	$(foreach F,$(FILES1), ./pg1 $(F);)

t1v:
	$(foreach F,$(FILES1), $(VALG) ./pg1 $(F);)


t2 :
	$(foreach F,$(FILES2), ./pg2 $(F);)

t2v:
	$(foreach F,$(FILES2), $(VALG) ./pg2 $(F);)

clean:
	rm -f -v ../test/*.ladj ../test/*.edge ./*.o pg1 pg2
