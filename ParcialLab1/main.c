#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "negocios.h"
#include "utn.h"
#define cant 100

int main()
{
    eJuegos juegos[cant];
    eClientes clientes[cant];
    int opcionMenu, opcionUno, opcionDos, flag;

    initJuego(juegos, cant);
    initCliente(clientes, cant);

    do
    {
      opcionMenu = menuOpcion_getNumero(opcionMenu, "\n\n Opcion Seleccionada: ", "\n Error! *-* No es un dato valido.");

       switch(opcionMenu)
       {
       case 1:
           opcionUno = menuJuegos_getNumero(opcionUno, "\n\n Opcion Seleccionada: ", "\n Error! *-* No es un dato valido.");

           switch(opcionUno)
           {
           case 1:
               altaJuegos(juegos, cant);
               break;
           case 2:
               break;
           case 3:
               flag = bloqueoCargaVacia(juegos, cant);
               if(flag == 0)
               {
                bajaJuegos(juegos, cant);
               }
               else
               {
                   system("cls");
                   printf("No existen registros aun para Borrar.");
                   system("pause");
               }
               break;
           case 4:
               ordenJuegos(juegos, cant);
               break;
           }

           break;
       case 2:
           opcionDos = menuClientes_getNumero(opcionDos, "\n\n Opcion Seleccionada: ", "\n Error! *-* No es un dato valido.");

           switch(opcionDos)
           {
           case 1:
               altaClientes(clientes, cant);
               break;
           case 2:
               break;
           case 3:
               bajaClientes(clientes, cant);
               break;
           case 4:
               ordenClientes(cant);
               break;
           }

           break;

       case 3:
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
