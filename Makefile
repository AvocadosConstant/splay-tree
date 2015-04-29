all:main

main: splay.o main.o
	g++ -g -std=c++11 splay.o main.o -o main

main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

splay.o: splay.h splay.cpp
	g++ -g -c -std=c++11 splay.cpp

clean:
	rm *.o *~ *# main
