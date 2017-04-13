FLAGS = -Wall -Wextra -DDEBUG -g -pedantic
PROJECT = lab3


all: test.o LinkedList.o Ant.o
	g++ $(FLAGS) Ant.o test.o LinkedList.o -o test
run: all
	./test
test.o: test.cpp LinkedList.cpp Ant.cpp Ant.h LinkedList.h
	g++ $(FLAGS) -c test.cpp -o test.o
LinkedList.o: LinkedList.cpp Ant.h Ant.cpp LinkedList.h
	g++ $(FLAGS) -c LinkedList.cpp -o LinkedList.o
Ant.o: Ant.cpp Ant.h
	g++ $(FLAGS) -c Ant.cpp -o Ant.o
checkmem: all
	valgrind ./test
clean:
	rm *.o test
