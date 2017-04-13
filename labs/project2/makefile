FLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14

all: program2.o Player.o Heap.o Card.o
	g++ $(FLAGS) program2.o Player.o Heap.o Deck.o Card.o Table.o -o program2
program2.o: program2.cpp Table.o Deck.o Card.o Player.o Heap.o
	g++ $(FLAGS) -c program2.cpp -o program2.o
Heap.o: Heap.cpp Heap.h
	g++ $(FLAGS) -c Heap.cpp -o Heap.o
Player.o: Player.cpp Player.h Card.o
	g++ $(FLAGS) -c Player.cpp -o Player.o
Card.o: Card.cpp Card.h
	g++ $(FLAGS) -c Card.cpp -o Card.o
Deck.o: Deck.cpp Deck.h Card.o
	g++ $(FLAGS) -c Deck.cpp -o Deck.o
Table.o: Table.cpp Table.h Player.o 
	g++ $(FLAGS) -c Table.cpp -o Table.o
checkmem: all
	valgrind ./program2
clean:
	rm *.o program2
run: all
	./program2
