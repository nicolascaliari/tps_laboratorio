#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Informes.h"
#include "Jugador.h"
#include "Confederacion.h"
#include "Salida_datos.h"

/**
 * \brief Calcula porcentaje
 * \param pResultado puntero a float
 * \param multiplicador variable de tipo int
 * \param divisor variable de tipo int
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int calcularPorcentaje(float *pResultado, int multiplicador, int divisor)
{

    float promedio;
    int retorno = -1;

    if(pResultado != NULL && divisor != 0)
    {
        promedio = (float)(multiplicador * 100) / divisor;

        *pResultado = promedio;
        retorno = 0;

    }else
    {
    	*pResultado = 0;
    }

    return retorno;
}


/**
 * \brief Calcula promedio
 * \param pResultado puntero a float
 * \param multiplicador variable de tipo int
 * \param divisor variable de tipo int
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int calcularPromedio(float *pResultado, int multiplicador, int divisor)
{

    float promedio;
    int retorno = -1;

    if(pResultado != NULL && divisor != 0)
    {
        promedio = (float)(multiplicador) / divisor;

        *pResultado = promedio;
        retorno = 0;

    }else
    {
    	*pResultado = 0;
    }

    return retorno;
}



/**
 * \brief Calcula el numero maximo
 * \param numero1, numero2, numero3, numero4, numero5, numero 6 variables de tipo int
 * \param pResultado puntero a int
 * \param pIdMayor puntero a int
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int maximo_numero(int numero1, int numero2, int numero3, int numero4, int numero5, int numero6, int *pResultado, int *pIdMayor)
{

    int retorno = -1;
    int resultado;

    if(pResultado != NULL && pIdMayor != NULL)
    {

        if(numero1 > numero2 && numero1 > numero3 && numero1 > numero4 && numero1 > numero5 && numero1 > numero6)
        {
        	*pIdMayor = 100;
            resultado = numero1;

        }
        else if (numero2 > numero3 && numero2 > numero4 && numero2 > numero5 && numero2 > numero6 )
        {
        	*pIdMayor = 101;
            resultado = numero2;

        }
        else if (numero3 > numero4 && numero3 > numero5 && numero3> numero6)
        {
        	*pIdMayor = 102;
            resultado = numero3;

        }
        else if(numero4 > numero5 && numero4 > numero6)
        {
        	*pIdMayor = 103;
            resultado = numero4;

        }
        else if( numero5 > numero6)
        {
        	*pIdMayor = 104;
            resultado = numero5;

        }
        else
        {
        	*pIdMayor = 105;
            resultado = numero6;

        }

        retorno = 0;
    }

    if(retorno == 0)
    {

        *pResultado = resultado;
    }

    return retorno;
}
