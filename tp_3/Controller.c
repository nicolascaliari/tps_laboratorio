#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "Validaciones.h"
#include "Controller.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pArchivo = NULL;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			if(parser_JugadorFromText(pArchivo, pArrayListJugador) == 0)
			{
				printf("\nEl archivo se leyo corrrectamente");
				retorno = 0;
			}else
			{
				printf("\nError al leer al archivo");
			}
		}
		fclose(pArchivo);
	}
    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pArchivo;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pArchivo = fopen(path, "rb");
		if(pArchivo != NULL)
		{
			if(parser_JugadorFromBinary(pArchivo, pArrayListJugador))
			{
				printf("\nEl archivo se leyo corrrectamente");
				retorno = 0;
			}else
			{
				printf("\nError al leer al archivo");
			}
		}
		fclose(pArchivo);
	}
    return retorno;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int id;
	char nombreCompleto[1024];
	int edad;
	char posicion[1024];
	char nacionalidad[1024];
	Jugador* pJugador = NULL;

	if(pArrayListJugador != NULL && ll_len(pArrayListJugador) >= 0)
	{
		if(utn_getNombre(nombreCompleto, 1024, "\nIngrese el nombre del jugador", "\nError al ingresar nombre", 2) == 0 &&
		utn_getNumero(&edad, "\nIngrese la edad del jugador", "Error al ingresar la edad del jugador", 18, 50, 2) == 00 &&
		utn_getNombre(posicion, 1024, "\nIngrese la posicion del jugador", "\nError al ingresar posicion", 2) == 0 &&
		utn_getNombre(nacionalidad, 1024, "\nIngrese la nacionalidad del jugador", "\nError al ingresar nacionalidad", 2) == 0)
		{
			int idSeleccion = 0;
			id = idAutoincremental();

			pJugador = jug_new();

			if(pJugador != NULL)
			{
				if(jug_setId(pJugador, id)
						&& jug_setNombreCompleto(pJugador, nombreCompleto)
						&& jug_setEdad(pJugador, edad)
						&& jug_setPosicion(pJugador, posicion)
						&& jug_setNacionalidad(pJugador, nacionalidad)
						&& jug_setIdSeleccion(pJugador, idSeleccion))
				{
					if(ll_add(pArrayListJugador, pJugador) == 0)
					{
						retorno = 0;
						printf("\nJugador cargado correctamente");
					}
				}else
				{
					printf("\nAlgo salio mal");
				}
			}
		}else
		{
			printf("\nNo es posible cargar los empleados");
		}
	}
    return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int opcion;
	int menu;
	int indice;
	int retorno = -1;
	char auxiliarNombre[30];
	int auxiliarEdad;
	char auxiliarPosicion[30];
	char auxiliarNacionalidad[30];
	Jugador* pJugador = NULL;

	if(pArrayListJugador != NULL && ll_len(pArrayListJugador) != 0)
	{

		if(controller_listarJugadores(pArrayListJugador) == 0)
		{

			if(utn_getNumero(&opcion, "\nIngrese el ID que desea modificas", "\nError al ingresar ID a modificar", 1, 10000, 2) == 0)
			{

				indice = encontrarjugador(pArrayListJugador, opcion);

				if(indice != 1)
				{
					pJugador = (Jugador*)ll_get(pArrayListJugador, indice);

					if(pJugador != NULL)
					{

						if(utn_getNumero(&menu, "\n          Menu de modificar"
													"\n1-Modificar nombre"
													"\n2-Modificar edad"
													"\n3-Modificar posicion"
													"\n4-Modificar nacionalidad"
													,"Error ingrese las opciones que se muestran en el menu", 1,4, 2)==0)
						{
							switch(menu)
							{
							case 1:
								if(utn_getNombre(auxiliarNombre, 30, "\nIngrese el nuevo nombre", "\nError", 2) == 0)
								{
									jug_setNombreCompleto(pJugador, auxiliarNombre);
									retorno = 0;
								}
								break;
							case 2:
								if(utn_getNumero(&auxiliarEdad, "\nIngrese la nueva edad", "\nError al ingresar nueva edad", 18, 50, 2) == 0)
								{
									jug_setEdad(pJugador, auxiliarEdad);
									retorno = 0;
								}
								break;
							case 3:
								if(utn_getNombre(auxiliarPosicion, 30, "\nIngrese la nueva posicion", "\nError", 2) == 0)
								{
									jug_setPosicion(pJugador, auxiliarPosicion);
									retorno = 0;
								}
								break;
							case 4:
								if(utn_getNombre(auxiliarNacionalidad, 30, "\nIngrese la nueva nacionalidad", "\nError al ingresar la nueva nacionalidad", 2) == 0)
								{
									jug_setNacionalidad(pJugador, auxiliarNacionalidad);
									retorno = 0;
								}
								break;

							}
						}
					}
				}
			}
		}
	}

		return retorno;
}


