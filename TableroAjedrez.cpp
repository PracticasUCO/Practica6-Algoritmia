#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include "TableroAjedrez.hpp"
#include "FichaAjedrez.hpp"
#include "Recta2D.hpp"

#define DIMENSION_DEFECTO_TABLERO_AJEDREZ 8

using namespace std;

namespace algoritmia
{
	list<Coordenada2D> TableroAjedrez::listaMovimientos(const Coordenada2D &p) const
	{
		list<Coordenada2D> movimientos;

		if(this->getEnumFicha(p) == REINA)
		{
			movimientos = this->listaMovimientosReina(p);
		}

		return movimientos;
	}

	list<Coordenada2D> TableroAjedrez::listaMovimientosReina(const Coordenada2D &p) const
	{
		const Coordenada2D horizontal(1, 0);
		const Coordenada2D vertical(0, 1);
		const Coordenada2D diagonalSuperior(1, 1);
		const Coordenada2D diagonalInferior(1, -1);

		Recta2D direccion;
		Coordenada2D pDos = p;

		list<Coordenada2D> movReina;

		//Primero sacamos toda la Recta2D horizontal
		pDos = pDos + horizontal;
		direccion.establecerRecta2D(p, pDos);

		for(unsigned int i = 0; i < this->getDimension(); i++)
		{
			unsigned int x = i;
			unsigned int y = direccion.getY(x);

			// No hace falta comprobar si y es mayor que cero, debido a que estamos
			// trabajando con enteros sin signo. Si el metodo Recta2D::getY o el metodo
			// Recta2D::getX devolviera un numero negativo, este desbordaria y devolveria
			// un numero muy grande
			if(y < this->getDimension())
			{
				Coordenada2D mov(x, y);
				movReina.push_back(mov);
			}
		}
		pDos = p;

		//Sacamos ahora el movimiento vertical
		pDos = pDos + vertical;
		direccion.establecerRecta2D(p, pDos);

		for(unsigned int i = 0; i < this->getDimension(); i++)
		{
			unsigned int y = i;
			unsigned int x = direccion.getX(y);

			if(x < this->getDimension())
			{
				Coordenada2D mov(x, y);
				movReina.push_back(mov);
			}
		}
		pDos = p;

		//Sacamos la direccion que sigue la primera diagonal
		pDos = pDos + diagonalSuperior;
		direccion.establecerRecta2D(p, pDos);

		for(unsigned int i = 0; i < this->getDimension(); i++)
		{
			unsigned int x = i;
			unsigned int y = direccion.getY(x);

			if(y < this->getDimension())
			{
				Coordenada2D mov(x, y);
				movReina.push_back(mov);
			}
		}
		pDos = p;

		//Sacamos la direccion de la ultima diagonal
		pDos = pDos + diagonalInferior;
		direccion.establecerRecta2D(p, pDos);

		for(unsigned int i = 0; i < this->getDimension(); i++)
		{
			unsigned int x = i;
			unsigned int y = direccion.getY(x);

			if(y < this->getDimension())
			{
				Coordenada2D mov(x, y);
				movReina.push_back(mov);
			}
		}

		movReina.unique();
		movReina.remove(p);

		return movReina;
	}

	TableroAjedrez::TableroAjedrez()
	{
		this->setDimension(DIMENSION_DEFECTO_TABLERO_AJEDREZ);
	}

	TableroAjedrez::TableroAjedrez(const unsigned int &dimension)
	{
		this->setDimension(dimension);
	}

	TableroAjedrez::TableroAjedrez(const TableroAjedrez &table)
	{
		unsigned int dimension = table.getDimension();

		this->setDimension(dimension);

		for(unsigned int i = 0; i < dimension; i++)
		{
			for(unsigned int j = 0; j < dimension; j++)
			{
				enum CLASE_FICHA type = table.getEnumFicha(i, j);

				if(type != EMPTY)
				{
					this->setFicha(i, j, type);
				}
			}
		}
	}

	bool TableroAjedrez::hayFicha(const unsigned int &row, const unsigned int &col) const
	{
		assert(row < this->getDimension());
		assert(col < this->getDimension());

		return this->getEnumFicha(row, col) != EMPTY;
	}

	bool TableroAjedrez::hayFicha(const Coordenada2D &p) const
	{
		return this->getEnumFicha(p) != EMPTY;
	}

	enum CLASE_FICHA TableroAjedrez::getEnumFicha(const unsigned int &row, const unsigned int &col) const
	{
		assert(row < this->getDimension());
		assert(col < this->getDimension());

		return this->getFicha(row, col).getType();
	}

	enum CLASE_FICHA TableroAjedrez::getEnumFicha(const Coordenada2D &p) const
	{
		return this->getFicha(p).getType();
	}

