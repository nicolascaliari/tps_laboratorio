#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"

int main(void)
{

    int option = 0;
    LinkedList* listaJugadores = ll_newLinkedList();

    puts("funciona ok");

    do{
        switch(option)
        {
            case 1:
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);

                break;
        }
    }while(option != 10);

    return EXIT_SUCCESS;
}

