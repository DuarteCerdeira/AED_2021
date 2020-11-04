# AED, last modified abl 2020.10.21
#
# To compile progs:
#    make   OR  make sorwords  OR qsortwords  OR bsortwords
# To run tests:
#    make t     OR: make qt     OR (Valgrind):  make tv  ETC
#
# NOTE:
# In case of trouble with the shell for loop, GNU Make has 'foreach':
#	$(foreach file,$(FILES),./labconn $(file);)
# https://stackoverflow.com/questions/1490949/how-to-write-loop-in-a-makefile
#----------------------------------------------------------------------
#   Compiler, Compiler Flags

CC = gcc
CFLAGS = -g -Wall -ansi -pedantic

#   Sources
SOURCES = word.c sortwords.c

#   Objects  ('make' automatically compiles .c to .o)
OBJECTS = word.o sortwords.o
QOBJECTS = word.o qsortwords.o
BOBJECTS = word.o bsortwords.o

sortwords: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

word.o: word.c word.h defs.h

sortwords.o: sortwords.c word.h defs.h

qsortwords: $(QOBJECTS)
	$(CC) $(CFLAGS) -o $@ $(QOBJECTS)

word.o: word.c word.h defs.h

qsortwords.o: qsortwords.c word.h defs.h

bsortwords: $(BOBJECTS)
		$(CC) $(CFLAGS) -o $@ $(BOBJECTS)

word.o: word.c word.h defs.h

bsortwords.o: qsortwords.c word.h defs.h

clean:
	rm -f *.o  sortwords qsortwords bsortwords


FILES = $(shell ls ../test/*.txt)

VALG = valgrind --leak-check=full

t:
	for F in ${FILES}; do  ./sortwords $${F} ; done;


tv:
	for F in ${FILES}; do ${VALG} ./sortwords $${F} ; done;


tt:
	for F in ${FILES}; do  time ./sortwords $${F} ; done;



qt:
	for F in ${FILES}; do  ./qsortwords $${F} ; done;


qtv:
	for F in ${FILES}; do ${VALG} ./qsortwords $${F} ; done;


qtt:
	for F in ${FILES}; do  time ./qsortwords $${F} ; done;



bt:
	for F in ${FILES}; do  ./bsortwords $${F} ; done;


btv:
	for F in ${FILES}; do ${VALG} ./bsortwords $${F} ; done;


btt:
	for F in ${FILES}; do  time ./bsortwords $${F} ; done;
