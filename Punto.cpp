#include <iostream>
#include "Punto.hpp"

using namespace std;

namespace algoritmia
{
	Punto::Punto(const unsigned int &row, const unsigned int &col)
	{
		this->setPunto(row, col);
	}

	Punto::Punto(const Punto &p)
	{
		unsigned int row;
		unsigned int col;

		row = p.getRow();
		col = p.getCol();

		this->setPunto(row, col);
	}

	void Punto::setPunto(const unsigned int &row, const unsigned int &col)
	{
		_row = row;
		_col = col;
	}

	unsigned int Punto::getRow() const
	{
		return _row;
	}

	unsigned int Punto::getCol() const
	{
		return _col;
	}

	void Punto::operator=(const Punto &p)
	{
		unsigned int row = p.getRow();
		unsigned int col = p.getCol();

		this->setPunto(row, col);
	}

	void Punto::operator+(const Punto &p)
	{
		unsigned int row = this->getRow() + p.getRow();
		unsigned int col = this->getCol() + p.getCol();

		this->setPunto(row, col);
	}

	void Punto::operator-(const Punto &p)
	{
		unsigned int row = this->getRow() - p.getRow();
		unsigned int col = this->getCol() - p.getCol();

		this->setPunto(row, col);
	}

	void Punto::operator*(const Punto &p)
	{
		unsigned int row = this->getRow() * p.getRow();
		unsigned int col = this->getCol() * p.getCol();

		this->setPunto(row, col);
	}

	void Punto::operator/(const Punto &p)
	{
		unsigned int row = this->getRow() / p.getRow();
		unsigned int col = this->getCol() / p.getCol();

		this->setPunto(row, col);
	}

	bool Punto::operator==(const Punto &p) const
	{
		return (this->getRow() == p.getRow()) && (this->getCol() && p.getCol());
	}

	bool Punto::operator!=(const Punto &p) const
	{
		return !(*this == p);
	}

	bool Punto::operator<(const Punto &p) const
	{
		unsigned int distanciaA;
		unsigned int distanciaB;

		distanciaA = this->getRow() + this->getCol();
		distanciaB = p.getRow() + p.getCol();

		return distanciaA < distanciaB;
	}

	bool Punto::operator<=(const Punto &p) const
	{
		unsigned int distanciaA;
		unsigned int distanciaB;

		distanciaA = this->getRow() + this->getCol();
		distanciaB = p.getRow() + p.getCol();

		return distanciaA <= distanciaB;
	}

	bool Punto::operator>(const Punto &p) const
	{
		unsigned int distanciaA;
		unsigned int distanciaB;

		distanciaA = this->getRow() + this->getCol();
		distanciaB = p.getRow() + p.getCol();

		return distanciaA > distanciaB;
	}

	bool Punto::operator>=(const Punto &p) const
	{
		unsigned int distanciaA;
		unsigned int distanciaB;

		distanciaA = this->getRow() + this->getCol();
		distanciaB = p.getRow() + p.getCol();

		return distanciaA >= distanciaB;
	}

	ostream& operator<<(ostream &output, const Punto &p)
	{
		output << "(" << p.getRow() << ", " << p.getCol() << ")";
		return output;
	}

	istream& operator>>(istream &input, Punto &p)
	{
		unsigned int row;
		unsigned int col;

		cout << "Introduzca la fila: ";
		input >> row;
		cout << endl;

		cout << "Introduzca la columna: ";
		input >> col;
		cout << endl;

		p.setPunto(row, col);

		return input;
	}
}