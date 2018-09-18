#include <stdio.h>
#include <stdlib.h>
#include "legajo.h"
#define cant 200

int main()
{
    int opcion;
    ePersona per[cant];
    long int dniAux;

    init(per, cant);

    do
    {
        system("cls");
        printf("Bienvenido al Menu, que desea realizar?");
        printf("\n\n 1. Agregar persona");
        printf("\n 2. Borrar persona");
        printf("\n 3. Imprimir lista ordenada de nombres");
        printf("\n 4. Imprimir grafico de edades");
        printf("\n 5. Salir.");
        printf("\n\n Opcion seleccionada: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            alta(per, cant);
            break;
        case 2:
            printf("DNI: ");
            scanf("%ld", &dniAux);
            baja(per, cant);
            break;
        }

    }while(opcion != 5);



    return 0;
}
