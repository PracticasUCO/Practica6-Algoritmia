.PHONY: clean-objects clean-all

CXX = g++
CXXFLAGS = -Wall $(INCLUDE) $(LIBRARY) -ggdb3
INCLUDE = -I.
LIBRARY = -L.

practica6: main.o FichaAjedrez.o TableroAjedrez.o Posicion.o ListaPosiciones.o
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -o $@ $^

FichaAjedrez.o: FichaAjedrez.hpp FichaAjedrez.cpp
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ FichaAjedrez.cpp

TableroAjedrez.o: TableroAjedrez.cpp TableroAjedrez.hpp FichaAjedrez.o
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ TableroAjedrez.cpp

Posicion.o: Posicion.cpp Posicion.hpp
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ Posicion.cpp

ListaPosiciones.o: ListaPosiciones.cpp ListaPosiciones.hpp
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) ListaPosiciones.cpp

clean-objects:
	-rm *.o

clean-all: clean-objects
	-rm practica6

## For test only purpose
test: