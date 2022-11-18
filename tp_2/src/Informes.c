#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Informes.h"
#include "Jugador.h"
#include "Confederacion.h"
#include "Salida_datos.h"
#include "Calculos.h"


/**
 * \brief Ordena el array por nombre de confederacion y en el caso de ser iguales se ordena por nombre de jugador
 * \param arrayJugador Array de tipo ejugador
 * \param arrayConfederacion Array de tipo eConfederacion
 * \param limiteJugador Limite del array de jugador
 * \param limiteConfederacion Limite del array de confederacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int jugador_ordenar_id_descripcion(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion)
{
	int retorno = -1;
	int i;
	int j;
	eJugador auxJugador;
	int bandera;
	char nombreConfederacionI[50];
	char nombreConfederacionJ[50];

	if(arrayJugador != NULL && arrayConfederacion != NULL && limiteJugador > 0 && limiteConfederacion > 0)
	{
		retorno = 0;
		do
		{
			bandera = 0;
			for(i = 0; i < limiteJugador -1 ; i++)
			{
				for(j = i + 1; j < limiteJugador ; j++)
				{
					if(arrayJugador[i].isEmpty == 1 && arrayJugador[j].isEmpty == 1 && buscarConfederacion(arrayConfederacion, limiteConfederacion, arrayJugador[i].idConfederacion, nombreConfederacionI) == 0
							&& buscarConfederacion(arrayConfederacion, limiteConfederacion, arrayJugador[j].idConfederacion, nombreConfederacionJ) == 0)
					{
						if(strncmp(nombreConfederacionI, nombreConfederacionJ, 50) > 0)
						{
							bandera = 1;
							auxJugador = arrayJugador[i];
							arrayJugador[i] = arrayJugador[j];
							arrayJugador[j] = auxJugador;

						}else if(strncmp(nombreConfederacionI, nombreConfederacionJ, 50) == 0)
						{
							if(strncmp(arrayJugador[i].nombre, arrayJugador[j].nombre, 50) > 0)
							{
								bandera = 1;
								auxJugador = arrayJugador[i];
								arrayJugador[i] = arrayJugador[j];
								arrayJugador[j] = auxJugador;
							}
						}
					}
				}
			}

		}while(bandera);
	}



	return retorno;
}

int acumular_salarios(eJugador arrayJugador[] , int limiteJugador, float* acumulador, int* contador)
{
	int retorno = -1;
	int i;
	float acumulador_salarios = 0;
	int contador_salarios = 0;
	for(i = 0; i < limiteJugador; i++)
	{
		if(arrayJugador[i].isEmpty == 1)
		{
			acumulador_salarios+=arrayJugador[i].salario;
			contador_salarios++;
		}
	}

	if(acumulador > 0)
	{
		*acumulador = acumulador_salarios;
		*contador = contador_salarios;
		retorno = 0;
	}else
	{
		printf("\nNo se cargo nada");
	}
	return retorno;
}




int Calcular_cantidad_asalariados(eJugador arrayJugador[], int limiteJugador, float promedio, int* cantidad)
{

	int retorno = -1;
	int i;
	int contadorJugadores = 0;
			for(i = 0; i < limiteJugador; i++)
			{
				if(arrayJugador[i].isEmpty == 1 && arrayJugador[i].salario > promedio)
				{
					contadorJugadores++;
				}
			}

	if(contadorJugadores > 0)
	{
		*cantidad = contadorJugadores;
		retorno = 0;
	}else
	{
		printf("\nNo hay ninguno que supere el promedio");
	}
	return retorno;
}



/**
 * \brief Calcula el total y promedio y cantidad de jugador que tiene un salario mayor al promedio
 * \param arrayJugadorArray de tipo eJugador
 * \param limiteJugador Limite de arrayJugador
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int calcular_total_promedio_salario(eJugador arrayJugador[], int limiteJugador)
{
	int retorno = -1;
	float acumulador = 0;
	int contador = 0;
	int cantidadAsalariados = 0;
	float promedio;

	if(arrayJugador != NULL && limiteJugador > 0)
	{
		if( acumular_salarios(arrayJugador, limiteJugador, &acumulador, &contador) == 0)
		{
			if(calcularPromedio(&promedio, acumulador, contador) == 0)
			{
				if(Calcular_cantidad_asalariados(arrayJugador, limiteJugador, promedio, &cantidadAsalariados) == 0)
				{
					printf("El total de los salarios es: %2.f\n El promedio es:%2.f \n La cantidad que superan el promedio son: %d",acumulador, promedio, cantidadAsalariados);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}


/**
 * \brief Informa la confederacion con mayor cantidad de anios de contrato
 * \param arrayJugador Array de tipo ejugador
 * \param arrayConfederacion Array de tipo eConfederacion
 * \param limiteJugador Limite de arrayJugador
 * \param limiteConfederacion Limite de arrayConfederacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int calcularConfederacionMayorAniosDeContratoTotal(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion)
{
	int retorno = -1;
	int i;
	int j;
	int maximoAnios;
	int acumuladorGnerico;
	char variableAuxiliarNombreConf[30];
		if(arrayJugador != NULL && arrayConfederacion != NULL && limiteJugador > 0 && limiteConfederacion > 0)
		{
			retorno = 0;

			for(i =0; i < limiteConfederacion; i++)
			{
				acumuladorGnerico = 0;
				for(j= 0 ; j < limiteJugador; j++)
				{
					if(arrayJugador[j].idConfederacion == arrayConfederacion[i].id && arrayJugador[j].isEmpty == 1)
					{

						acumuladorGnerico+= arrayJugador[j].aniosContrato;
					}

				}

				if(maximoAnios < acumuladorGnerico || i == 0)
				{
					maximoAnios = acumuladorGnerico;
					strcpy(variableAuxiliarNombreConf,arrayConfederacion[i].nombre);
				}
			}
			printf("\nLa confederacion: %s con cantidad de anios : %d", variableAuxiliarNombreConf, maximoAnios);

		}

	return retorno;
}



/**
 * \brief Informa la region con mas jugadores
 * \param arrayJugador Array de tipo ejugador
 * \param arrayConfederacion Array de tipo eConfederacion
 * \param limiteJugador Limite de arrayJugador
 * \param limiteConfederacion Limite de arrayConfederacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int calcularRegionConMasJugadores(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion)
{
		int retorno = -1;
		int i;
		int j;
		int maximoAnios;
		char variableAuxiliarNombreConf[30];
		int contador;
		int auxiliarID;
			if(arrayJugador != NULL && arrayConfederacion != NULL && limiteJugador > 0 && limiteConfederacion > 0)
			{
				retorno = 0;

				for(i =0; i < limiteConfederacion; i++)
				{
					contador = 0;
					for(j= 0 ; j < limiteJugador; j++)
					{
						if(arrayJugador[j].idConfederacion == arrayConfederacion[i].id && arrayJugador[j].isEmpty == 1)
						{

							contador++;
						}

					}


					if(maximoAnios < contador || i == 0)
					{
						maximoAnios = contador;
						strcpy(variableAuxiliarNombreConf,arrayConfederacion[i].region);
						 auxiliarID = arrayConfederacion[i].id;
					}
				}
				printf("\n\nLa region con mas jugadores es: %s\n\n" , variableAuxiliarNombreConf);

				listarJugadoresPorConfederacion(arrayJugador, limiteJugador, auxiliarID, arrayConfederacion, limiteConfederacion);
		}

	return retorno;
}




/**
 * \brief Calcula porcentaje de jugadores por cada confederacion
 * \param arrayJugador Array de tipo eJugador
 * \param limiteJugador Limite de arrayJugador
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int calcularPorcentajeJugadores(eJugador arrayJugador[], int limiteJugador, eConfederacion arrayConfederacion[], int limiteConfederacion)
{
			int retorno = -1;
			int i;
			int j;
			char variableAuxiliarNombreConf[30];
			int contadorTotal = 0;
			int contadorJugadores = 0;
			float porcentaje;
				if(arrayJugador != NULL && arrayConfederacion != NULL && limiteJugador > 0 && limiteConfederacion > 0)
				{
					retorno = 0;

					for(int k = 0; k < limiteJugador; k++)
					{
						if(arrayJugador[k].isEmpty == 1)
						{
							contadorTotal++;
						}
					}

					for(i =0; i < limiteConfederacion; i++)
					{
						contadorJugadores = 0;
						for(j= 0 ; j < limiteJugador; j++)
						{
							if(arrayJugador[j].idConfederacion == arrayConfederacion[i].id && arrayJugador[j].isEmpty == 1)
							{
								contadorJugadores++;
							}

						}
						strcpy(variableAuxiliarNombreConf,arrayConfederacion[i].nombre);
						calcularPorcentaje(&porcentaje,contadorJugadores, contadorTotal);
						printf("\nEl promedio de %s es: %.2f",variableAuxiliarNombreConf, porcentaje);
					}
			}

	return retorno;
}

