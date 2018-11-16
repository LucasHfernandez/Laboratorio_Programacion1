#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;
}eEmpleado;

int emp_menuOpcion_getNumero(int, char*, char*);
int emp_obtenerEspacioLibre(eEmpleado[], int);
int emp_bloqueoCargaVacia(eEmpleado[], int);
void emp_initEmployees(eEmpleado[], int);
void emp_addEmployee(eEmpleado[], int);
void emp_modifyEmployee(eEmpleado[], int);
void emp_removeEmployee(eEmpleado[], int);
void emp_sortEmployees(eEmpleado[], int);
void emp_printEmployees(eEmpleado[], int);
#endif
