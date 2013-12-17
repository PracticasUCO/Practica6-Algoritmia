.PHONY: clean-objects clean-all

CXX = g++
CXXFLAGS = -Wall $(INCLUDE) $(LIBRARY) -ggdb3
INCLUDE = -I.
LIBRARY = -L.

practica6: main.o FichaAjedrez.o TableroAjedrez.o Punto.o
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -o $@ $^

FichaAjedrez.o: FichaAjedrez.hpp FichaAjedrez.cpp
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ FichaAjedrez.cpp

TableroAjedrez.o: TableroAjedrez.cpp TableroAjedrez.hpp FichaAjedrez.o Recta.o
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ TableroAjedrez.cpp

Punto.o: Punto.cpp Punto.hpp
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ Punto.cpp

Recta.o: Recta.hpp Recta.cpp Pendiente.o
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ Recta.cpp

Pendiente.o: Pendiente.cpp Pendiente.hpp Punto.o
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ Pendiente.cpp

clean-objects:
	-rm *.o

clean-all: clean-objects
	-rm practica6

## For test only purpose
test: test.cpp Punto.o Pendiente.o Recta.o TableroAjedrez.o FichaAjedrez.o
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -o $@ $^