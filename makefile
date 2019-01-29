output: main.o myint.o
	g++ main.o myint.o -o output

main.o: main.cpp
	g++ -c main.cpp

myint.o: myint.cpp myint.h
	g++ -c myint.cpp
