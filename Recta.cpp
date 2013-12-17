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
			int Ix;
			unsigned int y;

			Ix = 0 - punto.getX();
			y = punto.getY() + (pendiente.getValue() * Ix);

			solution.setPunto(0, y);
		}
		return solution;
	}
}