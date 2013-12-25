#include <cassert>
#include <random>
#include <cmath>
#include "TableroAjedrez.hpp"
#include "FichaAjedrez.hpp"
#include "Coordenada2D.hpp"
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
		Coordenada2D posicion(0, 0);

		tablero.setDimension(this->getDimension());

		while(posicion.getX() < tablero.getDimension())
		{
			if(!tablero.amenaza(posicion))
			{
				tablero.setFicha(posicion, REINA);
				posicion.setCoordenada2D(posicion.getX() + 1, 0);
			}
			else
			{
				posicion.setCoordenada2D(posicion.getX(), posicion.getY() + 1);

				if(posicion.getY() >= tablero.getDimension()) //Hay que retroceder
				{
					posicion.setCoordenada2D(posicion.getX() - 1, 0);

					if(this->buscarReina(tablero, posicion))
					{
						tablero.borrarFicha(posicion);
						posicion.setCoordenada2D(posicion.getX(), posicion.getY() + 1);

						if(posicion.getY() >= tablero.getDimension()) //No creo que deba de pasar nunca
						{
							if(posicion.getX() != 0)
							{
								posicion.setCoordenada2D(posicion.getX() - 1 , 0);
								this->buscarReina(tablero, posicion);
								tablero.borrarFicha(posicion);
								posicion.setCoordenada2D(posicion.getX(), posicion.getY() + 1);
							}
						}
					}
					else //No creo que deba de pasar nunca
					{
						posicion.setCoordenada2D(posicion.getX() + 2, 0);
					}
				}
			}
		}

		return tablero;
	}

	list<TableroAjedrez> NReinas::allSolutions() const
	{
		list<TableroAjedrez> lista;
		TableroAjedrez tablero;

		tablero.setDimension(this->getDimension());

		this->search(lista, tablero);


		return lista;
	}


	void NReinas::search(list<TableroAjedrez> &lista, TableroAjedrez &table, const unsigned int k) const
	{
		if(k == this->getDimension())
		{
			lista.push_back(table);
		}
		else
		{

			for(unsigned int i = 0; i < this->getDimension(); i++)
			{
				if((!table.amenaza(Coordenada2D(k, i))) && (!table.hayFicha(Coordenada2D(k, i))))
				{
					table.setFicha(Coordenada2D(k, i), REINA);
				
					cerr << endl;

					search(lista, table, k+1);

					table.borrarFicha(Coordenada2D(k, i));
				}
			}
		}
	}

	void NReinas::setNSolutionsFlag(const bool &flag)
	{
		_nSolutionsCalculated = flag;
	}

	bool NReinas::getNSolutionsFlag() const
	{
		return _nSolutionsCalculated;
	}

	void NReinas::setNSolutions(const unsigned int &nSolutions)
	{
		if(this->getNSolutionsFlag())
		{
			_nSolutions = nSolutions;
			this->setNSolutionsFlag(false);
		}
	}

	void NReinas::setIntentosVegas(const unsigned int &intentos)
	{
		_intentosVegas = intentos;
	}

	unsigned int NReinas::getIntentosVegas() const
	{
		return _intentosVegas;
	}

	bool NReinas::vegas(TableroAjedrez &table, const unsigned int &nIntentos)
	{
		random_device rd;
		unsigned int reinas = 0;
		table.clear();
		unsigned int intentos = 0;

		for(unsigned int i = 0; i < table.getDimension(); i++)
		{
			while(intentos < nIntentos)
			{
				unsigned int j = rd() % table.getDimension();
				Coordenada2D p(i, j);

				if(table.amenaza(p))
				{
					intentos++;
				}
				else
				{
					table.setFicha(p, REINA);
					reinas++;
					break;
				}
			}
		}

		this->setIntentosVegas(intentos);

		if(reinas == table.getDimension())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	double NReinas::probabilidadVegas() const
	{
		double resultado;
		list<TableroAjedrez> lista = this->allSolutions(); //Contiene todas las soluciones

		resultado = 1/this->getDimension();

		resultado = pow(resultado, this->getDimension());
		resultado *= lista.size();

		return resultado;
	}

	double NReinas::probabilidadVegasAll(const unsigned int &nIntentos) const
	{
		//Se sigue una distribucion binaria o de poison con probabilidad p
		//La suma de n intentos es una distribuccion binomial
		//El espacio de probabilidad es 0 1 2 3 4 5 ... S siendo S el numero de soluciones
		//La idea es, calcular la probabilidad p(x = 0) + p(x = 1) etc, hasta llegar a S - 1
		// y restarle eso a 1 De esa manera tendriamos la probabilidad
		// En realidad sigue una distribucion hipergeometrica, pero se puede aproximar mediante
		// una binomial
		unsigned int x; // Valor de la distribucion en un momento dado
		unsigned int xMaximo; //Valor maximo que me interesa de la distribucion
		double p = this->probabilidadVegas(); //Probabilidad de acierto
	}

	bool NReinas::buscarReina(const TableroAjedrez &t, Coordenada2D &p) const
	{
		assert(p.getX() < t.getDimension());
		
		bool resultado = false;

		for(unsigned int j = 0; j < t.getDimension(); j++)
		{
			if(t.getEnumFicha(Coordenada2D(p.getX(), j)) == REINA)
			{
				p.setCoordenada2D(p.getX(), j);
				resultado = true;
				break;
			}
		}

		return resultado;
	}

	list<Coordenada2D> NReinas::searchQueens(const TableroAjedrez &t) const
	{
		list<Coordenada2D> l;

		for(unsigned int i = 0; i < t.getDimension(); i++)
		{
			for(unsigned int j = 0; j < t.getDimension(); j++)
			{
				Coordenada2D p(i, j);

				if((t.hayFicha(p)) && (t.getEnumFicha(p) == REINA))
				{
					l.push_back(p);
				}
			}
		}

		return l;
	}

	void NReinas::setDimension(const unsigned int &dim)
	{
		assert(dim > 3);
		_dim = dim;
	}

	unsigned int NReinas::getNSolutions()
	{
		if(this->getNSolutionsFlag())
		{
			this->allSolutions();
		}

		return _nSolutions;
	}

	unsigned int NReinas::getDimension() const
	{
		return _dim;
	}

	unsigned int NReinas::countQueens(const TableroAjedrez &table) const
	{
		list<Coordenada2D> queens = table.listarFichas();

		for(auto point : queens)
		{
			if(table.getEnumFicha(point) != REINA)
			{
				queens.remove(point);
			}
		}

		return static_cast<unsigned int>(queens.size());
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