FLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++11

all: lab7.o BSTree.o
	g++ $(FLAGS) lab7.o BSTree.o -o lab7
lab7.o: lab7.cpp
	g++ $(FLAGS) -c lab7.cpp -o lab7.o
BSTree.o: BSTree.cpp BSTree.h
	g++ $(FLAGS) -c BSTree.cpp -o BSTree.o
checkmem: all
	valgrind ./lab7
clean:
	rm *.o lab7
run: all
	./lab7
