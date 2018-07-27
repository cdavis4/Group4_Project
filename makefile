#Group4Projectmakefile
#Variables

CXX =	g++
CFLAGS = -Wall -pedantic -std=gnu++11 

Main:	main.o	Critter.o Ant.o DoodleBug.o Menu.o Board.o
	$(CXX)	$(CFLAGS) -o main main.o Critter.o Ant.o DoodleBug.o Menu.o Board.o

main.o:	main.cpp
	$(CXX)	$(CFLAGS) -c main.cpp

Critter.o:	Critter.cpp Critter.hpp
	$(CXX)	$(CFLAGS) -c Critter.cpp
	
Ant.o:	Ant.cpp Ant.hpp
	$(CXX)	$(CFLAGS) -c Ant.cpp

DoodleBug.o:	DoodleBug.cpp DoodleBug.hpp
	$(CXX)	$(CFLAGS) -c DoodleBug.cpp	

Menu.o:	Menu.cpp Menu.hpp
	$(CXX)	$(CFLAGS) -c Menu.cpp

clean:
	rm -f main main.o Critter.o Ant.o DoodleBug.o Menu.o Board.o
