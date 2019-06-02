#Alejandro Diera, pa02 Makefile , 21 May 2019

CXX_FLAG = --std=c++11 -g

all: runMovies  

runMovies: movies.o utility.o main.o
	g++ $(CXX_FLAG) -o runMovies movies.o utility.o main.o

tests: tests.o movies.o 
	g++ $(CXX_FLAG) -o tests tests.o movies.o

utility.o: utility.cpp utility.h
	g++ -c $(CXX_FLAG) utility.cpp

tests.o: tests.cpp tests.h
	g++ -c $(CXX_FLAG) tests.cpp

movies.o: movies.cpp movies.h
	g++ -c $(CXX_FLAG) movies.cpp

main.o: main.cpp movies.h 
	g++ -c $(CXX_FLAG) main.cpp

clean:
	rm *.o
