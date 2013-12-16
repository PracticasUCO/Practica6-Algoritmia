#ifndef __FICHA_AJEDREZ_HPP
#define __FICHA_AJEDREZ_HPP

#include <string>

using namespace std;

namespace algoritmia
{

	enum CLASE_FICHA {PEON, TORRE, ALFIL, CABALLO, REY, REINA};

	class FichaAjedrez
	{
	private:
		enum CLASE_FICHA _type; //!< Especifica el tipo de ficha que es

		void establecerTipoFicha(const enum CLASE_FICHA &type);

	public:
		/** @brief Constructor de la clase FichaAjedrez
		    @param CLASE_FICHA, indica el tipo de ficha que se esta construyendo **/
		FichaAjedrez(const enum CLASE_FICHA &type);

		/** @brief Devuelve el tipo de ficha que es, en forma de enumerado **/
		enum CLASE_FICHA getType() const;

		/** @brief Devuelve el tipo de ficha que es, en forma de cadena **/
		string getNameType() const;

		~FichaAjedrez();
	
		/* data */
	};
}

#endif