	FichaAjedrez TableroAjedrez::getFicha(const unsigned int &row, const unsigned int &col) const
	{
		assert(row < this->getDimension());
		assert(col < this->getDimension());

		return _tablero[row][col];
	}

	FichaAjedrez TableroAjedrez::getFicha(const Coordenada2D &p) const
	{
		unsigned int row = p.getX();
		unsigned int col = p.getY();

		assert(row < this->getDimension());
		assert(col < this->getDimension());

		return _tablero[row][col];
	}

	bool TableroAjedrez::amenaza(const unsigned int &row, const unsigned int &col) const
	{
		Coordenada2D p(row, col);
		return this->amenaza(p);
	}

	bool TableroAjedrez::amenaza(const Coordenada2D &p) const
	{
		assert(p.getX() < this->getDimension());
		assert(p.getY() < this->getDimension());

		bool deteccion = false;
		for(unsigned int i = 0; ((i < this->getDimension()) && (deteccion == false)); i++)
		{
			for(unsigned int j = 0; ((j < this->getDimension()) && (deteccion == false)); j++)
			{
				Coordenada2D busqueda(i, j);

				if(busqueda != p)
				{
					list<Coordenada2D> movimientos;
					movimientos = this->listaMovimientos(busqueda);

					for(list<Coordenada2D>::const_iterator it = movimientos.begin(); it != movimientos.end(); it++)
					{
						if(*it == p)
						{
							deteccion = true;
							break;
						}
					}
				}
			}
		}

		return deteccion;
	}

	void TableroAjedrez::detail() const
	{
		for(unsigned int i = 0; i < this->getDimension(); i++)
		{
			for(unsigned int j = 0; j < this->getDimension(); j++)
			{
				if(this->getEnumFicha(i, j) != EMPTY)
				{
					Coordenada2D posicion;
					posicion.setCoordenada2D(static_cast<double>(i), static_cast<double>(j));

					cout << "Ficha: " << this->getFicha(i, j) << " Coordenada2D: " << posicion << endl; 
				}
			}
		}
	}

	unsigned int TableroAjedrez::getDimension() const
	{
		return _dimension;
	}

	void TableroAjedrez::setDimension(const unsigned int &dimension)
	{
		assert(dimension > 0);

		_tablero.resize(dimension);

		for(unsigned int i = 0; i < dimension; i++)
		{
			_tablero[i].resize(dimension);
		}

		_dimension = dimension;
	}

	void TableroAjedrez::setFicha(const unsigned int &row, const unsigned int &col, const FichaAjedrez &f)
	{
		assert(row < this->getDimension());
		assert(col < this->getDimension());

		if(this->getFicha(row, col) != f)
		{
			_tablero[row][col] = f;
		}
	}

	void TableroAjedrez::setFicha(const Coordenada2D &p, const FichaAjedrez &f)
	{
		unsigned int row = p.getX();
		unsigned int col = p.getY();

		this->setFicha(row, col, f);
	}

	void TableroAjedrez::setFicha(const unsigned int &row, const unsigned int &col, const enum CLASE_FICHA &e)
	{
		assert(row < this->getDimension());
		assert(col < this->getDimension());

		FichaAjedrez f(e);

		this->setFicha(row, col, f);
	}

	void TableroAjedrez::setFicha(const Coordenada2D &p, const enum CLASE_FICHA &e)
	{
		FichaAjedrez f(e);

		this->setFicha(p, f);
	}

	bool TableroAjedrez::moverFicha(const unsigned int &rowSource, const unsigned int &colSource, 
						const unsigned int &rowDest, const unsigned int &colDest)
	{
		Coordenada2D source(rowSource, colSource);
		Coordenada2D dest(rowDest, colDest);
		return this->moverFicha(source, dest);
	}

	bool TableroAjedrez::moverFicha(const Coordenada2D &source, const Coordenada2D &dest)
	{
		bool resultado = false;

		//Una posicion marcada como empty siempre dara una lista de movimientos
		//vacia, por lo que si la posicion origen que tratamos de mover es EMPTY
		//no afectara al algoritmo
		list<Coordenada2D> movimientosPosibles = this->listaMovimientos(source);
		list<Coordenada2D>::const_iterator it = find(movimientosPosibles.begin(), movimientosPosibles.end(), dest);

		if(it != movimientosPosibles.end())
		{
			resultado = true;
			this->setFicha(dest, this->getEnumFicha(source));
			this->setFicha(source, EMPTY);
		}

		return resultado;
	}

	bool TableroAjedrez::borrarFicha(const unsigned int &row, const unsigned int &col)
	{
		assert(row < this->getDimension());
		assert(col < this->getDimension());

		if(this->getEnumFicha(row, col) == EMPTY) //No hay nada que hacer
		{
			return false;
		}
		else
		{
			_tablero[row][col].establecerTipoFicha(EMPTY);
			return true;
		}
	}

