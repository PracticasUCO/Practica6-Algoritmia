#include <iostream>
#include <cassert>
#include "Combinatorio.hpp"

using namespace std;

namespace numbers
{
	void Combinatorio::setUpdate(const bool &b)
	{
		_needUpdate = b;
	}

	long double Combinatorio::factorial(const unsigned long long int &f)
	{
		long double resultado = 1;

		for(unsigned long long int i = 2; i < f; i++)
		{
			resultado *= i;
		}

		return resultado;
	}

	Combinatorio::Combinatorio()
	{
		this->setUpper(0);
		this->setDown(0);
		this->update();
	}

	Combinatorio::Combinatorio(const unsigned long long int &upper, const unsigned long long int &down)
	{
		this->setUpper(upper);
		this->setDown(down);
		this->update();
	}

	Combinatorio::Combinatorio(const Combinatorio &c)
	{
		this->clone(c);
	}

	unsigned long long int Combinatorio::getUpper() const
	{
		return _upper;
	}

	unsigned long long int Combinatorio::getDown() const
	{
		return _down;
	}

	long double Combinatorio::getResult() const
	{
		assert(!this->checkUpdate());
		return _result;
	}

	bool Combinatorio::checkUpdate() const
	{
		return _needUpdate;
	}

	void Combinatorio::setUpper(const unsigned long long int &upper)
	{
		if(this->getUpper() != upper)
		{
			this->setUpdate(true);
			_upper = upper;
		}
	}

	void Combinatorio::setDown(const unsigned long long int &down)
	{
		if(this->getDown() != down)
		{
			this->setUpdate(true);
			_down = down;
		}
	}
}