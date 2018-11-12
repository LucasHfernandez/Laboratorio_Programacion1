#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"

int utn_menuGetNumero(int opcion, char* mensaje, char* mensajeErrorUno)
{
    system("cls");
    printf("\t\tBienvenido al Menu, que desea realizar?");
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


int utn_menuJuegosGetNumero(int opcion, char* mensaje, char* mensajeErrorUno)
{
    system("cls");
    printf("\t\tBienvenido al Menu Juegos, que desea realizar?");
    printf("\n\n 1. Alta del juego.");
    printf("\n 2. Modificar informacion.");
    printf("\n 3. Baja del juego.");
    printf("\n 4. Listado de juegos.");
    printf("\n 5. Volver.");
    printf(mensaje);
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion > 5 || opcion < 1)
    {
        printf(mensajeErrorUno);
        printf("\n\n Por favor ingrese otro dato: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }


    return opcion;
}


int utn_menuClientesGetNumero(int opcion, char* mensaje, char* mensajeErrorUno)
{
    system("cls");
    printf("\t\tBienvenido al Menu Clientes, que desea realizar?");
    printf("\n\n 1. Alta del cliente.");
    printf("\n 2. Modificar informacion.");
    printf("\n 3. Baja del cliente.");
    printf("\n 4. Listado de clientes.");
    printf("\n 5. Volver.");
    printf(mensaje);
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion > 5 || opcion < 1)
    {
        printf(mensajeErrorUno);
        printf("\n\n Por favor ingrese otro dato: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}
