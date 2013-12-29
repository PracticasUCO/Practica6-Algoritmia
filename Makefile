.PHONY: clean-objects clean-all

CXX = g++
CXXFLAGS = -Wall $(INCLUDE) $(LIBRARY) -std=c++11 -ggdb3
INCLUDE = -I.
LIBRARY = -L.
OBJECTS = FichaAjedrez.o TableroAjedrez.o Coordenada2D.o NReinas.o Recta2D.o Pendiente.o funcionesAltoNivel.o Combinatorio.o

practica6: main.o $(OBJECTS)
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -o $@ $^

FichaAjedrez.o: FichaAjedrez.hpp FichaAjedrez.cpp
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ FichaAjedrez.cpp

TableroAjedrez.o: TableroAjedrez.cpp TableroAjedrez.hpp FichaAjedrez.o Recta2D.o
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ TableroAjedrez.cpp

Coordenada2D.o: Coordenada2D.cpp Coordenada2D.hpp
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ Coordenada2D.cpp

Recta2D.o: Recta2D.hpp Recta2D.cpp Pendiente.o
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ Recta2D.cpp

Pendiente.o: Pendiente.cpp Pendiente.hpp Coordenada2D.o
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ Pendiente.cpp

NReinas.o: TableroAjedrez.o NReinas.cpp NReinas.hpp
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ NReinas.cpp

Combinatorio.o: Combinatorio.hpp Combinatorio.cpp
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -c -o $@ Combinatorio.cpp

funcionesAltoNivel.o: funcionesAltoNivel.hpp funcionesAltoNivel.cpp Coordenada2D.o TableroAjedrez.o NReinas.o

clean-objects:
	-rm *.o

clean-all: clean-objects
	-rm practica6

## For test only purpose
test: test.o $(OBJECTS)
	$(CXX) $(INCLUDE) $(LIBRARY) $(CXXFLAGS) -o $@ $^