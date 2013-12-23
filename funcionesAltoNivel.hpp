#ifndef __FUNCIONES_ALTO_NIVEL_P6_ALGORITMIA
#define __FUNCIONES_ALTO_NIVEL_P6_ALGORITMIA

#include <list>
#include "Punto.hpp"

using namespace std;

/** @brief Muestra un menu con las opciones del programa **/
int menu();

/** @brief Muestra una lista de puntos por pantalla **/
void showPuntos(const list<Punto> &l);

#endif