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
	int isEmpty;

}eConfederacion;

int hardcodeoConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion);
int pedirConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion);
int mostrarConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion);
int buscarConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion, int id,char *pConfederacion);
int buscarRegion(eConfederacion arrayConfederacion[], int limiteConfederacion, int id,char *pConfederacion);

int inicializar_array_confederacion(eConfederacion arrayConfederacion[], int limiteConfederacion);
int alta_confederacion(eConfederacion arrayConfederacion[], int limiteConfederacion);
int confederacion_bajaArray(eConfederacion arrayConfederacion[], int limiteConfederacion);
int confederacion_modificarArray(eConfederacion arrayConfederacion[],int limiteConfederacion);
int buscar_espacio_libre_confederacion(eConfederacion arrayConfederacion[], int limiteConfederacion);
int buscar_id_confederacion(eConfederacion arrayConfederacion[], int limiteConfederacion, int valorBuscado);
int buscar_espacio_array_confederacion(eConfederacion arrayConfederacion[], int limiteConfederacion);







#endif /* CONFEDERACION_H_ */
