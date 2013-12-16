#ifndef __Punto_HPP
#define __Punto_HPP

#include <iostream>

using namespace std;

namespace algoritmia
{
	class Punto
	{
	private:
		unsigned int _row;
		unsigned int _col;

	public:
		/** @brief Constructor de la clase Punto **/
		Punto(const unsigned int &row = 0, const unsigned int &col = 0);

		/** @brief Constructor de copia **/
		Punto(const Punto &p);

		/** @brief Establece la Punto en un punto determinado
		 	@param row Indica la fila donde se situara
		 	@param col Indica la columna donde se situara **/
		void setPunto(const unsigned int &row = 0, const unsigned int &col = 0);

		/** @brief Devuelve la fila almacenada **/
		unsigned int getRow() const;

		/** @brief Devuelve la columna almacenada **/
		unsigned int getCol() const;

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