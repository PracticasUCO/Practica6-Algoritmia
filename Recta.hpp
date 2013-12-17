#ifndef __RECTA_HPP
#define __RECTA_CPP

#include <iostream>
#include "Punto.hpp"
#include "Pendiente.hpp"

using namespace std;

namespace algoritmia
{
	class Recta
	{
	private:
		Punto _inicio;
		Pendiente _pendiente;

		/** @brief Trata de mover un punto con una pendiente lo maximo posible hacia la
			izquierda y lo maximo posible hacia arriba
			@param punto El punto a mover
			@param pendiente La pendiente de la recta a seguir
			@return El nuevo punto al comienzo de la recta **/
		Punto moverAlInicio(const Punto &punto, const Pendiente &pendiente) const;

	public:
		/** @brief Constructor vacio **/
		Recta();

		/** @brief Constructor de la recta que pasa por dos puntos
			@param A Primer punto por el que debe de pasar la recta
			@param B Segundo punto por el que debe pasar la recta **/
		Recta(const Punto &A, const Punto &B);

		/** @brief Constructor de copia **/
		Recta(const Recta &r);

		/** @brief Establece la recta que pasa por dos puntos dados **/
		void establecerRecta(const Punto &A, const Punto &B);

		/** @brief Devuelve el valor que tendria Y al darle X a la recta
			@param X el valor de la abscisa X
			@return Un valor que indica el valor de Y **/
		double getY(const double &X) const;

		/** @brief Devuelve el valor que tendria X al darle Y a la recta
			@param Y el valor del eje Y
			@return Un valor que indica el valor de la X **/
		double getX(const double &Y) const;

		/** @brief Devuelve el punto inicial almacenado por la recta **/
		Punto getPuntoInicial() const;

		/** @brief Devuelve la pendiente de la recta **/
		Pendiente getPendiente() const;

		/** Copia la recta **/
		void operator=(const Recta &r);

		bool operator==(const Recta &r);
		bool operator!=(const Recta &r);
		/** Las ordenaciones se hacen por pendiente **/
		bool operator<(const Recta &r);
		bool operator<=(const Recta &r);
		bool operator>(const Recta &r);
		bool operator>=(const Recta &r);

		friend ostream& operator<<(ostream& output, const Recta &r);
		friend istream& operator>>(istream& input, Recta &r);
	};
}

#endif