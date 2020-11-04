
CC=g++

CFLAGS=-std-c++11

all: hello

<<<<<<< HEAD
hello: main.o test.o

main.o:
	$(CC) $(CFLAGS) main.cpp -o hello
=======
hello: main.o test.o test.o
	$(CC) main.o test.o test.o -o hello

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

test.o: test.h
	$(CC) $(CFLAGS) test.h

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp
>>>>>>> be7a7bad3b923119ec8b7d228eb7022ebc79c804

test.o:
	$(CC) $(CFLAGS) test.cpp -o test
