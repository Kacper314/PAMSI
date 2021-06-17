__start__: a.out
	./a.out

a.out: main.o Gra2.o
	g++ main.o Gra2.o

main.o: main.cpp gra.hh
	g++ -c -Wall -pedantic main.cpp

stos.o: Gra2.cpp gra.hh
	g++ -c -Wall -pedantic stos.cpp	