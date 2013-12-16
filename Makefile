.PHONY: clean-objects clean-all

CXX = g++
CXXFLAGS = -Wall $(INCLUDE) $(LIBRARY) -ggdb3
INCLUDE = -I.
LIBRARY = -L.

practica6: main.o FichaAjedrez.o TableroAjedrez.o
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -o $@ $^

FichaAjedrez.o: FichaAjedrez.hpp FichaAjedrez.cpp
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ FichaAjedrez.cpp

TableroAjedrez.o: TableroAjedrez.cpp TableroAjedrez.hpp FichaAjedrez.o
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ TableroAjedrez.cpp

clean-objects:
	-rm *.o

clean-all: clean-objects
	-rm practica6

## For test only purpose
test: