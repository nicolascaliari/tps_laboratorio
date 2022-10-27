/*
 ============================================================================
 Name        : tp_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Salida_datos.h"
#include "Jugador.h"
#include "Confederacion.h"
#include "Validaciones.h"


#define CANTIDAD_JUGADOR 100
#define CANTIDAD_CONFEDERACIONES 6


int main(void) {
	eJugador arrayJugadores[CANTIDAD_JUGADOR];
	eConfederacion arrayConfederaciones[CANTIDAD_CONFEDERACIONES];
	inicializar_array(arrayJugadores, CANTIDAD_JUGADOR);
	hardcodeoConfederacion(arrayConfederaciones,CANTIDAD_CONFEDERACIONES);

	menuJugador(arrayJugadores, arrayConfederaciones, CANTIDAD_JUGADOR, CANTIDAD_CONFEDERACIONES);
	return EXIT_SUCCESS;
}
