#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "juegos.h"
#include "alquiler.h"
#include "clientes.h"

void alquiler_initAlquiler(eAlquiler alquiler[], int cantidad)
{
    int i;

    for(i = 0; i < cantidad; i++)
    {
        alquiler[i].isEmpty = 1;
    }
}

int alquiler_obtenerEspacioLibreAlquiler(eAlquiler alquiler[], int cantidad)
{
    int i, retorno = -1;

    for(i = 0; i < cantidad; i++)
    {
        if(alquiler[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}


static int juego_genCodigo(void)
{
    static int nextId = -1;

    return ++nextId;
}


int alquiler_bloqueoCargaVaciaAlquiler(eAlquiler alquiler[] ,int cantidad)
{
    int i, flag;

    for(i = 0; i < cantidad; i++)
    {
        if(alquiler[i].isEmpty == 1)
        {
            flag = 0;
        }
        else
        {
            flag = 1;
            break;
        }
    }

     return flag;
}


void alquiler_altaAlquiler(eAlquiler alquiler[], int cantidad)
{
    eJuegos juegos[cantidad];
    eClientes clientes[cantidad];
    int index;
    int opcion;
    int i;
    int auxCodigoJuego;
    int auxCodigoCliente;

    do
    {
        index = alquiler_obtenerEspacioLibreAlquiler(alquiler, cantidad);

        if(index != -1)
        {
            system("cls");
            printf("Altas de los Alquileres.");
            printf("\n-----------------------------------------");

            printf("\nIngrese el codigo del juego: ");
            fflush(stdin);
            scanf("%d", &auxCodigoJuego);

            printf("\nIngrese el codigo del cliente: ");
            fflush(stdin);
            scanf("%d", &auxCodigoCliente);

            for(i = 0; i < cantidad; i++)
            {
                if(auxCodigoJuego == juegos[i].codigo)
                {
                    alquiler[i].codigoJuego = juegos[i].codigo;
                }
                else if(auxCodigoCliente == clientes[i].codigo)
                {
                    alquiler[i].codigoCliente = clientes[i].codigo;
                }
            }

            printf("Ingrese la fecha: ");
            scanf("%d %d %d", &alquiler[index].fecha.dia, &alquiler[index].fecha.mes, &alquiler[index].fecha.anio);

            alquiler[index].codigoAlquiler = juego_genCodigo();

            alquiler[index].isEmpty = 0;

            printf("\nEl Alquiler fue dado de alta n_n");
            system("pause");

            printf("\n\nDesea dar de alta otro dato? 1= SI 2= NO");
            printf("\nOpcion seleccionada: ");
            fflush(stdin);
            scanf("%d", &opcion);
        }
    }while(opcion != 2);
}
