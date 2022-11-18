#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Informes.h"
#include "Salida_datos.h"
#include "Jugador.h"
#include "Confederacion.h"
#include "Validaciones.h"


static int idJugador(void);
static int idJugador(void)
{
	static int idIncremental = 1;
	return idIncremental++;
}


/**
 * \brief Inicializa el array
 * \param arrayJugador Array de jugadores a ser actualizado
 * \param limiteJugador Limite del array de jugadores
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int inicializar_array(eJugador arrayJugador[], int limiteJugador)
{
	int retorno = -1;
	int i;
	if(arrayJugador != NULL && limiteJugador > 0)
	{
		retorno = 0;
		for(i = 0 ; i < limiteJugador; i++)
		{
			arrayJugador[i].isEmpty = 0;
		}
	}
	return retorno;
}



/**
 * \brief Imprime los datos de un jugador
 * \param unJugador variable de tipo eJugador
 * \param arrayConfederacion
 * \param limiteJugador
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int jugador_imprimir(eJugador unJugador, eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int retorno = -1;
	int i;
	if(unJugador.isEmpty == 1 && arrayConfederacion != NULL && limiteConfederacion > 0)
	{
		for(i = 0; i < limiteConfederacion; i++)
		{
			if(unJugador.idConfederacion == arrayConfederacion[i].id)
			{
				retorno = 0;
				printf("|%*d|%*s|%*s|%*d|%*.2f|%*s|%*d|\n", 2,unJugador.id,20,
						unJugador.nombre, 20, unJugador.posicion, 10, unJugador.numeroCamiseta, 11,
						unJugador.salario, 15, arrayConfederacion[i].nombre,10, unJugador.aniosContrato);
			}
		}
	}
	return retorno;
}


/**
 * \brief Imprime el array de jugador
 * \param arrayJugador Array de tipo eJugador
 * \param arrayConfederacion Array de tipo eConfederacion
 * \param limiteJugador Limite del array de jugador
 * \param limiteConfederacion Limite del array de confederacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int jugador_imprimirArray(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteConfederacion, int limiteJugador)
{
	int retorno = -1;
	int i;
	if(arrayJugador != NULL && arrayConfederacion != NULL && limiteConfederacion > 0)
	{
		retorno = 0;
		encabezadoJugadores();

		for(i = 0; i < limiteJugador; i++)
		{
			jugador_imprimir(arrayJugador[i], arrayConfederacion, limiteConfederacion);
		}
	}
	return retorno;
}

/**
 * \brief Carga los datos y da de alta un jugador en una posicion del array
 * \param arrayJugador Array de tipo eJugador
 * \param arrayConfederacion Array de tipo eConfederacion
 * \param limiteJugador Limite del array de jugador
 * \param limiteConfederacion Limite del array de confederacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int alta_jugador(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion)
{
	int retorno = -1;
	eJugador auxiliar;
	int indice;

	if(arrayJugador != NULL && limiteJugador > 0)
	{
		indice = buscar_espacio_libre(arrayJugador, limiteJugador);

		if(indice != -1)
		{

			if(utn_getNombre(auxiliar.nombre, 20, "\nIngrese su nombre, tiene 2 intentos\n","\nERROR\n", 2) == 0
					&& elegirPosicion(auxiliar.posicion) == 0
					&& utn_getNumeroShort(&auxiliar.numeroCamiseta,"Ingrese su numero de camiseta, tiene 2 intentos", "error", 1, 90, 2) == 0
					&& utn_getNumeroFlotante(&auxiliar.salario,"Ingrese su salario, tiene 2 intentos", "error", 1, 600000, 2) == 0
					&& utn_getNumeroShort(&auxiliar.aniosContrato,"Ingrese anios de contrato, tiene 2 intentos", "error", 1, 50, 2)== 0)
					{
				auxiliar.idConfederacion = pedirConfederacion(arrayConfederacion, limiteConfederacion);
				auxiliar.isEmpty = 1;
				auxiliar.id = idJugador();
				arrayJugador[indice] = auxiliar;
				retorno = 0;
			}

		}
	}
	return retorno;
}



/**
 * \brief Da de baja un jugador ingresando su ID
 * \param arrayJugador Array de tipo eJugador
 * \param arrayConfederacion Array de tipo eConfederacion
 * \param limiteJugador Limite del array de jugador
 * \param limiteConfederacion Limite del array de confederacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */


