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
};