#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int ingresarNumeros_utn(int *resultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int retorno;
	int numero;

	while (reintentos > 0) {
		printf(mensaje);
		if (getInt(&numero) == 1) {
			if (numero <= maximo && numero >= minimo)
				break;
		}
		__fpurge(stdin);

		reintentos--;
		printf(mensajeError);
	}

	if (reintentos == 0) {
		retorno = -1;
	} else {
		retorno = 0;
		*resultado = numero;
	}
	return retorno;
}

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

int getInt(int *resultado) {
	int retorno = -1;
	char buffer[64];
	fgets(buffer, sizeof(buffer), stdin);
	if (esNumerica(buffer)) {
		*resultado = atoi(buffer);
		retorno = 1;
	}

	return retorno;
}

void inicializarVector(int vector[], int size, int inicial) {
	for (int i = 0; i < size; i++) {
		vector[i] = inicial;
	}
}

int ingresarNumero(int *resultado, char *mensaje, int minimo, int maximo,
		char *mensajeError) {

	int retorno = -1;
	if (resultado != NULL && mensaje != NULL) {
		printf(mensaje);
		scanf("%d", &retorno);
		__fpurge(stdin);
		while (retorno < minimo || retorno > maximo) {
			printf(mensajeError);
			printf(mensaje);
			scanf("%d", &retorno);
			__fpurge(stdin);
		}
	}

	return retorno;

}

char ingresarString(int *resultado, char *mensaje, char *mensajeError) {
	char string[22];
	int retorno;
	if (resultado != NULL && mensaje != NULL && mensajeError != NULL) {
		printf(mensaje);
		fgets(string, 22 , stdin);
		__fpurge(stdin);
		normalizar(string , 22);
		printf("%s" , string);

//		esString(string);



		while (strcmp(string, "delantero") != 0 && strcmp(string, "arquero")!= 0 && strcmp(string, "mediocampista") != 0 && strcmp(string, "defensor")!= 0) {
			printf("\nERROR Ingrese la posicion: ");
			fgets(string , 22 , stdin);
			__fpurge(stdin);
			normalizar(string , 22);
		}
//
//		printf("Pude salir");
	}
	return string;
}

int esString(char * string){
	int i = 0;
	int retorno =-1;
	if(string != NULL && strlen(string) > 0){
		while(string[i] != '\n'){
			if(string[i] < '0' || string[i] > '9'){
				retorno = 0;
				break;
			}
			i++;
		}
	}
		return retorno;
}
int normalizar(char * string, int len){
	int retorno = -1;
	if(string != NULL && len > 0){
		for( int i =0; i< len ; i++){
			__fpurge(stdin);
			if(string [strlen(string) -1 ] == '\n'){
				string [strlen(string)-1] = '\0';
			}
			retorno = 0;
		}
	}
	return retorno;
}

