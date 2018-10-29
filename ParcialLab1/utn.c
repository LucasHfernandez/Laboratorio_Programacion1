#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "negocios.h"
#include "utn.h"

int menuOpcion_getNumero(int opcion, char* mensaje, char* mensajeErrorUno)
{
    system("cls");
    printf("Bienvenido al Menu, que desea realizar?");
    printf("\n\n 1. Menu Juegos.");
    printf("\n 2. Menu Clientes.");
    printf("\n 3. Menu Alquileres.");
    printf("\n 4. Informes.");
    printf("\n 5. Salir.");
    printf(mensaje);
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion > 5 || opcion < 1)
    {
        printf(mensajeErrorUno);
        printf("\n\n Por favor ingrese otro numero: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}

int menuJuegos_getNumero(int opcion, char* mensaje, char* mensajeErrorUno)
{
    char salir;

    system("cls");
    printf("\t\tBienvenido al Menu Juegos, que desea realizar?");
    printf("\n\n 1. Alta del juego.");
    printf("\n 2. Modificar informacion.");
    printf("\n 3. Baja del juego.");
    printf("\n 4. Listado de juegos.");
    printf("\n S. Volver.");
    printf(mensaje);
    fflush(stdin);
    scanf("%d", &opcion);
    scanf("%c", &salir);

    if(salir == 's')
    {
        opcion = 0;
        return opcion;
    }

    while(opcion > 4 || opcion < 1 || opcion != 's')
    {
        printf(mensajeErrorUno);
        printf("\n\n Por favor ingrese otro dato: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }


    return opcion;
}

int menuClientes_getNumero(int opcion, char* mensaje, char* mensajeErrorUno)
{
    char salir;

    system("cls");
    printf("\t\tBienvenido al Menu Clientes, que desea realizar?");
    printf("\n\n 1. Alta del cliente.");
    printf("\n 2. Modificar informacion.");
    printf("\n 3. Baja del cliente.");
    printf("\n 4. Listado de clientes.");
    printf("\n S. Volver.");
    printf(mensaje);
    fflush(stdin);
    scanf("%d", &opcion);
    scanf("%c", &salir);

    if(salir == 's')
    {
        opcion = 0;
        return opcion;
    }

    while(opcion > 4 || opcion < 1 || opcion != 's')
    {
        printf(mensajeErrorUno);
        printf("\n\n Por favor ingrese otro dato: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}

int bloqueoCargaVacia(eJuegos juegos[] ,int cantidad)
{
    int i, flag = 0;

    for(i = 0; i < cantidad; i++)
    {
        if(juegos[i].isEmpty == 0)
        {
            flag = 1;
        }
    }

     return flag;
}


/*

    alquiler:
    * codigo alquiler(autoincrementar)
    * codigo de juego(debe existir) validar
    * codigo de cliente(debe existir) validar
    * fecha

    Juego: alta, modificar, baja, listar importe(descendente) y descripcion(ascendente).
    cliente: alta, modificar, baja, listar ordenado por apellido (ascendente) y nombre (ascendente).
    alquiler: se dara de alta cada ocurrencia de alquiler, relacinando Juego, cliente, fecha y codigo de alquiler.
*/
