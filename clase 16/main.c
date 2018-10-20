#include <stdio.h>
#include <stdlib.h>
#define cant 3

//void mostrarCadena(char*);

typedef struct
{
    int edad;
    char nombre[31];
}ePersona;


int main()
{
    /*char cad[] = "Hoy es Sabado";
    mostrarCadena(cad);*/

    ePersona pers[cant], *ps;
    int i;

    /*printf("Ingrese la edad: ");
    scanf("%d", &per.edad);

    printf("\nIngrese el nombre: ");
    scanf("%s", per.nombre);

    p = &per

    printf("\n\nEdad: %d", p->edad);
    printf("\nNombre: %s", p->nombre);*/

    /*ps = pers;

    for(i = 0; i < cant; i++)
    {
        system("cls");
        printf("Ingrese un nombre: ");
        scanf("%s", (ps + i)->nombre);
        printf("\nIngrese una edad: ");
        fflush(stdin);
        scanf("%d", &(ps + i)->edad);
    }

    system("cls");

    for(i = 0; i < cant; i++)
    {
       printf("Nombre: %s\tEdad: %d\n", (ps + i)->nombre, (ps + i)->edad);
    }*/

    ps = pers;

    for(i = 0; i < cant; i++)
    {
        system("cls");
        printf("Ingrese un nombre: ");
        scanf("%s", (*(ps + i)).nombre);
        printf("\nIngrese una edad: ");
        fflush(stdin);
        scanf("%d", &(*(ps + i)).edad);
    }

    system("cls");

    for(i = 0; i < cant; i++)
    {
       printf("Nombre: %s\tEdad: %d\n", (*(ps + i)).nombre, (*(ps + i)).edad);
    }

    return 0;
}

/*void mostrarCadena(char* punteroCadena)
{
    while(*punteroCadena != '\0')
    {
        printf("%c", *punteroCadena);
        punteroCadena++;
    }
}*/
