#include <iostream>
#include "Posicion.hpp"

using namespace std;

namespace algoritmia
{
	Posicion::Posicion(const unsigned int &row, const unsigned int &col)
	{
		this->setPosicion(row, col);
	}
}