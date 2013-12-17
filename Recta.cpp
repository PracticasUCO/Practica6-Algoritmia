#include <iostream>
#include <cassert>
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

	Recta::Recta(const Punto &A, const Punto &B)
	{
		this->establecerRecta(A, B);
	}

	Recta::Recta(const Recta &r)
	{
		Punto rInicio;
		Pendiente rPendiente;
		Punto final;

		double xValue;
		double yValue;

		rInicio = r.getPuntoInicial();
		rPendiente = r.getPendiente();

		if(rPendiente.getType() != INF)
		{
			xValue = rInicio.getX() + 1;
			yValue = rInicio.getY() + rPendiente.getValue();
		}
		else
		{
			xValue = rInicio.getX();
			yValue = rInicio.getY() + 1;
		}

		final.setPunto(xValue, yValue);

		this->establecerRecta(rInicio, final);
	}

	void Recta::establecerRecta(const Punto &A, const Punto &B)
	{
		Pendiente m; //Pendiente de la recta
		Punto inicio; //Punto de inicio de la recta

		m.establecerPendiente(A, B);
		inicio = this->moverAlInicio(A, m);

		_inicio = inicio;
		_pendiente = m;
	}

	double Recta::getY(const double &X) const
	{
		assert(!(this->esVertical()));
		Punto inicio = this->getPuntoInicial();
		Pendiente m = this->getPendiente();
		double Y;

		double Ix = X - inicio.getX();
		Y = inicio.getY() + (Ix * m.getValue());

		return Y;
	}

	double Recta::getX(const double &Y) const
	{
		assert(!(this->esHorizontal()));

		if(this->esVertical())
		{
			return this->getPuntoInicial().getX();
		}
		else
		{
			Punto inicio = this->getPuntoInicial();
			Pendiente m = this->getPendiente();
			double Iy = Y - inicio.getY();

			double X = inicio.getX() + (Iy * m.getValue());
			return X;
		}
	}
}