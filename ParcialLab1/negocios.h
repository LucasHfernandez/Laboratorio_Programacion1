#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int dia, mes, anio;
}eFecha;

typedef struct
{
   int codigo;
   char descripcion[52];
   float importe;
   int isEmpty;

}eJuegos;

typedef struct
{
    int codigo;
    char apellido[52];
    char nombre[52];
    char sexo;
    char domicilio[52];
    int isEmpty;

}eClientes;

typedef struct
{
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    eFecha fecha;
}eAlquiler;

/*Juegos*/
void initJuego(eJuegos[], int);
int obtenerEspacioLibreJuegos(eJuegos[], int);
void altaJuegos(eJuegos[], int);
void bajaJuegos(eJuegos[], int);
void ordenJuegos(int);

/*Clientes*/
void initCliente(eClientes[], int);
int obtenerEspacioLibreClientes(eClientes[], int);
void altaClientes(eClientes[], int);
void bajaClientes(eClientes[], int);
void ordenClientes(int);

/*Alquileres*/
void cargaAlquiler(eAlquiler[], int);

#endif
