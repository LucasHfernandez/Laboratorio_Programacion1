#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int dia, mes, anio;
}eFecha;

typedef struct
{
    char apellido[31];
    char nombre[31];
    long int dni;
    eFecha fechaNac;
    int isEmpty;
}ePersona;

void init(ePersona[], int);
void alta(ePersona[]);
int obtenerEspacioLibre(ePersona[], int);
void baja(ePersona[], int);
#endif
