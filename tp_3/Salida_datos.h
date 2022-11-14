/*
 * Salida_datos.h
 *
 *  Created on: 7 nov. 2022
 *      Author: nicolas
 */

#ifndef SALIDA_DATOS_H_
#define SALIDA_DATOS_H_

int menuListar(LinkedList* listaJugadores, LinkedList* listaSelecciones);
int menuListar_ordenar(LinkedList* listaJugadores, LinkedList* listaSelecciones);
int menuConvocarJugadores(LinkedList* listaJugadores, LinkedList* listaSelecciones);
int menu_guardar_JugadoresBinario(LinkedList* listaJugadores, LinkedList* listaSelecciones);
int menu_cargar_JugadoresBinario(LinkedList* listaJugadores, LinkedList* listaSelecciones);
#endif /* SALIDA_DATOS_H_ */
