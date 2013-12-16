#include <iostream>
#include <string>
#include <cassert>
#include "TableroAjedrez.hpp"
#include "FichaAjedrez.hpp"

#define ROWS_DEFAULT 8
#define COLS_DEFAULT 8

using namespace std;

namespace algoritmia
{
	TableroAjedrez::TableroAjedrez()
	{
		this->setTablero(ROWS_DEFAULT, COLS_DEFAULT);
	}

	TableroAjedrez::TableroAjedrez(const unsigned int rows, const unsigned int cols)
	{
		this->setTablero(rows, cols);
	}

	TableroAjedrez::TableroAjedrez(const TableroAjedrez &table)
	{
		unsigned int rows = table.getRows();
		unsigned int cols = table.getCols();

		this->setTablero(rows, cols);

		for(unsigned int i = 0; i < rows; i++)
		{
			for(unsigned int j = 0; j < cols; j++)
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
		return this->getEnumFicha(row, col) != EMPTY;
	}

	bool TableroAjedrez::hayFicha(const Posicion &p) const
	{
		return this->getEnumFicha(p) != EMPTY;
	}

	enum CLASE_FICHA TableroAjedrez::getEnumFicha(const unsigned int &row, const unsigned int &col) const
	{
		return this->getFicha(row, col).getType();
	}

	enum CLASE_FICHA TableroAjedrez::getEnumFicha(const Posicion &p) const
	{
		return this->getFicha(p).getType();
	}

	FichaAjedrez TableroAjedrez::getFicha(const unsigned int &row, const unsigned int &col) const
	{
		assert(row < this->getRows());
		assert(col < this->getCols());

		return _tablero[row][col];
	}

	FichaAjedrez TableroAjedrez::getFicha(const Posicion &p) const
	{
		unsigned int row = p.getRow();
		unsigned int col = p.getCol();

		assert(row < this->getRows());
		assert(col < this->getCols());

		return _tablero[row][col];
	}

	void TableroAjedrez::detail() const
	{
		for(unsigned int i = 0; i < this->getRows(); i++)
		{
			for(unsigned int j = 0; j < this->getCols(); j++)
			{
				if(this->getEnumFicha(i, j) != EMPTY)
				{
					cout << "Ficha: " << this->getFicha(i, j) << " Posicion: (" << i << ", " << j << ")" << endl; 
				}
			}
		}
	}

	unsigned int TableroAjedrez::getRows() const
	{
		return _rows;
	}

	unsigned int TableroAjedrez::getCols() const
	{
		return _cols;
	}

	void TableroAjedrez::setTablero(const unsigned int &rows, const unsigned int &cols)
	{
		assert(rows > 0);
		assert(cols > 0);

		_rows = rows;
		_cols = cols;

		_tablero.resize(rows);

		for(unsigned int i = 0; i < rows; i++)
		{
			_tablero[i].resize(cols);
		}
	}

	void TableroAjedrez::setFicha(const unsigned int &row, const unsigned int &col, const FichaAjedrez &f)
	{
		assert(row < this->getRows());
		assert(col < this->getCols());

		if(this->getFicha(row, col) != f)
		{
			_tablero[row][col] = f;
		}
	}

	void TableroAjedrez::setFicha(const Posicion &p, const FichaAjedrez &f)
	{
		unsigned int row = p.getRow();
		unsigned int col = p.getCol();

		assert(row < this->getRows());
		assert(col < this->getCols());

		if(this->getFicha(row, col) != f)
		{
			_tablero[row][col] = f;
		}
	}

	void TableroAjedrez::setFicha(const unsigned int &row, const unsigned int &col, const enum CLASE_FICHA &e)
	{
		FichaAjedrez f(e);

		this->setFicha(row, col, f);
	}

	void TableroAjedrez::setFicha(const Posicion &p, const enum CLASE_FICHA &e)
	{
		FichaAjedrez f(e);

		this->setFicha(p, f);
	}

	bool TableroAjedrez::borrarFicha(const unsigned int &row, const unsigned int &col)
	{
		assert(row < this->getRows());
		assert(col < this->getCols());

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
};