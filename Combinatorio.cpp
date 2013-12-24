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
		this->set(0 , 0);
		this->update();
	}

	Combinatorio::Combinatorio(const unsigned long long int &upper, const unsigned long long int &down)
	{
		this->set(upper, down);
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

	void Combinatorio::set(const unsigned long long int &upper, const unsigned long long &down)
	{
		assert(upper >= down);

		if((upper != this->getUpper()) || (down != this->getDown()))
		{
			_upper = upper;
			_down = down;
			this->setUpdate(true);
		}
	}

	void Combinatorio::update()
	{
		if(this->checkUpdate())
		{
			long double resultado;
			unsigned long long int upper;
			unsigned long long int down;

			upper = this->getUpper();
			down = this->getDown();

			resultado = this->factorial(upper) / (this->factorial(down) * this->factorial(upper - down));
			_result = resultado;
			this->setUpdate(false);
		}
	}

	void Combinatorio::clone(const Combinatorio &c)
	{
		unsigned long long int upper;
		unsigned long long int down;

		upper = c.getUpper();
		down = c.getDown();

		this->set(upper, down);

		this->update();
	}

	void Combinatorio::operator=(const Combinatorio &c)
	{
		this->clone(c);
	}
}