#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pointerFile File* puntero a la direccion de memoria de un archivo abierto
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 1 si se completa con exito, 0 de lo contrario
 *
 */
int parser_EmployeeFromText(FILE* pointerFile , LinkedList* pArrayListEmployee)
{
    int okay=0;
    int quantity;
    char stringFile[4][128];

    Employee* auxEmployee = (Employee*) employee_new();
    if (pointerFile == NULL || pArrayListEmployee == NULL)
    {
        return okay;
    }
    fscanf(pointerFile, "%[^,],%[^,],%[^,],%[^\n]",stringFile[0], stringFile[1], stringFile[2], stringFile[3]);
    while(!feof(pointerFile))
    {
        quantity = fscanf(pointerFile, "%[^,],%[^,],%[^,],%[^\n]",stringFile[0], stringFile[1], stringFile[2], stringFile[3]);
        if(quantity == 4)
        {
            auxEmployee = employee_newParametros(stringFile[0], stringFile[1], stringFile[2], stringFile[3]);
            if (auxEmployee != NULL)
            {
                ll_add(pArrayListEmployee, auxEmployee);
            }
        }
    }
    okay = 1;
    return okay;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pointerFile FILE* puntero a la direccion de memoria de un archivo abierto
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 1 si se completa con exito, 0 de lo contrario
 *
 */
int parser_EmployeeFromBinary(FILE* pointerFile , LinkedList* pArrayListEmployee)
{
    int okay = 0;
    int quantity;
    if (pointerFile == NULL || pArrayListEmployee == NULL)
    {
        return okay;
    }
    while (!feof(pointerFile))
    {
        Employee* auxEmployee = (Employee*) employee_new();
        if (auxEmployee != NULL)
        {
            quantity = fread(auxEmployee, sizeof(Employee), 1, pointerFile);
            if(quantity==1)
            {
                ll_add(pArrayListEmployee, auxEmployee);
                okay=1;
            }
        }
    }
    return okay;
}
