#include <iostream>
#include "Posicion.hpp"

using namespace std;

namespace algoritmia
{
	Posicion::Posicion(const unsigned int &row, const unsigned int &col)
	{
		this->setPosicion(row, col);
	}

	Posicion::Posicion(const Posicion &p)
	{
		unsigned int row;
		unsigned int col;

		row = p.getRow();
		col = p.getCol();

		this->setPosicion(row, col);
	}

	void Posicion::setPosicion(const unsigned int &row, const unsigned int &col)
	{
		_row = row;
		_col = col;
	}

	unsigned int Posicion::getRow() const
	{
		return _row;
	}
}