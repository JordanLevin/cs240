all:	Hello

Hello:	main.o myfile.o
    g++ -g main.o myfile.o -o Hello

myfile.o:	myfile.cpp
    g++ -g -c myfile.cpp -o myfile.o

main.o:	main.cpp
    g++ -g -c main.cpp -o main.o

clean:
	rm *.o  Hello
