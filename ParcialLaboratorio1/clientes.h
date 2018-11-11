#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int codigo;
    char apellido[52];
    char nombre[52];
    char sexo;
    char domicilio[52];
    int isEmpty;
}eClientes;

void cliente_initCliente(eClientes[], int cantidad);

#endif
