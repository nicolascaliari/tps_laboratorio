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
#define OK 1

int main(void) {
	eJugador arrayJugadores[CANTIDAD_JUGADOR];
	eConfederacion arrayConfederaciones[CANTIDAD_CONFEDERACIONES];
	hardcodeoConfederacion(arrayConfederaciones,CANTIDAD_CONFEDERACIONES);

	 eJugador jugadoresTest[15]={
	       {1,"Emiliano Martinez","ARQUERO",1,100,100000,4,OK},
	       {2,"Juan Musso","ARQUERO",12,100,80000,2,OK},
	       {3,"Leo Messi","DELANTERO",10,100,80000,4,OK},
	       {4,"Almirez Ali","DELANTERO",9,100,55000,1,OK},
	       {5,"Harry Maguire","DEFENSOR",2,101,70000,4,OK},
	       {6,"Eric Dier","DEFENSOR",3,101,60000,2,OK},
	       {7,"Harry Kane","DELANTERO",10,101,3000,2,OK},
	       {8,"Alfred Gomis","ARQUERO",1,101,9000,1,OK},
	       {9,"Abdelkarim Hassan","MEDIOCAMPISTA",8,101,48000,1,OK},
	       {10,"Guillermo Ochoa","ARQUERO",1,104,90000,4,OK},
	       {11,"Tecatito","DELANTERO",11,104,100000,3,OK},
	       {12,"Luis Romo","MEDIOCAMPISTA",7,104,100000,2,OK},
	       {13,"Bamba Dieng ","DELANTERO",9,103,100000,2,OK},
	       {14,"Demba Seck","DELANTERO",11,103,6000,2,OK},
	       {15,"Tarek Salman","DEFENSOR",6,102,78000,5,OK}
	   };


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
//				if(bandera == 1)
//				{
					if(menuInformes(jugadoresTest, arrayConfederaciones, CANTIDAD_JUGADOR, CANTIDAD_CONFEDERACIONES) == 0)
					{
						printf("Salio todo bien");
					}
//				}else
//				{
//					printf("\nAntes de ingresar al menu de informes debe dar un alta");
//				}
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
