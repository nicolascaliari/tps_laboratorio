#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "Controller.h"
#include "Seleccion.h"
#include "Validaciones.h"


/**
 * \brief Reserva espacio en memoria para el tipo de dato Jugador.
 * \param void
 * \return Puntero a Jugador.
**/
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


/**
 * \brief Setea los datos en los campos.
 * \param 6 punteros a char.
 * \return Puntero a jugador.
**/
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

/**
 * \brief Libera el espacio en memoria de un tipo de dato Jugador.
 * \param Puntero a Jugador
 * \return void.
**/
void jug_delete(Jugador* this)
{
	if(this != NULL)
	{
		free(this);
	}
}



/**
 * \brief Carga un dato de tipo int en el campo id de jugador.
 * \param puntero a jugador
 * \param int
 * \return int 1 Bien, 0 ERROR.
**/
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

/**
 * \brief Consigue un dato de tipo int en el campo id de jugador.
 * \param puntero a jugador
 * \param puntero a int
 * \return int 1 Bien, 0 ERROR.
**/
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

/**
 * \brief Carga un dato de tipo char en el campo nombreCompleto de jugador.
 * \param puntero a jugador
 * \param puntero a char
 * \return int 1 Bien, 0 ERROR.
**/
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

/**
 * \brief Consigue un dato de tipo char en el campo nombreCompleto de jugador.
 * \param puntero a jugador
 * \param puntero a char
 * \return int 1 Bien, 0 ERROR.
**/
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

/**
 * \brief Carga un dato de tipo char en el campo posicion de jugador.
 * \param puntero a jugador
 * \param puntero a char
 * \return int 1 Bien, 0 ERROR.
**/
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

/**
 * \brief Consigue un dato de tipo char en el campo posicion de jugador.
 * \param puntero a jugador
 * \param puntero a char
 * \return int 1 Bien, 0 ERROR.
**/
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

/**
 * \brief Carga un dato de tipo char en el campo nacionalidad de jugador.
 * \param puntero a jugador
 * \param puntero a char
 * \return int 1 Bien, 0 ERROR.
**/
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

/**
 * \brief Consigue un dato de tipo char en el campo nacionalidad de jugador.
 * \param puntero a jugador
 * \param puntero a char
 * \return int 1 Bien, 0 ERROR.
**/
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

/**
 * \brief Carga un dato de tipo int en el campo edad de jugador.
 * \param puntero a jugador
 * \param int
 * \return int 1 Bien, 0 ERROR.
**/
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

/**
 * \brief Consigue un dato de tipo int en el campo edad de jugador.
 * \param puntero a jugador
 * \param puntero a int
 * \return int 1 Bien, 0 ERROR.
**/
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


/**
 * \brief Carga un dato de tipo int en el campo idSeleccion de jugador.
 * \param puntero a jugador
 * \param int
 * \return int 1 Bien, 0 ERROR.
**/
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


/**
 * \brief Consigue un dato de tipo int en el campo idSeleccion de jugador.
 * \param puntero a jugador
 * \param puntero a int
 * \return int 1 Bien, 0 ERROR.
**/
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



/**
 * \brief Autoincremente el id
 * \param VOID
 * \return retorna el id
**/
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
 * \brief Imprime jugador
 * \param puntero a Linkedlist
 * \param int
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


/**
 * \brief Imprimi jugador con la seleccion en string.
 * \param Puntero a LinkedList
 * \param Puntero a Linkedlist
 * \param int
 * \return 0 si funciono, -1 si hubo un error
**/
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


/**
 * \brief Chequea la existencia de jugador.
 * \param Puntero a Linkedlist
 * \param int
 * \return -1 error, si encuentra retorna el indice.
**/
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


int elegirPosicion(char *Pposicion)
{
	int retorno = -1;
	int elegir;

	if(utn_getNumero(&elegir, "\nElegir la posicion del jugador"
								"\n1-Portero"
								"\n2-Defensa central"
								"\n3-Lateral izquierdo"
								"\n4-Lateral derecho"
								"\n5-Pivote"
								"\n6-Mediocentro"
								"\n7-Medio centro ofensivo"
								"\n8-Extremo izquierdo"
								"\n9-Extremo derecho"
								"\n10-Mediapunta"
								"\n11-Delantero centro"
								"\n12-Interior derecho"
								"\n13-Interior izquierdo", "\nError", 1, 13, 2) == 0)
	{
		retorno = 0;

		switch(elegir)
		{
		case 1:
			strncpy(Pposicion , "Portero" , 30);
			break;
		case 2:
			strncpy(Pposicion , "Defensa central" , 30);
			break;
		case 3:
			strncpy(Pposicion , "Lateral izquierdo" , 30);
			break;
		case 4:
			strncpy(Pposicion , "Lateral derecho" , 30);
			break;
		case 5:
			strncpy(Pposicion , "Pivote" , 30);
			break;
		case 6:
			strncpy(Pposicion , "Mediocentro" , 30);
			break;
		case 7:
			strncpy(Pposicion , "Mediocentro ofensivo" , 30);
			break;
		case 8:
			strncpy(Pposicion , "Extremo izquierdo" , 30);
			break;
		case 9:
			strncpy(Pposicion , "Extremo derecho" , 30);
			break;
		case 10:
			strncpy(Pposicion , "Mediapunta" , 30);
			break;
		case 11:
			strncpy(Pposicion , "Delantero derecho" , 30);
			break;
		case 12:
			strncpy(Pposicion , "Interior derecho" , 30);
			break;
		case 13:
			strncpy(Pposicion , "Interior izquierdo" , 30);
			break;


		}
	}

	return retorno;
}



