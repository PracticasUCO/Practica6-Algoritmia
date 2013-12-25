#include <iostream>
#include <cassert>
#include "Pendiente.hpp"

using namespace std;

namespace algoritmia
{
	Pendiente::Pendiente()
	{
		Coordenada2D x0;
		Coordenada2D x1;

		x0.setCoordenada2D(0, 0);
		x1.setCoordenada2D(1, 0);

		this->establecerPendiente(x0, x1);
	}

	Pendiente::Pendiente(const Coordenada2D &A, const Coordenada2D &B)
	{
		this->establecerPendiente(A, B);
	}

	Pendiente::Pendiente(const Pendiente &p)
	{
		*this = p;
	}

	void Pendiente::establecerPendiente(const Coordenada2D &A, const Coordenada2D &B)
	{
		// La pendiente sera Iy / Ix siendo:
		// Iy --> El incremento de Y
		// Ix --> El incremento de X
		double Ix;
		double Iy;

		Ix = B.getX() - A.getX();
		Iy = B.getY() - A.getY();

		// Si Ix == 0 entonces la pendiente es INF
		if(Ix == 0)
		{
			_typeValue = INF;
			_value = 0;
		}
		else
		{
			_typeValue = REAL;
			_value = Iy / Ix;
		}
	}

	const enum PENDIENTE Pendiente::getType() const
	{
		return _typeValue;
	}

	double Pendiente::getValue() const
	{
		assert(this->getType() != INF);
		return _value;
	}

	void Pendiente::operator=(const Pendiente &p)
	{
		Coordenada2D A;
		Coordenada2D B;

		if(p.getType() == INF)
		{
			A.setCoordenada2D(0, 0);
			B.setCoordenada2D(0, 1);
		}
		else
		{
			double m = p.getValue(); //Pendiente de p
			A.setCoordenada2D(0, 0);
			B.setCoordenada2D(1, m);
		}

		this->establecerPendiente(A, B);
	}

	bool Pendiente::operator==(const Pendiente &p) const
	{
		if((this->getType() == INF) && (p.getType() == INF))
		{
			return true;
		}
		else
		{
			return this->getValue() == p.getValue();
		}
	}

	bool Pendiente::operator!=(const Pendiente &p) const
	{
		return !(*this == p);
	}

	bool Pendiente::operator<(const Pendiente &p) const
	{
		if((this->getType() == INF) && (p.getType() != INF))
		{
			return false;
		}
		else if((this->getType() != INF) && (p.getType() == INF))
		{
			return true;
		}
		else if((this->getType() == INF) && (p.getType() == INF))
		{
			return false;
		}
		else
		{
			return this->getValue() < p.getValue();
		}
	}

	bool Pendiente::operator<=(const Pendiente &p) const
	{
		if((this->getType() == INF) && (p.getType() != INF))
		{
			return false;
		}
		else if((this->getType() != INF) && (p.getType() == INF))
		{
			return true;
		}
		else if((this->getType() == INF) && (p.getType() == INF))
		{
			return true;
		}
		else
		{
			return this->getValue() <= p.getValue();
		}
	}

	bool Pendiente::operator>(const Pendiente &p) const
	{
		if((this->getType() == INF) && (p.getType() != INF))
		{
			return true;
		}
		else if((this->getType() != INF) && (p.getType() == INF))
		{
			return false;
		}
		else if((this->getType() == INF) && (p.getType() == INF))
		{
			return false;
		}
		else
		{
			return this->getValue() > p.getValue();
		}	
	}

	bool Pendiente::operator>=(const Pendiente &p) const
	{
		if((this->getType() == INF) && (p.getType() != INF))
		{
			return true;
		}
		else if((this->getType() != INF) && (p.getType() == INF))
		{
			return false;
		}
		else if((this->getType() == INF) && (p.getType() == INF))
		{
			return true;
		}
		else
		{
			return this->getValue() >= p.getValue();
		}
	}

	ostream& operator<<(ostream &output, const Pendiente &p)
	{
		if(p.getType() == INF)
		{
			output << "INF";
		}
		else
		{
			output << p.getValue();
		}
		return output;
	}

	istream& operator>>(istream &input, Pendiente &p)
	{
		Coordenada2D A;
		Coordenada2D B;

		cout << "Estableciendo el Coordenada2D A" << endl;
		input >> A;
		cout << endl;

		cout << "Estableciendo el Coordenada2D B" << endl;
		input >> B;
		cout << endl;

		p.establecerPendiente(A, B);

		return input;
	}

	Pendiente::~Pendiente()
	{
		//Empty
	}
}