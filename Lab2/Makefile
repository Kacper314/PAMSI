__start__: a.out
	./a.out

a.out: main.o sortowania.o
	g++ main.o sortowania.o

main.o: main.cpp sortowania.hh
	g++ -c -Wall -pedantic main.cpp

stos.o: sortowania.cpp sortowania.hh
	g++ -c -Wall -pedantic sortowania.cpp	