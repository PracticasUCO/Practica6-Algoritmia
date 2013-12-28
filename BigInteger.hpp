#ifndef __BIG_INTEGER_HPP
#define __BIG_INTEGER_HPP

#include <string>

using namespace std;

namespace numbers
{
	class BigInteger
	{
	private:
		string _BigInteger; //!< Representa el numero en formato cadena de texto

	public:
		/** @brief Constructor vacio de clase, crea un BigInteger = 0 */
		BigInteger();

		/** @brief Constructor parametrizado de clase
			@param s Cadena a introduccir el numero **/
		BigInteger(const string &s);

		/** @brief Constructor de copia
			@param BD Instancia de BigInteger a copiar **/
		BigInteger(const BigInteger &BD);

		/** @brief Establece el numero de la clase a través de un numero
			@param s Cadena a introduccir
			@return Un valor booleano indicando que se pudo realizar la operacion (True) o que indica un fallo (False) **/
		bool setNumber(const string &s);

		/** @brief Devuelve la cadena almacenada
			@return Un string que representa al numero almacenado **/
		string toString() const;

		/** @brief Realiza una clonacion del numero BigInteger pasado **/
		void clone(const BigInteger &bd);

		/** @brief Suma una cantidad al numero indicado **/
		void add(const string &s);
		void add(const BigInteger &bd);

		/** @brief Resta una cantidad al numero indicado **/
		void deduct(const string &s);
		void deduct(const BigInteger &bd);

		/** @brief Multiplica una cantidad al numero indicado **/
		void multiply(const string &s);
		void multiply(const BigInteger &bd);

		/** @brief Divide una cantidad al numero indicado **/
		void divide(const string &s);
		void divide(const BigInteger &bd);

		/** @brief Eleva a una determinada cantidad el numero indicado **/
		void pow(const string &s);
		void pow(const BigInteger &bd);

		/** @brief Destructor de clase **/
		~BigInteger();
	};
}

#endif