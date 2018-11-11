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
        juegos[i].isEmpty = 0;
    }
}


int juego_obtenerEspacioLibreJuegos(eJuegos juegos[], int cantidad)
{
    int i, retorno = 0;

    for(i = 0; i < cantidad; i++)
    {
        if(juegos[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}


int juego_genCodigo(char* strCodigo)
{
    int retorno = 0;
    int codigo;
    static int nextId = -1;

    codigo = atoi(strCodigo);

    if(codigo == -1)
        {
            nextId++;
            retorno = 1;
        }else if(codigo > nextId)
        {
            nextId = codigo;
            retorno = 1;
        }

    return retorno;
}

int juego_bloqueoCargaVaciaJuego(eJuegos juegos[] ,int cantidad)
{
    int i, flag;

    for(i = 0; i < cantidad; i++)
    {
        if(juegos[i].isEmpty == 0)
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
    char codigo[200] = "-1";

    index = juego_obtenerEspacioLibreJuegos(juegos, cantidad);

    if(index != 0)
    {
        juegos[index].codigo = juego_genCodigo(codigo);

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

        juegos[index].isEmpty = 1;

        printf("\n\nEl juego fue dado de alta n_n");
        system("pause");
    }
}


void juego_modificarJuegos(eJuegos juegos[], int cantidad)
{
    int auxCodigo;
    float auxImporte;
    char auxDescripcion[300];
    int i;
    int opcionUno;
    int opcionDos;
    int opcionTres;
    int flag = 0;

    do
    {
        system("cls");
        printf("Modificar dato de los Juegos.");
        printf("\n------------------------------------------");
        printf("\nIngrese el codigo del juego que desea modificar.");
        printf("\n\n Codigo: ");
        fflush(stdin);
        scanf("%d", &auxCodigo);

        for(i = 0; i < cantidad; i++)
        {
            if(auxCodigo == juegos[i].codigo)
            {
                flag = 1;
                printf("\nDato Encontrado :3");
                printf("\n\nCodigo: %d, Descripcion: %s, Importe: %.2f", juegos[i].codigo, juegos[i].descripcion, juegos[i].importe);
                printf("\n\nDesea modificar el registro? SI = 1 NO = 2");
                printf("\n\nOpcion seleccionada: ");
                fflush(stdin);
                scanf("%d", &opcionUno);

                while(opcionUno < 1 || opcionUno > 2)
                {
                    printf("Error, ingrese nuevamente.");
                    fflush(stdin);
                    scanf("%d", &opcionUno);
                }
            }

            if(opcionUno == 1)
            {
                do
                {
                    system("cls");
                    printf("que datos desea modificar?");
                    printf("\n----------------------------------------");
                    printf("\n\n1.Descripcion");
                    printf("\n2.Importe");
                    printf("\n3.Salir");
                    fflush(stdin);
                    scanf("%d", &opcionDos);

                    while(opcionDos < 1 || opcionDos > 3)
                    {
                        printf("Error, ingrese nuevamente.");
                        fflush(stdin);
                        scanf("%d", &opcionDos);
                    }

                    switch(opcionDos)
                    {
                        case 1:
                            system("cls");
                            printf("Ingrese la nueva descripcion: ");
                            fflush(stdin);
                            fgets(auxDescripcion, sizeof(auxDescripcion)-2, stdin);
                            strcpy(juegos[i].descripcion, auxDescripcion);
                            printf("\n\nEl dato fue modificado.");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            printf("Ingrese el nuevo importe: ");
                            fflush(stdin);
                            scanf("%f", &auxImporte);
                            juegos[i].importe = auxImporte;
                            printf("\n\nEl dato fue modificado.");
                            system("pause");
                            break;
                    }

                }while(opcionDos != 3);

               break;
            }
            else if(opcionUno == 2)
            {
                printf("\nNo se modificaran los datos.");
                system("pause");
                break;
            }
        }

    printf("\n\nDesea modificar otro dato? 1= SI 2= NO");
    printf("\nOpcion seleccionada: ");
    fflush(stdin);
    scanf("%d", &opcionTres);

    }while(opcionTres != 2);

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
        printf("\n\n Codigo: ");
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
    int i, j;
    float auxImporte;
    char auxDescripcion[200];

    system("cls");
    printf("Lista de todos los Juegos.");
    printf("\n------------------------------------");

    for(i = 0; i < cantidad; i++){
        for(j = i+1; j < cantidad; j++)
        {
            if(juegos[i].descripcion > juegos[j].descripcion)
            {
                auxDescripcion = juegos[i].descripcion;
                juegos[i].descripcion = juegos[j].descripcion;
                juegos[j].descrpicion = auxDescripcion;
                printf("\nDescripcion: %s\n", juegos[i].descripcion);
            }

            if(juegos[i].importe < juegos[j].importe)
            {
                auxImporte = juegos[i].importe;
                juegos[i].importe = juegos[j].importe;
                juegos[j].importe = auxImporte;
                printf("Importe: %.2f\n", juegos[i].importe);
                printf("--------------------------------------------------");
            }
        }
    }
}
