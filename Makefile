.PHONY: clean-objects clean-all

CXX = g++
CXXFLAGS = -Wall $(INCLUDE) $(LIBRARY) -std=c++11 -ggdb3
INCLUDE = -I.
LIBRARY = -L.
OBJECTS = FichaAjedrez.o TableroAjedrez.o Punto.o NReinas.o Recta.o Pendiente.o funcionesAltoNivel.o

practica6: main.o $(OBJECTS)
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

NReinas.o: TableroAjedrez.o NReinas.cpp NReinas.hpp
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ NReinas.cpp

funcionesAltoNivel.o: funcionesAltoNivel.hpp funcionesAltoNivel.cpp Punto.o

clean-objects:
	-rm *.o

clean-all: clean-objects
	-rm practica6

## For test only purpose
test: test.cpp $(OBJECTS)
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -o $@ $^