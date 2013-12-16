#include <iostream>
#include "Punto.hpp"

using namespace std;

namespace algoritmia
{
	Punto::Punto(const unsigned int &X, const unsigned int &Y)
	{
		this->setPunto(X, Y);
	}

	Punto::Punto(const Punto &p)
	{
		unsigned int X;
		unsigned int Y;

		X = p.getX();
		Y = p.getY();

		this->setPunto(X, Y);
	}

	void Punto::setPunto(const unsigned int &X, const unsigned int &Y)
	{
		_X = X;
		_Y = Y;
	}

	unsigned int Punto::getX() const
	{
		return _X;
	}

	unsigned int Punto::getY() const
	{
		return _Y;
	}

	void Punto::operator=(const Punto &p)
	{
		unsigned int X = p.getX();
		unsigned int Y = p.getY();

		this->setPunto(X, Y);
	}

	void Punto::operator+(const Punto &p)
	{
		unsigned int X = this->getX() + p.getX();
		unsigned int Y = this->getY() + p.getY();

		this->setPunto(X, Y);
	}

	void Punto::operator-(const Punto &p)
	{
		unsigned int X = this->getX() - p.getX();
		unsigned int Y = this->getY() - p.getY();

		this->setPunto(X, Y);
	}

	void Punto::operator*(const Punto &p)
	{
		unsigned int X = this->getX() * p.getX();
		unsigned int Y = this->getY() * p.getY();

		this->setPunto(X, Y);
	}

	void Punto::operator/(const Punto &p)
	{
		unsigned int X = this->getX() / p.getX();
		unsigned int Y = this->getY() / p.getY();

		this->setPunto(X, Y);
	}

	bool Punto::operator==(const Punto &p) const
	{
		return (this->getX() == p.getX()) && (this->getY() && p.getY());
	}

	bool Punto::operator!=(const Punto &p) const
	{
		return !(*this == p);
	}

	bool Punto::operator<(const Punto &p) const
	{
		unsigned int distanciaA;
		unsigned int distanciaB;

		distanciaA = this->getX() + this->getY();
		distanciaB = p.getX() + p.getY();

		return distanciaA < distanciaB;
	}

	bool Punto::operator<=(const Punto &p) const
	{
		unsigned int distanciaA;
		unsigned int distanciaB;

		distanciaA = this->getX() + this->getY();
		distanciaB = p.getX() + p.getY();

		return distanciaA <= distanciaB;
	}

	bool Punto::operator>(const Punto &p) const
	{
		unsigned int distanciaA;
		unsigned int distanciaB;

		distanciaA = this->getX() + this->getY();
		distanciaB = p.getX() + p.getY();

		return distanciaA > distanciaB;
	}

	bool Punto::operator>=(const Punto &p) const
	{
		unsigned int distanciaA;
		unsigned int distanciaB;

		distanciaA = this->getX() + this->getY();
		distanciaB = p.getX() + p.getY();

		return distanciaA >= distanciaB;
	}

	ostream& operator<<(ostream &output, const Punto &p)
	{
		output << "(" << p.getX() << ", " << p.getY() << ")";
		return output;
	}

	istream& operator>>(istream &input, Punto &p)
	{
		unsigned int X;
		unsigned int Y;

		cout << "Introduzca la fila: ";
		input >> X;
		cout << endl;

		cout << "Introduzca la Yumna: ";
		input >> Y;
		cout << endl;

		p.setPunto(X, Y);

		return input;
	}
}