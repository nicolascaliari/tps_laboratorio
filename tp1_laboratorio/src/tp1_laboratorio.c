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

#define LEN 22
int main(void) {
	int opcion;
	float costoComida = 0;
	float costoHospedaje = 0;
	float costoTransporte = 0;
	int camisetas;
	int posicion;
	int confederacion;

	int arquerosCargados = 0;
	int delanterosCargados = 0;
	int defensoresCargados = 0;
	int mediocampistasCargados = 0;

	int i;
	int respuesta;
	int resultado;

	int contadorAFC = 0;
	int contadorCAF = 0;
	int contadorCONCACAF = 0;
	int contadorCONMEBOL = 0;
	int contadorUEFA = 0;
	int contadorOFC = 0;
	float promedio;
	float mantenimiento;
	int contadorJugadores = 0;
	int flagMantenimiento = 0;
	int flagJugadores = 0;

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
		printf("\n5. Salir");

		printf("\nOpcion: ");
		scanf("%i", &opcion);

		switch (opcion) {
		case 1:

			if (ingresarNumeroFloat(&costoHospedaje, "Ingrese costo de hospedaje: ",
					1, 100000, "Error al ingresar los costos\n") == 0) {

				if (ingresarNumeroFloat(&costoComida, "Ingrese costo de comida: ",
						1, 100000, "Error al ingresar los costos\n") == 0) {

					if (ingresarNumeroFloat(&costoTransporte,
							"Ingrese costo de transporte: ", 1, 100000,
							"Error al ingresar los costos\n") == 0) {

						mantenimiento = costoHospedaje + costoComida+ costoTransporte;
						flagMantenimiento = 1;
					}

				}

			}

			break;

		case 2:
			if (contadorJugadores < 4) {

				if (ingresarNumeroInt(&respuesta, "Ingrese numero de camiseta: ",
						1, 99, "Error al ingresar el numero de camiseta\n")
						== 0) {

					if (ingresarNumeroInt(&respuesta,
							"Ingrese la posicion del jugador.\n"
							"coloque 1 para delantero\n "
							"coloque 2 para mediocampista\n "
							"coloque 3 para defensor\n"
							"coloque 4 para arquero",
							1, 4, "error") == 0) {

						switch (respuesta) {

						case 1:
							if (delanterosCargados < 4) {
								delanterosCargados++;
								contadorJugadores++;
							} else {
								printf("No se pueden ingresar mas");
								ingresarNumeroInt(&respuesta,
										"Ingrese la posicion del jugador.\n"
										"coloque 1 para delantero\n "
										"coloque 2 para mediocampista\n "
										"coloque 3 para defensor\n "
										"coloque 4 para arquero",
										1, 4, "error");
							}
							break;
//						case 2:
//							if (mediocampistasCargados < 8) {
//								mediocampistasCargados++;
//								contadorJugadores++;
//							} else {
//								printf("No se pueden ingresar mas");
//								ingresarNumeroInt(&respuesta,
//								"Ingrese la posicion del jugador.\n"
//								"coloque 1 para delantero\n "
//								"coloque 2 para mediocampista\n "
//								"coloque 3 para defensor\n "
//								"coloque 4 para arquero",
//								1, 4, "error");
//							}
//							break;
//						case 3:
//							if (defensoresCargados < 8) {
//								defensoresCargados++;
//								contadorJugadores++;
//							} else {
//								printf("No se pueden ingresar mas");
//								ingresarNumeroInt(&respuesta,
//								"Ingrese la posicion del jugador.\n"
//								"coloque 1 para delantero\n "
//								"coloque 2 para mediocampista\n "
//								"coloque 3 para defensor\n "
//								"coloque 4 para arquero",
//								1, 4, "error");
//							}
//							break;
//						case 4:
//							if (arquerosCargados < 2) {
//								arquerosCargados++;
//								contadorJugadores++;
//							} else {
//								printf("No se pueden ingresar mas");
//								ingresarNumeroInt(&respuesta,
//								"Ingrese la posicion del jugador.\n"
//								"coloque 1 para delantero\n "
//								"coloque 2 para mediocampista\n "
//								"coloque 3 para defensor\n "
//								"coloque 4 para arquero",
//								1, 4, "error");
//							}
//							break;
						}

						if (ingresarNumeroInt(&respuesta,
								"Ingrese la confederacion que esta jugando: AFC/CAF/CONCACAF/CONMEBOL/UEFA/OFC",
								0, 6, "Error") == 0) {

							switch(respuesta){
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

			int aumento = 35;
			float precioFinal;
			if (flagMantenimiento == 0 && flagJugadores == 0) {
				printf("Debe completas el campo 1 y 2");
			} else {
				if (contadorUEFA > contadorAFC && contadorUEFA > contadorCAF
						&& contadorUEFA > contadorCONCACAF
						&& contadorUEFA > contadorCONMEBOL
						&& contadorUEFA > contadorOFC) {
					precioFinal = mantenimiento + (mantenimiento * aumento) / 100;
				} else {
					precioFinal = mantenimiento;
					promedio = contadorUEFA / 22;
				}
				printf("El costo de mantenimiento es:%.2f", precioFinal);
				printf("%f" , promedio);

			}

			break;
		case 4:
			printf("Ingresaste a la opcion %i", opcion);
			break;
		}
	} while (opcion != 5);
	return EXIT_SUCCESS;
}

