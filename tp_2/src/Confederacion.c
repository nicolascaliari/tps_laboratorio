#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Salida_datos.h"
#include "Jugador.h"
#include "Confederacion.h"
#include "Validaciones.h"

static int idConfederacion(void);
static int idConfederacion(void)
{
	static int idIncremental = 106;
	return idIncremental++;
}


/**
 * \brief Inicializa el array
 * \param arrayConfederacion Array de confederacion a ser actualizado
 * \param limiteConfederacion Limite del array de confederaciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int inicializar_array_confederacion(eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int retorno = -1;
	int i;
	if(arrayConfederacion != NULL && limiteConfederacion > 0)
	{
		retorno = 0;
		for(i = 6 ; i < limiteConfederacion; i++)
		{
			arrayConfederacion[i].isEmpty = 0;
		}
	}
	return retorno;
}

/**
 * \brief Carga los datos y da de alta una confederacion en una posicion del array
 * \param arrayConfederacion Array de tipo eConfederacion
 * \param limiteConfederacion Limite del array de confederacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int alta_confederacion(eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int retorno = -1;
	eConfederacion auxiliar;
	int indice;

	if(arrayConfederacion != NULL && limiteConfederacion > 0)
	{
		indice = buscar_espacio_libre_confederacion(arrayConfederacion, limiteConfederacion);

		if(indice != -1)
		{

			if(utn_getNombre(auxiliar.nombre, 50, "\nIngrese nombre de confederacion\n","\nERROR\n", 2) == 0
					&& utn_getNombre(auxiliar.region, 50,"Ingrese region de confederacion", "error", 2) == 0
					&& utn_getNumero(&auxiliar.anioCreacion,"Ingrese anio de creacion", "error", 1, 90, 2) == 0)
					{
				auxiliar.isEmpty = 1;
				auxiliar.id = idConfederacion();
				arrayConfederacion[indice] = auxiliar;
				retorno = 0;
			}

		}
	}
	return retorno;
}


/**
 * \brief Da de baja una confederacion ingresando su ID
 * \param arrayConfederacion Array de tipo eConfederacion
 * \param limiteConfederacion Limite del array de confederacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int confederacion_bajaArray(eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int retorno = -1;
	int id;
	int indice;

	if(arrayConfederacion != NULL && limiteConfederacion > 0)
	{

		mostrarConfederacion(arrayConfederacion, limiteConfederacion);

			if(utn_getNumero(&id, "\nIngrese el ID que desea dar de baja", "Error al ingresar un ID", 100, 200, 2)==0)
			{
				indice = buscar_id_confederacion(arrayConfederacion, limiteConfederacion, id);

				if(indice != -1)
				{
					arrayConfederacion[indice].isEmpty = 0;
					retorno = 0;
				}

			}
	}
	return retorno;
}



/**
 * \brief Modifico los datos de una variable de tipo eConfederacion seleccionado
 * \param arrayConfederacion Array de tipo eConfederacion
 * \param limiteConfederacion Limite del array de confederacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int confederacion_modificarArray(eConfederacion arrayConfederacion[],int limiteConfederacion)
{
	int retorno = -1;
	int id;
	int indice;
	int opcion;

	if(arrayConfederacion != NULL && limiteConfederacion > 0)
	{
		mostrarConfederacion(arrayConfederacion, limiteConfederacion);

		if(utn_getNumero(&id, "\nIngrese el ID que desea modificar", "\nError al ingresar el ID para modificar", 100, 200, 2) == 0)
		{
			indice = buscar_id_confederacion(arrayConfederacion, limiteConfederacion, id);

			if(indice != -1)
			{
				if(utn_getNumero(&opcion,"\nMenu para modificar recurso"
						"\n\n1.Ingrese 1 para modificar nombre del jugador"
						"\n2.Ingrese 2 para modificar la posicion del jugador"
						"\n3.Ingrese 3 para modificar el numero de camiseta"
						"\n4.Ingrese 4 para modificar el salario"
						"\n5.Ingrese 5 para modificar los anios de contrato",
						 "Error al elegir una opcion", 1, 5, 2) == 0)
				{
					switch(opcion)
					{
					case 1:
						utn_getNombre(arrayConfederacion[indice].nombre, 50, "\nIngrese el nuevo nombre", "Error al ingresar el nombre", 2);
						retorno = 0;
						break;
					case 2:
						utn_getNombre(arrayConfederacion[indice].region, 50, "\nIngrese la nueva posicion", "Error al ingresar la posicion", 2);
						retorno = 0;
						break;
					case 3:
						utn_getNumero(&arrayConfederacion[indice].anioCreacion, "\nIngrese el nuevo numero de camiseta", "Error al ingresar la camiseta", 1, 99, 2);
						retorno = 0;
						break;
					}
				}
			}
		}
	}
	return retorno;
}


/**
 * \brief Buscar primer posicion vacia
 * \param arrayConfederacion Array de eConfederacion
 * \param limiteConfederacion Limite del array de eConfederacion
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */

