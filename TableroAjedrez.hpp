#ifndef __TABLERO_AJEDREZ_HPP
#define __TABLERO_AJEDREZ_HPP

#include <string>
#include <vector>
#include <list>
#include "Posicion.hpp"
#include "FichaAjedrez.hpp"

using namespace std;

namespace algoritmia
{
	class TableroAjedrez
	{
	private:
		unsigned int _rows;
		unsigned int _cols;
		vector<vector<FichaAjedrez> > _tablero;

	public:
		/** @brief Constructor por defecto, que inicializa el tablero en blanco con el tamaño
		           actual del ajedrez **/
		TableroAjedrez();

		/** @brief Constructor del tablero del ajedrez que inicializa a un tamaño predeterminado
		           el tablero **/
		TableroAjedrez(const unsigned int rows, const unsigned int cols);

		/** @brief Constructor de copia **/
		TableroAjedrez(const TableroAjedrez &table);

		/** @brief Consulta si hay alguna ficha en la posicion indicada
		    @param rows Indica la fila donde debe de estar la ficha (empezando por cero)
		    @param cols Indica la columna donde debe de estar la ficha (empezando por cero)
		    @return Un valor booleano indicando si esta (TRUE) o si no hay ficha (FALSE) **/
	    bool hayFicha(const unsigned int &row, const unsigned int &col) const;

	    /** @brief Consulta si hay alguna ficha en la posicion indicada
	    	@param p Posicion donde se deseea buscar la ficha
	    	@return Un valor booleano indicando si esta la ficha (TRUE) o ni no esta (FALSE) **/
    	bool hayFicha(const Posicion &p) const;

	    /** @brief Devuelve la ficha que se encuentra en la posicion elegida
	    	@param row Indica la fila donde debe de estar la ficha (empezando por cero)
	    	@param col Indica la columna donde debe de estar la ficha (empezando por cero)
	    	@return enum CLASE_FICHA que representa dicha ficha **/
	    enum CLASE_FICHA getEnumFicha(const unsigned int &row, const unsigned int &col) const;

	    /** @brief Devuelve la ficha que se encuentra en la posicion elegida
	    	@param p Posicion donde se debe encontrar la ficha
	    	@return enum CLASE_FICHA  que representa dicha ficha **/
    	enum CLASE_FICHA getEnumFicha(const Posicion &p) const;

	    /** @brief Devuelve la ficha que se encuentra en la posicion elegida
	        @param row Indica la fila donde debe de esta la ficha (empezando por cero)
	        @param col Indica la columna donde debe de estar la ficha (empezando por cero)
	        @return Una FichaAjedrez de la posicion adecuada **/
        FichaAjedrez getFicha(const unsigned int &row, const unsigned int &col) const;

        /** @brief Devuelve la ficha que se encuentra en la posicion indicada
        	@param p La posicion que deseas obtener la ficha
        	@return Una FichaAjedrez de la posicion indicada **/
    	FichaAjedrez getFicha(const Posicion &p) const;

        /** @brief Devuelve si la posicion elegida esta amenazada por otra ficha (De momento solo esta implementada la reina)
        	@param row Indica la fila a evaluar
        	@param col Indica la columna a evaluar
        	@return Un valor booleano que indica que dicha posicion esta amenazada por otra ficha (TRUE) o no (FALSE) **/
        bool amenaza(const unsigned int &row, const unsigned int &col) const;

        /** @brief Devuelve si la posicion elegida esta amenazada por otra ficha (De momento solo esta implementada la reina)
        	@param p Posicion
        	@return Un valor booleano que indica que dicha posicion esta amenazada por otra ficha (TRUE) o no (FALSE) **/
    	bool amenaza(const Posicion &p) const;

        /** @brief Muestra por pantalla donde estan situadas cada una de las ficha del tablero **/
        void detail() const;

        /** @brief Devuelve el numero de filas del tablero **/
        unsigned int getRows() const;

        /** @brief Devuelve el numero de columnas del tablero **/
        unsigned int getCols() const;

        /** @brief Establece el tamaño del tablero
         	@param rows Indica el numero de filas
         	@param cols Indica el numero de columnas **/
     	void setTablero(const unsigned int &rows, const unsigned int &cols);

     	/** @brief Coloca una ficha en la posicion indicada
     		@param row Fila donde establecer la ficha
     		@param col Columan donde establecer la ficha
     		@param f Ficha a establecer **/
 		void setFicha(const unsigned int &row, const unsigned int &col, const FichaAjedrez &f);

 		/** @brief Coloca una ficha en la posicion indicada
 			@param p Posicion donde deseas insertar la ficha
 			@param f Ficha de ajedrez a insertar **/
		void setFicha(const Posicion &p, const FichaAjedrez &f);

 		/** @brief Coloca una ficha en la posicion indicada
 			@param row Fila donde establecer la ficha
 			@param col Columna donde establecer la ficha
 			@param e Enumeracion que representa la ficha a establecer **/
		void setFicha(const unsigned int &row, const unsigned int &col, const enum CLASE_FICHA &e);

		/** @brief Coloca una ficha en la posicion indicada
			@param p Posicion donde deseas insertar la ficha
			@param e Enumeracion que representa la ficha a establecer **/
		void setFicha(const Posicion &p, const enum CLASE_FICHA &e);

		/** @brief Borra una ficha del tablero
			@param row Fila donde se encuentra la ficha a borrar
			@param columna donde se encuentra la ficha a borrar
			@return Devuelve un valor booleano que indica que en la posicion indicada habia una ficha y fue borrada (TRUE) o que
			no habia ninguna ficha y por tanto no se borro nada (FALSE) **/
		bool borrarFicha(const unsigned int &row, const unsigned int &col);

		/** @brief Borra una ficha del tablero
			@param p Posicion de la que deseas borrar la ficha
			@return Devuelve un valor booleano que indica que en la posicion indicada habia una ficha y fue borrada (TRUE) o que
			no habia ninguna ficha y por tanto no se borro nada (FALSE) **/
		bool borrarFicha(const Posicion &p);
		~TableroAjedrez();
	};
}

#endif