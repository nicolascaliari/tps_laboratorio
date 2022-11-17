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
int calcular_total_promedio_salario(eJugador arrayJugador[], int limiteJugador);
int calcularConfederacionMayorAniosDeContratoTotal(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion);
int maximo_numero(int num1, int num2, int num3, int num4, int num5, int num6, int *pResultado, int *pIdMayor);
int calcularRegionConMasJugadores(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion);
int calcularPromedio(float *pResultado, int multiplicador, int divisor);
int calcularPorcentajeJugadores(eJugador arrayJugador[], int limiteJugador, eConfederacion arrayConfederacion[], int limiteConfederacion);
int calcularPorcentaje(float *pResultado, int multiplicador, int divisor);
int acumular_salarios(eJugador arrayJugador[] , int limiteJugador, float* acumulador, int* contador);
int Calcular_cantidad_asalariados(eJugador arrayJugador[], int limiteJugador, float promedio, int* cantidad);






#endif /* INFORMES_H_ */