int buscar_espacio_libre_confederacion(eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int i;
	int retorno = -1;
	if(arrayConfederacion != NULL && limiteConfederacion > 0)
	{
		for(i = 0; i < limiteConfederacion; i++)
		{
			if(arrayConfederacion[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


/** \brief Busca un ID que sea igual al valorBuscado y devuelve la posicion en que se encuentra
 * \param arrayConfederacion Array de tipo eConfederacion
 * \param limiteConfederacion Limite del array de eConfederacion
 * \param valorBuscado variable de tipo INT
 * \return Retorna la posicion donde encontro la coincidencia, si no encuentra retorna -1
 */

int buscar_id_confederacion(eConfederacion arrayConfederacion[], int limiteConfederacion, int valorBuscado)
{
	int retorno = -1;
	int i;
	if(arrayConfederacion != NULL && limiteConfederacion > 0 && valorBuscado > 0)
	{
		for(i = 0; i < limiteConfederacion; i++)
		{
			if(arrayConfederacion[i].id == valorBuscado && arrayConfederacion[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


/**
 * \brief Hardcodea los campos de la estructura eConfederacion
 * \param arrayConfederacion Array de eConfederacion
 * \param limiteConfederacion Limite de arrayConfederacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int hardcodeoConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int retorno = -1;
	if(arrayConfederacion != NULL && limiteConfederacion > 0)
	{
		arrayConfederacion[0].id = 100;
		strncpy(arrayConfederacion[0].nombre, "CONMEBOL", 50);
		strncpy(arrayConfederacion[0].region, "SUDAMERICA", 50);
		arrayConfederacion[0].anioCreacion = 1916;
		arrayConfederacion[0].isEmpty = 1;


		arrayConfederacion[1].id = 101;
		strncpy(arrayConfederacion[1].nombre, "UEFA", 50);
		strncpy(arrayConfederacion[1].region, "EUROPA", 50);
		arrayConfederacion[1].anioCreacion = 1954;
		arrayConfederacion[1].isEmpty = 1;

		arrayConfederacion[2].id = 102;
		strncpy(arrayConfederacion[2].nombre, "AFC", 50);
		strncpy(arrayConfederacion[2].region, "ASIA", 50);
		arrayConfederacion[2].anioCreacion = 1954;
		arrayConfederacion[2].isEmpty = 1;


		arrayConfederacion[3].id = 103;
		strncpy(arrayConfederacion[3].nombre, "CAF", 50);
		strncpy(arrayConfederacion[3].region, "AFRICA", 50);
		arrayConfederacion[3].anioCreacion = 1957;
		arrayConfederacion[3].isEmpty = 1;


		arrayConfederacion[4].id = 104;
		strncpy(arrayConfederacion[4].nombre, "CONCACAF", 50);
		strncpy(arrayConfederacion[4].region, "NORTE Y CENTRO AMERICA", 50);
		arrayConfederacion[4].anioCreacion = 1961;
		arrayConfederacion[4].isEmpty = 1;


		arrayConfederacion[5].id = 105;
		strncpy(arrayConfederacion[5].nombre, "OFC", 50);
		strncpy(arrayConfederacion[5].region, "OCEANIA", 50);
		arrayConfederacion[5].anioCreacion = 1966;
		arrayConfederacion[5].isEmpty = 1;
	}

	return retorno;
}


/**
 * \brief Pide un ID y lo retorna
 * \param arrayConfederacion Array de eConfederacion
 * \param limiteConfederacion Limite de arrayConfederacion
 * \return Retorna el ID ingresado
 *
 */

int pedirConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int opcion = 0;

	if(arrayConfederacion != NULL && limiteConfederacion > 0)
	{
		mostrarConfederacion(arrayConfederacion, limiteConfederacion);
		utn_getNumero(&opcion, "\nIngrese el ID de la confederacion que desea", "Error", 100, 200, 2);
	}
	return opcion;
}



/**
 * \brief Muestra todos las confederaciones hardcodeados
 * \param arrayConfederacion Array de eConfederacion
 * \param limiteConfederacion Limite de arrayConfederacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int mostrarConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int retorno = -1;
	int i;
	hardcodeoConfederacion(arrayConfederacion, limiteConfederacion);
	if(arrayConfederacion != NULL && limiteConfederacion > 0)
	{
		retorno = 0;
		printf("       ID		      NOMBRE		         REGION	   		     ANIO");
		for( i = 0; i < limiteConfederacion ; i++)
		{
			if(arrayConfederacion[i].isEmpty == 1)
			{
				printf("\n%d		|%10s		 |%25s			|%10d|" , arrayConfederacion[i].id, arrayConfederacion[i].nombre, arrayConfederacion[i].region, arrayConfederacion[i].anioCreacion);
			}
		}
	}
	return retorno;
}

/**
 * \brief busca una confederacion comparando los id
 * \param arrayConfederacion Array de eConfederacion
 * \param limiteConfederacion Limite de arrayConfederacion
 * \param id variable de tipo int
 * \param pConfederacion puntero a char
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

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

/**
 * \brief busca una region comparando los id
 * \param arrayConfederacion Array de eConfederacion
 * \param limiteConfederacion Limite de arrayConfederacion
 * \param id variable de tipo int
 * \param pConfederacion puntero a char
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
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
