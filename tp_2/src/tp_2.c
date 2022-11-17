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


#define CANTIDAD_JUGADOR 3000
#define CANTIDAD_CONFEDERACIONES 6


int main(void) {
	eJugador arrayJugadores[CANTIDAD_JUGADOR];
	eConfederacion arrayConfederaciones[CANTIDAD_CONFEDERACIONES];
	hardcodeoConfederacion(arrayConfederaciones,CANTIDAD_CONFEDERACIONES);


	int opcion;
	int bandera = 0;
	int contador = 0;

	if(inicializar_array(arrayJugadores, CANTIDAD_JUGADOR) == 0)
	{

	do
	{
		if(utn_getNumero(&opcion, "\n          Bienvenido al menu de jugadores"
									"\n1-Alta de jugador"
									"\n2-Baja de jugador"
									"\n3-Modificacion de jugador"
									"\n4-informes"
									"\n5-Salir", "Error ingrese las opciones que se muestran en el menu", 1,5, 2)==0)
		{

			switch(opcion)
			{
			case 1:
				if(buscar_espacio_array(arrayJugadores, CANTIDAD_JUGADOR) == 1)
				{
					if(alta_jugador(arrayJugadores, arrayConfederaciones, CANTIDAD_JUGADOR, CANTIDAD_CONFEDERACIONES) == 0)
					{
						printf("\nDado de alta exitosamente");
						bandera = 1;
						contador++;
					}else
					{
						printf("\nNo se pudo dar de alta");
					}

				}else
				{
					printf("\nNo hay mas espacio");
				}
				break;
			case 2:
				if(bandera == 1 && jugador_bajaArray(arrayJugadores, arrayConfederaciones ,CANTIDAD_JUGADOR, CANTIDAD_CONFEDERACIONES) == 0)
				{
					printf("\nDado de baja exitosamente");
					contador--;
					if(contador == 0)
					{
						bandera = 0;
					}
				}else
				{
					printf("\nNo se pudo dar de baja");
				}
				break;
			case 3:
				if(bandera == 1 && jugador_modificarArray(arrayJugadores, arrayConfederaciones, CANTIDAD_JUGADOR, CANTIDAD_CONFEDERACIONES)==0)
				{
					printf("\nmodificacion dada con exito");
				}else
				{
					printf("No se puede modificar");
				}
				break;

			case 4:
				if(bandera == 1)
				{
					if(menuInformes(arrayJugadores, arrayConfederaciones, CANTIDAD_JUGADOR, CANTIDAD_CONFEDERACIONES) == 0)
					{
						printf("Salio todo bien");
					}
				}else
				{
					printf("\nAntes de ingresar al menu de informes debe dar un alta");
				}
				break;

			case 5:
				if(utn_getNumero(&opcion, "Seguro que desea salir del programa? \n Para confirmar ingrese 6\n Para seguir en el menu ingrese 1", "Error al ingresar un numero", 1, 5, 2))
				{
					printf("Todo okey");
				}
				break;
			}
		}

	}while(opcion != 6);

}

	return EXIT_SUCCESS;
}
