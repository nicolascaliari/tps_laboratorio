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

int menuListar_ordenar(LinkedList* listaJugadores, LinkedList* listaSelecciones)
{
	int retorno = -1;
	int opcion;

	if(listaJugadores != NULL && listaSelecciones != NULL)
	{
		retorno = 0;

	do
	{
		if(utn_getNumero(&opcion, "\n          Elegir que ordenar y listar"
									"\n1-Jugadores"
									"\n2-Selecciones"
									"\n3-Salir"
									,"Error ingrese las opciones que se muestran en el menu", 1,6, 2)==0)
		{

			switch(opcion)
			{
			case 1:
				if(controller_ordenarJugadores(listaJugadores) == 0)
				{
					printf("\nSalio bien");
				}else
				{
					printf("\nSalio mal");
				}
				break;
			case 2:
				if(controller_ordenarSelecciones(listaSelecciones) == 0)
				{
					printf("\nSalio bien");
				}else
				{
					printf("\nSalio mal");
				}
				break;
			case 3:
				break;
		}
	}
	}while(opcion != 3);

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


int menu_guardar_JugadoresBinario(LinkedList* listaJugadores, LinkedList* listaSelecciones)
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
									"\n1-Generar archivo binario de conmebol"
									"\n2-Generar archivo binario de afc"
									"\n3-Generar archivo binario de caf"
									"\n4-Generar archivo binario de cancacaf"
									"\n5-Generar archivo binario de uefa"
									"\n6-Salir"
									,"Error ingrese las opciones que se muestran en el menu", 1,6,2)==0)
		{

			switch(opcion)
			{
			case 1:
				strncpy(confederacion, "CONMEBOL", 30);
				if(controller_guardar_Jugador_Confederacion_Binario("CONMEBOL.bin", listaJugadores, listaSelecciones,confederacion ) == 0)
				{
					printf("\nSalio todo bien");
				}
				break;
			case 2:
				strncpy(confederacion, "AFC", 30);
				if(controller_guardar_Jugador_Confederacion_Binario("AFC.bien", listaJugadores, listaSelecciones,confederacion ) == 0)
				{
					printf("\nSalio todo bien");
				}
				break;
			case 3:
				strncpy(confederacion, "CAF", 30);
				if(controller_guardar_Jugador_Confederacion_Binario("CAF.bin", listaJugadores, listaSelecciones,confederacion ) == 0)
				{
					printf("\nSalio todo bien");
				}
				break;
			case 4:
				strncpy(confederacion, "CONCACAF", 30);
				if(controller_guardar_Jugador_Confederacion_Binario("CONCACAF.bin", listaJugadores, listaSelecciones,confederacion ) == 0)
				{
					printf("\nSalio todo bien");
				}
				break;
			case 5:
				strncpy(confederacion, "UEFA", 30);
				if(controller_guardar_Jugador_Confederacion_Binario("UEFA.bin", listaJugadores, listaSelecciones,confederacion ) == 0)
				{
					printf("\nSalio todo bien");
				}
				break;
			case 6:
				break;
		}
	}
	}while(opcion != 6);

}

	return retorno;
}



int menu_cargar_JugadoresBinario(LinkedList* listaJugadores, LinkedList* listaSelecciones)
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
									"\n1-Generar archivo binario de conmebol"
									"\n2-Generar archivo binario de afc"
									"\n3-Generar archivo binario de caf"
									"\n4-Generar archivo binario de cancacaf"
									"\n5-Generar archivo binario de uefa"
									"\n6-Salir"
									,"Error ingrese las opciones que se muestran en el menu", 1,6,2)==0)
		{

			switch(opcion)
			{
			case 1:
				strncpy(confederacion, "CONMEBOL", 30);
				if(controller_cargarJugador_Confederacion_Binario("CONMEBOL.bin", listaJugadores, listaSelecciones,confederacion ) == 0)
				{
					printf("\nSalio todo bien");
				}
				break;
			case 2:
				strncpy(confederacion, "AFC", 30);
				if(controller_cargarJugador_Confederacion_Binario("AFC.bien", listaJugadores, listaSelecciones,confederacion ) == 0)
				{
					printf("\nSalio todo bien");
				}
				break;
			case 3:
				strncpy(confederacion, "CAF", 30);
				if(controller_cargarJugador_Confederacion_Binario("CAF.bin", listaJugadores, listaSelecciones,confederacion ) == 0)
				{
					printf("\nSalio todo bien");
				}
				break;
			case 4:
				strncpy(confederacion, "CONCACAF", 30);
				if(controller_cargarJugador_Confederacion_Binario("CONCACAF.bin", listaJugadores, listaSelecciones,confederacion ) == 0)
				{
					printf("\nSalio todo bien");
				}
				break;
			case 5:
				strncpy(confederacion, "UEFA", 30);
				if(controller_cargarJugador_Confederacion_Binario("UEFA.bin", listaJugadores, listaSelecciones,confederacion ) == 0)
				{
					printf("\nSalio todo bien");
				}
				break;
			case 6:
				break;
		}
	}
	}while(opcion != 6);

}

	return retorno;
}
