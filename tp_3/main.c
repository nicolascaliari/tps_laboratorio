#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Validaciones.h"
#include "Salida_datos.h"
#include "Seleccion.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    char confederacion[30];
    strncpy(confederacion, "CONMEBOL", 30);
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();


    do{
    	if(utn_getNumero(&option, "\n          Bienvenido al menu principal"
									"\n1-Cargar los datos de los jugadores y selecciones "
									"\n2-Alta de jugador"
									"\n3-Modificacion de jugador"
									"\n4-Baja de jugador"
									"\n5-Listados"
									"\n6-Convocar Jugadores"
									"\n7-Ordenar y listar"
									"\n8-Generar archivo binario"
									"\n9-Cargar archivo binario"
									"\n10-Guardar archivo .csv"
    								"\n11-Salir", "Error ingrese las opciones que se muestran en el menu",1, 11, 2)==0)
    	{


        switch(option)
        {
            case 1:
            	if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores)== 0)
            	{
            		printf("\nEl archivo de jugadores se leyo correctamente");
            	}
            	if(controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones)==0)
            	{
            		printf("\nEl archivo de selecciones se leyo correctamente");
            	}
                break;
            case 2:
            	if(controller_agregarJugador(listaJugadores) == 0)
            	{
            		printf("\nTodo salio bien al dar de alta");
            	}
            	break;
            case 3:
            	if(controller_editarJugador(listaJugadores) == 0)
            	{
            		printf("\nTodo salio bien al modificar");
            	}
                break;
            case 4:
            	if(controller_removerJugador(listaJugadores, listaSelecciones) == 0)
            	{
            		printf("\nTodo salio bien al dar de baja");
            	}
                break;
            case 5:
            	if(menuListar(listaJugadores, listaSelecciones) == 0)
            	{
            		printf("Todo ok");
            	}
                break;
            case 6:
            	if(menuConvocarJugadores(listaJugadores, listaSelecciones))
            	{
            		printf("\nTodo ok");
            	}
                break;
            case 7:
            	menuListar_ordenar(listaJugadores,listaSelecciones);
                break;
            case 8:
            	menu_guardar_JugadoresBinario(listaJugadores, listaSelecciones);
                break;
            case 9:
            	menu_cargar_JugadoresBinario(listaJugadores, listaSelecciones);
                break;
            case 10:
            	controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
                break;
            case 11:
            	break;
        }
    }
    }while(option != 11);

    return 0;
}

