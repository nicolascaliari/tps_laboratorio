/*
 * Jugador.h
 *
 *  Created on: 25 oct. 2022
 *      Author: nicolas
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "Confederacion.h"

typedef struct
{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;

int inicializar_array(eJugador arrayJugador[], int limiteJugador);
int jugador_imprimir(eJugador unJugador, eConfederacion arrayConfederacion[], int limiteConfederacion);
int jugador_imprimirArray(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteConfederacion);
int alta_jugador(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion);
int jugador_bajaArray(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion);
int jugador_modificarArray(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int limiteJugador, int limiteConfederacion);
int buscar_espacio_libre(eJugador arrayJugador[], int limiteJugador);
int buscar_id(eJugador arrayJugador[], int limiteJugador, int valorBuscado);
int buscar_espacio_array(eJugador arrayJugador[], int limitejugador);


#endif /* JUGADOR_H_ */
