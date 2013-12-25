#ifndef __PENDIENTE_HPP
#define __PENDIENTE_HPP

#include <Coordenada2D.hpp>
#include <iostream>

using namespace std;

namespace algoritmia
{
	enum PENDIENTE { REAL, INF };

	class Pendiente
	{
		enum PENDIENTE _typeValue;
		double _value;

	public:
		/** @brief Constructor por defecto de la pendiente inicializandola a cero **/
		Pendiente();

		/** @brief Constructor de la pendiente en el que se la pasan los dos puntos implicados
			@param A Primera coordenada de la pendiente
			@param B Segunda Coordenada2D de la pendiente **/
		Pendiente(const Coordenada2D &A, const Coordenada2D &B);

		/** @brief Constructor de copia **/
		Pendiente(const Pendiente &p);

		/** @brief Establece la pendiente entre dos Coordenada2Ds
			@param A Primera Coordenada2D de la pendiente
			@param B Segunda Coordenada2D de la pendiente **/
		void establecerPendiente(const Coordenada2D &A, const Coordenada2D &B);

		/** @brief Devuelve el tipo de pendiente de la que estamos tratando
			@return INF si se trata de una pendiente INF y REAL en cualquier otro caso **/
		const enum PENDIENTE getType() const;

		/** @brief Devuelve el valor de la pendiente
			@pre La pendiente no debe de ser infinita, en caso contrario saltara un assert
			@return El valor de la pendiente **/
		double getValue() const;

		/** @brief Destructor de la clase **/
		~Pendiente();

		/** Sobrecarga de operadores **/
		void operator=(const Pendiente &p);
		bool operator==(const Pendiente &p) const;
		bool operator!=(const Pendiente &p) const;
		bool operator<(const Pendiente &p) const;
		bool operator<=(const Pendiente &p) const;
		bool operator>(const Pendiente &p) const;
		bool operator>=(const Pendiente &p) const;

		friend ostream& operator<<(ostream &output, const Pendiente &p);
		friend istream& operator>>(istream &input, Pendiente &p);

	};
}

#endif