/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Jugador* pJugador = NULL;
	Seleccion* pSeleccion = NULL;
	int idBuscado;
	int indice;
	int indiceSelec;
	int seleccionID;
	int convocado;

		if(pArrayListJugador != NULL && pArrayListSeleccion != NULL && ll_len(pArrayListJugador) >= 0)
		{

			if(controller_listarJugadores(pArrayListJugador) == 0)
			{

				utn_getNumero(&idBuscado, "\nIngrese el ID que desea eliminar", "\nError al eliminar el id", 1, 10000, 2);

				indice = encontrarjugador(pArrayListJugador, idBuscado);

				if(indice != -1)
				{
					pJugador = (Jugador*)ll_get(pArrayListJugador, indice);
					jug_getIdSeleccion(pJugador, &seleccionID);
					if(seleccionID != 0)
					{
						indiceSelec = encontrarSeleccion(pArrayListSeleccion, seleccionID);
						if(indiceSelec != -1)
						{
							pSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, indiceSelec);

							selec_getConvocados(pSeleccion, &convocado);
							convocado--;
							selec_setConvocados(pSeleccion, convocado);
						}
					}
					ll_remove(pArrayListJugador, indice);
					jug_delete(pJugador);
					printf("\nEmpleado eliminado correctamente\n");
					retorno = 0;
				}else
				{
					printf("\nUsted no dio a nadie de baja");
				}
			}

		}
    return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */

int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = -1;
    Jugador* pJugador = NULL;

    	if(pArrayListJugador != NULL)
    	{

    		for(int i = 0; i < ll_len(pArrayListJugador); i++)
    		{
    			pJugador = (Jugador*)ll_get(pArrayListJugador, i);

    			if(pJugador != NULL)
    			{
    				if(imprimirJugador(pArrayListJugador,i) == 0)
    				{
    					retorno = 0;
    				}
    			}
    		}
    	}else
    	{
    		printf("No funciono bien");
    	}

    return retorno;
}


