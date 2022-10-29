#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Jugador.h"
#include "Confederacion.h"
#include "Informes.h"

int menuInformes(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion);
/**
*\brief: menu para amb de jugadores
*\param: arrayJugador Array de tipo eJugador
*\param: arrayConfederacion array de tipo eConfederacion
*\param: limiteJugador Limite del array de eJugador
*\param: limiteConfederacion Limite del array de eConfederacion
*\return: Retorna 0 (EXITO) y -1 (ERROR)
**/

int menuJugador(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion)
{
	int retorno = -1;
	int opcion;
	int bandera = 0;
	int contador = 0;

	if(arrayJugador != NULL && arrayConfederacion != NULL && limiteJugador > 0 && limiteConfederacion > 0)
	{
		retorno = 0;

	do
	{
		if(utn_getNumero(&opcion, "\n          Bienvenido al menu de jugadores"
									"\n1-Alta de jugador"
									"\n2-Baja de jugador"
									"\n3-Modificacion de jugador"
									"\n4-informes"
									"\n5-Salir", "Error ingrese las opciones que se muestran en el menu", 1,5, 2)==0)
		{

			switch(opcion)
			{
			case 1:
				if(buscar_espacio_array(arrayJugador, limiteJugador) == 1)
				{
					if(alta_jugador(arrayJugador, arrayConfederacion, limiteJugador, limiteConfederacion) == 0)
					{
						printf("\nDado de alta exitosamente");
						bandera = 1;
						contador++;
					}else
					{
						printf("\nNo se pudo dar de alta");
					}

				}else
				{
					printf("\nNo hay mas espacio");
				}
				break;
			case 2:
				if(bandera == 1 && jugador_bajaArray(arrayJugador, arrayConfederacion ,limiteJugador, limiteConfederacion) == 0)
				{
					printf("\nDado de baja exitosamente");
					contador--;
					if(contador == 0)
					{
						bandera = 0;
					}
				}else
				{
					printf("\nNo se pudo dar de baja");
				}
				break;
			case 3:
				if(bandera == 1 && jugador_modificarArray(arrayJugador, arrayConfederacion, limiteJugador, limiteConfederacion)==0)
				{
					printf("\nmodificacion dada con exito");
				}else
				{
					printf("No se puede modificar");
				}
				break;

			case 4:
				if(bandera == 1)
				{
					if(menuInformes(arrayJugador, arrayConfederacion, limiteJugador, limiteConfederacion) == 0)
					{
						printf("Salio todo bien");
					}
				}else
				{
					printf("\nAntes de ingresar al menu de informes debe dar un alta");
				}
				break;

			case 5:
				if(utn_getNumero(&opcion, "Seguro que desea salir del programa? \n Para confirmar ingrese 6\n Para seguir en el menu ingrese 1", "Error al ingresar un numero", 1, 5, 2))
				{
					printf("Todo okey");
				}
				break;
			}
		}

	}while(opcion != 6);

}

	return retorno;
}






/**
*\brief: menu de informes
*\param: arrayJugador Array de tipo eJugador
*\param: arrayConfederacion array de tipo eConfederacion
*\param: limiteJugador Limite del array de eJugador
*\param: limiteConfederacion Limite del array de eConfederacion
*\return: Retorna 0 (EXITO) y -1 (ERROR)
**/
int menuInformes(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion)
{
	int opcion;
	int retorno = -1;

	if(arrayJugador != NULL && arrayConfederacion != NULL && limiteConfederacion > 0 && limiteJugador > 0)
	{

	retorno = 0;

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
				if(calcularConfederacionMayorAniosContratoTotal(arrayJugador, arrayConfederacion, limiteJugador, limiteConfederacion) == 0)
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
	return retorno;
}
