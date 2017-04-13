FLAGS = -Wall -Wextra -DDEBUG -g -pedantic
PROJECT = lab2
SOURCES = lab2.cpp AntHill.cpp

all: lab2.o AntHill.o
	g++ $(FLAGS) lab2.o AntHill.o -o lab2	
run: all
	./$(PROJECT)
$(PROJECT).o: lab2.cpp
	g++ $(FLAGS) -c lab2.cpp -o lab2.o
AntHill.o: AntHill.cpp AntHill.h
	g++ $(FLAGS) -c AntHill.cpp -o AntHill.o
checkmem: all
	valgrind ./$(PROJECT)
clean:
	rm *.o $(PROJECT)