/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int limite;
	Jugador* auxiliarJugador = NULL;
	FILE* pArchivo;
	int auxiliarID;
	char auxiliarNombre[1024];
	int auxiliarEdad;
	char auxiliarPosicion[1024];
	char auxiliarNacionalidad[1024];
	int auxiliarIdSeleccion;
	int i;

		if(path != NULL && pArrayListJugador !=NULL)
		{
			pArchivo = fopen(path, "w");

			if(pArchivo != NULL)
			{
				limite = ll_len(pArrayListJugador);
				fprintf(pArchivo, "id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
				for(i=0 ; i < limite; i++)
				{
					auxiliarJugador = ll_get(pArrayListJugador, i);

					if(jug_getId(auxiliarJugador, &auxiliarID)
							&& jug_getNombreCompleto(auxiliarJugador, auxiliarNombre)
							&& jug_getEdad(auxiliarJugador, &auxiliarEdad)
							&& jug_getPosicion(auxiliarJugador, auxiliarPosicion)
							&& jug_getNacionalidad(auxiliarJugador, auxiliarNacionalidad)
							&& jug_getIdSeleccion(auxiliarJugador, &auxiliarIdSeleccion))
					{
						fprintf(pArchivo, "%d, %s, %d, %s , %s, %d\n", auxiliarID, auxiliarNombre, auxiliarEdad, auxiliarPosicion, auxiliarNacionalidad, auxiliarIdSeleccion);
						retorno = 0;
					}

				}
			}else
			{
				printf("Algo salio mal");
			}
			fclose(pArchivo);
		}
    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int limite;
	Jugador* auxiliarJugador = NULL;
	FILE* pArchivo;
	int retornoWrite;
	int i;

		if(path != NULL && pArrayListJugador !=NULL)
		{
			pArchivo = fopen(path, "wb");

			if(pArchivo != NULL)
			{
				limite = ll_len(pArrayListJugador);
				for(i=0 ; i < limite; i++)
				{
					auxiliarJugador = (Jugador*)ll_get(pArrayListJugador, i);

				if(auxiliarJugador != NULL)
				{
					retornoWrite = fwrite(auxiliarJugador, sizeof(Jugador), 1, pArchivo);

					if(retornoWrite == 1)
					{
						retorno = 0;
					}else
					{
						break;
					}
				}
			}
		}
		fclose(pArchivo);
	}

    return retorno;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	FILE* pArchivo;

	if(path != NULL && pArrayListSeleccion != NULL)
	{
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			if(parser_SeleccionFromText(pArchivo, pArrayListSeleccion) == 0)
			{
				printf("\nEl archivo se leyo corrrectamente");
				retorno = 0;
			}else
			{
				printf("\nError al leer al archivo de selecciones");
			}
		}
		fclose(pArchivo);
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
	int opcion;
		int menu;
		int indice;
		int retorno = -1;
		int auxiliarConvocados;
		Seleccion* pSeleccion = NULL;

		if(pArrayListSeleccion != NULL && ll_len(pArrayListSeleccion) != 0)
		{

			if(controller_listarJugadores(pArrayListSeleccion) == 0)
			{

				if(utn_getNumero(&opcion, "\nIngrese el ID que desea modificas", "\nError al ingresar ID a modificar", 1, 30, 2) == 0)
				{

					indice = encontrarjugador(pArrayListSeleccion, opcion);

					if(indice != 1)
					{
						pSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, indice);

						if(pSeleccion != NULL)
						{

							if(utn_getNumero(&menu, "\n          Menu de modificar"
														"\n1-Modificar nombre"
														"\n2-Modificar edad"
														"\n3-Modificar posicion"
														"\n4-Modificar nacionalidad"
														,"Error ingrese las opciones que se muestran en el menu", 1,4, 2)==0)
							{
								switch(menu)
								{
								case 1:
									if(utn_getNumero(&auxiliarConvocados, "\nIngrese nuevo numero de convocado ", "\nError", 1, 22, 2) == 0)
									{
										selec_setConvocados(pSeleccion, auxiliarConvocados);
										retorno = 0;
									}
									break;
								}
							}
						}
					}
				}
			}
		}
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{

    int retorno = -1;
    Seleccion* pSeleccion = NULL;

    if(pArrayListSeleccion != NULL)
    {

        for(int i = 0; i < ll_len(pArrayListSeleccion); i++)
        {

            pSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);

            if(pSeleccion != NULL)
            {

                if(imprimirSeleccion(pArrayListSeleccion, i) == 0){
                    retorno = 0;
                }
            }
        }
    }else
    {
    	printf("No funciono bien");
    }

    return retorno;

}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
		int limite;
		Seleccion* auxiliarSeleccion = NULL;
		FILE* pArchivo;
		limite = ll_len(pArrayListSeleccion);
		int auxiliarID;
		char auxiliarPais[1024];
		char auxiliarConfederacion[1024];
		int auxiliarConvocados;
		int i;

		if(path != NULL && pArrayListSeleccion !=NULL)
		{
			pArchivo = fopen(path, "w");

			if(pArchivo != NULL)
			{
				for(i=0 ; i < limite; i++)
				{
					auxiliarSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
					if(auxiliarSeleccion != NULL)
					{
						if(selec_getId(auxiliarSeleccion, &auxiliarID )
								&& selec_getPais(auxiliarSeleccion, auxiliarPais)
								&& selec_getConfederacion(auxiliarSeleccion, auxiliarConfederacion)
								&& selec_getConvocados(auxiliarSeleccion, &auxiliarConvocados))
						{
							fprintf(pArchivo, "%d, %s, %s, %d\n", auxiliarID, auxiliarPais, auxiliarConfederacion, auxiliarConvocados);
							retorno = 0;
						}
					}

				}
			}else
			{
				printf("Algo salio mal");
			}
			fclose(pArchivo);
		}
    return retorno;
}


