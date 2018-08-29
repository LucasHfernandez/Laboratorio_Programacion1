#include <stdio.h>
#include <stdlib.h>

int suma(int, int); //prototipo, firma, declaración.

int main()
{
    int numeroUno, numeroDos, resultado;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numeroUno);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &numeroDos);
    resultado = suma(numeroUno, numeroDos); //llamada a la función.
    printf("El resultado es: %d", resultado);

    return 0;
}

int suma(int operandoUno, int operandoDos)
{
    int res;

    res = operandoUno + operandoDos;

    return res;
}
