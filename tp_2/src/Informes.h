/*
 * Informes.h
 *
 *  Created on: 26 oct. 2022
 *      Author: nicolas
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "Jugador.h"
#include "Confederacion.h"

int jugador_ordenar_id_descripcion(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion);
int imprimir_jugador_informes(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteConfederaciones);
int jugador_imprimir_informe(eJugador unJugador, eConfederacion arrayConfederacion[], int limiteConfederacion);
int total_promedio_salario(eJugador arrayJugador[], int limiteJugador);
int calcularConfederacionMayorAniosContratoTotal(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion);
int maximo_numero(int num1, int num2, int num3, int num4, int num5, int num6, int *pResultado, int *pIdMayor);
int regionMasJugadores(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion);
int calcularPromedio(float *pResultado, int multiplicador, int divisor);
int porcentajeJugadores(eJugador arrayJugador[], int limiteJugador);
int calcularPorcentaje(float *pResultado, int multiplicador, int divisor);
#endif /* INFORMES_H_ */
