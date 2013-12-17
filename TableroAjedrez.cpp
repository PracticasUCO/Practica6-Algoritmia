#include <iostream>
#include <string>
#include <cassert>
#include "TableroAjedrez.hpp"
#include "FichaAjedrez.hpp"
#include "Recta.hpp"

#define DIMENSION_DEFECTO_TABLERO_AJEDREZ 8

using namespace std;

namespace algoritmia
{
	list<Punto> TableroAjedrez::listaMovimientos(const Punto &p, const FichaAjedrez &f) const
	{
		list<Punto> movimientos;

		if(f.getType() == REINA)
		{
			movimientos = this->listaMovimientosReina(p);
		}

		return movimientos;
	}

	TableroAjedrez::TableroAjedrez()
	{
		this->setTablero(DIMENSION_DEFECTO_TABLERO_AJEDREZ);
	}

	TableroAjedrez::TableroAjedrez(const unsigned int &dimension)
	{
		this->setTablero(dimension);
	}

	TableroAjedrez::TableroAjedrez(const TableroAjedrez &table)
	{
		unsigned int dimension = table.getDimension();

		this->setTablero(dimension);

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

	bool TableroAjedrez::hayFicha(const Punto &p) const
	{
		return this->getEnumFicha(p) != EMPTY;
	}

	enum CLASE_FICHA TableroAjedrez::getEnumFicha(const unsigned int &row, const unsigned int &col) const
	{
		assert(row < this->getDimension());
		assert(col < this->getDimension());

		return this->getFicha(row, col).getType();
	}

	enum CLASE_FICHA TableroAjedrez::getEnumFicha(const Punto &p) const
	{
		return this->getFicha(p).getType();
	}

	FichaAjedrez TableroAjedrez::getFicha(const unsigned int &row, const unsigned int &col) const
	{
		assert(row < this->getDimension());
		assert(col < this->getDimension());

		return _tablero[row][col];
	}

	FichaAjedrez TableroAjedrez::getFicha(const Punto &p) const
	{
		unsigned int row = p.getX();
		unsigned int col = p.getY();

		assert(row < this->getDimension());
		assert(col < this->getDimension());

		return _tablero[row][col];
	}

	void TableroAjedrez::detail() const
	{
		for(unsigned int i = 0; i < this->getDimension(); i++)
		{
			for(unsigned int j = 0; j < this->getDimension(); j++)
			{
				if(this->getEnumFicha(i, j) != EMPTY)
				{
					Punto posicion;
					posicion.setPunto(static_cast<double>(i), static_cast<double>(j));

					cout << "Ficha: " << this->getFicha(i, j) << " Punto: " << posicion << endl; 
				}
			}
		}
	}

	unsigned int TableroAjedrez::getDimension() const
	{
		return _dimension;
	}

	void TableroAjedrez::setTablero(const unsigned int &dimension)
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

	void TableroAjedrez::setFicha(const Punto &p, const FichaAjedrez &f)
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

	void TableroAjedrez::setFicha(const Punto &p, const enum CLASE_FICHA &e)
	{
		FichaAjedrez f(e);

		this->setFicha(p, f);
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

	bool TableroAjedrez::borrarFicha(const Punto &p)
	{
		unsigned int row = p.getX();
		unsigned int col = p.getY();

		return this->borrarFicha(row, col);
	}
};