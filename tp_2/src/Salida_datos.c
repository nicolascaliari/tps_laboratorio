#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Jugador.h"
#include "Confederacion.h"
#include "Informes.h"


void menuJugador(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion)
{
	int opcion;
	int bandera = 0;
	int contador = 0;

	do
	{
		if(utn_getNumero(&opcion, "\n          Bienvenido al menu de jugadores"
									"\n1-Alta de jugador"
									"\n2-Baja de jugador"
									"\n3-Modificacion de jugador"
									"\n4-informes"
									"\n5-Salir", "Error ingrese las opciones que se muestran en el menu", 1, 6, 2)==0)
		{

			switch(opcion)
			{
			case 1:
				if(buscar_espacio_array(arrayJugador, limiteJugador) == 1)
				{
					if(alta_jugador(arrayJugador, arrayConfederacion, limiteJugador, limiteConfederacion) == 0)
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
				if(bandera == 1 && jugador_bajaArray(arrayJugador, arrayConfederacion ,limiteJugador, limiteConfederacion) == 0)
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
				if(bandera == 1 && jugador_modificarArray(arrayJugador, arrayConfederacion, limiteJugador, limiteConfederacion)==0)
				{
					printf("\nmodificacion dada con exito");
				}
				break;

			case 4:
				menuInformes(arrayJugador, arrayConfederacion, limiteJugador, limiteConfederacion);
				break;

			case 5:
				jugador_imprimirArray(arrayJugador, arrayConfederacion,limiteConfederacion);
				break;
			case 6:
				break;
			}
		}

	}while(opcion != 6);
}
