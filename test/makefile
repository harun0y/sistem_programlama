CLASSDIR = ../test
INCLUDE = -I$(CLASSDIR)/include
LIBS = $(CLASSDIR)/lib/libfdr.a
CC = gcc

EX  =  bin/main 

all: $(EX) 

clean: 
	rm -f bin/*

bin/main: src/main.c $(LIBS)
	$(CC) $(INCLUDE) -o bin/main src/main.c $(LIBS)

