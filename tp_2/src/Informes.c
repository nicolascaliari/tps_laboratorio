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





/**
 * \brief Ordena el array por nombre de confederacion y en el caso de ser iguales se ordena por nombre de jugador
 * \param arrayJugador Array de tipo ejugador
 * \param arrayConfederacion Array de tipo eConfederacion
 * \param limiteJugador Limite del array de jugador
 * \param limiteConfederacion Limite del array de confederacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int imprimir_jugador_informes(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteConfederaciones)
{
	int retorno = -1;
	int i;
	if(arrayConfederacion != NULL && limiteConfederaciones > 0)
	{
		retorno = 0;
		for( i = 0; i < limiteConfederaciones; i++)
		{
			jugador_imprimir_informe(arrayJugador[i], arrayConfederacion, limiteConfederaciones);
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
int jugador_imprimir_informe(eJugador unJugador, eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int retorno = -1;
	int i;
	if(unJugador.isEmpty == 1 && arrayConfederacion != NULL && limiteConfederacion > 0)
	{
		for(i = 0; i < limiteConfederacion; i++)
		{
			if(unJugador.idConfederacion == arrayConfederacion[i].id)
			{
				printf("  NOMBRE:%s   CONFEDERACION:%s\n\n", unJugador.nombre, arrayConfederacion[i].nombre);
				retorno = 0;
			}
		}
	}
	return retorno;
}




/**
 * \brief Calcula el total y promedio y cantidad de jugador que tiene un salario mayor al promedio
 * \param arrayJugadorArray de tipo eJugador
 * \param limiteJugador Limite de arrayJugador
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int total_promedio_salario(eJugador arrayJugador[], int limiteJugador)
{
	int retorno = -1;
	int i;
	int j;
	float acumulador = 0;
	int contador = 0;
	int contadorJugadores = 0;
	float promedio;
	float total;

	if(arrayJugador != NULL && limiteJugador > 0)
	{
		retorno = 0;

		for(i = 0; i < limiteJugador; i++)
		{
			if(arrayJugador[i].isEmpty == 1)
			{
				acumulador+=arrayJugador[i].salario;
				contador++;
			}
		}
		total = acumulador;
		if(calcularPromedio(&promedio, total, contador) == 0)
		{
			printf("El promedio es:%2.f", promedio);
		}


		for(j = 0; j < limiteJugador; j++)
		{
			if(arrayJugador[j].isEmpty == 1 && arrayJugador[j].salario > promedio)
			{
				contadorJugadores++;
			}
		}
		printf("\nEl total de los salarios es:%2.f", total);
		printf("\nLa cantidad de jugadores que superan el salario promedio es:%d", contadorJugadores);
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
int calcularConfederacionMayorAniosContratoTotal(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion)
{
	int retorno = -1;
	int i;
	int acumulador_conmebol = 0;
	int acumulador_uefa = 0;
	int acumulador_afc = 0;
	int acumulador_caf = 0;
	int acumulador_concacaf = 0;
	int acumulador_ofc = 0;
	int resultado;
	char nombreConfederacion[50];
	int id;

		if(arrayJugador != NULL && arrayConfederacion != NULL && limiteJugador > 0 && limiteConfederacion > 0)
		{
			retorno = 0;

			for(i = 0; i < limiteJugador; i++)
			{
				if(arrayJugador[i].idConfederacion == 100)
						{
							acumulador_conmebol+= arrayJugador[i].aniosContrato;
						}
						else if(arrayJugador[i].idConfederacion == 101)
						{
							acumulador_uefa+= arrayJugador[i].aniosContrato;
						}
						else if(arrayJugador[i].idConfederacion == 102)
						{
							acumulador_afc+= arrayJugador[i].aniosContrato;
						}
						else if(arrayJugador[i].idConfederacion == 103)
						{
							acumulador_caf+= arrayJugador[i].aniosContrato;
						}
						else if(arrayJugador[i].idConfederacion == 104)
						{
							acumulador_concacaf+= arrayJugador[i].aniosContrato;
						}
						else if(arrayJugador[i].idConfederacion == 105)
						{
							acumulador_ofc+= arrayJugador[i].aniosContrato;
						}
			}

			maximo_numero(acumulador_conmebol, acumulador_uefa, acumulador_afc, acumulador_caf, acumulador_concacaf, acumulador_ofc, &resultado, &id);
			buscarConfederacion(arrayConfederacion, limiteConfederacion, id, nombreConfederacion);
			printf("\nEl nombre es: %s y su cantidad es:%d", nombreConfederacion, resultado);
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
int regionMasJugadores(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion)
{
	int retorno = -1;
	int i;
	int contador_conmebol = 0;
	int contador_uefa = 0;
	int contador_afc = 0;
	int contador_caf = 0;
	int contador_concacaf = 0;
	int contador_ofc = 0;
	int resultado;
	char nombreConfederacion[50];
	int id;

		if(arrayJugador != NULL && arrayConfederacion != NULL && limiteJugador > 0 && limiteConfederacion > 0)
		{
			retorno = 0;

			for(i = 0; i < limiteJugador; i++)
			{
				if(arrayJugador[i].idConfederacion == 100)
						{
							contador_conmebol++;
						}
						else if(arrayJugador[i].idConfederacion == 101)
						{
							contador_uefa++;
						}
						else if(arrayJugador[i].idConfederacion == 102)
						{
							contador_afc++;
						}
						else if(arrayJugador[i].idConfederacion == 103)
						{
							contador_caf++;
						}
						else if(arrayJugador[i].idConfederacion == 104)
						{
							contador_concacaf++;
						}
						else if(arrayJugador[i].idConfederacion == 105)
						{
							contador_ofc++;
						}
			}

			maximo_numero(contador_conmebol, contador_uefa, contador_afc, contador_caf, contador_concacaf, contador_ofc, &resultado, &id);
			buscarRegion(arrayConfederacion, limiteConfederacion, id, nombreConfederacion);
			printf("\nEl nombre de la region es: %s y su cantidad es:%d", nombreConfederacion, resultado);
		}

	return retorno;
}




/**
 * \brief Calcula porcentaje de jugadores por cada confederacion
 * \param arrayJugador Array de tipo eJugador
 * \param limiteJugador Limite de arrayJugador
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int porcentajeJugadores(eJugador arrayJugador[], int limiteJugador)
{
	int retorno = -1;
	int i;
	int contador_conmebol = 0;
	int contador_uefa = 0;
	int contador_afc = 0;
	int contador_caf = 0;
	int contador_concacaf = 0;
	int contador_ofc = 0;
	int unJugador = 0;

	float porcentajeConmebol;
	float porcentajeUefa;
	float porcentajeAfc;
	float porcentajeCaf;
	float porcentajeConcacaf;
	float porcentajeOfc;


		if(arrayJugador != NULL &&  limiteJugador > 0)
		{
			retorno = 0;

			for(i = 0; i < limiteJugador; i++)
			{

				if(arrayJugador[i].isEmpty == 1)
				{
					unJugador++;


				if(arrayJugador[i].idConfederacion == 100)
						{
							contador_conmebol++;
						}
						else if(arrayJugador[i].idConfederacion == 101)
						{
							contador_uefa++;
						}
						else if(arrayJugador[i].idConfederacion == 102)
						{
							contador_afc++;
						}
						else if(arrayJugador[i].idConfederacion == 103)
						{
							contador_caf++;
						}
						else if(arrayJugador[i].idConfederacion == 104)
						{
							contador_concacaf++;
						}
						else if(arrayJugador[i].idConfederacion == 105)
						{
							contador_ofc++;
						}
					}
				}
					calcularPorcentaje(&porcentajeConmebol,contador_conmebol, unJugador);
					calcularPorcentaje(&porcentajeUefa,contador_uefa, unJugador);
					calcularPorcentaje(&porcentajeAfc,contador_afc, unJugador);
					calcularPorcentaje(&porcentajeCaf,contador_caf, unJugador);
					calcularPorcentaje(&porcentajeConcacaf,contador_concacaf, unJugador);
					calcularPorcentaje(&porcentajeOfc,contador_ofc, unJugador);


					printf("\nEl promedio de CONMEBOL es: %.2f",porcentajeConmebol );
					printf("\nEl promedio de UEFA es: %.2f",porcentajeUefa );
					printf("\nEl promedio de AFC es: %.2f",porcentajeAfc );
					printf("\nEl promedio de CAF es: %.2f",porcentajeCaf );
					printf("\nEl promedio de CONCACAF es: %.2f",porcentajeConcacaf );
					printf("\nEl promedio de OFC es: %.2f",porcentajeOfc );


			}

	return retorno;
}
