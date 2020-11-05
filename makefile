all: hello

hello: main.o

main.o:
	gсс main.cpp -o main
	
run:
	main

.PHONY: clean

clean:
	rm -rf *.o
