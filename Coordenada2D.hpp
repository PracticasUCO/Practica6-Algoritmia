#ifndef __Coordenada2D_HPP
#define __Coordenada2D_HPP

#include <iostream>

using namespace std;

namespace algoritmia
{
	class Coordenada2D
	{
	private:
		double _X;
		double _Y;

	public:
		/** @brief Constructor de la clase Coordenada2D **/
		Coordenada2D(const double &X = 0, const double &Y = 0);

		/** @brief Constructor de copia **/
		Coordenada2D(const Coordenada2D &p);

		/** @brief Establece la Coordenada2D en un punto determinado
		 	@param X Indica la posicion X
		 	@param Y Indica la posicion Y **/
		void setCoordenada2D(const double &X = 0, const double &Y = 0);

		/** @brief Devuelve la Coordenada2D X **/
		double getX() const;

		/** @brief Devuelve la Coordenada2D Y **/
		double getY() const;

		void operator=(const Coordenada2D &p);
		Coordenada2D operator+(const Coordenada2D &p) const;
		Coordenada2D operator-(const Coordenada2D &p) const;
		Coordenada2D operator*(const Coordenada2D &p) const;
		Coordenada2D operator/(const Coordenada2D &p) const;

		bool operator==(const Coordenada2D &p) const;
		bool operator!=(const Coordenada2D &p) const;
		bool operator<(const Coordenada2D &p) const;
		bool operator<=(const Coordenada2D &p) const;
		bool operator>(const Coordenada2D &p) const;
		bool operator>=(const Coordenada2D &p) const;

		friend ostream& operator<<(ostream &output, const Coordenada2D &p);
		friend istream& operator>>(istream &input, Coordenada2D &p); 

		/** @brief Destructor de clase **/
		~Coordenada2D();
	};
}

#endif