#include <cassert>
#include "TableroAjedrez.hpp"
#include "FichaAjedrez.hpp"
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

	void NReinas::setDimension(const unsigned int &dim)
	{
		assert(dim > 0);
		_dim = dim;
	}
}