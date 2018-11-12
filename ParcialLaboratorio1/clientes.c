#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"

void cliente_initCliente(eClientes clientes[], int cantidad)
{
    int i;

    for(i = 0; i < cantidad; i++)
    {
        clientes[i].isEmpty = 1;
    }
}


int cliente_obtenerEspacioLibreClientes(eClientes clientes[], int cantidad)
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


static int cliente_genCodigo(void)
{
    static int nextId = -1;

    return ++nextId;
}


int cliente_bloqueoCargaVaciaCliente(eClientes clientes[] ,int cantidad)
{
    int i, flag;

    for(i = 0; i < cantidad; i++)
    {
        if(clientes[i].isEmpty == 1)
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


void cliente_altaClientes(eClientes clientes[], int cantidad)
{
    int index;
    int opcion;

    do
    {
        index = cliente_obtenerEspacioLibreClientes(clientes, cantidad);

        if(index != -1)
        {
            system("cls");
            printf("Altas de los clientes.");
            printf("\n--------------------------------------");

            printf("\nIngrese el apellido: ");
            fflush(stdin);
            fgets(clientes[index].apellido, sizeof(clientes[index].apellido)-2, stdin);
            cantidad = strlen(clientes[index].apellido);
            clientes[index].apellido[cantidad-1] = '\0';
            clientes[index].apellido[0] = toupper(clientes[index].apellido[0]);

            printf("\nIngrese el nombre: ");
            fflush(stdin);
            fgets(clientes[index].nombre, sizeof(clientes[index].nombre)-2, stdin);
            cantidad = strlen(clientes[index].nombre);
            clientes[index].nombre[cantidad-1] = '\0';
            clientes[index].nombre[0] = toupper(clientes[index].nombre[0]);

            printf("\nIngrese el sexo (M/F): ");
            scanf("%c", &clientes[index].sexo);
            clientes[index].sexo = toupper(clientes[index].sexo);

            printf("\nIngrese el domicilio: ");
            fflush(stdin);
            fgets(clientes[index].domicilio, sizeof(clientes[index].domicilio)-2, stdin);
            cantidad = strlen(clientes[index].domicilio);
            clientes[index].domicilio[cantidad-1] = '\0';
            clientes[index].domicilio[0] = toupper(clientes[index].domicilio[0]);

            clientes[index].codigo = cliente_genCodigo();

            clientes[index].isEmpty = 0;

            printf("\nEl cliente fue dado de alta n_n");
            system("pause");

            printf("\n\nDesea dar de alta otro dato? 1= SI 2= NO");
            printf("\nOpcion seleccionada: ");
            fflush(stdin);
            scanf("%d", &opcion);
        }
    }while(opcion != 2);
}


void cliente_modificarCliente(eClientes clientes[], int cantidad)
{
    int auxCodigo;
    char auxApellido[300];
    char auxNombre[300];
    char auxSexo;
    char auxDomicilio[300];
    int i;
    int opcionUno;
    int opcionDos;
    int flag;

    do
    {
        system("cls");
        printf("Modificar dato de los clientes.");
        printf("\n------------------------------------------");
        printf("\nIngrese el codigo del cliente que desea modificar.");
        printf("\n\nCodigo: ");
        fflush(stdin);
        scanf("%d", &auxCodigo);
        flag = 0;

        for(i = 0; i < cantidad; i++)
        {
            if(auxCodigo == clientes[i].codigo)
            {
                flag = 1;
                printf("\nDato Encontrado :3");
                printf("\n\nCodigo: %d  -  Apellido: %s  -  Nombre: %s  -  sexo: %c  -  Domicilio: %s", clientes[i].codigo,
                                                                                                        clientes[i].apellido,
                                                                                                        clientes[i].nombre,
                                                                                                        clientes[i].sexo,
                                                                                                        clientes[i].domicilio);
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
                printf("\n1.Apellido anterior: %s", clientes[i].apellido);
                printf("\n2.Nombre anterior: %s", clientes[i].nombre);
                printf("\n3.Sexo anterior: %c", clientes[i].sexo);
                printf("\n4.domicilio anterior: %s", clientes[i].domicilio);

                printf("\n\nIngrese el nuevo apellido: ");
                fflush(stdin);
                fgets(auxApellido, sizeof(auxApellido)-2, stdin);
                strcpy(clientes[i].apellido, auxApellido);

                printf("\nIngrese el nuevo nombre: ");
                fflush(stdin);
                fgets(auxNombre, sizeof(auxNombre)-2, stdin);
                strcpy(clientes[i].nombre, auxNombre);

                printf("\nIngrese el nuevo sexo: ");
                fflush(stdin);
                scanf("%c", &auxSexo);
                clientes[i].sexo = auxSexo;

                printf("\nIngrese el nuevo domicilio: ");
                fflush(stdin);
                fgets(auxDomicilio, sizeof(auxDomicilio)-2, stdin);
                strcpy(clientes[i].domicilio, auxDomicilio);

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


void cliente_bajaClientes(eClientes clientes[], int cantidad)
{
    int i;
    int auxCodigo;
    int opcionUno;
    int opcionDos;
    int flag = 0;

    do
    {
        system("cls");
        printf("Bajas de los Clientes.");
        printf("\n----------------------------------------");
        printf("\nIngrese el codigo del cliente que desea dar de baja.");
        printf("\n\nCodigo: ");
        fflush(stdin);
        scanf("%d", &auxCodigo);

        for(i = 0; i < cantidad; i++)
        {
            if(auxCodigo == clientes[i].codigo)
            {
                flag = 1;
                printf("\nDato Encontrado :3");
                printf("\n\nCodigo: %d  -  Apellido: %s  -  Nombre: %s  -  sexo: %c  -  Domicilio: %s", clientes[i].codigo,
                                                                                                        clientes[i].apellido,
                                                                                                        clientes[i].nombre,
                                                                                                        clientes[i].sexo,
                                                                                                        clientes[i].domicilio);
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
                    clientes[i].isEmpty = 0;
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


void cliente_listaClientes(eClientes clientes[], int cantidad)
{
    int i;

    system("cls");
    printf("Lista de todos los Clientes.");
    printf("\n-----------------------------------------");

    for(i = 0; i < cantidad; i++)
    {
        if(clientes[i].isEmpty == 0)
        {
            printf("\nCodigo: %d  -  Apellido: %s  -  Nombre: %s  -  sexo: %c  -  Domicilio: %s\n", clientes[i].codigo,
                                                                                                        clientes[i].apellido,
                                                                                                        clientes[i].nombre,
                                                                                                        clientes[i].sexo,
                                                                                                        clientes[i].domicilio);
            printf("-------------------------------------------------------------------------------------------------------------------------");
        }
    }
    system("pause");
}