int jugador_bajaArray(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion)
{
	int retorno = -1;
	int id;
	int indice;

	if(arrayJugador != NULL && arrayConfederacion != NULL && limiteJugador > 0 && limiteConfederacion > 0)
	{

		jugador_imprimirArray(arrayJugador, arrayConfederacion, limiteConfederacion, limiteJugador);

			if(utn_getNumero(&id, "\nIngrese el ID que desea dar de baja, tiene 2 intentos", "Error al ingresar un ID", 1, 20, 2)==0)
			{
				indice = buscar_id(arrayJugador, limiteJugador, id);

				if(indice != -1)
				{
					arrayJugador[indice].isEmpty = 0;
					retorno = 0;
				}

			}else
			{
				printf("\nAgotaste los reintentos");
			}
	}
	return retorno;
}


/**
 * \brief Modifico los datos de una variable de tipo eJugador seleccionado
 * \param arrayJugador Array de tipo eJugador
 * \param arrayConfederacion Array de tipo eConfederacion
 * \param limiteJugador Limite del array de jugador
 * \param limiteConfederacion Limite del array de confederacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int jugador_modificarArray(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion)
{
	int retorno = -1;
	int id;
	int indice;
	int opcion;

	if(arrayJugador != NULL && arrayConfederacion != NULL && limiteJugador > 0 && limiteConfederacion > 0)
	{
		jugador_imprimirArray(arrayJugador, arrayConfederacion, limiteConfederacion , limiteJugador);

		if(utn_getNumero(&id, "\nIngrese el ID que desea modificar, tiene 2 intentos", "\nError al ingresar el ID para modificar", 1, 20, 2) == 0)
		{
			indice = buscar_id(arrayJugador, limiteJugador, id);

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
						utn_getNombre(arrayJugador[indice].nombre, 50, "\nIngrese el nuevo nombre", "Error al ingresar el nombre", 2);
						retorno = 0;
						break;
					case 2:
						utn_getNombre(arrayJugador[indice].posicion, 50, "\nIngrese la nueva posicion", "Error al ingresar la posicion", 2);
						retorno = 0;
						break;
					case 3:
						utn_getNumeroShort(&arrayJugador[indice].numeroCamiseta, "\nIngrese el nuevo numero de camiseta", "Error al ingresar la camiseta", 1, 99, 2);
						retorno = 0;
						break;
					case 4:
						utn_getNumeroFlotante(&arrayJugador[indice].salario, "\ningrese el nuevo salario", "Error al ingresar el salario", 1, 100000, 2);
						retorno = 0;
						break;
					case 5:
						utn_getNumeroShort(&arrayJugador[indice].aniosContrato, "\nIngrese la nueva cantidad de anios de contrato", "Error al ingresar la cantidad de anios de contrato", 1, 10, 2);
						retorno = 0;
						break;
					}
				}
			}
		}else
		{
			printf("\nAgotaste los reintentos");
		}
	}
	return retorno;
}


/**
 * \brief Buscar primer posicion vacia
 * \param arrayJugador Array de eJugador
 * \param limiteJugador Limite del array de eJugador
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */

