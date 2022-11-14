#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"
#include "LinkedList.h"

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

void selec_delete(Seleccion* this){

	if(this != NULL)
	{
		free(this);
	}
}



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


int encontrarSeleccionString(LinkedList* pArrayListaSeleccion, int indice, char* pSeleccion)
{
	int retorno =-1;
	int idSeleccion;
	Seleccion* pNuevoJugador;

	int i;

	if(pArrayListaSeleccion != NULL && pSeleccion != NULL && indice > 0)
	{

	for(i= 0 ; i < ll_len(pArrayListaSeleccion); i++)
	{
		pNuevoJugador = (Seleccion*)ll_get(pArrayListaSeleccion, i);

		selec_getId(pNuevoJugador, &idSeleccion);

			if(idSeleccion == indice)
			{
				retorno = ll_indexOf(pArrayListaSeleccion, pNuevoJugador);
				strncpy(pSeleccion , pNuevoJugador->pais, 50);
				break;
			}
		}
	}
	return retorno;
}




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


int selec_ordenarPorConfederacion(void* elementoA, void* elementoB)
{
	int retorno = -1;
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
