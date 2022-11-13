#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "Validaciones.h"


int menuListar(LinkedList* listaJugadores, LinkedList* listaSelecciones)
{
	int retorno = -1;
	int opcion;

	if(listaJugadores != NULL && listaSelecciones != NULL)
	{
		retorno = 0;

	do
	{
		if(utn_getNumero(&opcion, "\n          Menu de listados"
									"\n1-Listar todos los jugadores"
									"\n2-Listar todas las selecciones"
									"\n3-Listar jugadores convocados"
									"\n4-Salir y volver al menu principal"
									,"Error ingrese las opciones que se muestran en el menu", 1,4, 2)==0)
		{

			switch(opcion)
			{
			case 1:
				if(controller_listarJugadoresConSelec(listaJugadores,listaSelecciones) == 0)
				{
					printf("\nTodo ok");
				}
				break;
			case 2:
				if(controller_listarSelecciones(listaSelecciones) == 0)
				{
					printf("\nTodo ok");
				}
				break;
			case 3:
				if(controller_ListarConvocados(listaJugadores , listaSelecciones) == 0)
				{
					printf("\nTodo ok");
				}
				break;
			case 4:
				break;
		}
	}
	}while(opcion != 4);

}

	return retorno;
}

int menuOrdenarListar(LinkedList* listaJugadores, LinkedList* listaSelecciones)
{
	int retorno = -1;
	int opcion;

	if(listaJugadores != NULL && listaSelecciones != NULL)
	{
		retorno = 0;

	do
	{
		if(utn_getNumero(&opcion, "\n          Menu de ordenar y listar"
									"\n1-Jugadores por nacionalidad"
									"\n2-Selecciones por confederacion"
									"\n3-Jugadores por edad"
									"\n4-Jugadores por nombre"
									"\n5-Salir y volver al menu principal"
									,"Error ingrese las opciones que se muestran en el menu", 1,6, 2)==0)
		{

			switch(opcion)
			{
			case 1:
				if(ll_sort(listaJugadores, jug_ordenarPorNacionalidad, 1) == 0)
				{
					printf("\nSalio bien");
				}else
				{
					printf("\nSalio mal");
				}
				break;
			case 2:
				if(ll_sort(listaSelecciones, selec_ordenarPorConfederacion, 1) == 0)
				{
					printf("\nSalio bien");
				}else
				{
					printf("\nSalio mal");
				}
				break;
			case 3:
				if(ll_sort(listaJugadores, jug_ordenarPorEdad, 1) == 0)
				{
					printf("Ordenado correctamente\n");
				}
				else
				{
					printf("Hubo un error, reintente\n");
				}
				break;
			case 4:
				if(ll_sort(listaJugadores, jug_ordenarPorNombre, 1) == 0)
				{
					printf("Ordenado correctamente\n");
				}
				else
				{
					printf("Hubo un error, reintente\n");
				}
				break;
			case 5:
				break;
		}
	}
	}while(opcion != 5);

}

	return retorno;
}


int menuConvocarJugadores(LinkedList* listaJugadores, LinkedList* listaSelecciones)
{
	int retorno = -1;
	int opcion;

	if(listaJugadores != NULL && listaSelecciones != NULL)
	{
		retorno = 0;

	do
	{
		if(utn_getNumero(&opcion, "\n          Menu de convocacion"
									"\n1-Convocar jugador"
									"\n2-Quitar de la seleccion"
									"\n3-Salir y volver al menu principal"
									,"Error ingrese las opciones que se muestran en el menu", 1,3,2)==0)
		{

			switch(opcion)
			{
			case 1:
				controller_ConvocarJugadores(listaSelecciones, listaJugadores);
				break;
			case 2:
				quitarJugadorDeSeleccion(listaSelecciones, listaJugadores);
				break;
			case 3:
				break;
		}
	}
	}while(opcion != 3);

}

	return retorno;
}


int menuJugadoresBinario(LinkedList* listaJugadores, LinkedList* listaSelecciones)
{
	int retorno = -1;
	int opcion;
	char confederacion[30];

	if(listaJugadores != NULL && listaSelecciones != NULL)
	{
		retorno = 0;

	do
	{
		if(utn_getNumero(&opcion, "\n          Menu de convocacion"
									"\n1-Gnerar archivo binario de conmebol"
									"\n2-Quitar de la seleccion"
									"\n3-Salir y volver al menu principal"
									,"Error ingrese las opciones que se muestran en el menu", 1,3,2)==0)
		{

			switch(opcion)
			{
			case 1:
				strncpy(confederacion, "CONMEBOL", 30);
				if(controller_guardarJugadorPorConfederacionBinario("CONMEBOL.BIN", listaJugadores, listaSelecciones,confederacion ) == 0)
				{
					printf("\nSalio todo bien");
				}
				break;
			case 2:
				quitarJugadorDeSeleccion(listaSelecciones, listaJugadores);
				break;
			case 3:
				break;
		}
	}
	}while(opcion != 3);

}

	return retorno;
}
