#include <iostream>
#include <string>
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
};