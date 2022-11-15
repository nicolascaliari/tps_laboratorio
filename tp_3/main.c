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
    int bandera_cargar_datos = 0;
    int bandera_cargar_datos_binarios = 0;
    int bandera_guardar_archivos = 0;
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
            	if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores)== 0
            		&& controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones) == 0)

            	{
            		printf("\nLos archivos  se leyeron correctamente");
            		bandera_cargar_datos = 1;
            	}else
            	{
            		printf("\nLos archivos no se leyeron correctamente");
            	}
                break;
            case 2:
            	if(bandera_cargar_datos == 1 && ll_isEmpty(listaJugadores) == 0)
            	{
                	if(controller_agregarJugador(listaJugadores) == 0)
                	{
                		printf("\nTodo salio bien al dar de alta");
                	}
            	}else
            	{
            		printf("\nDebes ingresar la opcion uno primero");
            	}
            	break;
            case 3:
            	if(bandera_cargar_datos == 1 && ll_isEmpty(listaJugadores) == 0)
            	{
                	if(controller_editarJugador(listaJugadores) == 0)
                	{
                		printf("\nTodo salio bien al modificar");
                	}
            	}else
            	{
            		printf("\nDebes ingresar la opcion uno primero");
            	}
                break;
            case 4:
            	if(bandera_cargar_datos == 1 && ll_isEmpty(listaJugadores) == 0)
            	{
                	if(controller_removerJugador(listaJugadores, listaSelecciones) == 0)
                	{
                		printf("\nTodo salio bien al dar de baja");
                	}
            	}else
            	{
            		printf("\nDebes ingresar la opcion uno primero");
            	}
                break;
            case 5:
            	if(bandera_cargar_datos == 1 && ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0)
            	{
                	if(menuListar(listaJugadores, listaSelecciones) == 0)
                	{
                		printf("Todo ok");
                	}
            	}else
            	{
            		printf("\nDebes ingresar la opcion uno primero");
            	}
                break;
            case 6:
            	if(bandera_cargar_datos == 1 && ll_isEmpty(listaJugadores) == 0)
            	{
                	if(menuConvocarJugadores(listaJugadores, listaSelecciones) == 0)
                	{
                		printf("\nTodo ok");
                	}
            	}else
            	{
            		printf("\nDebes ingresar la opcion uno primero");
            	}
                break;
            case 7:
            	if(bandera_cargar_datos == 1 && ll_isEmpty(listaJugadores) == 0)
            	{
            		if(menuListar_ordenar(listaJugadores,listaSelecciones) == 0)
            		{
            			printf("\nSalio todo bien");
            		}
            	}else
            	{
            		printf("\nDebes ingresar la opcion uno primero");
            	}
                break;
            case 8:
            	if(bandera_cargar_datos == 1 && ll_isEmpty(listaJugadores) == 0)
            	{
            		menu_guardar_JugadoresBinario(listaJugadores, listaSelecciones);
            		bandera_cargar_datos_binarios = 1;
            	}else
            	{
            		printf("\nDebes ingresar la opcion uno primero");
            	}

                break;
            case 9:
            	if(bandera_cargar_datos == 1 && bandera_cargar_datos_binarios == 1)
            	{
                	if(menu_cargar_JugadoresBinario(listaJugadores, listaSelecciones) == 0)
                	{
                		printf("\nTodo salio bien");

                	}
            	}else
            	{
            		printf("\nDebes ingresar la opcion 1 y 8");
            	}

                break;
            case 10:
            	if(bandera_cargar_datos == 1 && ll_isEmpty(listaJugadores) == 0)
            	{
              		if(controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores) == 0
                    			&& controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones ) == 0)
                    		{
              			ll_clear(listaJugadores);
              			ll_clear(listaJugadores);
              					bandera_guardar_archivos = 1;
                    		}
            	}else
            	{
            		printf("\nDebes ingresar la opcion uno primero");
            	}
                break;
            case 11:
            	if(bandera_guardar_archivos == 0)
            	{
            		utn_getNumero(&option, "\nNo guardatse nada, seguro deseas salir? Ingresa 11 para salir o 1 para seguir.", "\nError", 1, 11, 2);

            	}else{
            		printf("\nPrograma finalizado");
            		ll_deleteLinkedList(listaSelecciones);
            		ll_deleteLinkedList(listaJugadores);
            	}
            	break;
        }
    }
    }while(option != 11);

    return 0;
}

