FLAGS = -Wall -Wextra -DDEBUG -g -pedantic
PROJECT = lab3
SOURCES = lab3.cpp AntHill.cpp Ant.cpp

all: lab3.o AntHill.o Ant.o
	g++ $(FLAGS) lab3.o AntHill.o Ant.o -o lab3	
run: all
	./$(PROJECT)
$(PROJECT).o: $(PROJECT).cpp
	g++ $(FLAGS) -c lab3.cpp -o lab3.o
AntHill.o: AntHill.cpp AntHill.h Ant.h
	g++ $(FLAGS) -c AntHill.cpp -o AntHill.o
Ant.o: Ant.cpp AntHill.h Ant.h
	g++ $(FLAGS) -c Ant.cpp -o Ant.o
checkmem: all
	valgrind ./$(PROJECT)
clean:
	rm *.o $(PROJECT)