int elegirNacionalidad(char *Pnacionalidad)
{
	int retorno = -1;
	int elegir;

	if(utn_getNumero(&elegir, "\nElegir la posicion del jugador"
								"\n1-Argentino"
								"\n2-Brasilero"
								"\n3-Uruguayo"
								"\n4-Portugues"
								"\n5-Ingles"
								"\n6-Aleman"
								"\n7-Mexicano"
								"\n8-Estado Unidense"
								"\n9-Camerunes"
								"\n10-Senegales"
								"\n11-Australiano"
								"\n12-Qatari"
								, "\nError", 1, 12, 2) == 0)
	{
		retorno = 0;

		switch(elegir)
		{
		case 1:
			strncpy(Pnacionalidad , "Argentino" , 30);
			break;
		case 2:
			strncpy(Pnacionalidad , "Brasilero" , 30);
			break;
		case 3:
			strncpy(Pnacionalidad , "Uruguayo" , 30);
			break;
		case 4:
			strncpy(Pnacionalidad , "Portugues" , 30);
			break;
		case 5:
			strncpy(Pnacionalidad , "Ingles" , 30);
			break;
		case 6:
			strncpy(Pnacionalidad , "Aleman" , 30);
			break;
		case 7:
			strncpy(Pnacionalidad , "Mexicano" , 30);
			break;
		case 8:
			strncpy(Pnacionalidad , "Estado Unidense" , 30);
			break;
		case 9:
			strncpy(Pnacionalidad , "Camerunes" , 30);
			break;
		case 10:
			strncpy(Pnacionalidad , "Senegales" , 30);
			break;
		case 11:
			strncpy(Pnacionalidad , "Australiano" , 30);
			break;
		case 12:
			strncpy(Pnacionalidad , "Qatari" , 30);
			break;
		}
	}

	return retorno;
}





/**
 * \brief selecciona dos punteros y evalua cual es mayor.
 * \param puntero a void, puntero a void
 * \return 0 error, retorna 1 o -1 dependiendo el ordenamiento
**/
int jug_ordenarPorEdad(void* elementoA, void* elementoB)
{
	int retorno = 0;
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


/**
 * \brief selecciona dos punteros y evalua cual es mayor.
 * \param puntero a void, puntero a void
 * \return 0 error, retorna 1 o -1 dependiendo el ordenamiento
**/
int jug_ordenarPorNacionalidad(void* elementoA, void* elementoB)
{
	int retorno = 0;
	Jugador* pJugadorA;
	Jugador* pJugadorB;
	char nacionalidad_uno[30];
	char nacionalidad_dos[30];
	pJugadorA = (Jugador*)elementoA;
	pJugadorB = (Jugador*)elementoB;

	jug_getNacionalidad(pJugadorA, nacionalidad_uno);
	jug_getNacionalidad(pJugadorB, nacionalidad_dos);

	 if(strcmp(nacionalidad_uno, nacionalidad_dos) > 0 )
	    {
	        retorno = 1;
	    }
	    else if(strcmp(nacionalidad_uno, nacionalidad_dos) < 0)
	    {
	        retorno = -1;
	    }
	 return retorno;
}


/**
 * \brief selecciona dos punteros y evalua cual es mayor.
 * \param puntero a void, puntero a void
 * \return 0 error, retorna 1 o -1 dependiendo el ordenamiento
**/
int jug_ordenarPorNombre(void* elementoA, void* elementoB)
{
	int retorno = 0;
	Jugador* pJugadorA;
	Jugador* pJugadorB;
	char nombre_uno[30];
	char nombre_dos[30];

	pJugadorA = (Jugador*)elementoA;
	pJugadorB = (Jugador*)elementoB;

	jug_getNombreCompleto(pJugadorA, nombre_uno);
	jug_getNombreCompleto(pJugadorB, nombre_dos);


	 if(strcmp(nombre_uno, nombre_dos) > 0 )
	    {
	        retorno = 1;
	    }
	    else if(strcmp(nombre_uno, nombre_dos) < 0)
	    {
	        retorno = -1;
	    }
	 return retorno;
}

