/*
 * validaciones.h
 *
 *  Created on: 12 sep. 2022
 *      Author: nicolas
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_


int esNumerica(char cadena[]);
int getInt(int *pResultado);
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
float calcularPromedio(float contador );
int getFloat(float* pResultado);
int esFlotante(char* cadena);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int getString(char* cadena, int longitud);



#endif /* VALIDACIONES_H_ */
