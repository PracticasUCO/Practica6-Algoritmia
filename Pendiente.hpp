#ifndef __PENDIENTE_HPP
#define __PENDIENTE_HPP

#include <Punto.hpp>
#include <iostream>

using namespace std;

namespace algoritmia
{
	enum PENDIENTE { NUMERICA, INFINITA };

	class Pendiente
	{
		enum PENDIENTE _typeValue;
		double _value;

	public:
		/** @brief Constructor por defecto de la pendiente inicializandola a cero **/
		Pendiente();

		/** @brief Constructor de la pendiente en el que se la pasan los dos puntos implicados
			@param A Primer punto de la pendiente
			@param B Segundo punto de la pendiente **/
		Pendiente(const Punto &A, const Punto &B);

		/** @brief Constructor de copia **/
		Pendiente(const Pendiente &p);

		/** @brief Establece la pendiente entre dos puntos
			@param A Primer punto de la pendiente
			@param B Segundo punto de la pendiente **/
		void establecerPendiente(const Punto &A, const Punto &B);

		/** @brief Devuelve el tipo de pendiente de la que estamos tratando
			@return INFINITA si se trata de una pendiente infinita y NUMERICA en cualquier otro caso **/
		const enum PENDIENTE getType() const;

		/** @brief Devuelve el valor de la pendiente
			@pre La pendiente no debe de ser infinita, en caso contrario saltara un assert
			@return El valor de la pendiente **/
		double getValue() const;

		/** Sobrecarga de operadores **/
		void operator=(const Pendiente &p);
		bool operator==(const Pendiente &p);
		bool operator!=(const Pendiente &p);
		bool operator<(const Pendiente &p);
		bool operator<=(const Pendiente &p);
		bool operator>(const Pendiente &p);
		bool operator>=(const Pendiente &p);

		friend ostream& operator<<(ostream &output, const Pendiente &p);
		friend istream& operator>>(istream &input, Pendiente &p);

	};
}

#endif