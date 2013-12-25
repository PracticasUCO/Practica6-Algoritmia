#ifndef __FUNCIONES_ALTO_NIVEL_P6_ALGORITMIA
#define __FUNCIONES_ALTO_NIVEL_P6_ALGORITMIA

#include <list>
#include <string>
#include "Coordenada2D.hpp"
#include "TableroAjedrez.hpp"
#include "NReinas.hpp"

using namespace std;

namespace algoritmia
{
	/** @brief Muestra un menu con las opciones del programa **/
	unsigned int menu();

	/** @brief Muestra una lista de Coordenada2Ds por pantalla **/
	void showCoordenada2Ds(const list<Coordenada2D> &l, const string &nombre);

	/** @brief Muestra una lista de tableros **/
	void showTableros(const list<TableroAjedrez> &l);

	/** @brief Ejecucion de las vegas **/
	bool vegas(NReinas &nr, TableroAjedrez &t, const unsigned int &repeticiones);
}

#endif