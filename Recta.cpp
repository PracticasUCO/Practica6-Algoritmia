#include <iostream>
#include "Punto.hpp"
#include "Pendiente.hpp"
#include "Recta.hpp"

using namespace std;

namespace algoritmia
{
	Punto Recta::moverAlInicio(const Punto &punto, const Pendiente &pendiente) const
	{
		Punto solution;
		if(pendiente.getType() == INF)
		{
			solution.setPunto(0, punto.getY());
		}
		else
		{
			double Ix;
			double y;

			Ix = 0 - punto.getX();
			y = punto.getY() + (pendiente.getValue() * Ix);

			solution.setPunto(0, y);
		}
		return solution;
	}

	Recta::Recta()
	{
		Punto A;
		Punto B;

		A.setPunto(0, 0);
		B.setPunto(1, 0);

		this->establecerRecta(A, B);
	}
}