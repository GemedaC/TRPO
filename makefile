
CC=g++

CFLAGS=-c -Wall

all: hello

hello: main.o test.o test.o
	$(CC) main.o test.o test.o -o hello

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

test.o: test.h
	$(CC) $(CFLAGS) test.h

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

clean:
	rm -rf *.o hello
