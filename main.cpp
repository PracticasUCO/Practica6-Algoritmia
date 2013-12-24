#include <iostream>
#include <list>
#include "NReinas.hpp"
#include "TableroAjedrez.hpp"
#include "Punto.hpp"
#include "funcionesAltoNivel.hpp"

using namespace std;
using namespace algoritmia;

int main()
{
	NReinas nr;
	unsigned int opcion;

	do
	{
		opcion = menu();

		switch(opcion)
		{
			case 1:
				{
					unsigned int nuevaDimension;
					cout << "Introduzca la nueva dimension: ";
					cin >> nuevaDimension;
					cout << endl;

					nr.setDimension(nuevaDimension);
				}
				break;

			case 2:
				{
					TableroAjedrez table = nr.singleSolution();

					table.detail();
					cout << endl;
				}
				break;

			case 3:
				{
					list<TableroAjedrez> lista = nr.allSolutions();
					showTableros(lista);
				}
				break;

			case 4:
				{
					unsigned int repeticiones;
					TableroAjedrez table;
					table.setDimension(nr.getDimension());

					cout << "Introduzca cuantas veces maximo lo intentara: " << endl;
					cout << "(0 para usar el limite maximo): ";
					cin >> repeticiones;
					cout << endl;

					if(vegas(nr, table, repeticiones))
					{
						cout << "Solucion hallada: " << endl;
						table.detail();
						cout << endl;

						cout << "Numero de intentos realizados: " << nr.getIntentosVegas() << endl;
					}
					else
					{
						cerr << "No se consiguio ningun resultado con " << repeticiones << " intentos." << endl;
					}
					cout << endl;
				}
				break;
		}
	} while (opcion != 0);

	return 0;
}