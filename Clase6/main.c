#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para el segundo ejercicio.
#define cant 5  // para el primer ejercicio.
#include <ctype.h> //para el ultimo ejercicio.

int main()
{
    /*int puntos[cant] = {1, 2, 3, 3, 1};
    int difGoles[cant] = {8, 1, 5, 3, 4};
    int auxPuntos, auxDg, i, j;

    for(i = 0; i < 5 - 1; i++)
    {
        for(j = i + 1; j < 5; j++)
        {
            if(puntos[i] < puntos[j])
            {
                auxPuntos = puntos[i];
                puntos[i] = puntos[j];
                puntos[j] = auxPuntos;
                auxDg = difGoles[i];
                difGoles[i] = difGoles[j];
                difGoles[j] = auxDg;
            }
            else
            {
                if(puntos[i] == puntos[j] && difGoles[i] < difGoles[j])
                {
                    auxDg = difGoles[i];
                    difGoles[i] = difGoles[j];
                    difGoles[j] = auxDg;
                }
            }
        }
    }

        printf("----Tabla de Posiciones----\n\n");
        printf("Puntos    Diferencia de goles\n");

    for(i = 0; i < cant; i++)
    {
        printf("----------------------------*\n");
        printf("   %d      |      %d\n", puntos[i], difGoles[i]);
        printf("----------------------------*\n");
    }*/


    /*char nombre[31];

    strcpy(nombre, "Bienvenido Lucas Fernandez");
    printf("%s\n", nombre);
    printf("\n Desea ingresar un nombre?");
    printf("\n\n Input: ");
    fflush(stdin);
    scanf("%[^\n]s", nombre);
    printf("\n\n Nombre ingresado: %s\n", nombre);*/

    char nombre[31];
    char apellido[31];
    char apellynom[62];
    int cantidad, i;

    printf("Ingrese el nombre: ");
    fgets(nombre, sizeof(nombre)-2, stdin);
    cantidad = strlen(nombre);
    nombre[cantidad-1] = '\0';
    nombre[0] = toupper(nombre[0]);
    printf("\n Ingrese el apellido: ");
    fgets(apellido, sizeof(apellido)-2, stdin);
    cantidad = strlen(apellido);
    apellido[cantidad-1] = '\0';
    apellido[0] = toupper(apellido[0]);

    for(i = 0; i < cantidad; i++)
    {
        if(nombre[i] == ' ' && nombre[i] != '\0')
        {
            nombre[i+1] = toupper(nombre[i+1]);
        }
    }

    for(i = 0; i < cantidad; i++)
    {
        if(apellido[i] == ' ' && apellido[i] != '\0')
        {
            apellido[i+1] = toupper(apellido[i+1]);
        }
    }

    /*strcpy(apellynom, apellido);
    strcat(apellynom, " ");
    strcat(apellynom, nombre);*/

    apellynom[0] = '\0';
    strcat(apellynom, apellido);
    strcat(apellynom, " ");
    strcat(apellynom, nombre);


    printf("El nombre ingresado es: %s", apellynom);



    return 0;
}
