FLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++11
#PROJECT = project1
#SOURCES = project1.cpp AntHill.cpp Ant.cpp

all: lab5.o Card.o Deck.o Card.h Deck.h LinkedList.h Queue.h
	g++ $(FLAGS) lab5.o Card.o Deck.o -o lab5
run: all
	./lab5
Card.o: Card.cpp Card.h
	g++ $(FLAGS) -c Card.cpp -o Card.o
Deck.o: Deck.cpp Deck.h Card.h
	g++ $(FLAGS) -c Deck.cpp -o Deck.o
lab5.o: lab5.cpp
	g++ $(FLAGS) -c lab5.cpp -o lab5.o
checkmem: all
	valgrind ./lab5
clean:
	rm -f *.o lab5
