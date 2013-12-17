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
}