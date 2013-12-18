#include <cassert>
#include "TableroAjedrez.hpp"
#include "FichaAjedrez.hpp"
#include "Punto.hpp"
#include "NReinas.hpp"

using namespace std;

namespace algoritmia
{
	NReinas::NReinas()
	{
		const unsigned int defaultDimension = 8;
		this->setDimension(defaultDimension);
	}

	NReinas::NReinas(const unsigned int &dim)
	{
		this->setDimension(dim);
	}

	NReinas::NReinas(const NReinas &nr)
	{
		*this = nr;
	}

	TableroAjedrez NReinas::singleSolution() const
	{
		TableroAjedrez tablero(this->getDimension());
		Punto posicion(0, 0);

		while(posicion.getX() < tablero.getDimension())
		{
			if(!tablero.amenaza(posicion))
			{
				tablero.setFicha(posicion, REINA);
				posicion.setPunto(posicion.getX() + 1, 0);
			}
			else
			{
				posicion.setPunto(posicion.getX(), posicion.getY() + 1);

				if(posicion.getY() > tablero.getDimension())
				{
					break;
				}
			}
		}

		return tablero;
	}

	void NReinas::setDimension(const unsigned int &dim)
	{
		assert(dim > 0);
		_dim = dim;
	}

	unsigned int NReinas::getDimension() const
	{
		return _dim;
	}

	void NReinas::operator=(const NReinas &nr)
	{
		unsigned int dimension = nr.getDimension();
		this->setDimension(dimension);
	}

	NReinas::~NReinas()
	{
		//Empty
	}
}