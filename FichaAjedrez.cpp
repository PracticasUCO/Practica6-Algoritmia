#include <string>
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
		else
		{
			return "REINA";
		}
	}
}