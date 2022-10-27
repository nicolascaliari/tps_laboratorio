/*
 * Confederacion.h
 *
 *  Created on: 25 oct. 2022
 *      Author: nicolas
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

typedef struct
{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;

}eConfederacion;

int hardcodeoConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion);
int pedirConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion);
int mostrarConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion);
int buscarConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion, int id,char *pConfederacion);
int buscarRegion(eConfederacion arrayConfederacion[], int limiteConfederacion, int id,char *pConfederacion);

#endif /* CONFEDERACION_H_ */
