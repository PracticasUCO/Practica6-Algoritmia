#ifndef __TABLERO_AJEDREZ_HPP
#define __TABLERO_AJEDREZ_HPP

#include <string>
#include <vector>
#include <list>
#include "Coordenada2D.hpp"
#include "FichaAjedrez.hpp"

using namespace std;

namespace algoritmia
{
	class TableroAjedrez
	{
	private:
		unsigned int _dimension; //!< Indica la dimension del tablero (que es de tamaño Dimension x Dimension)
		vector<vector<FichaAjedrez> > _tablero; //!< El tablero en si de ajedrez

		/** @brief Devuelve la lista de todos los movimientos que puede hacer la reina
			@param p Coordenada2D de inicio de la reina
			@return list<Coordenada2D> con cada uno de los Coordenada2Ds a donde podria llegar la reina **/
		list<Coordenada2D> listaMovimientosReina(const Coordenada2D &p) const;

	public:
		/** @brief Constructor por defecto, que inicializa el tablero en blanco con el tamaño
		           actual del ajedrez **/
		TableroAjedrez();

		/** @brief Constructor del tablero del ajedrez que inicializa a un tamaño predeterminado
		           el tablero **/
		TableroAjedrez(const unsigned int &dimension);

		/** @brief Constructor de copia **/
		TableroAjedrez(const TableroAjedrez &table);

		/** @brief Consulta si hay alguna ficha en la Coordenada2D indicada
		    @param rows Indica la fila donde debe de estar la ficha (empezando por cero)
		    @param cols Indica la columna donde debe de estar la ficha (empezando por cero)
		    @return Un valor booleano indicando si esta (TRUE) o si no hay ficha (FALSE) **/
	    bool hayFicha(const unsigned int &row, const unsigned int &col) const;

	    /** @brief Consulta si hay alguna ficha en la Coordenada2D indicada
	    	@param p Coordenada2D donde se deseea buscar la ficha
	    	@return Un valor booleano indicando si esta la ficha (TRUE) o ni no esta (FALSE) **/
    	bool hayFicha(const Coordenada2D &p) const;

	    /** @brief Devuelve la ficha que se encuentra en la Coordenada2D elegida
	    	@param row Indica la fila donde debe de estar la ficha (empezando por cero)
	    	@param col Indica la columna donde debe de estar la ficha (empezando por cero)
	    	@return enum CLASE_FICHA que representa dicha ficha **/
	    enum CLASE_FICHA getEnumFicha(const unsigned int &row, const unsigned int &col) const;

	    /** @brief Devuelve la ficha que se encuentra en la Coordenada2D elegida
	    	@param p Coordenada2D donde se debe encontrar la ficha
	    	@return enum CLASE_FICHA  que representa dicha ficha **/
    	enum CLASE_FICHA getEnumFicha(const Coordenada2D &p) const;

	    /** @brief Devuelve la ficha que se encuentra en la Coordenada2D elegida
	        @param row Indica la fila donde debe de esta la ficha (empezando por cero)
	        @param col Indica la columna donde debe de estar la ficha (empezando por cero)
	        @return Una FichaAjedrez de la Coordenada2D adecuada **/
        FichaAjedrez getFicha(const unsigned int &row, const unsigned int &col) const;

        /** @brief Devuelve la ficha que se encuentra en la Coordenada2D indicada
        	@param p La Coordenada2D que deseas obtener la ficha
        	@return Una FichaAjedrez de la Coordenada2D indicada **/
    	FichaAjedrez getFicha(const Coordenada2D &p) const;

        /** @brief Devuelve si la Coordenada2D elegida esta amenazada por otra ficha (De momento solo esta implementada la reina)
        	@param row Indica la fila a evaluar
        	@param col Indica la columna a evaluar
        	@return Un valor booleano que indica que dicha Coordenada2D esta amenazada por otra ficha (TRUE) o no (FALSE) **/
        bool amenaza(const unsigned int &row, const unsigned int &col) const;

        /** @brief Devuelve si la Coordenada2D elegida esta amenazada por otra ficha (De momento solo esta implementada la reina)
        	@param p Coordenada2D
        	@return Un valor booleano que indica que dicha Coordenada2D esta amenazada por otra ficha (TRUE) o no (FALSE) **/
    	bool amenaza(const Coordenada2D &p) const;

        /** @brief Muestra por pantalla donde estan situadas cada una de las ficha del tablero **/
        void detail() const;

        /** @brief Devuelve la dimension del tablero **/
        unsigned int getDimension() const;

