#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Salida_datos.h"
#include "Jugador.h"
#include "Confederacion.h"
#include "Validaciones.h"


int hardcodeoConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int retorno = -1;
	if(arrayConfederacion != NULL && limiteConfederacion > 0)
	{
		arrayConfederacion[0].id = 100;
		strncpy(arrayConfederacion[0].nombre, "CONMEBOL", 50);
		strncpy(arrayConfederacion[0].region, "SUDAMERICA", 50);
		arrayConfederacion[0].anioCreacion = 1916;


		arrayConfederacion[1].id = 101;
		strncpy(arrayConfederacion[1].nombre, "UEFA", 50);
		strncpy(arrayConfederacion[1].region, "SUDAMERICA", 50);
		arrayConfederacion[1].anioCreacion = 1916;

		arrayConfederacion[2].id = 102;
		strncpy(arrayConfederacion[2].nombre, "AFC", 50);
		strncpy(arrayConfederacion[2].region, "ASIA", 50);
		arrayConfederacion[2].anioCreacion = 1954;


		arrayConfederacion[3].id = 103;
		strncpy(arrayConfederacion[3].nombre, "CAF", 50);
		strncpy(arrayConfederacion[3].region, "AFRICA", 50);
		arrayConfederacion[3].anioCreacion = 1957;


		arrayConfederacion[4].id = 104;
		strncpy(arrayConfederacion[4].nombre, "CONCACAF", 50);
		strncpy(arrayConfederacion[4].region, "NORTE Y CENTRO AMERICA", 50);
		arrayConfederacion[4].anioCreacion = 1961;


		arrayConfederacion[5].id = 105;
		strncpy(arrayConfederacion[5].nombre, "OFC", 50);
		strncpy(arrayConfederacion[5].region, "OCEANIA", 50);
		arrayConfederacion[5].anioCreacion = 1966;
	}

	return retorno;
}




int pedirConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int opcion;

	if(arrayConfederacion != NULL && limiteConfederacion > 0)
	{
		mostrarConfederacion(arrayConfederacion, limiteConfederacion);
		utn_getNumero(&opcion, "\nIngrese el ID de la confederacion que desea", "Error", 100, 105, 2);
	}
	return opcion;
}


int mostrarConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int retorno = -1;
	int i;

	if(arrayConfederacion != NULL && limiteConfederacion > 0)
	{
		retorno = 0;
		printf("  id   descripcion");
		for( i = 0; i < limiteConfederacion ; i++)
		{
			printf("\n%d		%s		%s		%d" , arrayConfederacion[i].id, arrayConfederacion[i].nombre, arrayConfederacion[i].region, arrayConfederacion[i].anioCreacion);
		}
	}
	return retorno;
}



int buscarConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion, int id,char *pConfederacion)
{
	int retorno = -1;
	int i;

	if(arrayConfederacion != NULL && limiteConfederacion > 0 && id > 0 && pConfederacion != NULL)
	{
		for(i = 0; i < limiteConfederacion; i++)
		{
			if(arrayConfederacion[i].id == id)
			{
				strncpy(pConfederacion , arrayConfederacion[i].nombre, 50);
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}


int buscarRegion(eConfederacion arrayConfederacion[], int limiteConfederacion, int id,char *pConfederacion)
{
	int retorno = -1;
	int i;

	if(arrayConfederacion != NULL && limiteConfederacion > 0 && id > 0 && pConfederacion != NULL)
	{
		for(i = 0; i < limiteConfederacion; i++)
		{
			if(arrayConfederacion[i].id == id)
			{
				strncpy(pConfederacion , arrayConfederacion[i].region, 50);
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
