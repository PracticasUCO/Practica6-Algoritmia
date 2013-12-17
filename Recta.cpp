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
		*this = r;
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

		if(!(this->esHorizontal()))
		{
			Punto inicio = this->getPuntoInicial();
			Pendiente m = this->getPendiente();
			double Y;

			double Ix = X - inicio.getX();
			Y = inicio.getY() + (Ix * m.getValue());

			return Y;
		}
		else
		{
			return this->getPuntoInicial().getY();
		}
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

	Punto Recta::getPuntoInicial() const
	{
		return _inicio;
	}

	Pendiente Recta::getPendiente() const
	{
		return _pendiente;
	}

	bool Recta::esVertical() const
	{
		Pendiente m = this->getPendiente();

		return m.getType() == INF;
	}

	bool Recta::esHorizontal() const
	{
		Pendiente m = this->getPendiente();

		return ((m.getType() != INF) && (m.getValue() == 0));
	}

	void Recta::operator=(const Recta &r)
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

	bool Recta::operator==(const Recta &r)
	{
		return ((r.getPuntoInicial() == this->getPuntoInicial()) && (r.getPendiente() == this->getPendiente()));
	}

	bool Recta::operator!=(const Recta &r)
	{
		return !(*this == r);
	}

	bool Recta::operator<(const Recta &r)
	{
		return this->getPendiente() < r.getPendiente();
	}

	bool Recta::operator<=(const Recta &r)
	{
		return this->getPendiente() <= r.getPendiente();
	}
}