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
    eJuegos juegos[cant];
    eClientes clientes[cant];
    eAlquiler alquiler[cant];

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
                break;
        }



    }while(opcionMenu != 5);

    return 0;
}
