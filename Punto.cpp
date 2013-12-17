#include <iostream>
#include "Punto.hpp"

using namespace std;

namespace algoritmia
{
	Punto::Punto(const double &X, const double &Y)
	{
		this->setPunto(X, Y);
	}

	Punto::Punto(const Punto &p)
	{
		double X;
		double Y;

		X = p.getX();
		Y = p.getY();

		this->setPunto(X, Y);
	}

	void Punto::setPunto(const double &X, const double &Y)
	{
		_X = X;
		_Y = Y;
	}

	double Punto::getX() const
	{
		return _X;
	}

	double Punto::getY() const
	{
		return _Y;
	}

	void Punto::operator=(const Punto &p)
	{
		double X = p.getX();
		double Y = p.getY();

		this->setPunto(X, Y);
	}

	void Punto::operator+(const Punto &p)
	{
		double X = this->getX() + p.getX();
		double Y = this->getY() + p.getY();

		this->setPunto(X, Y);
	}

	void Punto::operator-(const Punto &p)
	{
		double X = this->getX() - p.getX();
		double Y = this->getY() - p.getY();

		this->setPunto(X, Y);
	}

	void Punto::operator*(const Punto &p)
	{
		double X = this->getX() * p.getX();
		double Y = this->getY() * p.getY();

		this->setPunto(X, Y);
	}

	void Punto::operator/(const Punto &p)
	{
		double X = this->getX() / p.getX();
		double Y = this->getY() / p.getY();

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
		double distanciaA;
		double distanciaB;

		distanciaA = this->getX() + this->getY();
		distanciaB = p.getX() + p.getY();

		return distanciaA < distanciaB;
	}

	bool Punto::operator<=(const Punto &p) const
	{
		double distanciaA;
		double distanciaB;

		distanciaA = this->getX() + this->getY();
		distanciaB = p.getX() + p.getY();

		return distanciaA <= distanciaB;
	}

	bool Punto::operator>(const Punto &p) const
	{
		double distanciaA;
		double distanciaB;

		distanciaA = this->getX() + this->getY();
		distanciaB = p.getX() + p.getY();

		return distanciaA > distanciaB;
	}

	bool Punto::operator>=(const Punto &p) const
	{
		double distanciaA;
		double distanciaB;

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
		double X;
		double Y;

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