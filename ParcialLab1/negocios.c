#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "negocios.h"
#include "utn.h"


void initJuego(eJuegos juegos[], int cantidad)
{
    int i;

    for(i = 0; i < cantidad; i++)
    {
        juegos[i].isEmpty = 1;
    }
}

void initCliente(eClientes clientes[], int cantidad)
{
    int i;

    for(i = 0; i < cantidad; i++)
    {
        clientes[i].isEmpty = 1;
    }
}

int obtenerEspacioLibreJuegos(eJuegos juegos[], int cantidad)
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

int obtenerEspacioLibreClientes(eClientes clientes[], int cantidad)
{
    int i, retorno = -1;

    for(i = 0; i < cantidad; i++)
    {
        if(clientes[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}


void altaJuegos(eJuegos juegos[], int cantidad)
{
    int index;

    index = obtenerEspacioLibreJuegos(juegos, cantidad);

    if(index != -1)
    {
        system("cls");

        printf("Ingrese la descripcion: ");
        fflush(stdin);

        fgets(juegos[index].descripcion, sizeof(juegos[index].descripcion)-2, stdin);
        cantidad = strlen(juegos[index].descripcion);
        juegos[index].descripcion[cantidad-1] = '\0';
        juegos[index].descripcion[0] = toupper(juegos[index].descripcion[0]);

        printf("\nIngrese el importe: ");
        scanf("%f", &juegos[index].importe);

        juegos[index].isEmpty = 0;
    }

}

void bajaJuegos(eJuegos juegos[], int cantidad)
{
    int i;
    int codigoAux;
    char respuesta;
    int bandera = 0;

    system("cls");
    printf("Ingrese el codigo del juego: ");
    fflush(stdin);
    scanf("%d", &codigoAux);

    for(i = 0; i < cantidad; i++)
    {
        if(codigoAux == juegos[i].codigo)
        {
            bandera = 1;
            printf("Descripcion: %s \t importe: %f", juegos[i].descripcion, juegos[i].importe);
            printf("\n\n Desea eliminar el registro? S/N: ");
            fflush(stdin);
            scanf("%c", &respuesta);
            while(respuesta != 's' && respuesta != 'n')
            {
                printf("Error ingrese S o N");
                scanf("%c", &respuesta);
            }

            if(respuesta == 's')
            {
                juegos[i].isEmpty = 1;
                printf("El registro fue eliminado.");
                system("pause");
                break;
            }
            else
            {
                printf("El registro no fue eliminado.");
                system("pause");
                break;
            }
        }

    }

    if(bandera == 0)
    {
        printf("Dato inexistente...");
        system("pause");
    }
}


void ordenJuegos(eJuegos importe[], int cantidad)
{
    float impoAux;
    int i, j;

    for(i = 0; i < cantidad; i++){
        for(j = i+1; j < cantidad; j++)
        {
            if(importe[i].importe < importe[j].importe)
            {
                impoAux = importe[i].importe;
                importe[i].importe = importe[j].importe;
                importe[j].importe = impoAux;
            }
        }
    }
}

void altaClientes(eClientes clientes[], int cantidad)
{
    int index;

    index = obtenerEspacioLibreClientes(clientes, cantidad);

    if(index != -1)
    {
        system("cls");

        printf("Ingrese el Apellido: ");
        fflush(stdin);

        fgets(clientes[index].apellido, sizeof(clientes[index].apellido)-2, stdin);
        cantidad = strlen(clientes[index].apellido);
        clientes[index].apellido[cantidad-1] = '\0';
        clientes[index].apellido[0] = toupper(clientes[index].apellido[0]);

        printf("\nIngrese el Nombre: ");

        fgets(clientes[index].nombre, sizeof(clientes[index].nombre)-2, stdin);
        cantidad = strlen(clientes[index].nombre);
        clientes[index].nombre[cantidad-1] = '\0';
        clientes[index].nombre[0] = toupper(clientes[index].nombre[0]);

        printf("\nIngrese el sexo (M/F): ");
        scanf("%c", &clientes[index].sexo);
        clientes[index].sexo = toupper(clientes[index].sexo);

        printf("\nIngrese el domicilio: ");

        fgets(clientes[index].domicilio, sizeof(clientes[index].domicilio)-2, stdin);
        cantidad = strlen(clientes[index].domicilio);
        clientes[index].domicilio[cantidad-1] = '\0';
        clientes[index].domicilio[0] = toupper(clientes[index].domicilio[0]);

        clientes[index].isEmpty = 0;
    }

}

void bajaClientes(eClientes clientes[], int cantidad)
{
    int i;
    int codigoAux;
    char respuesta;
    int flag = 0;

    system("cls");
    printf("Ingrese el codigo del cliente: ");
    fflush(stdin);
    scanf("%d", &codigoAux);

    for(i = 0; i < cantidad; i++)
    {
        if(codigoAux == clientes[i].codigo)
        {
            flag = 1;
            printf("Apellido: %s \t Nombre: %s \t Sexo: %c \t domicilio: %s", clientes[i].apellido, clientes[i].nombre, clientes[i].sexo, clientes[i].domicilio);
            printf("\n\n Desea eliminar el registro? S/N: ");
            fflush(stdin);
            scanf("%c", &respuesta);
            while(respuesta != 's' && respuesta != 'n')
            {
                printf("Error ingrese S o N");
                scanf("%c", &respuesta);
            }

            if(respuesta == 's')
            {
                clientes[i].isEmpty = 1;
                printf("El registro fue eliminado.");
                system("pause");
                break;
            }
            else
            {
                printf("El registro no fue eliminado.");
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
}

void ordenClientes(int cantidad)
{
    eClientes clientes[cantidad], cliAux;
    int i, j;

    for(i = 0; i < cantidad; i++){
        for(j = i+1; j < cantidad; j++)
        {
            if(strcmp(clientes[i].apellido, clientes[j].apellido) > 0)
            {
                cliAux = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = cliAux;
            }
            else if(strcmp(clientes[i].apellido, clientes[j].apellido) == 0 && strcmp(clientes[i].nombre, clientes[j].nombre) > 0)
            {
                cliAux = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = cliAux;
            }
        }
    }
}


void cargaAlquiler(eAlquiler alquiler[], int cantidad)
{
    eJuegos juegos[cantidad];
    eClientes clientes[cantidad];
    int i, codigoUno, codigoDos;

    printf("Ingrese el codigo del juego: ");
    scanf("%d", &codigoUno);
    printf("Ingrese el codigo del cliente: ");
    scanf("%d", &codigoDos);
    printf("Ingrese la fecha: ");
    scanf("%d %d %d", &alquiler[cantidad].fecha.dia, &alquiler[cantidad].fecha.mes, &alquiler[cantidad].fecha.anio);

    for(i = 0; i < cantidad; i++)
    {
        if(codigoUno == juegos[i].codigo)
        {
            alquiler[i].codigoJuego = juegos[i].codigo;
        }
        else if(codigoDos == clientes[i].codigo)
        {
            alquiler[i].codigoCliente = clientes[i].codigo;
        }

    }
}



