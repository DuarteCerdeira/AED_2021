CC = gcc
CFLAGS = -g -Wall

OBJECTS = adjmatrix.o pg1.o

pg1 : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

adjmatrix.o : adjmatrix.c adjmatrix.h
	$(CC) $(CFLAGS) -c $<

pg1.o : pg1.c
	$(CC) $(CFLAGS) -c $<

FILES1 = $(shell ls ../test/*.adj)
FILES = ../test/*.adj

VALG = valgrind --leak-check=full -s

t1 :
	$(foreach F,$(FILES1), ./pg1 $(F);)

t1v:
	$(foreach F,$(FILES1), $(VALG) ./pg1 $(F);)

clean:
	rm -f -v ../test/*.edge ./*.o pg1
