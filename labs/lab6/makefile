FLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++11

all: lab6.o
	g++ $(FLAGS) lab6.o -o lab6
lab6.o: lab6.cpp Sorter.h
	g++ $(FLAGS) -c lab6.cpp -o lab6.o
checkmem: all
	valgrind ./lab6
clean:
	rm *.o lab6
