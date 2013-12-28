#ifndef __BIG_DECIMAL_HPP
#define __BIG_DECIMAL_HPP

#include <string>

using namespace std;

namespace numbers
{
	class BigDecimal
	{
	private:
		string _bigDecimal; //!< Representa el numero en formato cadena de texto

	public:
		/** @brief Constructor vacio de clase, crea un BigDecimal = 0.0 */
		BigDecimal();

		/** @brief Constructor parametrizado de clase
			@param f Numero en punto flotante a ser convertido **/
		BigDecimal(const float &f);

		/** @brief Constructor parametrizado de clase
		   	@param d Numero double a ser convertido **/
		BigDecimal(const double &d);

		/** @brief Constructor parametrizado de clase
			@param ld Numero long double a ser convertido **/
		BigDecimal(const long double &ld);

		/** @brief Constructor parametrizado de clase
			@param s Cadena a introduccir el numero **/
		BigDecimal(const string &s);

		/** @brief Constructor de copia
			@param BD Instancia de BigDecimal a copiar **/
		BigDecimal(const BigDecimal &BD);

		/** @brief Establece el numero de la clase a través de un numero
			@param f Flotante que se quiere almacenar
			@return Un valor booleano indicando que se pudo realizar la operacion (True) o que indica fallo (False)**/
		bool setNumber(const float &f);

		/** @brief Establece el numero de la clase a través de un numero
			@param d Double que se quiere almacenar
			@return Un valor booleano indicando que se pudo realizar la operacion (True) o que indica un fallo (False) **/
		bool setNumber(const double &d);

		/** @brief Establece el numero de la clase a través de un numero
			@param ld Long double que se desea almacenar
			@return Un valor booleano indicando que se pudo realizar la operacion (True) o que  indica un fallo (False) **/
		bool setNumber(const long double &ld);

		/** @brief Establece el numero de la clase a través de un numero
			@param s Cadena a introduccir
			@return Un valor booleano indicando que se pudo realizar la operacion (True) o que indica un fallo (False) **/
		bool setNumber(const string &s);

		/** @brief Devuelve la cadena almacenada
			@return Un string que representa al numero almacenado **/
		string toString() const;

		/** @brief Comprueba si el numero sobrepasa el limite superior establecido para los flotantes 
			@return Un valor booleano que indica que sobrepasa dicho valor por encima (TRUE) o que no lo hace (False) **/
		bool isGreeterThanFloat() const;

		/** @brief Comprueba si el numero sobrepasa el limite inferior establecido para los flotantes
			@return Un valor booleano que indica que sobrepasa dicho limite por debajo (True) o que no lo hace (False) **/
		bool isLowerThanFloat() const;

		/** @brief Comprueba si el numero almacenado se encuentra dentro de los limites establecidos para los flotantes
			@return Un valor booleano que indica que se encuentra dentro de los limites establecidos (True) o que no esta (False) **/
		bool isFloat() const;

		/** @brief Comprueba si el numero sobrepasa el limite superior establecido para los doubles
			@return Un valor booleano que indica que se sobrepasa dicho valor por encima (True) o que no lo hace (False) **/
		bool isGreeterThanDouble() const;

		/** @brief Comprueba si el numero sobrepasa el limite inferior establecido para los doubles
			@return Un valor booleano que indica que se sobrepasa el limite por debajo (True) o que no lo hace (False) **/
		bool isLowerThanDouble() const;

		/** @brief Comprueba si el numero esta dentro de los limites inferior y/o superior establecidos para los doubles
			@return Un valor booleano que indica que esta dentro de los limites (True) o que no esta (False) **/
		bool isDouble() const;

		/** @brief Comprueba si el numero almacenado sobrepasa el limite superior establecido para los long doubles
			@return Un valor booleano que indica que sobrepasa dicho valor por encima (TRUE) o que no lo hace (FALSE) **/
		bool isGreeterThanLongDouble() const;

		/** @brief Comprueba si el numero almacenado sobrepasa el limite inferior establecido para los long double
			@return Un valor booleano que indica que sobrepasa dicho valor por debajo (True) o que no lo hace (False) **/
		bool isLowerThanLongDouble() const;

		/** @brief Comprueba que el numero almacenado esta dentro de los limites establecidos para los long double
			@return Un valor booleano que indica que el valor esta encuadrado dentro de los limites de un long double (True) o no (False) **/
		bool isLongDouble() const;

		/** @brief Devuelve el numero en formato flotante
			@pre El numero debe de estar dentro de los limites establecidos para los flotantes **/
		float toFloat() const;

		/** @brief Devuelve el numero en formato double
			@pre El numero debe de estar dentro de los limites establecidos para los doubles
			@return Un valor double con el numero almacenado **/
		double toDouble() const;

		/** @brief Devuelve el numero en formato long double
			@pre El numero debe de estar dentro de los limites establecidos para los doubles
			@return Un valor long double con el numero almacenado **/
		long double toLongDouble() const;

		/** @brief Realiza una clonacion del numero BigDecimal pasado **/
		void clone(const BigDecimal &bd);

		/** @brief Suma una cantidad al numero indicado **/
		void add(const string &s);
		void add(const double &d);
		void add(const float &f);
		void add(const long double &ld);
		void add(const BigDecimal &bd);

		/** @brief Resta una cantidad al numero indicado **/
		void deduct(const string &s);
		void deduct(const double &d);
		void deduct(const float &f);
		void deduct(const long double &ld);
		void deduct(const BigDecimal &bd);

		/** @brief Multiplica una cantidad al numero indicado **/
		void multiply(const string &s);
		void multiply(const double &d);
		void multiply(const float &f);
		void multiply(const long double &ld);
		void multiply(const BigDecimal &bd);

		/** @brief Divide una cantidad al numero indicado **/
		void divide(const string &s);
		void divide(const double &d);
		void divide(const float &f);
		void divide(const long double &ld);
		void divide(const BigDecimal &bd);

		/** @brief Eleva a una determinada cantidad el numero indicado **/
		void pow(const string &s);
		void pow(const double &s);
		void pow(const float &f);
		void pow(const long double &ld);
		void pow(const BigDecimal &bd);

		/** @brief Destructor de clase **/
		~BigDecimal();
	};
}

#endif