# AED, last modified abl 2020.05.29
#
# To compile prog:
#    make
# To run test with input teste01.txt (2/3/4):
#    make t1
# To run all tests just checking the "tree ordered/balanced" output:
#    make tt
#-----------------------------------------------------------------------
#   Compiler Flags

CC= gcc
CFLAGS= -g -Wall -ansi -pedantic

labt: labt.o tree.o queue.o
	gcc $(CFLAGS) -o labt tree.o labt.o queue.o

labt.o: labt.c tree.h queue.h
	gcc $(CFLAGS) -c labt.c

tree.o: tree.c tree.h queue.h
	gcc $(CFLAGS) -c tree.c

queue.o: queue.c tree.h queue.h
	gcc $(CFLAGS) -c queue.c

clean:
	rm -f *.o labt *.~

#---- Tests

TF = `ls test*.txt`

tt:
	for T in ${TF}; do  echo "-- " $${T}; ./labt $${T} | grep tree ; done;

t1:
	./labt teste01.txt

t2:
	./labt teste02.txt

t3:
	./labt teste03.txt

t4:
	./labt teste05.txt