int controller_ConvocarJugadores(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int idSeleccion;
	int buscarId;
	int indice;
	int indiceSeleccion;
	int convocados = 0;
	Jugador* auxJugador = NULL;
	Seleccion* auxSeleccion = NULL;
	int limite = ll_len(pArrayListJugador);


	if(pArrayListSeleccion != NULL && pArrayListJugador != NULL)
	{

		for(int i = 0; i < limite; i++)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador, i);
				if(auxJugador != NULL)
				{
					jug_getIdSeleccion(auxJugador, &idSeleccion);

					if(idSeleccion == 0)
					{
						imprimirJugadorConSelec(pArrayListJugador, pArrayListSeleccion, i);
					}
				}
		}

			if(utn_getNumero(&buscarId, "\nSeleccione el Jugador a convocar por su ID\n",
				"\nError Reingrese el ID: ", 1, 3000,2) == 0)
			{
				indice = encontrarjugador(pArrayListJugador, buscarId);

				if(indice != -1)
				{
					auxJugador = (Jugador*)ll_get(pArrayListJugador, indice);
					if(auxJugador != NULL)
					{
						controller_listarSelecciones(pArrayListSeleccion);

						if(utn_getNumero(&idSeleccion, "\nIngrese a que seleccion sera convocado: ",
								"\nNo existe una seleccion con ese ID\nReingrese: ", 1, 32, 2) == 0)
						{
							indiceSeleccion = encontrarSeleccion(pArrayListSeleccion, idSeleccion);

							auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, indiceSeleccion);
							if(auxSeleccion != NULL)
							{
								if(selec_getConvocados(auxSeleccion, &convocados))
								{
									printf("anduve bien el get convocados\n");
								}

									if(jug_setIdSeleccion(auxJugador, idSeleccion))
									{
										convocados++;
										if(selec_setConvocados(auxSeleccion, convocados))
										{
											retorno = 0;
										}

									}
							}
						}
					}
				}
			}
		}

	return retorno;
}


int quitarJugadorDeSeleccion(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int auxiliariD;
	int indice;
	int seleccion;
	int indiceSelec;
	int convocados;
	Jugador* pJugador = NULL;
	Seleccion* pSeleccion = NULL;
	controller_ListarConvocados(pArrayListJugador, pArrayListSeleccion);
	utn_getNumero(&auxiliariD, "\nIngrese ID del jugador para quitar de la seleccion", "\nError al ingresar ID", 1, 370, 2);

	indice = encontrarjugador(pArrayListJugador, auxiliariD);


	if(indice != 1)
	{
		pJugador = ll_get(pArrayListJugador, indice);
		jug_getIdSeleccion(pJugador, &seleccion);
		indiceSelec = encontrarSeleccion(pArrayListSeleccion, seleccion);
		pSeleccion = ll_get(pArrayListSeleccion, indiceSelec);
		jug_setIdSeleccion(pJugador, 0);
		selec_getConvocados(pSeleccion, &convocados);
		convocados--;
		selec_setConvocados(pSeleccion, convocados);
		retorno = 0;
	}
	return retorno;
}




int controller_ListarConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Jugador* Jugadores = NULL;
	int limite  = ll_len(pArrayListJugador);
	int convocado;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		printf("|%10s | %20s | %10s | %20s | %10s  | %10s |\n", "ID", "NOMBRE JUGADOR", "EDAD",
																"POSICION", "NACIONALIDAD", "idSeleccion");
		for(int i = 0; i < limite ; i++)
		{
			Jugadores = (Jugador*)ll_get(pArrayListJugador, i);

			if(Jugadores != NULL)
			{
				jug_getIdSeleccion(Jugadores, &convocado);

				if(convocado != 0){

					if(imprimirJugadorConSelec(pArrayListJugador, pArrayListSeleccion,i) == 0)
					{
						retorno = 0;
					}
				}
			}
		}
	}

	return retorno;
}


