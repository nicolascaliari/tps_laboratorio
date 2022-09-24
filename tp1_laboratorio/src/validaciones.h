/*
 * validaciones.h
 *
 *  Created on: 12 sep. 2022
 *      Author: nicolas
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/**
 * \brief Verifica
 * \param
 * \return
 *
 */
int esNumerica(char cadena[]);


/**
 * \brief
 * \param
 * \return
 *
 */

int getInt(int *pResultado);

/**
 *\brief solicita un numero al usuario, luego que se haya verificado devuelve el resultado.
 *\param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\param  mensaje Es el mensaje que se va a mostrar
 *\param mensajeError Es el mensaje de error
 *\param minimo Es el numero minimo aceptado
 *\param maximo Es el numero maximo aceptado
 *\param reintentos reintentos Es la cantidad de reintentos que tiene
 * \return Retorna 0 si se obtuvo el numero y retorna -1 si no se obtuvo el numero
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);


float calcularPromedio(float contador );


int getFloat(float* pResultado);


int esFlotante(char* cadena);



int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);



int getString(char* cadena, int longitud);



#endif /* VALIDACIONES_H_ */
