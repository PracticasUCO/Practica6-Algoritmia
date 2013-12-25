#include <iostream>
#include "Coordenada2D.hpp"

using namespace std;

namespace algoritmia
{
	Coordenada2D::Coordenada2D(const double &X, const double &Y)
	{
		this->setCoordenada2D(X, Y);
	}

	Coordenada2D::Coordenada2D(const Coordenada2D &p)
	{
		double X;
		double Y;

		X = p.getX();
		Y = p.getY();

		this->setCoordenada2D(X, Y);
	}

	void Coordenada2D::setCoordenada2D(const double &X, const double &Y)
	{
		_X = X;
		_Y = Y;
	}

	double Coordenada2D::getX() const
	{
		return _X;
	}

	double Coordenada2D::getY() const
	{
		return _Y;
	}

	void Coordenada2D::operator=(const Coordenada2D &p)
	{
		double X = p.getX();
		double Y = p.getY();

		this->setCoordenada2D(X, Y);
	}

	Coordenada2D Coordenada2D::operator+(const Coordenada2D &p) const
	{
		double X = this->getX() + p.getX();
		double Y = this->getY() + p.getY();

		return Coordenada2D(X, Y);
	}

	Coordenada2D Coordenada2D::operator-(const Coordenada2D &p) const
	{
		double X = this->getX() - p.getX();
		double Y = this->getY() - p.getY();

		return Coordenada2D(X, Y);
	}

	Coordenada2D Coordenada2D::operator*(const Coordenada2D &p) const
	{
		double X = this->getX() * p.getX();
		double Y = this->getY() * p.getY();

		return Coordenada2D(X, Y);
	}

	Coordenada2D Coordenada2D::operator/(const Coordenada2D &p) const
	{
		double X = this->getX() / p.getX();
		double Y = this->getY() / p.getY();

		return Coordenada2D(X, Y);
	}

	bool Coordenada2D::operator==(const Coordenada2D &p) const
	{
		if((this->getX() == p.getX()) && (this->getY() == p.getY()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Coordenada2D::operator!=(const Coordenada2D &p) const
	{
		return !(*this == p);
	}

	bool Coordenada2D::operator<(const Coordenada2D &p) const
	{
		double distanciaA;
		double distanciaB;

		distanciaA = this->getX() + this->getY();
		distanciaB = p.getX() + p.getY();

		return distanciaA > distanciaB;
	}

	bool Coordenada2D::operator<=(const Coordenada2D &p) const
	{
		double distanciaA;
		double distanciaB;

		distanciaA = this->getX() + this->getY();
		distanciaB = p.getX() + p.getY();

		return distanciaA >= distanciaB;
	}

	bool Coordenada2D::operator>(const Coordenada2D &p) const
	{
		double distanciaA;
		double distanciaB;

		distanciaA = this->getX() + this->getY();
		distanciaB = p.getX() + p.getY();

		return distanciaA < distanciaB;
	}

	bool Coordenada2D::operator>=(const Coordenada2D &p) const
	{
		double distanciaA;
		double distanciaB;

		distanciaA = this->getX() + this->getY();
		distanciaB = p.getX() + p.getY();

		return distanciaA <= distanciaB;
	}

	ostream& operator<<(ostream &output, const Coordenada2D &p)
	{
		output << "(" << p.getX() << ", " << p.getY() << ")";
		return output;
	}

	istream& operator>>(istream &input, Coordenada2D &p)
	{
		double X;
		double Y;

		cout << "Introduzca las Coordenada2Ds del Coordenada2D (x, y): ";
		input >> X >> Y;
		cout << endl;

		p.setCoordenada2D(X, Y);

		return input;
	}

	Coordenada2D::~Coordenada2D()
	{
		//Empty
	}
}