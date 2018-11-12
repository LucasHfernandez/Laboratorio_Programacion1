#ifndef FUNCIONES_C_INCLUDED
#define FUNCIONES_C_INCLUDED

typedef struct
{
    int codigo;
    char apellido[52];
    char nombre[52];
    char sexo;
    char domicilio[52];
    int isEmpty;
}eClientes;

void cliente_initCliente(eClientes clientes[], int cantidad);

#endif
