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
#define CANTIDAD_CONFEDERACIONES 20


int main(void) {
	eJugador arrayJugadores[CANTIDAD_JUGADOR];
	eConfederacion arrayConfederaciones[CANTIDAD_CONFEDERACIONES];
	hardcodeoConfederacion(arrayConfederaciones,CANTIDAD_CONFEDERACIONES);

	if(inicializar_array(arrayJugadores, CANTIDAD_JUGADOR) == 0
		&& inicializar_array_confederacion(arrayConfederaciones, CANTIDAD_CONFEDERACIONES) == 0
		&&  menuJugador(arrayJugadores, arrayConfederaciones, CANTIDAD_JUGADOR, CANTIDAD_CONFEDERACIONES)==0)
	{
		printf("Todo salio bien");
	}else
	{
		printf("Algo salio mal");
	}
	return EXIT_SUCCESS;
}
