#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int esNumerica(char *cadena) {

	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int ingresarNumeroInt(int *resultado, char *mensaje, int minimo, int maximo,char *mensajeError) {
	int numero;
	int retorno = 0;
	if (resultado != NULL && mensaje != NULL) {
		printf(mensaje);
		scanf("%d", &numero);
		__fpurge(stdin);
		while (numero < minimo || numero > maximo) {
			printf(mensajeError);
			printf(mensaje);
			scanf("%d", &numero);
			retorno = -1;
			__fpurge(stdin);
		}
		*resultado = numero;
	}

	return retorno;

}


int ingresarNumeroFloat(float *resultado, char *mensaje, int minimo, int maximo, char *mensajeError) {
	float numero;
	int retorno = 0;
	if (resultado != NULL && mensaje != NULL) {
		printf(mensaje);
		scanf("%f", &numero);
		__fpurge(stdin);
		while (numero < minimo || numero > maximo) {
			printf(mensajeError);
			printf(mensaje);
			scanf("%f", &numero);
			retorno = -1;
			__fpurge(stdin);
		}
		*resultado = numero;
	}

	return retorno;

}


int esString(char *string) {
	int i = 0;
	int retorno = -1;
	if (string != NULL && strlen(string) > 0) {
		while (string[i] != '\n') {
			if (string[i] < '0' || string[i] > '9') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}


//int calcularDatos(){
//
//
//}

