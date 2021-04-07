__start__: a.out
	./a.out

a.out: main.o lstos.o
	g++ main.o lstos.o

main.o: main.cpp lstos.hh
	g++ -c -Wall -pedantic main.cpp

lstos.o: lstos.cpp lstos.hh
	g++ -c -Wall -pedantic lstos.cpp	