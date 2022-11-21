/*
 * Validaciones.h
 *
 *  Created on: 25 oct. 2022
 *      Author: nicolas
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int esNumerica(char cadena[]);
int getInt(int *pResultado);
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroShort(short *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int getFloat(float* pResultado);
int esFlotante(char* cadena);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int esDescripcion(char* cadena,int longitud);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int esNombre(char* cadena,int longitud);
int getNombre(char* pResultado, int longitud);
int getString(char *cadena, int longitud);

#endif /* VALIDACIONES_H_ */
