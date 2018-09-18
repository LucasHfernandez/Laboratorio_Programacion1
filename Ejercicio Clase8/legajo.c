#include <stdio.h>
#include <stdlib.h>
#include "legajo.h"

void init(ePersona persona[], int cantidad)
{
    int i;

    for(i = 0; i < cantidad; i++)
    {
        persona[i].isEmpty = 1;
    }
}

int obtenerEspacioLibre(ePersona per[], int cantidad)
{
    int i, retorno = -1

    for(i = 0; i < cantidad; i++)
    {
        if(per[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

void alta(ePersona persona)
{
    int index;

    index = obtenerEspacioLibre(per, cantidad)

    if(index != -1)
    {
        printf("DNI: ");
        scanf("%d", &persona.dni);
        printf("\nApellido y Nombre: ");
        scanf("%s %s", persona.apellido, persona.nombre);
    }

}


void baja(ePersona per[], int cantidad)
{

    //buscar el dni.
    int i;
    long int dniAux;
    char respuesta;
    int flag = 0;

    for(i = 0; i < cantidad; i++)
    {
        if(dniAux == per[i].dni)
        {
            flag = 1;
            printf("%s %s %ld", per[i].apellido, per[i].nombre, per[i].dni);
            printf("\n\n Desea eliminar el registro? S/N: ");
            fflush(stdin);
            scanf("%c", &respuesta);
            respuesta = toupper(getchar());
            while(respuesta != 'S' && respuesta != 'N')
            {
                printf("Error ingrese S o N");
                scanf("%c", &respuesta);
            }

            if(respuesta == 'S')
            {
                per[i].isEmpty = 1;
                printf("El registro fue eliminado.");
                break;
            }
            else
            {
                printf("El registro no fue eliminado.");
                break;
            }
        }
        if(flag == 0)
        {
            printf("Dato inexistente...");
        }
    }
}
