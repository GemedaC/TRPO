all:
    gcc -o test -Wall -Werror test.cpp
test:  
    ./configure && make && make test
