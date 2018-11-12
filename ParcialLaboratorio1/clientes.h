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
void cliente_altaClientes(eClientes clientes[], int cantidad);
void cliente_modificarCliente(eClientes clientes[], int cantidad);
void cliente_bajaClientes(eClientes clientes[], int cantidad);
void cliente_listaClientes(eClientes clientes[], int cantidad);
int cliente_obtenerEspacioLibreClientes(eClientes clientes[], int cantidad);
int cliente_bloqueoCargaVaciaCliente(eClientes clientes[] ,int cantidad);

#endif
