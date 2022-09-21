#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int esNumerica(char cadena[]) {
	int i;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		for(i = 0; i < strlen(cadena); i++) {
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}


int getInt(int *pResultado) {
	int ret = -1;
	char buffer[1024];

	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer) - 1] = '\0';

	if (esNumerica(buffer)) {
		*pResultado = atoi(buffer);
		ret = 1;
	}
	return ret;
}


int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {
	int ret;
	int num;
	while (reintentos > 0) {
		printf("%s", mensaje);
		__fpurge(stdin);
		if (getInt(&num) == 1) {
			if (num <= maximo && num >= minimo){
				break;
			}
		}
		reintentos--;
		printf("%s", mensajeError);
		__fpurge(stdin);
	}
	if (reintentos == 0) {
		ret = -1;
	} else {
		ret = 0;
		*pResultado = num;
	}
	return ret;
}





 int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}



 int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}


int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}








int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		__fpurge(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}


float calcularPromedio(float  contador ){

	return ((contador / 22) * 100);
}