int controllerCargarId(char* path, char* auxiliarID)
{
	int retorno = -1;
	FILE* pArchivo = NULL;

		if(path != NULL && auxiliarID != NULL)
		{
			pArchivo = fopen(path,"r");

			if(pArchivo != NULL)
			{
				if(parser_ID(pArchivo, auxiliarID )== 0)
				{
					printf("\nEl archivo se leyo correctamente");
					retorno = 0;
				}else
				{
					printf("\nEl archivo se leyo mal");
				}

			}
		}
	return retorno;
}




int controller_listarJugadoresConSelec(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{

    int retorno = -1;
    Jugador* pJugador = NULL;

    if(pArrayListJugador != NULL)
    {

        for(int i = 0; i < ll_len(pArrayListJugador); i++)
        {

            pJugador = (Jugador*)ll_get(pArrayListJugador, i);

            if(pJugador != NULL)
            {
                if(imprimirJugadorConSelec(pArrayListJugador,pArrayListSeleccion,i) == 0)
                {
                    retorno = 0;
                }
            }
        }
    }else
    {
    	printf("No funciono bien");
    }

    return retorno;
}


//PUNTO 8 Y 9------------------------------------




int controller_guardarJugadorPorConfederacionBinario(char *path, LinkedList* pArrayListJugador,
											  LinkedList* pArrayListSeleccion, char* Confederacion){

	int retorno = -1;
	int longitudLinkedList;
	int auxIdJugador;
	char auxConfederacion[30];
	Jugador* auxJugador = NULL;
	LinkedList* listaClon = ll_clone(pArrayListJugador);
	LinkedList* nuevaLista = ll_newLinkedList();

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL && Confederacion != NULL){

		longitudLinkedList = ll_len(listaClon);

		for (int i = 0; i < longitudLinkedList; i++){

			auxJugador = (Jugador*)ll_get(listaClon, i);

			jug_getIdSeleccion(auxJugador, &auxIdJugador);
									//La de buscar la confederacion con letras. tiene que retornar 1 para bien.
			if(auxIdJugador > 0
			&& encontrarConfederacion(pArrayListSeleccion, auxIdJugador, auxConfederacion) == 0){

				if (strncmp(auxConfederacion, Confederacion, 30) == 0)
				{
					printf("Llegue");
					ll_add(nuevaLista, auxJugador);
					controller_guardarJugadoresModoBinario(path, nuevaLista);
					ll_deleteLinkedList(nuevaLista);
					ll_deleteLinkedList(listaClon);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int controller_cargarJugadoresPorConfederacionBinario(char *path, LinkedList* pArrayListJugador,
											LinkedList* pArrayListSeleccion, char Confederacion[]){
	int retorno = 0;
	int longitudLinkedList;
	int auxIdJugador;
	char auxConfederacion[30];
	LinkedList* listaClon = ll_clone(pArrayListJugador);
	LinkedList* nuevaLista = ll_newLinkedList();
	Jugador* auxJugador;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL && Confederacion != NULL){

		if (controller_cargarJugadoresDesdeBinario(path, listaClon)){

			longitudLinkedList = ll_len(listaClon);

			for (int i = 0; i < longitudLinkedList; i++){

				auxJugador = (Jugador*) ll_get(listaClon, i);

				jug_getIdSeleccion(auxJugador, &auxIdJugador);
											//validar retorno 1.
				if (auxIdJugador > 0
				&& encontrarConfederacion(pArrayListSeleccion, auxIdJugador, auxConfederacion)){

					if (strncmp(auxConfederacion, Confederacion, 30) == 0){

						ll_add(nuevaLista, auxJugador);
						retorno = 1;
					}
				}
			}
			controller_listarJugadoresConSelec(pArrayListJugador, pArrayListSeleccion);

		}
	}
	return retorno;
}


