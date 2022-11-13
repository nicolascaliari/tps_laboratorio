#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "Controller.h"
#include "Seleccion.h"

Jugador* jug_new()
{
	Jugador* pJugador;

	pJugador =(Jugador*)malloc(sizeof(Jugador));

	if(pJugador != NULL)
	{
		jug_setId(pJugador, 0);
		jug_setNombreCompleto(pJugador, " ");
		jug_setEdad(pJugador, 0);
		jug_setPosicion(pJugador, " ");
		jug_setNacionalidad(pJugador, " ");
		jug_setIdSeleccion(pJugador, 0);
	}
	return pJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador *nuevoJugador = jug_new();

	if(nuevoJugador != NULL && idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL)
	{
		if(!(jug_setId(nuevoJugador, atoi(idStr)) &&
			jug_setNombreCompleto(nuevoJugador, nombreCompletoStr) &&
			jug_setEdad(nuevoJugador, atoi(edadStr)) &&
			jug_setPosicion(nuevoJugador, posicionStr) &&
			jug_setNacionalidad(nuevoJugador, nacionalidadStr) &&
			jug_setIdSeleccion(nuevoJugador,atoi(idSelccionStr))))
		{
			jug_delete(nuevoJugador);
			nuevoJugador = NULL;
		}
	}
	return nuevoJugador;
}


void jug_delete(Jugador* this)
{
	if(this != NULL)
	{
		free(this);
	}
}



// set y get
int jug_setId(Jugador* this,int id)
{
	int retorno = 0;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}

int jug_getId(Jugador* this,int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}


int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = 0;
	if(this != NULL && nombreCompleto != NULL)
	{
		strncpy(this->nombreCompleto, nombreCompleto, 100);
		retorno = 1;
	}
	return retorno;
}


int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = 0;
	if(this != NULL && nombreCompleto != NULL)
	{
		strncpy(nombreCompleto,this->nombreCompleto,100);
		retorno = 1;
	}
	return retorno;
}


int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = 0;
	if(this != NULL && posicion != NULL)
	{
		strncpy(this->posicion, posicion,30);
		retorno = 1;
	}
	return retorno;
}


int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno = 0;
	if(this != NULL && posicion != NULL)
	{
		strncpy(posicion, this->posicion, 30);
		retorno = 1;
	}
	return retorno;
}


int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = 0;
	if(this != NULL && nacionalidad != NULL)
	{
		strncpy(this->nacionalidad, nacionalidad , 30);
		retorno = 1;
	}
	return retorno;
}


int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = 0;
	if(this != NULL && nacionalidad != NULL)
	{
		strncpy(nacionalidad, this->nacionalidad,30);
		retorno = 1;
	}
	return retorno;
}


int jug_setEdad(Jugador* this,int edad)
{
	int retorno = 0;
	if(this != NULL && edad > 1)
	{
		this->edad = edad;
		retorno = 1;
	}
	return retorno;
}

int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = 0;
	if(this != NULL && edad != NULL)
	{
		*edad = this->edad;
		retorno = 1;
	}
	return retorno;
}


int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno = 0;
	if(this != NULL && idSeleccion >= 0)
	{
		this->idSeleccion = idSeleccion;
		retorno = 1;
	}
	return retorno;
}


int jug_getIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = 0;
	if(this != NULL && idSeleccion > 0)
	{
		*idSeleccion = this->idSeleccion;
		retorno = 1;
	}
	return retorno;
}



int idAutoincremental()
{
	static int idJugador;
	static int bandera=0;
	char auxId[1000];

	if(bandera== 0)
	{
		if(controllerCargarId("ID.csv", auxId) == 0)
		{
			bandera = 1;
			idJugador = atoi(auxId);
		}
	}

	idJugador++;


	return idJugador;
}



/*
 * \brief Imprime empleado
 * \param * a la lista de empleados, index a imprimir
 * \return 0 si funciono, -1 si hubo un error
 */

int imprimirJugador(LinkedList* pArrayListaJugadores , int indice)
{
	int retorno = -1;
	int auxiliarId;
	char auxiliarNombreCompleto[100];
	int auxiliarEdad;
	char auxiliarPosicion[30];
	char auxiliarNacionalidad[30];
	Jugador* pJugador =NULL;

	 if(pArrayListaJugadores != NULL && indice >= 0 && indice < ll_len(pArrayListaJugadores))
	 {
		pJugador = (Jugador*)ll_get(pArrayListaJugadores, indice);

		if(pJugador != NULL)
		{
	        if(jug_getId(pJugador, &auxiliarId)
	        && jug_getNombreCompleto(pJugador, auxiliarNombreCompleto)
	        && jug_getEdad(pJugador, &auxiliarEdad)
	        && jug_getPosicion(pJugador, auxiliarPosicion)
	        && jug_getNacionalidad(pJugador, auxiliarNacionalidad))
	        {
	        	printf("|%10d | %20s | %10d | %20s | %10s |\n", auxiliarId, auxiliarNombreCompleto, auxiliarEdad, auxiliarPosicion,auxiliarNacionalidad);
	        	retorno  = 0;
	        }
		}
	 }
	 return retorno;
}



