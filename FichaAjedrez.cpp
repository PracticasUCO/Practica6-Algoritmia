#include <string>
#include <cassert>
#include <iostream>
#include "FichaAjedrez.hpp"

using namespace std;

namespace algoritmia
{
	void FichaAjedrez::establecerTipoFicha(const enum CLASE_FICHA &type)
	{
		_type = type;
	}

	FichaAjedrez::FichaAjedrez(const enum CLASE_FICHA &type)
	{
		this->establecerTipoFicha(type);
	}

	enum CLASE_FICHA FichaAjedrez::getType() const
	{
		return _type;
	}

	string FichaAjedrez::getNameType() const
	{
		enum CLASE_FICHA type = this->getType();

		if(type == PEON)
		{
			return "PEON";
		}
		else if(type == TORRE)
		{
			return "TORRE";
		}
		else if(type == ALFIL)
		{
			return "ALFIL";
		}
		else if(type == CABALLO)
		{
			return "CABALLO";
		}
		else if(type == REY)
		{
			return "REY";
		}
		else if(type == REINA)
		{
			return "REINA";
		}
		else
		{
			return "EMPTY";
		}
	}

	void FichaAjedrez::remove()
	{
		this->establecerTipoFicha(EMPTY);
	}

	void FichaAjedrez::operator=(const FichaAjedrez &f)
	{
		enum CLASE_FICHA type = f.getType();
		this->establecerTipoFicha(type);
	}

	bool FichaAjedrez::operator==(const FichaAjedrez &f) const
	{
		return f.getType() == this->getType();
	}

	bool FichaAjedrez::operator!=(const FichaAjedrez &f) const
	{
		return f.getType() != this->getType();
	}

	ostream& operator<<(ostream &output, const FichaAjedrez &f)
	{
		output << f.getNameType();
		return output;
	}

	istream& operator>>(istream &input, FichaAjedrez &f)
	{
		int opcion;
		enum CLASE_FICHA type;

		do
		{
			cout << "1- PEON" << endl;
			cout << "2- TORRE" << endl;
			cout << "3- ALFIL" << endl;
			cout << "4- CABALLO" << endl;
			cout << "5- REY" << endl;
			cout << "6- REINA" << endl;
			cout << "7- EMPTY" << endl;

			cout << "Escoja el tipo de ficha: ";
			input >> opcion;
			cout << endl;
		} while((opcion < 1) || (opcion > 7));

		switch(opcion)
		{
			case 1:
				type = PEON;
				break;

			case 2:
				type = TORRE;
				break;

			case 3:
				type = ALFIL;
				break;

			case 4:
				type = CABALLO;
				break;

			case 5:
				type = REY;
				break;

			case 6:
				type = REINA;
				break;

			default:
				type = EMPTY;
		};

		f.establecerTipoFicha(type);

		return input;
	}

	FichaAjedrez::~FichaAjedrez()
	{
		//Empty
	}
}