        /** @brief Establece la dimension del tablero
         	@param rows Indica el numero de filas
         	@param cols Indica el numero de columnas **/
     	void setDimension(const unsigned int &dimension);

     	/** @brief Coloca una ficha en la Coordenada2D indicada
     		@param row Fila donde establecer la ficha
     		@param col Columan donde establecer la ficha
     		@param f Ficha a establecer **/
 		void setFicha(const unsigned int &row, const unsigned int &col, const FichaAjedrez &f);

 		/** @brief Coloca una ficha en la Coordenada2D indicada
 			@param p Coordenada2D donde deseas insertar la ficha
 			@param f Ficha de ajedrez a insertar **/
		void setFicha(const Coordenada2D &p, const FichaAjedrez &f);

 		/** @brief Coloca una ficha en la Coordenada2D indicada
 			@param row Fila donde establecer la ficha
 			@param col Columna donde establecer la ficha
 			@param e Enumeracion que representa la ficha a establecer **/
		void setFicha(const unsigned int &row, const unsigned int &col, const enum CLASE_FICHA &e);

		/** @brief Coloca una ficha en la Coordenada2D indicada
			@param p Coordenada2D donde deseas insertar la ficha
			@param e Enumeracion que representa la ficha a establecer **/
		void setFicha(const Coordenada2D &p, const enum CLASE_FICHA &e);

		/** @brief Mueve una ficha del tablero a otra posicion. Si en la posicion de destino hay otra ficha
			esta desaparecera del tablero
			@param rowSource Indica la fila de origen
			@param colSource Indica la columna de origen
			@param rowDest Indica la fila de destino
			@param colDest Indica la columna de destino
			@warning Si la posicion de origen no tiene fichas, no se hace nada
			@return Un valor booleano indicando que se realizo el movimiento (TRUE) o que no se hizo nada (FALSE) **/
		bool moverFicha(const unsigned int &rowSource, const unsigned int &colSource, 
						const unsigned int &rowDest, const unsigned int &colDest);

		/** @brief Mueve una ficha del tablero a otra posicion. Si en la posicion de destino hay otra ficha
			esta desaparecera del tablero
			@param source Origen del movimiento
			@param dest Posicion a la que se movera la ficha
			@warning Si la posicion de origen no tiene fichas, no se hace nada
			@warning Si el movimiento no esta permitido, no se hara nada
			@return Un valor booleano indicando que se realizo el movimiento (TRUE) o que no se hizo nada (FALSE) **/
		bool moverFicha(const Coordenada2D &source, const Coordenada2D &dest);

		/** @brief Devuelve la lista de movimientos posibles por una ficha determinada en una Coordenada2D del juego
			@param p Coordenada2D de inicio de la ficha
			@param f Ficha a mover
			@return Una lista en formato list<Coordenada2D> que indica todas las posibles direcciones que puede tomar **/
		list<Coordenada2D> listaMovimientos(const Coordenada2D &p) const;

		/** @brief Borra una ficha del tablero
			@param row Fila donde se encuentra la ficha a borrar
			@param columna donde se encuentra la ficha a borrar
			@return Devuelve un valor booleano que indica que en la Coordenada2D indicada habia una ficha y fue borrada (TRUE) o que
			no habia ninguna ficha y por tanto no se borro nada (FALSE) **/
		bool borrarFicha(const unsigned int &row, const unsigned int &col);

		/** @brief Borra una ficha del tablero
			@param p Coordenada2D de la que deseas borrar la ficha
			@return Devuelve un valor booleano que indica que en la Coordenada2D indicada habia una ficha y fue borrada (TRUE) o que
			no habia ninguna ficha y por tanto no se borro nada (FALSE) **/
		bool borrarFicha(const Coordenada2D &p);

		/** @brief Borra el tablero completamente, eliminando todas las fichas **/
		void clear();

		/** @brief Devuelve una lista con todas las posiciones donde hay fichas **/
		list<Coordenada2D> listarFichas() const;

		/** @brief Sobrecarga del operador = **/
		void operator=(const TableroAjedrez &t);

		/** @brief Sobrecarga del operador == **/
		bool operator==(const TableroAjedrez &t) const;

		/** @brief Sobrecarga del operador != **/
		bool operator!=(const TableroAjedrez &t) const;

		bool operator<(const TableroAjedrez &t) const;
		bool operator<=(const TableroAjedrez &t) const;
		bool operator>(const TableroAjedrez &t) const;
		bool operator>=(const TableroAjedrez &t) const;

		/** @brief Destructor **/
		~TableroAjedrez();
	};
}

#endif