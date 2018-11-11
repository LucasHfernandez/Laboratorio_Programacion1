#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"

void cliente_initCliente(eClientes clientes[], int cantidad)
{
    int i;

    for(i = 0; i < cantidad; i++)
    {
        clientes[i].isEmpty = 1;
    }
}
