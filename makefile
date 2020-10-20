

CC=g++

CFLAGS=-c -Wall

all: hello

hello: main.o test.o
	$(CC) main.o hello.o -o hello

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

hello.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

clean:
	rm -rf *.o hello
