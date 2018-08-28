#include <stdio.h>
#include <stdlib.h>
#define esc 27 //Esto solo sirve para el ultimo ejercicio.

/*int main()
{
    int numero = 10;

    while(numero > 0)
    {
        printf("%d\n", numero);
        numero--;
    }

    return 0;
}*/

/*int main()
{
    int numero = 10;

    do
    {
        printf("%d\n", numero);
        numero--;
    }while(numero > 0);

    return 0;
}*/

/*int main()
{
    int numero;

    for(numero=0;numero<10;numero++)
    {
        printf("%d\n",numero+1);
    }

    return 0;
}*/

/*int main()
{
    int edad, contador, acumulador = 0;
    float promedio;

    for(contador=0;contador<5;contador++)
    {
        printf("Ingrese edad: ");
        scanf("%d", &edad);
        acumulador = acumulador + edad;
    }

    promedio = (float)acumulador / contador;      //Hay que agregar el float entre parentesis para que las variables enteras se hagan momentaneamente flotantes.
    printf("\n" "El promedio es: %.2f ", promedio);
    return 0;
}*/

int main()
{
    int numero, maximo, minimo, flag = 0;
    char continuar;

    do
    {
        system("cls"); //esto sirve para limpiar todo de la consola.
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        if(flag == 0)
        {
            maximo = numero;
            minimo = numero;
            flag = 1;
        }
        if(numero > maximo)
        {
            maximo = numero;
        }
        else if(numero < minimo)
        {
            minimo = numero;
        }

        printf("Presione cualquier tecla para continuar, salir = Esc: ");
        fflush(stdin);
        scanf("%c", &continuar);
    }while(continuar != esc);

    printf("El maximo es: %d\n", maximo);
    printf("El minimo es: %d\n", minimo);

    return 0;
}
