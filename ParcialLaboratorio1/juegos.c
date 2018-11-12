#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "juegos.h"

void juego_initJuego(eJuegos juegos[], int cantidad)
{
    int i;

    for(i = 0; i < cantidad; i++)
    {
        juegos[i].isEmpty = 1;
    }
}


int juego_obtenerEspacioLibreJuegos(eJuegos juegos[], int cantidad)
{
    int i, retorno = -1;

    for(i = 0; i < cantidad; i++)
    {
        if(juegos[i].isEmpty == 1)
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

int juego_bloqueoCargaVaciaJuego(eJuegos juegos[] ,int cantidad)
{
    int i, flag;

    for(i = 0; i < cantidad; i++)
    {
        if(juegos[i].isEmpty == 1)
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


void juego_altaJuegos(eJuegos juegos[], int cantidad)
{
    int index;
    int opcion;

    do
    {
        index = juego_obtenerEspacioLibreJuegos(juegos, cantidad);

        if(index != -1)
        {
            system("cls");
            printf("Altas de los Juegos.");
            printf("\n-------------------------------");
            printf("\nIngrese la descripcion: ");
            fflush(stdin);
            fgets(juegos[index].descripcion, sizeof(juegos[index].descripcion)-2, stdin);
            cantidad = strlen(juegos[index].descripcion);
            juegos[index].descripcion[cantidad-1] = '\0';
            juegos[index].descripcion[0] = toupper(juegos[index].descripcion[0]);

            printf("\nIngrese el importe: ");
            fflush(stdin);
            scanf("%f", &juegos[index].importe);

            while(juegos[index].importe <= 0)
            {
                printf("\nEl importe debe ser mayor a cero");
                printf("\nIngrese el importe: ");
                fflush(stdin);
                scanf("%f", &juegos[index].importe);
            }

            juegos[index].codigo = juego_genCodigo();

            juegos[index].isEmpty = 0;

            printf("\nEl juego fue dado de alta n_n");
            system("pause");

            printf("\n\nDesea dar de alta otro dato? 1= SI 2= NO");
            printf("\nOpcion seleccionada: ");
            fflush(stdin);
            scanf("%d", &opcion);
        }
    }while(opcion != 2);
}


void juego_modificarJuegos(eJuegos juegos[], int cantidad)
{
    int auxCodigo;
    float auxImporte;
    char auxDescripcion[300];
    int i;
    int opcionUno;
    int opcionDos;
    int flag;

    do
    {
        system("cls");
        printf("Modificar dato de los Juegos.");
        printf("\n------------------------------------------");
        printf("\nIngrese el codigo del juego que desea modificar.");
        printf("\n\nCodigo: ");
        fflush(stdin);
        scanf("%d", &auxCodigo);
        flag = 0;

        for(i = 0; i < cantidad; i++)
        {
            if(auxCodigo == juegos[i].codigo)
            {
                flag = 1;
                printf("\nDato Encontrado :3");
                printf("\n\nCodigo: %d  -  Descripcion: %s  -  Importe: %.2f", juegos[i].codigo, juegos[i].descripcion, juegos[i].importe);
                printf("\n\nDesea modificar el registro? SI = 1 NO = 2");
                printf("\n\nOpcion seleccionada: ");
                fflush(stdin);
                scanf("%d", &opcionUno);

                while(opcionUno < 1 || opcionUno > 2)
                {
                    printf("Error, ingrese nuevamente.");
                    printf("\nOpcion seleccionada: ");
                    fflush(stdin);
                    scanf("%d", &opcionUno);
                }
                break;
            }
        }

            if(opcionUno == 1)
            {
                system("cls");
                printf("Por favor ingrese los nuevos datos por favor.");
                printf("\n-------------------------------------------------------");
                printf("\n1.Descripcion anterior: %s", juegos[i].descripcion);
                printf("\n2.Importe anterior: %.2f", juegos[i].importe);
                printf("\n\nIngrese la nueva descripcion: ");
                fflush(stdin);
                fgets(auxDescripcion, sizeof(auxDescripcion)-2, stdin);
                strcpy(juegos[i].descripcion, auxDescripcion);
                printf("\nIngrese el nuevo importe: ");
                fflush(stdin);
                scanf("%f", &auxImporte);
                juegos[i].importe = auxImporte;
                printf("\nLos datos fueron modificados n_n");
                system("pause");
            }
            else if(opcionUno == 2 && flag == 1)
            {
                printf("\nNo se modificaran los datos.");
                system("pause");
            }

    if(flag == 0)
    {
        printf("Dato inexistente...");
        system("pause");
    }

    printf("\n\nDesea modificar otro dato? 1= SI 2= NO");
    printf("\nOpcion seleccionada: ");
    fflush(stdin);
    scanf("%d", &opcionDos);

    }while(opcionDos != 2);

}


void juego_bajaJuegos(eJuegos juegos[], int cantidad)
{
    int i;
    int auxCodigo;
    int opcionUno;
    int opcionDos;
    int flag = 0;

    do
    {
        system("cls");
        printf("Bajas de los Juegos.");
        printf("\n---------------------------------");
        printf("\nIngrese el codigo del juego que desea dar de baja.");
        printf("\n\nCodigo: ");
        fflush(stdin);
        scanf("%d", &auxCodigo);

        for(i = 0; i < cantidad; i++)
        {
            if(auxCodigo == juegos[i].codigo)
            {
                flag = 1;
                printf("\nDato Encontrado :3");
                printf("\n\nCodigo: %d, Descripcion: %s, Importe: %.2f", juegos[i].codigo, juegos[i].descripcion, juegos[i].importe);
                printf("\n\nDesea eliminar el registro? SI = 1 NO = 2");
                printf("\n\nOpcion seleccionada: ");
                fflush(stdin);
                scanf("%d", &opcionUno);

                while(opcionUno < 1 || opcionUno > 2)
                {
                    printf("Error, ingrese nuevamente.");
                    printf("\nOpcion seleccionada: ");
                    fflush(stdin);
                    scanf("%d", &opcionUno);
                }

                if(opcionUno == 1)
                {
                    juegos[i].isEmpty = 0;
                    printf("\nEl registro fue eliminado.");
                    system("pause");
                    break;
                }
                else
                {
                    printf("\nEl registro no fue eliminado.");
                    system("pause");
                    break;
                }
            }

        }

    if(flag == 0)
    {
        printf("Dato inexistente...");
        system("pause");
    }

    printf("\n\nDesea elminar otro dato? 1= SI 2= NO");
    printf("\nOpcion seleccionada: ");
    fflush(stdin);
    scanf("%d", &opcionDos);

    }while(opcionDos != 2);
}


void juego_listaJuegos(eJuegos juegos[], int cantidad)
{
    int i;

    system("cls");
    printf("Lista de todos los Juegos.");
    printf("\n------------------------------------");

    for(i = 0; i < cantidad; i++)
    {
        if(juegos[i].isEmpty == 0)
        {
            printf("\nCodigo: %d  -  Importe: %.2f  -  Descripcion: %s\n", juegos[i].codigo, juegos[i].importe, juegos[i].descripcion);
            printf("-------------------------------------------------------------------------------------------------------------------");
        }
    }
    system("pause");
}