	bool TableroAjedrez::borrarFicha(const Coordenada2D &p)
	{
		unsigned int row = p.getX();
		unsigned int col = p.getY();

		return this->borrarFicha(row, col);
	}

	void TableroAjedrez::clear()
	{
		for(unsigned int i = 0; i < this->getDimension(); i++)
		{
			for(unsigned int j = 0; j < this->getDimension(); j++)
			{
				Coordenada2D p(i, j);
				this->borrarFicha(p);
			}
		}
	}

	list<Coordenada2D> TableroAjedrez::listarFichas() const
	{
		list<Coordenada2D> lista;

		for(unsigned int i = 0; i < this->getDimension(); i++)
		{
			for(unsigned int j = 0; j < this->getDimension(); j++)
			{
				Coordenada2D p(i, j);
				if(this->hayFicha(p))
				{
					lista.push_back(p);
				}
			}
		}

		return lista;
	}

	void TableroAjedrez::operator=(const TableroAjedrez &t)
	{
		unsigned int dimension = t.getDimension();
		this->setDimension(dimension);

		this->clear();

		for(unsigned int i = 0; i < this->getDimension(); i++)
		{
			for(unsigned int j = 0; j < this->getDimension(); j++)
			{
				Coordenada2D p(i, j);
				if(t.getEnumFicha(p) != EMPTY)
				{
					enum CLASE_FICHA e = t.getEnumFicha(p);
					this->setFicha(p, e);
				}
			}
		}
	}

	bool TableroAjedrez::operator==(const TableroAjedrez &t) const
	{
		if(this->getDimension() != t.getDimension())
		{
			return false;
		}
		else
		{
			bool resultado;
			list<Coordenada2D> listaFichasA;
			list<Coordenada2D> listaFichasB;

			listaFichasA = this->listarFichas();
			listaFichasB = t.listarFichas();

			if(listaFichasA.size() != listaFichasB.size())
			{
				return false;
			}

			listaFichasA.sort();
			listaFichasB.sort();

			list<Coordenada2D>::const_iterator iteratorA;
			list<Coordenada2D>::const_iterator iteratorB;

			for(iteratorA = listaFichasA.begin(), iteratorB = listaFichasB.begin(); iteratorA != listaFichasA.end(); iteratorA++, iteratorB++)
			{
				resultado = *iteratorA == *iteratorB;
				if(!resultado)
				{
					break;
				}
			} 

			return resultado;
		}
	}

	bool TableroAjedrez::operator!=(const TableroAjedrez &t) const
	{
		return !(*this == t);
	}

	bool TableroAjedrez::operator<(const TableroAjedrez &t) const
	{
		assert(this->getDimension() == t.getDimension());

		list<Coordenada2D> fichasA = this->listarFichas();
		list<Coordenada2D> fichasB = t.listarFichas();

		if(fichasA.size() < fichasB.size())
		{
			return true;
		}
		else if(fichasA.size() > fichasB.size())
		{
			return false;
		}
		else
		{
			bool resultado = false;
			fichasA.sort();
			fichasB.sort();

			list<Coordenada2D>::const_iterator iteradorA = fichasA.begin();
			list<Coordenada2D>::const_iterator iteradorB = fichasB.begin();

			while(iteradorA != fichasA.end())
			{
				if(*iteradorA == *iteradorB)
				{
					iteradorA++;
					iteradorB++;
				}
				else
				{
					resultado = *iteradorA < *iteradorB;
					break;
				}
			}

			return resultado;
		}
	}

	bool TableroAjedrez::operator<=(const TableroAjedrez &t) const
	{
		assert(this->getDimension() == t.getDimension());

		list<Coordenada2D> fichasA = this->listarFichas();
		list<Coordenada2D> fichasB = t.listarFichas();

		if(fichasA.size() < fichasB.size())
		{
			return true;
		}
		else if(fichasA.size() > fichasB.size())
		{
			return false;
		}
		else
		{
			bool resultado = true;
			fichasA.sort();
			fichasB.sort();

			list<Coordenada2D>::const_iterator iteradorA = fichasA.begin();
			list<Coordenada2D>::const_iterator iteradorB = fichasB.begin();

			while(iteradorA != fichasA.end())
			{
				if(*iteradorA == *iteradorB)
				{
					iteradorA++;
					iteradorB++;
				}
				else
				{
					resultado = *iteradorA < *iteradorB;
					break;
				}
			}

			return resultado;
		}
	}

	bool TableroAjedrez::operator>(const TableroAjedrez &t) const
	{
		return !(*this <= t);
	}

	bool TableroAjedrez::operator>=(const TableroAjedrez &t) const
	{
		return !(*this < t);
	}

	TableroAjedrez::~TableroAjedrez()
	{
		//Empty
	}
};