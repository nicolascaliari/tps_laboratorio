/*
 ============================================================================
 Name        : tp1_laboratorio.c
 Author      : Nicolas Caliari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int main(void) {
	int opcion;
	float costoComida = 0;
	float costoHospedaje = 0;
	float costoTransporte = 0;

	int arquerosCargados = 0;
	int delanterosCargados = 0;
	int defensoresCargados = 0;
	int mediocampistasCargados = 0;

	int respuesta;

	float contadorAFC = 0;
	float contadorCAF = 0;
	float contadorCONCACAF = 0;
	float contadorCONMEBOL = 0;
	float contadorUEFA = 0;
	float contadorOFC = 0;

	float promedioUefa;
	float promedioAFC;
	float promedioCAF;
	float promedioCONMEBOL;
	float promedioOFC;
	float promedioCONCACAF;

	float mantenimiento;
	int contadorJugadores = 0;
	int flagMantenimiento = 0;
	int flagJugadores = 0;
	int flagCalcularDatos = 0;

	int aumento = 35;
	float precioFinal;
	do {
		puts("        Menu principal");
		printf("\n1. Ingreso de los costos de mantenimiento");
		printf("\nCosto de hospedaje -> $%.2f", costoHospedaje);
		printf("\nCosto de comida -> $%.2f", costoComida);
		printf("\nCosto de transporte -> $%.2f", costoTransporte);

		printf("\n2.Carga de jugadores");
		printf("\nArqueros -> %d", arquerosCargados);
		printf("\nDefensores -> %d", defensoresCargados);
		printf("\nMediocampistas -> %d", mediocampistasCargados);
		printf("\nDelanteros -> %d", delanterosCargados);

		printf("\n3.Realizar todos los calculos");
		printf("\n4.Informar todos los resultados");
		printf("\n5. Salir\n");

		utn_getNumero(&opcion, "Opcion: \n","Error, solamente puedes ingresar numeros del 1 al 5\n" , 1, 5, 5 );

		switch (opcion) {
		case 1:

			utn_getNumero(&respuesta, "Ingrese\n 1.para hospedaje:\n 2.para comida:\n 3.para transporte: \n","Error, solamente puedes ingresar numeros del 1 al 5\n" , 1, 3, 5 );


			switch(respuesta){

			case 1:
				utn_getNumeroFlotante(&costoHospedaje,"Ingrese costo de hospedaje:\n ","Error al ingresar los costos\n", 1, 100000, 5);
				break;

			case 2:
				utn_getNumeroFlotante(&costoComida,"Ingrese costo de comida:\n ","Error al ingresar los costos\n", 1, 100000, 5);
				break;

			case 3:
				utn_getNumeroFlotante(&costoTransporte,"Ingrese costo de transporte:\n ","Error al ingresar los costos\n", 1, 100000, 5);
				break;
			}
			flagMantenimiento =1;

			break;

		case 2:
			if (contadorJugadores < 4) {

				if (utn_getNumero(&respuesta, "Ingrese numero de camiseta: ",
						"Error al ingresar el numero de camiseta\n", 1, 99, 5)
						== 0) {

					if (utn_getNumero(&respuesta,
							"Ingrese la posicion del jugador:\n"
									"coloque 1 para delantero\n"
									"coloque 2 para mediocampista\n"
									"coloque 3 para defensor\n"
									"coloque 4 para arquero\n", "error", 1, 4,
							5) == 0) {

						switch (respuesta) {

						case 1:
							if (delanterosCargados < 4) {
								delanterosCargados++;
								contadorJugadores++;
							} else {
								printf("No se pueden ingresar mas");
								utn_getNumero(&respuesta,
										"Ingrese la posicion del jugador.\n"
												"coloque 1 para delantero\n "
												"coloque 2 para mediocampista\n "
												"coloque 3 para defensor\n "
												"coloque 4 para arquero",
										"error", 1, 4, 5);
							}
							break;
						case 2:
							if (mediocampistasCargados < 8) {
								mediocampistasCargados++;
								contadorJugadores++;
							} else {
								printf("No se pueden ingresar mas");
								utn_getNumero(&respuesta,
										"Ingrese la posicion del jugador.\n"
												"coloque 1 para delantero\n "
												"coloque 2 para mediocampista\n "
												"coloque 3 para defensor\n "
												"coloque 4 para arquero",
										"error", 1, 4, 5);
							}
							break;
						case 3:
							if (defensoresCargados < 8)
							{
								defensoresCargados++;
								contadorJugadores++;
							} else
							{
								printf("No se pueden ingresar mas");
								utn_getNumero(&respuesta,
										"Ingrese la posicion del jugador.\n"
												"coloque 1 para delantero\n "
												"coloque 2 para mediocampista\n "
												"coloque 3 para defensor\n "
												"coloque 4 para arquero",
										"error", 1, 4, 5);
							}
							break;
						case 4:
							if (arquerosCargados < 2)
							{
								arquerosCargados++;
								contadorJugadores++;
							}
							else
							{
								printf("No se pueden ingresar mas");
								utn_getNumero(&respuesta,
										"Ingrese la posicion del jugador:\n"
												"coloque 1 para delantero\n "
												"coloque 2 para mediocampista\n "
												"coloque 3 para defensor\n "
												"coloque 4 para arquero",
										"error", 1, 4, 5);
							}
							break;
						}

						if (utn_getNumero(&respuesta,
								"Ingrese la confederacion que esta jugando:\n"
										"1.AFC\n"
										"2.CAF\n"
										"3.CONCACAF\n"
										"4.CONMEBOL\n"
										"5.UEFA\n"
										"6.OFC\n", "Error", 0, 6, 5) == 0) {

							switch (respuesta)
							{
							case 1:
								contadorAFC++;
								break;
							case 2:
								contadorCAF++;
								break;
							case 3:
								contadorCONCACAF++;
								break;
							case 4:
								contadorCONMEBOL++;
								break;
							case 5:
								contadorUEFA++;
								break;
							case 6:
								contadorOFC++;
								break;
							}

							flagJugadores = 1;
						}

					}

				}

			}
			break;
		case 3:
			if (flagMantenimiento == 0 || flagJugadores == 0)
			{
				printf("Debe completas el campo 1 y 2\n\n\n");
			}
			else
			{

			printf("Todos los datos se cargaron correctamente");
			flagCalcularDatos = 1;

			mantenimiento = costoHospedaje + costoComida + costoTransporte;

			promedioUefa = calcularPromedio(contadorUEFA);
			promedioCAF = calcularPromedio(contadorCAF);
			promedioAFC = calcularPromedio(contadorAFC);
			promedioCONMEBOL = calcularPromedio(contadorCONMEBOL);
			promedioOFC = calcularPromedio(contadorOFC);
			promedioCONCACAF = calcularPromedio(contadorCONCACAF);

			if (contadorUEFA > contadorAFC && contadorUEFA > contadorCAF
					&& contadorUEFA > contadorCONCACAF
					&& contadorUEFA > contadorCONMEBOL
					&& contadorUEFA > contadorOFC) {
				precioFinal = mantenimiento + (mantenimiento * aumento) / 100;
			}
			else
			{
				precioFinal = mantenimiento;
			}
		}

			break;
		case 4:
			if (flagCalcularDatos == 0)
			{
				printf("Debes calcular los datos del punto 3 antes de ingresar a la opcion 4\n\n\n");
			}
			else
			{

				printf("El promedio de la UEFA es: %.2f\n\n", promedioUefa);
				printf("El promedio de la AFC es: %.2f\n\n", promedioAFC);
				printf("El promedio de la CAF es: %.2f\n\n", promedioCAF);
				printf("El promedio de la OFC es: %.2f\n\n", promedioOFC);
				printf("El promedio de la CONCACAF es: %.2f\n\n",promedioCONCACAF);
				printf("El promedio de la CONMEBOL es: %.2f\n\n",promedioCONMEBOL);

				printf("El costo de mantenimiento es:%.2f", precioFinal);

			}

			break;
		}

	} while (opcion != 5);
	return EXIT_SUCCESS;
}

