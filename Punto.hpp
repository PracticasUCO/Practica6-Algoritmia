#ifndef __Punto_HPP
#define __Punto_HPP

#include <iostream>

using namespace std;

namespace algoritmia
{
	class Punto
	{
	private:
		unsigned int _X;
		unsigned int _Y;

	public:
		/** @brief Constructor de la clase Punto **/
		Punto(const unsigned int &X = 0, const unsigned int &Y = 0);

		/** @brief Constructor de copia **/
		Punto(const Punto &p);

		/** @brief Establece la Punto en un punto determinado
		 	@param X Indica la posicion X
		 	@param Y Indica la posicion Y **/
		void setPunto(const unsigned int &X = 0, const unsigned int &Y = 0);

		/** @brief Devuelve la fila almacenada **/
		unsigned int getX() const;

		/** @brief Devuelve la Yumna almacenada **/
		unsigned int getY() const;

		void operator=(const Punto &p);
		void operator+(const Punto &p);
		void operator-(const Punto &p);
		void operator*(const Punto &p);
		void operator/(const Punto &p);

		bool operator==(const Punto &p) const;
		bool operator!=(const Punto &p) const;
		bool operator<(const Punto &p) const;
		bool operator<=(const Punto &p) const;
		bool operator>(const Punto &p) const;
		bool operator>=(const Punto &p) const;

		friend ostream& operator<<(ostream &output, const Punto &p);
		friend istream& operator>>(istream &input, Punto &p); 

		~Punto();
	};
}

#endif