__start__: a.out
	./a.out

a.out: main.o stos.o
	g++ main.o stos.o

main.o: main.cpp stos.hh
	g++ -c -Wall -pedantic main.cpp

stos.o: stos.cpp stos.hh
	g++ -c -Wall -pedantic stos.cpp	