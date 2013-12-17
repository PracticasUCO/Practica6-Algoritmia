#include <iostream>
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
}