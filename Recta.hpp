#ifndef __RECTA_HPP
#define __RECTA_CPP

#include "Punto.hpp"

namespace algoritmia
{
	class Recta
	{
	private:
		double _coeficienteX;
		double _coeficienteY;
		double _coeficienteIndependiente;

	public:
		/** @brief Constructor vacio **/
		Recta();

		/** @brief Constructor de la recta que pasa por dos puntos
			@param A Primer punto por el que debe de pasar la recta
			@param B Segundo punto por el que debe pasar la recta **/
		Recta(const Punto &A, const &Punto &B);

		/** @brief Constructor de copia **/
		Recta(const Recta &r);

		/** @brief Establece la recta que pasa por dos puntos dados **/
		void establecerRecta(const Punto &A, const &Punto B);

		/** @brief Devuelve el valor que tendria Y al darle X a la recta
			@param X el valor de la abscisa X
			@return Un valor que indica el valor de Y **/
		double getY(const double &X) const;

		/** @brief Devuelve el valor que tendria X al darle Y a la recta
			@param Y el valor del eje Y
			@return Un valor que indica el valor de la X **/
		double getX(const double &Y) const;

		/** @brief Devuelve el valor del coeficiente X **/
		double getCoeficienteX() const;

		/** @brief Devuelve el valor del coeficiente Y **/
		double getCoeficienteY() const;

		/** @brief Devuelve el valor del coeficiente independiente **/
		double getCoeficienteIndependiente() const;

		/** Copia la recta **/
		void operator=(const Recta &r);

		bool operator==(const Recta &r);
		bool operator!=(const Recta &r);
		/** Las ordenaciones se hacen por pendiente **/
		bool operator<(const Recta &r);
		bool operator<=(const Recta &r);
		bool operator>(const Recta &r);
		bool operator>=(const Recta &r);
	};
}

#endif