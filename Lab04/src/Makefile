CC = gcc
CFLAGS = -g -Wall

OBJECTS2= LinkedList.o pg2.o

pg2 : $(OBJECTS2)
	$(CC) $(CFLAGS) -o $@ $^

pg2.o : pg2.c
	$(CC) $(CFLAGS) -c $<

LinkedList.o : LinkedList.c LinkedList.h listest.c
	$(CC) $(CFLAGS) -c $<

FILES2 = $(shell ls ../test/*.edge)
FILES = ../test/*.edge

VALG = valgrind --leak-check=full -s

t2 :
	$(foreach F,$(FILES2), ./pg2 $(F);)

t2v:
	$(foreach F,$(FILES2), $(VALG) ./pg2 $(F);)

clean:
	rm -f -v ../test/*.ladj ./*.o pg2