int buscar_espacio_libre(eJugador arrayJugador[], int limiteJugador)
{
	int i;
	int retorno = -1;
	if(arrayJugador != NULL && limiteJugador > 0)
	{
		for(i = 0; i < limiteJugador; i++)
		{
			if(arrayJugador[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


/** \brief Busca un ID que sea igual al valorBuscado y devuelve la posicion en que se encuentra
 * \param arrayJugador Array de tipo eJugador
 * \param limiteJugador Limite del array de eJugador
 * \param valorBuscado variable de tipo INT
 * \return Retorna la posicion donde encontro la coincidencia, si no encuentra retorna -1
 */

int buscar_id(eJugador arrayJugador[], int limiteJugador, int valorBuscado)
{
	int retorno = -1;
	int i;
	if(arrayJugador != NULL && limiteJugador > 0 && valorBuscado > 0)
	{
		for(i = 0; i < limiteJugador; i++)
		{
			if(arrayJugador[i].id == valorBuscado && arrayJugador[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


/**
*\brief: Verifica que haya espacio para cargar un nuevo dato de tipo eJugador.
*\param: arrayJugador Array de tipo eJugador
*\param: limiteJugador Limite del array de eJugador
*\return: Retorna 1 si encuentra espacio, Retorna 0 si no lo encuentra.
**/

int buscar_espacio_array(eJugador arrayJugador[], int limitejugador)
{
	int retorno = 0;
	int i;
	if(arrayJugador != NULL && limitejugador > 0)
	{
		for(i = 0; i < limitejugador; i++)
		{
			if(arrayJugador[i].isEmpty == 0)
			{
				retorno = 1;

			}
		}
	}
	return retorno;
}


/**
 * \brief Permite elegir una posicion para el jugado.
 * \param Puntero a char
 * \return -1 error, si encuentra retorna el indice.
**/
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


/**
 * \brief Encabezado.
 * \param void
 * \return void
**/
void encabezadoJugadores(void) {
	printf("\n+-----------------------------------------------------------------------------------------------------+\n");
	printf("| %2s |%17s | %18s | %1s | %2s | %4s | %1s |\n","ID","NOMBRE","POSICION","N°CAMISETA","SUELDO","CONFEDERACION","AÑOS DE CONTRATO");
	printf("+-------------------------------------------------------------------------------------------------------+\n");
}



/**
 * \brief Permite elegir una posicion para el jugado.
 * \param  arrayJugador Array de tipo eJugador
 * \param limite de eJugador
 * \param id de confederacion
 * \param arrayConfederacion Array de tipo eConfederacion
 * \param limite de confederacion
**/
int listarJugadoresPorConfederacion(eJugador arrayJugador[], int limiteJugador, int idConfederacion, eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int retorno = -1;

	if(arrayJugador != NULL && limiteJugador > 0)
	{
		encabezadoJugadores();
		if(ordenarJugadoresporId(arrayJugador, limiteJugador) == 0)
		{
			for(int i = 0; i < limiteJugador; i++)
			{
				if(arrayJugador[i].isEmpty == 1 && arrayJugador[i].idConfederacion == idConfederacion)
				{
					retorno = 0;
					jugador_imprimir(arrayJugador[i], arrayConfederacion, limiteConfederacion);
				}
			}
		}
	}
	return retorno;
}


/**
 * \brief ordena la lista de jugadores por tipoId
 * \param arrayJugador Array de tipo eJugador
 * \param limite de eJugador
**/
int ordenarJugadoresporId(eJugador arrayJugador[], int limiteJugador)
{
	int retorno = -1;
	int i;
	int j;
	eJugador auxJugador;

	if(arrayJugador != NULL && limiteJugador > 0)
	{
		for(i = 0; i < limiteJugador - 1; i++)
		{
			for(j = i + 1; j < limiteJugador; j++)
			{
				if(arrayJugador[i].isEmpty == 1 && arrayJugador[j].isEmpty == 1)
				{
					if(arrayJugador[i].id > arrayJugador[j].id)
					{
						auxJugador = arrayJugador[i];
						arrayJugador[i] = arrayJugador[j];
						arrayJugador[j] = auxJugador;
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief  Imprime un listado de los Jugadores separ�ndolos por la confederaci�n
 * \param  arrayJugador Array de tipo eJugador
 * \param limite de eJugador
 * \param id de confederacion
 * \param arrayConfederacion Array de tipo eConfederacion
 * \param limite de confederacion
**/
int listarJugadoresDeConfederaciones(eConfederacion arrayConfederacion[], int limiteConfederacion, eJugador arrayJugadores[], int limiteJugador)
{
		int retorno = -1;
		int i;
		if(arrayConfederacion != NULL && limiteConfederacion > 0 && arrayJugadores != NULL && limiteJugador > 0)
		{
			for(i = 0; i < limiteConfederacion; i++)
			{
				printf("%30s\n", arrayConfederacion[i].nombre);
				if(listarJugadoresPorConfederacion(arrayJugadores, limiteJugador,arrayConfederacion[i].id, arrayConfederacion, limiteConfederacion) == 0)
				{
					retorno = 0;
				}
				printf("\n");
		}
	}
		return retorno;
}
