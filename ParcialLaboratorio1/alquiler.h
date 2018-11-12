#ifndef FUNCIONES_A_INCLUDED
#define FUNCIONES_A_INCLUDED

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

void alquiler_initAlquiler(eAlquiler alquiler[], int);
void alquiler_altaAlquiler(eAlquiler alquiler[], int cantidad);
int alquiler_obtenerEspacioLibreAlquiler(eAlquiler alquiler[], int cantidad);
int alquiler_bloqueoCargaVaciaAlquiler(eAlquiler alquiler[] ,int cantidad);

#endif
