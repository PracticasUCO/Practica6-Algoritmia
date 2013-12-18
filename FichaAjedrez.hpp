#ifndef __FICHA_AJEDREZ_HPP
#define __FICHA_AJEDREZ_HPP

#include <string>
#include <iostream>

using namespace std;

namespace algoritmia
{

	enum CLASE_FICHA {PEON, TORRE, ALFIL, CABALLO, REY, REINA, EMPTY};

	class FichaAjedrez
	{
	private:
		enum CLASE_FICHA _type; //!< Especifica el tipo de ficha que es

	public:
		/** @brief Constructor de la clase FichaAjedrez
		    @param CLASE_FICHA, indica el tipo de ficha que se esta construyendo **/
		FichaAjedrez(const enum CLASE_FICHA &type = EMPTY);

		/** @brief Devuelve el tipo de ficha que es, en forma de enumerado **/
		enum CLASE_FICHA getType() const;

		/** @brief Devuelve el tipo de ficha que es, en forma de cadena **/
		string getNameType() const;

		/** @brief Borra la ficha **/
		void remove();

		void establecerTipoFicha(const enum CLASE_FICHA &type);

		/** @brief Destructor **/
		~FichaAjedrez();

		/** Sobrecarga de operadores **/
		void operator=(const FichaAjedrez &f);
		bool operator==(const FichaAjedrez &f) const;
		bool operator!=(const FichaAjedrez &f) const;
		friend ostream& operator<<(ostream &output, const FichaAjedrez &f);
		friend istream& operator>>(istream &input, FichaAjedrez &f); 
	};
}

#endif