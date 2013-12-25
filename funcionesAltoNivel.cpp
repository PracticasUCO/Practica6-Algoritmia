#include <iostream>
#include <string>
#include <list>
#include <limits>
#include "Coordenada2D.hpp"
#include "NReinas.hpp"
#include "TableroAjedrez.hpp"

using namespace std;

namespace algoritmia
{
	unsigned int menu()
	{
		unsigned int opcion;

		do
		{
			cout << "1- Establecer dimension del tablero" << endl;
			cout << "2- Encontrar la primera solucion (Backtraking)" << endl;
			cout << "3- Encontrar todas las soluciones (Backtraking)" << endl;
			cout << "4- Buscar una solucion por el algoritmo de las vegas" << endl;
			cout << "0- Salir" << endl << endl;

			cout << "Introduzca una opcion: ";
			cin >> opcion;
			cout << endl;
		}while(opcion > 4);

		return opcion;
	}

	void showCoordenada2Ds(const list<Coordenada2D> &l, const string &nombre)
	{
		for(auto point : l)
		{
			cout << nombre << " in " << point << endl;
		}
	}

	void showTableros(const list<TableroAjedrez> &l)
	{
		int k = 0;

		for(auto table : l)
		{
			cout << "Tablero numero: " << k + 1 << " (" << table.getDimension() << ")" << endl;
			table.detail();
			cout << endl;
			k++;
		}
	}

	bool vegas(NReinas &nr, TableroAjedrez &t, const unsigned int &repeticiones)
	{
		if(repeticiones != 0)
		{
			return nr.vegas(t, repeticiones);
		}
		else
		{
			return nr.vegas(t, numeric_limits<unsigned int>::max());
		}
	}
}