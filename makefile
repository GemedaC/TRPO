all:
    gcc -o main -Wall -Werror test.cpp
test:
    ./main User
    ./main
clean:
    rm test.exe main
