#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
   int codigo;
   char descripcion[52];
   float importe;
   int isEmpty;
}eJuegos;

void juego_initJuego(eJuegos juegos[], int cantidad);
void juego_altaJuegos(eJuegos juegos[], int cantidad);
void juego_modificarJuegos(eJuegos juegos[], int cantidad);
void juego_bajaJuegos(eJuegos juegos[], int cantidad);
void juego_listaJuegos(eJuegos juegos[], int cantidad);
int juego_obtenerEspacioLibreJuegos(eJuegos juegos[], int cantidad);
int juego_bloqueoCargaVaciaJuego(eJuegos juegos[] ,int cantidad);

#endif
