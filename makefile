
CC=g++

CFLAGS=-std-c++11

all: hello

hello: main.o test.o

main.o:
	$(CC) $(CFLAGS) main.cpp -o hello

test.o:
	$(CC) $(CFLAGS) test.cpp -o test
