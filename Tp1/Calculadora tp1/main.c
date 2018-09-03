#include <stdio.h>
#include <stdlib.h>

float suma(float, float);
float resta(float, float);
float division(float, float);
float multiplicar(float, float);
float factorUno(float);
float factorDos(float);

int main()
{
    float numeroUno, numeroDos, resultado;
    int opcionUno;
    int continuar;
    char opcionDos;

    do
    {
        system("cls");
        printf("Bienvenido al Menu, que desea realizar?");
        printf("\n\n 1. Ingresar el Primer operando: (A = %.2f)", numeroUno);
        printf("\n 2. Ingresar el Segundo operando. (B = %.2f)", numeroDos);
        printf("\n 3. Calcular operaciones.");
        printf("\n 4. Salir.");
        printf("\n\n Opcion Seleccionada: ");
        fflush(stdin);
        scanf("%d", &opcionUno);

        switch(opcionUno)
        {
        case 1:
            system("cls");
            printf("Ingrese el primer operando: ");
            fflush(stdin);
            scanf("%f", &numeroUno);
            break;
        case 2:
            system("cls");
            printf("Ingrese el segundo operando: ");
            fflush(stdin);
            scanf("%f", &numeroDos);
            break;
        case 3:
            do
            {
                system("cls");
                printf("Que operacion desea realizar?");
                printf("\n\n a. Sumar");
                printf("\n b. Restar");
                printf("\n c. Dividir");
                printf("\n d. Multiplicar");
                printf("\n e. Factorizar");
                printf("\n s. Salir");
                printf("\n\n Opcion seleccionada: ");
                fflush(stdin);
                scanf("%c", &opcionDos);

                switch(opcionDos)
                {
                case 'a':
                    resultado = suma(numeroUno, numeroDos);
                    printf("\n La suma es: %.2f", resultado);
                    break;
                case 'b':
                    resultado = resta(numeroUno, numeroDos);
                    printf("\n La resta es: %.2f", resultado);
                    break;
                case 'c':
                    resultado = division(numeroUno, numeroDos);
                    break;
                case 'd':
                    resultado = multiplicar(numeroUno, numeroDos);
                    printf("\n la multiplicacion es: %.2f", resultado);
                    break;
                case 'e':
                    printf("\n Que operador desea factorizar?");
                    printf("\n\n 1. 1er operador.");
                    printf("\n 2. 2do operador.");
                    printf("\n\n Opcion seleccionada: ");
                    scanf("%d", &opcionUno);

                    if(opcionUno == 1)
                    {
                        resultado = factorUno(numeroUno);
                        printf("\n El factor del primer numero es: %.0f", resultado);
                    }
                    else if(opcionUno == 2)
                    {
                        resultado = factorDos(numeroDos);
                        printf("\n El factor del segundo numero es: %.0f", resultado);
                    }
                    break;
                case 's':
                    continuar = 0;
                    break;
                }

                if(opcionDos != 's')
                {
                    printf("\n\n Desea realizar otra operacion? (Si = 1 No = 0): ");
                    scanf("%d", &continuar);
                }

            }while(continuar != 0);
            break;
        case 4:
            printf("\n Adios! n_n");
            break;
        }

    }while(opcionUno != 4);

    return 0;
}


float suma(float operadorUno, float operadorDos)
{
    float resultado;

    resultado = operadorUno + operadorDos;

    return resultado;
}

float resta(float operadorUno, float operadorDos)
{
    float resultado;

    resultado = operadorUno - operadorDos;

    return resultado;
}

float multiplicar(float operadorUno, float operadorDos)
{
    float resultado;

    resultado = operadorUno * operadorDos;

    return resultado;
}

float division(float operadorUno, float operadorDos)
{
    float resultado;

    while(operadorDos == 0)
    {
        printf("Error, no se puede dividir por cero!");
        printf("\n\n Por favor ingrese un nuevo valor: ");
        scanf("%f", &operadorDos);
    }

    resultado = operadorUno / operadorDos;
    printf("\n La division es: %.2f", resultado);

    return resultado;
}

float factorUno(float operadorUno)
{
    float resultado;

    if(operadorUno == 1)
    {
        return 1;
    }

    resultado = operadorUno * factorUno(operadorUno -1);

    return resultado;
}

float factorDos(float operadorDos)
{
    float resultado;

    if(operadorDos == 1)
    {
        return 1;
    }

    resultado = operadorDos * factorDos(operadorDos -1);

    return resultado;
}
