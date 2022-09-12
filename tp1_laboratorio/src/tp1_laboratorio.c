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
	int costo[3] = { 0, 0, 0 };
	int camisetas[LEN];

//	int arquero[2];
//	int defensor[8];
//	int mediocampista[8];
//	int delantero[4];
//
//	inicializarVector(arquero, 2, 0);
//	inicializarVector(defensor, 8, 0);
//	inicializarVector(mediocampista, 8, 0);
//	inicializarVector(delantero, 4, 0);

	int arquerosCargados = 0;
	int delanterosCargados = 0;
	int defensoresCargados = 0;
	int mediocampistasCargados = 0;

	char posicion[22];
	char confederacion[22];
	int i;
	int respuesta;
	int resultado;
//	char resultadoPosicion[15];
	do {

		puts("        Menu principal");
		printf("\n1. Ingreso de los costos de mantenimiento");
		printf("\nCosto de hospedaje -> $%d", costo[0]);
		printf("\nCosto de comida -> $%d", costo[1]);
		printf("\nCosto de transporte -> $%d", costo[2]);

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
			resultado = ingresarNumero(&respuesta,
					"Ingrese costo de hospedaje: ", 100, 500,
					"Error al ingresar los costos\n");
			costo[0] = resultado;

			resultado = ingresarNumero(&respuesta, "Ingrese costo de comida: ",
					100, 500, "Error al ingresar los costos\n");
			costo[1] = resultado;

			resultado = ingresarNumero(&respuesta,
					"Ingrese costo de transporte: ", 100, 500,
					"Error al ingresar los costos\n");
			costo[2] = resultado;
			break;
		case 2:
			for (i = 0; i < 4; i++) {
				resultado = ingresarNumero(&respuesta,
						"Ingrese numero de camiseta: ", 1, 99,
						"Error al ingresar el numero de camiseta\n");
				camisetas[i] = resultado;


				resultado = ingresarNumero(&respuesta, "Ingrese la posicion del jugador.\n coloque 1 para delantero\n coloque 2 para mediocampista\n coloque 3 para defensor\n coloque 4 para arquero", 1, 4 , "error");
				posicion[i] = resultado;


				if(resultado == 1){
					delanterosCargados++;
				}else if(resultado == 2){
					mediocampistasCargados++;
				}else if(resultado == 3){
					defensoresCargados++;
				}else {
					arquerosCargados++;
				}


				if(delanterosCargados > 4){
					delanterosCargados--;

					printf("No se puede cargar mas de 4 delanteros\n");
				}
				if(mediocampistasCargados > 8){
					mediocampistasCargados--;
					printf("No puede cargar mas de 8 mediocampistas\n");
				}
				if(defensoresCargados > 8){
					defensoresCargados--;
					printf("No puede cargar mas de 8 defensores\n");
				}
				if(arquerosCargados > 3){
					arquerosCargados--;
					printf("No puede cargas mas de 3 arqueros\n");
				}
//				strcpy(resultadoPosicion,  ingresarString(&respuesta,"Ingresar posicion: delantero/mediocampista/defensor/arquero", "error"));
//				strcpy(posicion[i] , resultadoPosicion);
//				printf("%s", resultadoPosicion);



//				if (strcmp(resultadoPosicion , "delantero") == 0) {
//					delanterosCargados++;
//				}
//
//				if (strcmp(resultadoPosicion , "defensor") == 0) {
//					defensoresCargados++;
//				}
//
//				if (resultadoPosicion == "mediocampista") {
//					mediocampistasCargados++;
//				}
//
//				if (resultadoPosicion == "arquero") {
//					arquerosCargados++;
//				}

//				printf("Ingrese la confederacion que esta jugando: AFC/CAF/CONCACAF/CONMEBOL/UEFA/OFC");
//				fgets(confederacion, 30, stdin);
//				__fpurge(stdin);
//
			}
			break;
		case 3:
			printf("Ingresaste a la opcion %i", opcion);
			break;
		case 4:
			printf("Ingresaste a la opcion %i", opcion);
			break;
		}
	} while (opcion != 5);
	return EXIT_SUCCESS;
}

