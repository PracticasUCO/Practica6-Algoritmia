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

	unsigned int Posicion::getCol() const
	{
		return _col;
	}

	void Posicion::operator=(const Posicion &p)
	{
		unsigned int row = p.getRow();
		unsigned int col = p.getCol();

		this->setPosicion(row, col);
	}

	void Posicion::operator+(const Posicion &p)
	{
		unsigned int row = this->getRow() + p.getRow();
		unsigned int col = this->getCol() + p.getCol();

		this->setPosicion(row, col);
	}

	void Posicion::operator-(const Posicion &p)
	{
		unsigned int row = this->getRow() - p.getRow();
		unsigned int col = this->getCol() - p.getCol();

		this->setPosicion(row, col);
	}

	void Posicion::operator*(const Posicion &p)
	{
		unsigned int row = this->getRow() * p.getRow();
		unsigned int col = this->getCol() * p.getCol();

		this->setPosicion(row, col);
	}

	void Posicion::operator/(const Posicion &p)
	{
		unsigned int row = this->getRow() / p.getRow();
		unsigned int col = this->getCol() / p.getCol();

		this->setPosicion(row, col);
	}

	bool Posicion::operator==(const Posicion &p) const
	{
		return (this->getRow() == p.getRow()) && (this->getCol() && p.getCol());
	}

	bool Posicion::operator!=(const Posicion &p) const
	{
		return !(*this == p);
	}

	bool Posicion::operator<(const Posicion &p) const
	{
		unsigned int distanciaA;
		unsigned int distanciaB;

		distanciaA = this->getRow() + this->getCol();
		distanciaB = p.getRow() + p.getCol();

		return distanciaA < distanciaB;
	}

	bool Posicion::operator<=(const Posicion &p) const
	{
		unsigned int distanciaA;
		unsigned int distanciaB;

		distanciaA = this->getRow() + this->getCol();
		distanciaB = p.getRow() + p.getCol();

		return distanciaA <= distanciaB;
	}

	bool Posicion::operator>(const Posicion &p) const
	{
		unsigned int distanciaA;
		unsigned int distanciaB;

		distanciaA = this->getRow() + this->getCol();
		distanciaB = p.getRow() + p.getCol();

		return distanciaA > distanciaB;
	}

	bool Posicion::operator>=(const Posicion &p) const
	{
		unsigned int distanciaA;
		unsigned int distanciaB;

		distanciaA = this->getRow() + this->getCol();
		distanciaB = p.getRow() + p.getCol();

		return distanciaA >= distanciaB;
	}

	ostream& operator<<(ostream &output, const Posicion &p)
	{
		output << "(" << p.getRow() << ", " << p.getCol() << ")";
		return output;
	}

	istream& operator>>(istream &input, Posicion &p)
	{
		unsigned int row;
		unsigned int col;

		cout << "Introduzca la fila: ";
		input >> row;
		cout << endl;

		cout << "Introduzca la columna: ";
		input >> col;
		cout << endl;

		p.setPosicion(row, col);

		return input;
	}
}