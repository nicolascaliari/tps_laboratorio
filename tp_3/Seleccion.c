#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"
#include "LinkedList.h"


/**
 * \brief Reserva espacio en memoria para el tipo de dato Seleccion.
 * \param void
 * \return direccion de memoria reservada Seleccion.
**/
Seleccion* selec_new()
{
	Seleccion* pSeleccion;

	pSeleccion  = (Seleccion*)malloc(sizeof(Seleccion)*1);

	if(pSeleccion != NULL)
	{
		pSeleccion->id = 0;
		strcpy(pSeleccion->pais," ");
		strcpy(pSeleccion->confederacion, " ");
		pSeleccion->convocados = 0;
	}
	return pSeleccion;
}


/**
 * \brief Setea los datos en los campos.
 * \param 4 punteros a char.
 * \return Puntero a Seleccion.
**/
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{

	Seleccion* pSeleccion = selec_new();

	if(pSeleccion != NULL)
	{
		if(!(selec_setConvocados(pSeleccion, atoi(convocadosStr))))
		{
			selec_delete(pSeleccion);
			pSeleccion =NULL;
		}else
		{
			pSeleccion->id = atoi(idStr);
			strcpy(pSeleccion->pais,paisStr);
			strcpy(pSeleccion->confederacion, confederacionStr);
		}

	}
	return pSeleccion;
}

/**
 * \brief Libera el espacio en memoria de un tipo de dato Seleccion.
 * \param Puntero a Seleccion
 * \return void.
**/
void selec_delete(Seleccion* this){

	if(this != NULL)
	{
		free(this);
	}
}



/**
 * \brief Consigue un dato de tipo int en el campo id de Seleccion.
 * \param puntero a Seleccion
 * \param Puntero a int
 * \return int 1 Bien, 0 ERROR.
**/
int selec_getId(Seleccion* this,int* id)
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
 * \brief Consigue un dato de tipo int en el campo pais de Seleccion.
 * \param puntero a Seleccion
 * \param Puntero a char
 * \return int 1 Bien, 0 ERROR.
**/
int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = 0;
	if(this != NULL && pais != NULL)
	{
		strcpy(pais, this->pais);
		retorno = 1;
	}
	return retorno;

}

/**
 * \brief Consigue un dato de tipo int en el campo confederacion de Seleccion.
 * \param puntero a Seleccion
 * \param Puntero a char
 * \return int 1 Bien, 0 ERROR.
**/
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = 0;
	if(this != NULL && confederacion != NULL)
	{
		strcpy(confederacion, this->confederacion);
		retorno = 1;
	}
	return retorno;
}


/**
 * \brief Carga un dato de tipo int en el campo convocados de Seleccion.
 * \param puntero a Seleccion
 * \param int
 * \return int 1 Bien, 0 ERROR.
**/
int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = 0;
	if(this != NULL && convocados <= 22)
	{
		this->convocados = convocados;
		retorno = 1;
	}
	return retorno;
}


/**
 * \brief Consigue un dato de tipo int en el campo convocados de Seleccion.
 * \param puntero a Seleccion
 * \param Puntero a int
 * \return int 1 Bien, 0 ERROR.
**/
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno = 0;
	if(this != NULL && convocados != NULL)
	{
		*convocados = this->convocados;
		retorno = 1;
	}
	return retorno;
}



/*
 * \brief Imprime Seleccion
 * \param puntero a Linkedlist
 * \param int
 * \return 0 si funciono, -1 si hubo un error
 */
int imprimirSeleccion(LinkedList* pArrayListaSelecciones, int indice)
{
	int retorno = -1;
	int auxiliarId;
	char auxiliarPais[30];
	char auxiliarConfederacion[30];
	int auxiliarConvocados;
	Seleccion* pSeleccion =NULL;

	 if(pArrayListaSelecciones != NULL && indice >= 0 && indice < ll_len(pArrayListaSelecciones))
	 {
		pSeleccion = (Seleccion*)ll_get(pArrayListaSelecciones, indice);

		if(pSeleccion != NULL)
		{
	        if(selec_getId(pSeleccion, &auxiliarId)
	        && selec_getPais(pSeleccion, auxiliarPais)
	        && selec_getConfederacion(pSeleccion, auxiliarConfederacion)
	        && selec_getConvocados(pSeleccion, &auxiliarConvocados))
	        {
	        	printf("|%10d | %20s | %10s | %20d  |\n", auxiliarId, auxiliarPais, auxiliarConfederacion, auxiliarConvocados);
	        	retorno  = 0;
	        }
		}
	 }
	 return retorno;
}


