/*
 * validaciones.h
 *
 *  Created on: 12 sep. 2022
 *      Author: nicolas
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_


int esNumerica( char * cadena);
int ingresarNumeroInt(int * resultado, char * mensaje, int minimo , int maximo, char * mensajeError);
int ingresarNumeroFloat(float *resultado, char *mensaje, int minimo, int maximo, char *mensajeError);
int esString(char * string);




#endif /* VALIDACIONES_H_ */
