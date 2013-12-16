#ifndef __POSICION_HPP
#define __POSICION_HPP

#include <iostream>

using namespace std;

namespace algoritmia
{
	class Posicion
	{
	private:
		unsigned int _row;
		unsigned int _col;

	public:
		/** @brief Constructor de la clase Posicion **/
		Posicion(const unsigned int &row = 0, const unsigned int &col = 0);

		/** @brief Constructor de copia **/
		Posicion(const Posicion &p);

		/** @brief Establece la posicion en un punto determinado
		 	@param row Indica la fila donde se situara
		 	@param col Indica la columna donde se situara **/
		void setPosicion(const unsigned int &row = 0, const unsigned int &col = 0);

		/** @brief Devuelve la fila almacenada **/
		unsigned int getRow() const;

		/** @brief Devuelve la columna almacenada **/
		unsigned int getCol() const;

		void operator=(const Posicion &p);
		void operator+(const Posicion &p);
		void operator-(const Posicion &p);
		void operator*(const Posicion &p);
		void operator/(const Posicion &p);

		bool operator==(const Posicion &p) const;
		bool operator!=(const Posicion &p) const;
		bool operator<(const Posicion &p) const;
		bool operator<=(const Posicion &p) const;
		bool operator>(const Posicion &p) const;
		bool operator>=(const Posicion &p) const;

		friend ostream& operator<<(ostream &output, const Posicion &p);
		friend istream& operator>>(istream &input, Posicion &p); 

		~Posicion();
	};
}

#endif