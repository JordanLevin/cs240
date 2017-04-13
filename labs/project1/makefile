FLAGS = -Wall -Wextra -DDEBUG -g -pedantic
PROJECT = project1
SOURCES = project1.cpp AntHill.cpp Ant.cpp

all: project1.o LinkedList.o Ant.o AntHill.o
	g++ $(FLAGS) AntHill.o Ant.o project1.o LinkedList.o -o project1
run: all
	./project1
test: LinkedList.o Ant.o LinkedListTester.o
	g++ $(FLAGS) LinkedListTester.o LinkedList.o Ant.o -o LinkedListTester
project1.o: project1.cpp Ant.h LinkedList.h
	g++ $(FLAGS) -c project1.cpp -o project1.o
LinkedList.o: LinkedList.cpp Ant.h LinkedList.h
	g++ $(FLAGS) -c LinkedList.cpp -o LinkedList.o
Ant.o: Ant.cpp Ant.h
	g++ $(FLAGS) -c Ant.cpp -o Ant.o
AntHill.o: AntHill.cpp AntHill.h
	g++ $(FLAGS) -c AntHill.cpp -o AntHill.o
LinkedListTester.o: LinkedListTester.cpp
	g++ $(FLAGS) -c LinkedListTester.cpp -o LinkedListTester.o
checkmem: all
	valgrind ./project1
clean:
	rm -f *.o project1 LinkedListTester
