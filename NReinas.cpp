#include "TableroAjedrez.hpp"
#include "FichaAjedrez.hpp"
#include "NReinas.hpp"

namespace algoritmia
{
	NReinas::NReinas()
	{
		const unsigned int defaultDimension = 8;
		this->setDimension(defaultDimension);
	}
}