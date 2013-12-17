#ifndef __Punto_HPP
#define __Punto_HPP

#include <iostream>

using namespace std;

namespace algoritmia
{
	class Punto
	{
	private:
		double _X;
		double _Y;

	public:
		/** @brief Constructor de la clase Punto **/
		Punto(const double &X = 0, const double &Y = 0);

		/** @brief Constructor de copia **/
		Punto(const Punto &p);

		/** @brief Establece la Punto en un punto determinado
		 	@param X Indica la posicion X
		 	@param Y Indica la posicion Y **/
		void setPunto(const double &X = 0, const double &Y = 0);

		/** @brief Devuelve la coordenada X **/
		double getX() const;

		/** @brief Devuelve la coordenada Y **/
		double getY() const;

		void operator=(const Punto &p);
		Punto operator+(const Punto &p) const;
		Punto operator-(const Punto &p) const;
		Punto operator*(const Punto &p) const;
		Punto operator/(const Punto &p) const;

		bool operator==(const Punto &p) const;
		bool operator!=(const Punto &p) const;
		bool operator<(const Punto &p) const;
		bool operator<=(const Punto &p) const;
		bool operator>(const Punto &p) const;
		bool operator>=(const Punto &p) const;

		friend ostream& operator<<(ostream &output, const Punto &p);
		friend istream& operator>>(istream &input, Punto &p); 
	};
}

#endif