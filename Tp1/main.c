#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion;
    float numeroUno, numeroDos;

    do
    {
        system("cls");
        printf("menu");
        printf("\n\n 1. Ingresar el 1er operando: (A = %.0f)", numeroUno); //Estp muestra el numero 0.
        printf("\n 2. Ingresar el 2do operando: (B = %.0f)", numeroDos);
        printf("\n 3. Calcular todos los resultados.");
        printf("\n 4. Mostrar todos los resultados.");
        printf("\n\n seleccionar opcion: ");
        scanf("%d", opcion);
        switch(opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
        }
    }while(opcion != 5);

    return 0;
}

int menu()
{
    printf();
    printf();
    printf("seleccione: ");
    scanf("%d", &opcion);

    return opcion;
}
