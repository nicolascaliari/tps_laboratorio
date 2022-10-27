#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Informes.h"
#include "Jugador.h"
#include "Confederacion.h"

void menuInformes(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion)
{
	int opcion;

	do
	{
		if(utn_getNumero(&opcion, "\nBienvenido al menu de informes\n"
				"\n1-Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador."
				"\n2-Listado de confederaciones con sus jugadores."
				"\n3-Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio."
				"\n4-Informar la confederación con mayor cantidad de años de contratos total."
				"\n5.Informar porcentaje de jugadores por cada confederación."
				"\n6.Informar cual es la región con más jugadores y el listado de los mismos."
				"\n7-Salir", "\nError, solo puede ingresar del 1 al 5",1, 7, 2) == 0)
		{

			switch(opcion)
			{
			case 1:
				if(jugador_ordenar_id_descripcion(arrayJugador, arrayConfederacion, limiteJugador, limiteConfederacion) == 0)
				{
					jugador_imprimirArray(arrayJugador, arrayConfederacion, limiteConfederacion);
				}else
				{
					printf("\nNo se pudo hacer el ordenamiento");
				}

				break;
			case 2:
				if(imprimir_jugador_informes(arrayJugador, arrayConfederacion, limiteConfederacion) == 0)
				{
					printf("\nListado de jugadores con sus confederaciones realizado con exito");
				}else
				{
					printf("\nAlgo salio mal");
				}
				break;
			case 3:
				if(total_promedio_salario(arrayJugador, limiteJugador) ==0 )
				{
					printf("\nTotal y promedio salio bien");
				}else
				{
					printf("\nAlgo salio mal");
				}
				break;
			case 4:
				if(confederacionMayorAniosContratoTotal(arrayJugador, arrayConfederacion, limiteJugador, limiteConfederacion) == 0)
				{
					printf("\nTodo salio bien");
				}else
				{
					printf("\nAlgo salio mal");
				}
				break;

			case 5:
				if(porcentajeJugadores(arrayJugador, limiteJugador) ==0)
				{
					printf("\nTodo salio bien");
				}else
				{
					printf("\nAlgo salio mal");
				}

				break;
			case 6:
				if(regionMasJugadores(arrayJugador, arrayConfederacion, limiteJugador, limiteConfederacion)==0)
				{
					printf("\nTodo salio bien");
				}else
				{
					printf("\nAlgo salio mal");
				}
				break;
			case 7:
				break;
			}
		}

	}while(opcion != 7);
}

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
						if(strncmp(nombreConfederacionI, nombreConfederacionJ, 50) < 0)
						{
							bandera = 1;
							auxJugador = arrayJugador[i];
							arrayJugador[i] = arrayJugador[j];
							arrayJugador[j] = auxJugador;

						}else if(strncmp(nombreConfederacionI, nombreConfederacionJ, 50) == 0)
						{
							if(strncmp(arrayJugador[i].nombre, arrayJugador[j].nombre, 50) < 0)
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
		promedio = total / contador;


		for(j = 0; j < limiteJugador; j++)
		{
			if(arrayJugador[j].isEmpty == 1 && arrayJugador[j].salario > promedio)
			{
				contadorJugadores++;
			}
		}
		printf("\nEl total de los salarios es:%2.f", total);
		printf("\nEl promedio es:%2.f", promedio);
		printf("\nLa cantidad de jugadores que superan el salario promedio es:%d", contadorJugadores);
	}
	return retorno;
}




int confederacionMayorAniosContratoTotal(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion)
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
					calcularPromedio(&porcentajeConmebol,contador_conmebol, unJugador);
					calcularPromedio(&porcentajeUefa,contador_uefa, unJugador);
					calcularPromedio(&porcentajeAfc,contador_afc, unJugador);
					calcularPromedio(&porcentajeCaf,contador_caf, unJugador);
					calcularPromedio(&porcentajeConcacaf,contador_concacaf, unJugador);
					calcularPromedio(&porcentajeOfc,contador_ofc, unJugador);


					printf("\nEl promedio es: %.2f",porcentajeConmebol );
					printf("\nEl promedio es: %.2f",porcentajeUefa );
					printf("\nEl promedio es: %.2f",porcentajeAfc );
					printf("\nEl promedio es: %.2f",porcentajeCaf );
					printf("\nEl promedio es: %.2f",porcentajeConcacaf );
					printf("\nEl promedio es: %.2f",porcentajeOfc );


			}

	return retorno;
}




int calcularPromedio(float *pResultado, int multiplicador, int divisor)
{

    float promedio;
    int retorno = -1;

    if(pResultado != NULL && divisor != 0)
    {
        promedio = (float)(multiplicador * 100) / divisor;

        *pResultado = promedio;
        retorno = 0;

    }else
    {
    	*pResultado = 0;
    }

    return retorno;
}


int maximo_numero(int num1, int num2, int num3, int num4, int num5, int num6, int *pResultado, int *pIdMayor)
{

    int retorno = -1;
    int resultado;

    if(pResultado != NULL && pIdMayor != NULL)
    {

        if(num1 > num2 && num1 > num3 && num1 > num4 && num1 > num5 && num1 > num6)
        {
        	*pIdMayor = 100;
            resultado = num1;

        }
        else if (num2 > num3 && num2 > num4 && num2 > num5 && num2 > num6 )
        {
        	*pIdMayor = 101;
            resultado = num2;

        }
        else if (num3 > num4 && num3 > num5 && num3> num6)
        {
        	*pIdMayor = 102;
            resultado = num3;

        }
        else if(num4 > num5 && num4 > num6)
        {
        	*pIdMayor = 103;
            resultado = num4;

        }
        else if( num5 > num6)
        {
        	*pIdMayor = 104;
            resultado = num5;

        }
        else
        {
        	*pIdMayor = 105;
            resultado = num6;

        }

        retorno = 0;
    }

    if(retorno == 0)
    {

        *pResultado = resultado;
    }

    return retorno;
}