int imprimirJugadorConSelec(LinkedList* pArrayListaJugadores, LinkedList* pArrayListaSeleccion, int indice)
{
	int retorno = -1;
	int auxiliarId;
	char auxiliarNombreCompleto[100];
	int auxiliarEdad;
	char auxiliarPosicion[30];
	char auxiliarNacionalidad[30];
	int auxiliarIdSeleccion;
	Jugador* pJugador =NULL;
	char seleccion[50];

	 if(pArrayListaJugadores != NULL && indice >= 0 && indice < ll_len(pArrayListaJugadores))
	 {
		pJugador = (Jugador*)ll_get(pArrayListaJugadores, indice);

		if(pJugador != NULL)
		{
	        if(jug_getId(pJugador, &auxiliarId)
	        && jug_getNombreCompleto(pJugador, auxiliarNombreCompleto)
	        && jug_getEdad(pJugador, &auxiliarEdad)
	        && jug_getPosicion(pJugador, auxiliarPosicion)
	        && jug_getNacionalidad(pJugador, auxiliarNacionalidad)
			&& jug_getIdSeleccion(pJugador, &auxiliarIdSeleccion))
	        {
	        	encontrarSeleccionString(pArrayListaSeleccion, auxiliarIdSeleccion, seleccion);
	        	printf("|%10d | %20s | %10d | %20s | %10s |  %10s  |\n", auxiliarId, auxiliarNombreCompleto, auxiliarEdad, auxiliarPosicion,auxiliarNacionalidad, seleccion);
		        retorno  = 0;
	        }
		}
	 }
	 return retorno;
}



int encontrarjugador(LinkedList* pArrayListaJugadores, int indice)
{
	int retorno =-1;
	int idJugador;
	Jugador* pJugador;
	int i;

	if(pArrayListaJugadores != NULL && indice >=0)
	{

	for(i= 0 ; i < ll_len(pArrayListaJugadores); i++)
	{
		pJugador = (Jugador*)ll_get(pArrayListaJugadores, i);

		jug_getId(pJugador, &idJugador);

			if(idJugador == indice)
			{
				retorno = ll_indexOf(pArrayListaJugadores, pJugador);
				break;
			}
		}
	}
	return retorno;
}




int jug_ordenarPorEdad(void* elementoA, void* elementoB)
{
	int retorno = -1;
	Jugador* pJugadorA;
	Jugador* pJugadorB;

	pJugadorA = (Jugador*)elementoA;
	pJugadorB = (Jugador*)elementoB;

	 if((*pJugadorA).edad > (*pJugadorB).edad)
	    {
	        retorno = 1;
	    }
	    else if((*pJugadorA).edad < (*pJugadorB).edad)
	    {
	        retorno = -1;
	    }
	 return retorno;
}



int jug_ordenarPorNacionalidad(void* elementoA, void* elementoB)
{
	int retorno = -1;
	Jugador* pJugadorA;
	Jugador* pJugadorB;

	pJugadorA = (Jugador*)elementoA;
	pJugadorB = (Jugador*)elementoB;

	 if(strncmp(pJugadorA->nacionalidad, pJugadorB->nacionalidad, 50) > 0 )
	    {
	        retorno = 1;
	    }
	    else if(strncmp(pJugadorA->nacionalidad, pJugadorB->nacionalidad, 50) < 0)
	    {
	        retorno = -1;
	    }
	 return retorno;
}

int jug_ordenarPorNombre(void* elementoA, void* elementoB)
{
	int retorno = -1;
	Jugador* pJugadorA;
	Jugador* pJugadorB;

	pJugadorA = (Jugador*)elementoA;
	pJugadorB = (Jugador*)elementoB;

	 if(strncmp(pJugadorA->nombreCompleto, pJugadorB->nombreCompleto, 50) > 0 )
	    {
	        retorno = 1;
	    }
	    else if(strncmp(pJugadorA->nombreCompleto, pJugadorB->nombreCompleto, 50) < 0)
	    {
	        retorno = -1;
	    }
	 return retorno;
}

