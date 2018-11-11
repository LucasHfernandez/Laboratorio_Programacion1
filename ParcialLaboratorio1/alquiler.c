#include <stdio.h>
#include <stdlib.h>
#include "alquiler.h"

void alquiler_initAlquiler(eAlquiler alquiler[], int cantidad)
{
    int i;

    for(i = 0; i < cantidad; i++)
    {
        alquiler[i].isEmpty = 1;
    }
}
