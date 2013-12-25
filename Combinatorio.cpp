#include <iostream>
#include <cassert>
#include "Combinatorio.hpp"

using namespace std;

namespace numbers
{
	long double Combinatorio::factorial(const unsigned long long int &f)
	{
		long double resultado = 1;

		for(unsigned long long int i = 2; i <= f; i++)
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
		return _result;
	}

	void Combinatorio::set(const unsigned long long int &upper, const unsigned long long &down)
	{
		assert(upper >= down);
		if((upper != this->getUpper()) || (down != this->getDown()))
		{
			_upper = upper;
			_down = down;
			this->update();
		}
	}

	void Combinatorio::update()
	{
		long double resultado;
		unsigned long long int upper;
		unsigned long long int down;

		upper = this->getUpper();
		down = this->getDown();

		resultado = this->factorial(upper) / (this->factorial(down) * this->factorial(upper - down));
		_result = resultado;
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

	bool Combinatorio::operator==(const Combinatorio &c) const
	{
		if((this->getUpper() == c.getUpper()) && (this->getDown() == c.getDown()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Combinatorio::operator!=(const Combinatorio &c) const
	{
		return !(*this == c);
	}

	bool Combinatorio::operator<(const Combinatorio &c) const
	{
		if(this->getResult() < c.getResult())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Combinatorio::operator<=(const Combinatorio &c) const
	{
		if(this->getResult() <= c.getResult())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Combinatorio::operator>(const Combinatorio &c) const
	{
		return !(*this <= c);
	}

	bool Combinatorio::operator>=(const Combinatorio &c) const
	{
		return !(*this < c);
	}

	ostream& operator<<(ostream &output, const Combinatorio &c)
	{
		output << "C(" << c.getUpper() << ", " << c.getDown() << ") = " << c.getResult();
		return output;
	}

	istream& operator>>(istream &input, Combinatorio &c)
	{
		unsigned long long int upper;
		unsigned long long int down;

		cout << "Introducciendo en numero combinatorio C(upper, down)" << endl;
		cout << "Introduzca el valor de upper: ";
		input >> upper;
		cout << endl;

		cout << "Introduzca el valor de down: ";
		input >> down;
		cout << endl;

		c.set(upper, down);
		c.update();

		return input;
	}

	long double Combinatorio::operator+(const Combinatorio &c) const
	{
		return this->getResult() + c.getResult();
	}

	long double Combinatorio::operator-(const Combinatorio &c) const
	{
		return this->getResult() - c.getResult();
	}

	long double Combinatorio::operator*(const Combinatorio &d) const
	{
		return this->getResult() * d.getResult();
	}

	long double Combinatorio::operator/(const Combinatorio &d) const
	{
		return this->getResult() / d.getResult();
	}

	Combinatorio::~Combinatorio()
	{
		//Empty
	}
}