FLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14

all: lab8.o Hash.o
	g++ $(FLAGS) lab8.o Hash.o -o lab8
lab8.o: lab8.cpp
	g++ $(FLAGS) -c lab8.cpp -o lab8.o
Hash.o: Hash.cpp Hash.h 
	g++ $(FLAGS) -c Hash.cpp -o Hash.o
checkmem: all
	valgrind ./lab8
clean:
	rm *.o lab8
run: all
	./lab8
