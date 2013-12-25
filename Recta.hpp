#ifndef __RECTA_HPP
#define __RECTA_CPP

#include <iostream>
#include "Coordenada2D.hpp"
#include "Pendiente.hpp"

using namespace std;

namespace algoritmia
{
	class Recta
	{
	private:
		Coordenada2D _inicio;
		Pendiente _pendiente;

		/** @brief Trata de mover un Coordenada2D con una pendiente lo maximo posible hacia la
			izquierda y lo maximo posible hacia arriba
			@param Coordenada2D El Coordenada2D a mover
			@param pendiente La pendiente de la recta a seguir
			@return El nuevo Coordenada2D al comienzo de la recta **/
		Coordenada2D moverAlInicio(const Coordenada2D &Coordenada2D, const Pendiente &pendiente) const;

	public:
		/** @brief Constructor vacio **/
		Recta();

		/** @brief Constructor de la recta que pasa por dos Coordenada2Ds
			@param A Primer Coordenada2D por el que debe de pasar la recta
			@param B Segundo Coordenada2D por el que debe pasar la recta **/
		Recta(const Coordenada2D &A, const Coordenada2D &B);

		/** @brief Constructor de copia **/
		Recta(const Recta &r);

		/** @brief Establece la recta que pasa por dos Coordenada2Ds dados **/
		void establecerRecta(const Coordenada2D &A, const Coordenada2D &B);

		/** @brief Devuelve el valor que tendria Y al darle X a la recta
			@param X el valor de la abscisa X
			@warning La recta no puede ser vertical cuando se usa este metodo
			@return Un valor que indica el valor de Y **/
		double getY(const double &X) const;

		/** @brief Devuelve el valor que tendria X al darle Y a la recta
			@param Y el valor del eje Y
			@warning La recta no puede ser horizontal cuando se usa este metodo
			@return Un valor que indica el valor de la X **/
		double getX(const double &Y) const;

		/** @brief Devuelve el Coordenada2D inicial almacenado por la recta **/
		Coordenada2D getCoordenada2DInicial() const;

		/** @brief Devuelve la pendiente de la recta **/
		Pendiente getPendiente() const;

		/** @brief Comprueba si la recta almacenada es vertical
			@return TRUE si la recta es vertical y FALSE en caso contrario **/
		bool esVertical() const;

		/** @brief Comprueba si la recta almacenada es horizontal
			@return TRUE si la recta es horizontal y FALSE en caso contrario **/
		bool esHorizontal() const;

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

		/** @brief Destructor **/
		~Recta();
	};
}

#endif