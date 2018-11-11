#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int dia, mes, anio;
}eFecha;

typedef struct
{
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    int isEmpty;
    eFecha fecha;
}eAlquiler;

void alquiler_initAlquiler(eAlquiler[], int);

#endif
