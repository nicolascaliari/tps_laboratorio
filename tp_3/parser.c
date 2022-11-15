#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "Controller.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	char auxID[100];
	char auxNombre[100];
	char auxEdad[100];
	char auxPosicion[100];
	char auxNacionalidad[100];
	char auxIdSeleccion[100];
	int retornoVariable;
	Jugador* jugadorNuevo = NULL;


	if(pFile != NULL && pArrayListJugador != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxID, auxNombre, auxEdad, auxPosicion, auxNacionalidad, auxIdSeleccion);

		do
		{
		retornoVariable = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxID, auxNombre, auxEdad, auxPosicion, auxNacionalidad, auxIdSeleccion);
		if(retornoVariable == 6)
		{
			jugadorNuevo = jug_newParametros(auxID, auxNombre, auxEdad, auxPosicion,auxNacionalidad, auxIdSeleccion);
			if(jugadorNuevo != NULL)
			{
				if(ll_add(pArrayListJugador,jugadorNuevo) == 0)
				{
					retorno = 0;
				}
			}
		}else
		{
			retorno = -1;
			break;
		}

		}while(!feof(pFile));
	}
    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile, LinkedList* pArrayListJugador){

    int retorno = 0;
    int axuId;
    char auxNombreCompleto[100];
    int auxEdad;
    char axuPosicion[30];
    char auxNacionalidad[30];
    int auxIdSeleccion;
    Jugador* auxJugador;
    int retornoVariable;

    if(pFile != NULL && pArrayListJugador != NULL){


        do{

            auxJugador = jug_new();

            if(auxJugador != NULL){

                retornoVariable = fread(auxJugador, sizeof(Jugador), 1, pFile);

                if(retornoVariable == 1){

                    if(!(jug_getId(auxJugador, &axuId)
                    && jug_getNombreCompleto(auxJugador, auxNombreCompleto)
                    && jug_getEdad(auxJugador, &auxEdad)
                    && jug_getPosicion(auxJugador, axuPosicion)
                    && jug_getNacionalidad(auxJugador, auxNacionalidad)
                    && jug_getIdSeleccion(auxJugador, &auxIdSeleccion))){

                        retorno = 0;
                        break;

                    }
                    retorno = 1;
                }
            }

        }while(!feof(pFile));
    }
    return retorno;
}

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
		int retorno = -1;
		char auxiliarID[100];
		char auxiliarPais[100];
		char auxiliarConfederacion[100];
		char auxiliarConvocados[100];
		int retornoVariable;
		Seleccion* pSeleccion ;


		if(pFile != NULL && pArrayListSeleccion != NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxiliarID, auxiliarPais, auxiliarConfederacion, auxiliarConvocados);

			do
			{

				retornoVariable = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxiliarID, auxiliarPais, auxiliarConfederacion, auxiliarConvocados);

				if(retornoVariable == 4)
				{
				pSeleccion = selec_newParametros(auxiliarID, auxiliarPais, auxiliarConfederacion, auxiliarConvocados);

				if(pSeleccion != NULL)
				{
					 if(ll_add(pArrayListSeleccion,pSeleccion) == 0)
					 {
						 retorno = 0;
					 }
				}else
				{
					printf("\nAlgo salio mal");
				}
			}else
			{
				retorno = -1;
				break;
			}

			}while(!feof(pFile));
		}
    return retorno;
}



/** \brief Parsea los datos de los id desde el archivo ID.csv (modo texto).
 *
 * \param path char*
 * \param auxiliarID char*
 * \return int
 *
 */
int parser_ID(FILE* pFile , char* auxiliarID)
{
	int retorno = -1;
	int retornoVariable;

		if(pFile != NULL && auxiliarID != NULL)
		{

			retornoVariable = fscanf(pFile,"%[^\n]\n", auxiliarID);
			if(retornoVariable == 1)
			{
				printf("\nSe otorgo correctamente el ID");
				retorno = 0;
			}else
			{
				printf("\nError");
				retorno = -1;
			}
		}
	    return retorno;
}
