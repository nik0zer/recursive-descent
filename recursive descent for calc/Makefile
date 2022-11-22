CFLAGS=-g -fsanitize=address,leak -c
CFLAGS_OCOMPILE=-fsanitize=address,leak
CC = g++

all: calc

calc: calc.o calc.h main.o
	$(CC) $(CFLAGS_OCOMPILE) main.o calc.o -o calc

calc.o: calc.cpp calc.h
	$(CC) $(CFLAGS) calc.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp