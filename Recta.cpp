#include <iostream>
#include <cassert>
#include "Coordenada2D.hpp"
#include "Pendiente.hpp"
#include "Recta.hpp"

using namespace std;

namespace algoritmia
{
	Coordenada2D Recta::moverAlInicio(const Coordenada2D &c, const Pendiente &pendiente) const
	{
		Coordenada2D solution;
		if(pendiente.getType() == INF)
		{
			solution.setCoordenada2D(c.getX(), 0);
		}
		else
		{
			double Ix;
			double y;

			Ix = 0 - c.getX();
			y = c.getY() + (pendiente.getValue() * Ix);

			solution.setCoordenada2D(0, y);
		}
		return solution;
	}

	Recta::Recta()
	{
		Coordenada2D A;
		Coordenada2D B;

		A.setCoordenada2D(0, 0);
		B.setCoordenada2D(1, 0);

		this->establecerRecta(A, B);
	}

	Recta::Recta(const Coordenada2D &A, const Coordenada2D &B)
	{
		this->establecerRecta(A, B);
	}

	Recta::Recta(const Recta &r)
	{
		*this = r;
	}

	void Recta::establecerRecta(const Coordenada2D &A, const Coordenada2D &B)
	{
		Pendiente m; //Pendiente de la recta
		Coordenada2D inicio; //Coordenada2D de inicio de la recta

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
			Coordenada2D inicio = this->getCoordenada2DInicial();
			Pendiente m = this->getPendiente();
			double Y;

			double Ix = X - inicio.getX();
			Y = inicio.getY() + (Ix * m.getValue());

			return Y;
		}
		else
		{
			return this->getCoordenada2DInicial().getY();
		}
	}

	double Recta::getX(const double &Y) const
	{
		assert(!(this->esHorizontal()));

		if(this->esVertical())
		{
			return this->getCoordenada2DInicial().getX();
		}
		else
		{
			Coordenada2D inicio = this->getCoordenada2DInicial();
			Pendiente m = this->getPendiente();
			double Iy = Y - inicio.getY();

			double X = inicio.getX() + (Iy * m.getValue());
			return X;
		}
	}

	Coordenada2D Recta::getCoordenada2DInicial() const
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
		Coordenada2D rInicio;
		Pendiente rPendiente;
		Coordenada2D final;

		double xValue;
		double yValue;

		rInicio = r.getCoordenada2DInicial();
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

		final.setCoordenada2D(xValue, yValue);

		this->establecerRecta(rInicio, final);
	}

	bool Recta::operator==(const Recta &r)
	{
		return ((r.getCoordenada2DInicial() == this->getCoordenada2DInicial()) && (r.getPendiente() == this->getPendiente()));
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

	bool Recta::operator>(const Recta &r)
	{
		return this->getPendiente() > r.getPendiente();
	}

	bool Recta::operator>=(const Recta &r)
	{
		return this->getPendiente() >= r.getPendiente();
	}

	ostream& operator<<(ostream& output, const Recta &r)
	{
		Pendiente m = r.getPendiente();
		Coordenada2D inicio = r.getCoordenada2DInicial();

		if(r.esVertical())
		{
			output << "x = " << inicio.getX();
		}
		else if(r.esHorizontal())
		{
			output << "y = " << inicio.getY();
		}
		else
		{
			double independiente = (-1 * m.getValue() * inicio.getX()) + inicio.getY();

			output << "y = ";

			if(m.getValue() != 1)
			{
				output << m.getValue();
			}

			output << "x ";

			if(independiente > 0)
			{
				output << "+ ";
			}

			if(independiente != 0)
			{
				output << independiente;
			}
		}

		return output;
	}

	istream& operator>>(istream& input, Recta &r)
	{
		Coordenada2D A;
		Coordenada2D B;

		cout << "Primer Coordenada2D por donde pasara la recta." << endl;
		input >> A;
		cout << endl;

		cout << "Segundo Coordenada2D por donde pasara la recta." << endl;
		input >> B;
		cout << endl;

		r.establecerRecta(A, B);

		return input;
	}

	Recta::~Recta()
	{
		//Empty
	}
}