/**
 * \brief Chequea la existencia de Seleccion.
 * \param Puntero a Linkedlist
 * \param int
 * \return -1 error, si encuentra retorna el indice.
**/
int encontrarSeleccion(LinkedList* pArrayListaSelecciones, int indice)
{
	int retorno =-1;
	int idSeleccion;
	Seleccion* pSeleccion;
	int i;

	if(pArrayListaSelecciones != NULL && indice > 0)
	{

	for(i= 0 ; i < ll_len(pArrayListaSelecciones); i++)
	{
		pSeleccion = (Seleccion*)ll_get(pArrayListaSelecciones, i);

		selec_getId(pSeleccion, &idSeleccion);

			if(idSeleccion == indice)
			{
				retorno = ll_indexOf(pArrayListaSelecciones, pSeleccion);
				break;
			}
		}
	}
	return retorno;
}



/**
 * \brief Chequea la existencia de Seleccion.
 * \param Puntero a Linkedlist
 * \param int
 * \return -1 error, si encuentra retorna string en esa posicion.
**/

int encontrarSeleccionString(LinkedList *pArrayListSeleccion, int indice, char *Confederation)
{
	int retorno = -1;
	int limite;
	int auxiliarID;
	char auxiliarConfederation[30];
	Seleccion *pSeleccion = NULL;
	if (pArrayListSeleccion != NULL && Confederation != NULL && indice > 0)
	{
		limite = ll_len(pArrayListSeleccion);
		if (limite > 0)
		{
			for (int i = 0; i < limite; i++)
			{
				pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
				if (pSeleccion != NULL)
				{
					if (selec_getId(pSeleccion, &auxiliarID) == 1)
					{
						if (auxiliarID == indice && selec_getPais(pSeleccion, auxiliarConfederation) == 1)
						{
							strcpy(Confederation, auxiliarConfederation);
							retorno = 0;
							break;
						}
					}
				}
			}
		}
	}
	return retorno;
}


/**
 * \brief Encuentra el string de la confederacion que se pasa por indice.
 * \param Puntero a Linkedlist
 * \param int
 * \param puntero a char
 * \return -1 error, si encuentra retorna el indice.
**/
int encontrarConfederacion(LinkedList *pArrayListSeleccion, int indice, char *Confederation)
{
	int retorno = -1;
	int limite;
	int auxiliarID;
	char auxiliarConfederation[30];
	Seleccion *pSeleccion = NULL;
	if (pArrayListSeleccion != NULL && Confederation != NULL && indice > 0)
	{
		limite = ll_len(pArrayListSeleccion);
		if (limite > 0)
		{
			for (int i = 0; i < limite; i++)
			{
				pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
				if (pSeleccion != NULL)
				{
					if (selec_getId(pSeleccion, &auxiliarID) == 1)
					{
						if (auxiliarID == indice && selec_getConfederacion(pSeleccion, auxiliarConfederation) == 1)
						{
							strcpy(Confederation, auxiliarConfederation);
							retorno = 0;
						}
					}
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief selecciona dos punteros y evalua cual es mayor.
 * \param puntero a void, puntero a void
 * \return 0 error, retorna 1 o -1 dependiendo el ordenamiento
**/
int selec_ordenarPorConfederacion(void* elementoA, void* elementoB)
{
	int retorno = 0;
	Seleccion* pSeleccionA;
	Seleccion* pSeleccionB;
	char confederacion_uno[30];
	char confederacion_dos[30];

	pSeleccionA = (Seleccion*)elementoA;
	pSeleccionB = (Seleccion*)elementoB;

	selec_getConfederacion(pSeleccionA, confederacion_uno);
	selec_getConfederacion(pSeleccionB, confederacion_dos);

	 if(strcmp(confederacion_uno, confederacion_dos) > 0 )
	    {
	        retorno = 1;
	    }
	    else if(strcmp(confederacion_uno, confederacion_dos) < 0)
	    {
	        retorno = -1;
	    }
	 return retorno;
}
