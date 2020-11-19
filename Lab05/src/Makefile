#
# Makefile for heap example - process scheduler
#

CC=gcc
TARGET=simproc
CFLAGS= -g -ansi -Wall -I.
LIBS= -lm

SRCFILES= simproc.c heap.c
INCFILES= heap.h Item.h
OBJFILES= simproc.o heap.o

default: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LIBS)

clean:
	rm -f $(TARGET) $(OBJFILES) core.* #*

heap.o: heap.c heap.h Item.h

simproc.o: simproc.c heap.h Item.h
