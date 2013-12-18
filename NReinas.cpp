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
		TableroAjedrez tablero;
		Punto posicion(0, 0);

		tablero.setTablero(this->getDimension());

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

				if(posicion.getY() >= tablero.getDimension()) //Hay que retroceder
				{
					posicion.setPunto(posicion.getX() - 1, 0);

					if(this->buscarReina(tablero, posicion))
					{
						tablero.borrarFicha(posicion);
						posicion.setPunto(posicion.getX(), posicion.getY() + 1);

						if(posicion.getY() >= tablero.getDimension()) //No creo que deba de pasar nunca
						{
							if(posicion.getX() != 0)
							{
								posicion.setPunto(posicion.getX() - 1 , 0);
								this->buscarReina(tablero, posicion);
								tablero.borrarFicha(posicion);
								posicion.setPunto(posicion.getX(), posicion.getY() + 1);
							}
						}
					}
					else //No creo que deba de pasar nunca
					{
						posicion.setPunto(posicion.getX() + 2, 0);
					}
				}
			}
		}

		return tablero;
	}

	bool NReinas::buscarReina(const TableroAjedrez &t, Punto &p) const
	{
		assert(p.getX() < t.getDimension());
		
		bool resultado = false;

		for(unsigned int j = 0; j < t.getDimension(); j++)
		{
			if(t.getEnumFicha(Punto(p.getX(), j)) == REINA)
			{
				p.setPunto(p.getX(), j);
				resultado = true;
				break;
			}
		}

		return resultado;
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