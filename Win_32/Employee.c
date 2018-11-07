#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new()
{
   Employee* this = malloc(sizeof(this));

   return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* empNew;
    int id, horasTrabajadas, sueldo;
    empNew = employee_new();

    if(empNew != NULL)
    {
        id = atoi(idStr);
        horasTrabajadas = atoi(horasTrabajadasStr);
        sueldo = atoi(sueldoStr);
        employee_setId(empNew, id);
        employee_setNombre(empNew, nombreStr);
        employee_setHorasTrabajadas(empNew, horasTrabajadasStr);
        employee_setSueldo(empNew, sueldoStr);
    }

    return empNew;
}

int employee_setId(Employee* this,int id)
{
    int retorno = 0;

    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = 1;
    }

   return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 0;

    if(this != NULL && nombre[0] != '\0')
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 1;
    }

   return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = 0;

    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno = 1;
    }

    return retorno;
}
