#ifndef __TABLERO_AJEDREZ_HPP
#define __TABLERO_AJEDREZ_HPP

#include <string>
#include <vector>
#include <list>
#include "Punto.hpp"
#include "FichaAjedrez.hpp"

using namespace std;

namespace algoritmia
{
	class TableroAjedrez
	{
	private:
		unsigned int _dimension; //!< Indica la dimension del tablero (que es de tamaño Dimension x Dimension)
		vector<vector<FichaAjedrez> > _tablero; //!< El tablero en si de ajedrez

		/** @brief Devuelve la lista de movimientos posibles por una ficha determinada en una Punto del juego
			@param p Punto de inicio de la ficha
			@param f Ficha a mover
			@return Una lista en formato list<Punto> que indica todas las posibles direcciones que puede tomar **/
		list<Punto> listaMovimientos(const Punto &p, const FichaAjedrez &f) const;

		/** @brief Devuelve la lista de todos los movimientos que puede hacer la reina
			@param p Punto de inicio de la reina
			@return list<Punto> con cada uno de los puntos a donde podria llegar la reina **/
		list<Punto> listaMovimientosReina(const Punto &p) const;

	public:
		/** @brief Constructor por defecto, que inicializa el tablero en blanco con el tamaño
		           actual del ajedrez **/
		TableroAjedrez();

		/** @brief Constructor del tablero del ajedrez que inicializa a un tamaño predeterminado
		           el tablero **/
		TableroAjedrez(const unsigned int &dimension);

		/** @brief Constructor de copia **/
		TableroAjedrez(const TableroAjedrez &table);

		/** @brief Consulta si hay alguna ficha en la Punto indicada
		    @param rows Indica la fila donde debe de estar la ficha (empezando por cero)
		    @param cols Indica la columna donde debe de estar la ficha (empezando por cero)
		    @return Un valor booleano indicando si esta (TRUE) o si no hay ficha (FALSE) **/
	    bool hayFicha(const unsigned int &row, const unsigned int &col) const;

	    /** @brief Consulta si hay alguna ficha en la Punto indicada
	    	@param p Punto donde se deseea buscar la ficha
	    	@return Un valor booleano indicando si esta la ficha (TRUE) o ni no esta (FALSE) **/
    	bool hayFicha(const Punto &p) const;

	    /** @brief Devuelve la ficha que se encuentra en la Punto elegida
	    	@param row Indica la fila donde debe de estar la ficha (empezando por cero)
	    	@param col Indica la columna donde debe de estar la ficha (empezando por cero)
	    	@return enum CLASE_FICHA que representa dicha ficha **/
	    enum CLASE_FICHA getEnumFicha(const unsigned int &row, const unsigned int &col) const;

	    /** @brief Devuelve la ficha que se encuentra en la Punto elegida
	    	@param p Punto donde se debe encontrar la ficha
	    	@return enum CLASE_FICHA  que representa dicha ficha **/
    	enum CLASE_FICHA getEnumFicha(const Punto &p) const;

	    /** @brief Devuelve la ficha que se encuentra en la Punto elegida
	        @param row Indica la fila donde debe de esta la ficha (empezando por cero)
	        @param col Indica la columna donde debe de estar la ficha (empezando por cero)
	        @return Una FichaAjedrez de la Punto adecuada **/
        FichaAjedrez getFicha(const unsigned int &row, const unsigned int &col) const;

        /** @brief Devuelve la ficha que se encuentra en la Punto indicada
        	@param p La Punto que deseas obtener la ficha
        	@return Una FichaAjedrez de la Punto indicada **/
    	FichaAjedrez getFicha(const Punto &p) const;

        /** @brief Devuelve si la Punto elegida esta amenazada por otra ficha (De momento solo esta implementada la reina)
        	@param row Indica la fila a evaluar
        	@param col Indica la columna a evaluar
        	@return Un valor booleano que indica que dicha Punto esta amenazada por otra ficha (TRUE) o no (FALSE) **/
        bool amenaza(const unsigned int &row, const unsigned int &col) const;

        /** @brief Devuelve si la Punto elegida esta amenazada por otra ficha (De momento solo esta implementada la reina)
        	@param p Punto
        	@return Un valor booleano que indica que dicha Punto esta amenazada por otra ficha (TRUE) o no (FALSE) **/
    	bool amenaza(const Punto &p) const;

        /** @brief Muestra por pantalla donde estan situadas cada una de las ficha del tablero **/
        void detail() const;

        /** @brief Devuelve la dimension del tablero **/
        unsigned int getDimension() const;

        /** @brief Establece el tamaño del tablero
         	@param rows Indica el numero de filas
         	@param cols Indica el numero de columnas **/
     	void setTablero(const unsigned int &dimension);

     	/** @brief Coloca una ficha en la Punto indicada
     		@param row Fila donde establecer la ficha
     		@param col Columan donde establecer la ficha
     		@param f Ficha a establecer **/
 		void setFicha(const unsigned int &row, const unsigned int &col, const FichaAjedrez &f);

 		/** @brief Coloca una ficha en la Punto indicada
 			@param p Punto donde deseas insertar la ficha
 			@param f Ficha de ajedrez a insertar **/
		void setFicha(const Punto &p, const FichaAjedrez &f);

 		/** @brief Coloca una ficha en la Punto indicada
 			@param row Fila donde establecer la ficha
 			@param col Columna donde establecer la ficha
 			@param e Enumeracion que representa la ficha a establecer **/
		void setFicha(const unsigned int &row, const unsigned int &col, const enum CLASE_FICHA &e);

		/** @brief Coloca una ficha en la Punto indicada
			@param p Punto donde deseas insertar la ficha
			@param e Enumeracion que representa la ficha a establecer **/
		void setFicha(const Punto &p, const enum CLASE_FICHA &e);

		/** @brief Borra una ficha del tablero
			@param row Fila donde se encuentra la ficha a borrar
			@param columna donde se encuentra la ficha a borrar
			@return Devuelve un valor booleano que indica que en la Punto indicada habia una ficha y fue borrada (TRUE) o que
			no habia ninguna ficha y por tanto no se borro nada (FALSE) **/
		bool borrarFicha(const unsigned int &row, const unsigned int &col);

		/** @brief Borra una ficha del tablero
			@param p Punto de la que deseas borrar la ficha
			@return Devuelve un valor booleano que indica que en la Punto indicada habia una ficha y fue borrada (TRUE) o que
			no habia ninguna ficha y por tanto no se borro nada (FALSE) **/
		bool borrarFicha(const Punto &p);

		void puente() const;
	};
}

#endif