FLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14

all: program3.o Map.o City.o
	g++ $(FLAGS) program3.o City.o Map.o -o program3
program3.o: program3.cpp
	g++ $(FLAGS) -c program3.cpp -o program3.o
Map.o: Map.cpp Map.h 
	g++ $(FLAGS) -c Map.cpp -o Map.o
City.o: City.cpp City.h 
	g++ $(FLAGS) -c City.cpp -o City.o
checkmem: all
	valgrind ./program3
clean:
	rm *.o program3
run: all
	./program3
