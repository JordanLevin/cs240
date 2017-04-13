all: main

main: main.o User.o
	g++ main.o User.o -o main
User.o: User.cpp User.h
	g++ -c User.cpp -o User.o
main.o: main.cpp User.h
	g++ -c main.cpp -o main.o

clean:
	rm *.o main
