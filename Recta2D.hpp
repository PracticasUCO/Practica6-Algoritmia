#ifndef __RECTA2D_HPP
#define __RECTA2D_CPP

#include <iostream>
#include "Coordenada2D.hpp"
#include "Pendiente.hpp"

using namespace std;

namespace algoritmia
{
	class Recta2D
	{
	private:
		Coordenada2D _inicio;
		Pendiente _pendiente;

		/** @brief Trata de mover un Coordenada2D con una pendiente lo maximo posible hacia la
			izquierda y lo maximo posible hacia arriba
			@param Coordenada2D El Coordenada2D a mover
			@param pendiente La pendiente de la Recta2D a seguir
			@return El nuevo Coordenada2D al comienzo de la Recta2D **/
		Coordenada2D moverAlInicio(const Coordenada2D &Coordenada2D, const Pendiente &pendiente) const;

	public:
		/** @brief Constructor vacio **/
		Recta2D();

		/** @brief Constructor de la Recta2D que pasa por dos Coordenada2Ds
			@param A Primer Coordenada2D por el que debe de pasar la Recta2D
			@param B Segundo Coordenada2D por el que debe pasar la Recta2D **/
		Recta2D(const Coordenada2D &A, const Coordenada2D &B);

		/** @brief Constructor de copia **/
		Recta2D(const Recta2D &r);

		/** @brief Establece la Recta2D que pasa por dos Coordenada2Ds dados **/
		void establecerRecta2D(const Coordenada2D &A, const Coordenada2D &B);

		/** @brief Devuelve el valor que tendria Y al darle X a la Recta2D
			@param X el valor de la abscisa X
			@warning La Recta2D no puede ser vertical cuando se usa este metodo
			@return Un valor que indica el valor de Y **/
		double getY(const double &X) const;

		/** @brief Devuelve el valor que tendria X al darle Y a la Recta2D
			@param Y el valor del eje Y
			@warning La Recta2D no puede ser horizontal cuando se usa este metodo
			@return Un valor que indica el valor de la X **/
		double getX(const double &Y) const;

		/** @brief Devuelve el Coordenada2D inicial almacenado por la Recta2D **/
		Coordenada2D getCoordenada2DInicial() const;

		/** @brief Devuelve la pendiente de la Recta2D **/
		Pendiente getPendiente() const;

		/** @brief Comprueba si la Recta2D almacenada es vertical
			@return TRUE si la Recta2D es vertical y FALSE en caso contrario **/
		bool esVertical() const;

		/** @brief Comprueba si la Recta2D almacenada es horizontal
			@return TRUE si la Recta2D es horizontal y FALSE en caso contrario **/
		bool esHorizontal() const;

		/** Copia la Recta2D **/
		void operator=(const Recta2D &r);

		bool operator==(const Recta2D &r);
		bool operator!=(const Recta2D &r);
		/** Las ordenaciones se hacen por pendiente **/
		bool operator<(const Recta2D &r);
		bool operator<=(const Recta2D &r);
		bool operator>(const Recta2D &r);
		bool operator>=(const Recta2D &r);

		friend ostream& operator<<(ostream& output, const Recta2D &r);
		friend istream& operator>>(istream& input, Recta2D &r);

		/** @brief Destructor **/
		~Recta2D();
	};
}

#endif