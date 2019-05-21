#Alejandro Diera, pa02 Makefile , 21 May 2019

CXX_FLAG = --std=c++11 -g

all: movies tests

movies: movies.o utility.o
	g++ $(CXX_FLAG) -o movies movies.o utility.o

tests: tests.o 
	g++ $(CXX_FLAG) -o tests tests.o

utility.o: utility.cpp utility.h
	g++ -c $(CXX_FLAG) -o utility.cpp

tests.o: tests.cpp tests.h
	g++ -c $(CXX_FLAG) -o tests.cpp

movies.o: movies.cpp movies.h
	g++ -c $(CXX_FLAG) -o movies.cpp

clean:
	rm tests.o movies.o *.o
