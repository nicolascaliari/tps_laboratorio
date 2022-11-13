#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete();
int imprimirSeleccion(LinkedList* pArrayListaSelecciones, int indice);
int encontrarSeleccion(LinkedList* pArrayListaSelecciones, int indice);
int encontrarConfederacion(LinkedList* pArrayListaSelecciones, int indice, char* confederacion);
int encontrarSeleccionString(LinkedList* pArrayListaSeleccion, int indice, char* Seleccion);
int selec_ordenarPorConfederacion(void* elementoA, void* elementoB);
int selec_getId(Seleccion* this,int* id);

int selec_getPais(Seleccion* this,char* pais);

int selec_getConfederacion(Seleccion* this,char* confederacion);

int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);



#endif // selec_H_INCLUDED
