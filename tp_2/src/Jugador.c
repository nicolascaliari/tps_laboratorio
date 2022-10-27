#include <stdio.h>
#include <stdlib.h>
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
				printf("  %d   |%10s        |%10s        |%10d       |%2.f        |%10d          |%10s\n\n",
									unJugador.id, unJugador.nombre, unJugador.posicion,
									unJugador.numeroCamiseta, unJugador.salario,
									unJugador.aniosContrato, arrayConfederacion[i].nombre);
			}
		}
	}
	return retorno;
}



int jugador_imprimirArray(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int retorno = -1;
	int i;
	if(arrayJugador != NULL && arrayConfederacion != NULL && limiteConfederacion > 0)
	{
		retorno = 0;
		printf("                     ***LISTA DE JUGADORES***\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf("| ID  |      NOMBRE      |     POSICION     |   N DE CAMISETA |   SUELDO   | ANIOS DE CONTRATO  |    CONFEDERACION   |\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");

		for(i = 0; i < limiteConfederacion; i++)
		{
			jugador_imprimir(arrayJugador[i], arrayConfederacion, limiteConfederacion);
		}
	}
	return retorno;
}



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

			if(utn_getNombre(auxiliar.nombre, 50, "\nIngrese su nombre\n","\nERROR\n", 2) == 0
					&& utn_getNombre(auxiliar.posicion, 50,"Ingrese su posicion", "error", 2) == 0
					&& utn_getNumeroShort(&auxiliar.numeroCamiseta,"Ingrese su numero de camiseta", "error", 1, 90, 2) == 0
					&& utn_getNumeroFlotante(&auxiliar.salario,"Ingrese su salario", "error", 1, 600000, 2) == 0
					&& utn_getNumeroShort(&auxiliar.aniosContrato,"Ingrese anios de contrato", "error", 1, 50, 2)== 0)
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

int jugador_bajaArray(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion)
{
	int retorno = -1;
	int id;
	int indice;

	if(arrayJugador != NULL && arrayConfederacion != NULL && limiteJugador > 0 && limiteConfederacion > 0)
	{

		jugador_imprimirArray(arrayJugador, arrayConfederacion, limiteConfederacion);

			if(utn_getNumero(&id, "\nIngrese el ID que desea dar de baja", "Error al ingresar un ID", 1, 20, 2)==0)
			{
				indice = buscar_id(arrayJugador, limiteJugador, id);

				if(indice != -1)
				{
					arrayJugador[indice].isEmpty = 0;
					retorno = 0;
				}

			}
	}
	return retorno;
}



int jugador_modificarArray(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion)
{
	int retorno = -1;
	int id;
	int indice;
	int opcion;

	if(arrayJugador != NULL && arrayConfederacion != NULL && limiteJugador > 0 && limiteConfederacion > 0)
	{
		jugador_imprimirArray(arrayJugador, arrayConfederacion, limiteConfederacion);

		if(utn_getNumero(&id, "\nIngrese el ID que desea modificar", "\nError al ingresar el ID para modificar", 1, 20, 2) == 0)
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
		}
	}
	return retorno;
}


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


int buscar_id(eJugador arrayJugador[], int limiteJugador, int valorBuscado)
{
	int retorno = -1;
	int i;
	if(arrayJugador != NULL && limiteJugador > 0 && valorBuscado > 0)
	{
		for(i = 0; i < limiteJugador; i++)
		{
			if(arrayJugador[i].id == valorBuscado)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}




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