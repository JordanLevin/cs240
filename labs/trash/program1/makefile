FLAGS = -Wall -Wextra -DDEBUG -g -pedantic
PROJECT = lab3
SOURCES = lab3.cpp AntHill.cpp Ant.cpp

all: project1.o LinkedList.o Ant.o AntHill.o
	g++ $(FLAGS) AntHill.o Ant.o project1.o LinkedList.o -o program1
run: all
	./program1
project1.o: project1.cpp Ant.h LinkedList.h
	g++ $(FLAGS) -c project1.cpp -o project1.o
LinkedList.o: LinkedList.cpp Ant.h LinkedList.h
	g++ $(FLAGS) -c LinkedList.cpp -o LinkedList.o
Ant.o: Ant.cpp Ant.h
	g++ $(FLAGS) -c Ant.cpp -o Ant.o
AntHill.o: AntHill.cpp AntHill.h
	g++ $(FLAGS) -c AntHill.cpp -o AntHill.o
checkmem: all
	valgrind ./program1
clean:
	rm *.o program1
