/*
 * validaciones.h
 *
 *  Created on: 12 sep. 2022
 *      Author: nicolas
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int ingresarNumeros_utn(int * resultado , char * mensaje, char * mensajeError , int minimo , int maximo , int reintentos);
int esNumerica( char * cadena);
int getInt(int * resultado);
int ingresarNumero(int * resultado, char * mensaje, int minimo , int maximo, char * mensajeError);
void inicializarVector(int vector[], int size, int inicial);
char ingresarString(int * resultado, char * mensaje, char *mensajeError);
int normalizar(char * string, int len);


#endif /* VALIDACIONES_H_ */
