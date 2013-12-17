#include <iostream>
#include <cassert>
#include "Pendiente.hpp"

using namespace std;

namespace algoritmia
{
	Pendiente::Pendiente()
	{
		Punto x0;
		Punto x1;

		x0.setPunto(0, 0);
		x1.setPunto(1, 0);

		this->establecerPendiente(x0, x1);
	}

	Pendiente::Pendiente(const Punto &A, const Punto &B)
	{
		this->establecerPendiente(A, B);
	}

	Pendiente::Pendiente(const Pendiente &p)
	{
		*this = p;
	}

	void Pendiente::establecerPendiente(const Punto &A, const Punto &B)
	{
		// La pendiente sera Iy / Ix siendo:
		// Iy --> El incremento de Y
		// Ix --> El incremento de X
		double Ix;
		double Iy;

		Ix = B.getX() - A.getX();
		Iy = B.getY() - A.getY();

		// Si Ix == 0 entonces la pendiente es infinita
		if(Ix == 0)
		{
			_typeValue = INFINITA;
			_value = 0;
		}
		else
		{
			_typeValue = NUMERICA;
			_value = Iy / Ix;
		}
	}

	const enum PENDIENTE Pendiente::getType() const
	{
		return _typeValue;
	}

	double Pendiente::getValue() const
	{
		assert(this->getType() != INFINITA);
		return _value;
	}

	void Pendiente::operator=(const Pendiente &p)
	{
		Punto A;
		Punto B;

		if(p.getType() == INFINITA)
		{
			A.setPunto(0, 0);
			B.setPunto(0, 1);
		}
		else
		{
			double m = p.getValue(); //Pendiente de p
			A.setPunto(0, 0);
			B.setPunto(1, m);
		}

		this->establecerPendiente(A, B);
	}

	bool Pendiente::operator==(const Pendiente &p) const
	{
		if((this->getType() == INFINITA) && (p.getType() == INFINITA))
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
		if((this->getType() == INFINITA) && (p.getType() != INFINITA))
		{
			return false;
		}
		else if((this->getType() != INFINITA) && (p.getType() == INFINITA))
		{
			return true;
		}
		else if((this->getType() == INFINITA) && (p.getType() == INFINITA))
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
		if((this->getType() == INFINITA) && (p.getType() != INFINITA))
		{
			return false;
		}
		else if((this->getType() != INFINITA) && (p.getType() == INFINITA))
		{
			return true;
		}
		else if((this->getType() == INFINITA) && (p.getType() == INFINITA))
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
		if((this->getType() == INFINITA) && (p.getType() != INFINITA))
		{
			return true;
		}
		else if((this->getType() != INFINITA) && (p.getType() == INFINITA))
		{
			return false;
		}
		else if((this->getType() == INFINITA) && (p.getType() == INFINITA))
		{
			return false;
		}
		else
		{
			return this->getValue() > p.getValue();
		}	
	}
}