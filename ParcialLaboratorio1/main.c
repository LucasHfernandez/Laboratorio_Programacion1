#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juegos.h"
#include "clientes.h"
#include "alquiler.h"
#include "utn.h"
#define cant 100

int main()
{
    eAlquiler alquiler[cant];
    eClientes clientes[cant];
    eJuegos juegos[cant];
    int opcionMenu, opcionUno, opcionDos, opcionTres;
    int flag;

    juego_initJuego(juegos, cant);
    cliente_initCliente(clientes, cant);
    alquiler_initAlquiler(alquiler, cant);

    do
    {
        opcionMenu = utn_menuGetNumero(opcionMenu, "\n\nOpcion seleccionada: ", "Error! *-* El dato no es valido.");

        switch(opcionMenu)
        {
            case 1:
                opcionUno = utn_menuJuegosGetNumero(opcionUno, "\n\nOpcion seleccionada: ", "Error! *-* El dato no es valido.");
                switch(opcionUno)
                {
                    case 1:
                        juego_altaJuegos(juegos, cant);
                        break;
                    case 2:
                        flag = juego_bloqueoCargaVaciaJuego(juegos, cant);
                        if(flag == 1)
                        {
                            juego_modificarJuegos(juegos, cant);
                        }
                        else
                        {
                            printf("\nNo hay registros para modificar.");
                            system("pause");
                        }
                        break;
                    case 3:
                        flag = juego_bloqueoCargaVaciaJuego(juegos, cant);
                        if(flag == 1)
                        {
                            juego_bajaJuegos(juegos, cant);
                        }
                        else
                        {
                            printf("\nNo hay registros para eliminar.");
                            system("pause");
                        }
                        break;
                    case 4:
                        flag = juego_bloqueoCargaVaciaJuego(juegos, cant);
                        if(flag == 1)
                        {
                            juego_listaJuegos(juegos, cant);
                        }
                        else
                        {
                            printf("\nNo hay registros para listar.");
                            system("pause");
                        }
                        break;
                    case 5:
                        break;
                }
                break;
            case 2:
                opcionDos = utn_menuClientesGetNumero(opcionDos, "\n\nOpcion seleccionada: ", "Error! *-* El dato no es valido.");
                switch(opcionDos)
                {
                    case 1:
                        cliente_altaClientes(clientes, cant);
                        break;
                    case 2:
                        flag = cliente_bloqueoCargaVaciaCliente(clientes, cant);
                        if(flag == 1)
                        {
                            cliente_modificarCliente(clientes, cant);
                        }
                        else
                        {
                            printf("\nNo hay registros para modificar.");
                            system("pause");
                        }
                        break;
                    case 3:
                        flag = cliente_bloqueoCargaVaciaCliente(clientes, cant);
                         if(flag == 1)
                        {
                            cliente_bajaClientes(clientes, cant);
                        }
                        else
                        {
                            printf("\nNo hay registros para eliminar.");
                            system("pause");
                        }
                        break;
                    case 4:
                        flag = cliente_bloqueoCargaVaciaCliente(clientes, cant);
                         if(flag == 1)
                        {
                            cliente_listaClientes(clientes, cant);
                        }
                        else
                        {
                            printf("\nNo hay registros para listar.");
                            system("pause");
                        }
                        break;
                    case 5:
                        break;
                }
                break;
            case 3:
                opcionTres = utn_menuAlquileresGetNumero(opcionTres, "\n\nOpcion seleccionada: ", "Error! *-* El dato no es valido.");
                switch(opcionTres)
                {
                    case 1:
                        alquiler_altaAlquiler(alquiler, cant);
                        break;
                    /*case 2:
                        flag = alquiler_bloqueoCargaVaciaAlquiler(alquiler, cant);
                        if(flag == 1)
                        {

                        }
                        else
                        {
                            printf("\nNo hay registros para eliminar.");
                            system("pause");
                        }
                        break;
                    case 3:
                        flag = alquiler_bloqueoCargaVaciaAlquiler(alquiler, cant);
                        if(flag == 1)
                        {

                        }
                        else
                        {
                            printf("\nNo hay registros para listar.");
                            system("pause");
                        }
                        break;
                    case 4:
                        break;*/
                }
                break;
            case 4:
                break;
            case 5:
                printf("Adios! n_n");
                break;
        }

    }while(opcionMenu != 5);

    return 0;
}
