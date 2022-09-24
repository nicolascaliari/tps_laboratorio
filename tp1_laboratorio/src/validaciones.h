/*
 * validaciones.h
 *
 *  Created on: 12 sep. 2022
 *      Author: nicolas
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a analizar
 * \return 1 si es  numerica (verdadera) y retorna 0 si no es numerica (falsa)
 *
 */
int esNumerica(char cadena[]);


/**
 * \brief Obtiene un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return retorna 1 si se obtiene un numero entero y retorna -1 si no se consiguio
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


/**
 * \brief obtiene un contador y luego retorna el resultado
 * \param obtiene un contador y realiza los calculos
 * \return retorna el calculo directamente
 */

float calcularPromedio(float contador );

/**
* \brief ​Verifica​ ​si​ ​la​ ​cadena​ ​ingresada​ ​es​ ​numerica
* \​param​ pResultado ​Puntero​ ​al​ ​espacio​ ​de​ ​memoria​ ​donde​ ​se​ ​dejara​ el ​resultado​ ​de​ ​la​ ​funcion
* \return ​Retorna​ 0 (EXITO) ​si​ ​se​ ​obtiene​ ​un​ ​numero​ ​entero​ y -1 (ERROR) ​si​ no
*
*/

int getFloat(float* pResultado);


/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
int esFlotante(char* cadena);



/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int getString(char* cadena, int longitud);



#endif /* VALIDACIONES_H_ */
