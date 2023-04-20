all: compile link run

compile:
	g++ -c main.cpp

link:
	g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system

run:
	./main