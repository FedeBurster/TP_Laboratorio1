#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* directorio del archivo
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 1 si se carga con exito, 0 de lo contrario
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int okay = 0;
    FILE* pointerFile = fopen(path, "r");
    if (pointerFile != NULL)
    {
        if (parser_EmployeeFromText(pointerFile, pArrayListEmployee))
        {
            okay = 1;
        }
    }
    fclose(pointerFile);
    return okay;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* directorio del archivo
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 1 si se carga con exito, 0 de lo contrario
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int okay = 0;

    FILE* pointerFile = fopen(path, "rb");
    if (pointerFile != NULL)
    {
        if (parser_EmployeeFromBinary(pointerFile, pArrayListEmployee))
        {
            okay = 1;
        }
    }
    fclose(pointerFile);
    return okay;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    employee_register(pArrayListEmployee);
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    employee_modify(pArrayListEmployee);
    return 1;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    removeEmployee(pArrayListEmployee);
    return 1;
}

/** \brief Muestra los empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    listEmployees(pArrayListEmployee);
    return 1;
}

/** \brief Ordena los empleados segun el criterio pedido
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    switchSortEmployees(pArrayListEmployee);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* directorio del archivo
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 1 si se guarda con exito, 0 de lo contrario
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int okay = 0,i;

    FILE* pointerFile = fopen(path, "w");
    Employee* auxEmployee = (Employee*) employee_new();
    if(path != NULL && pArrayListEmployee != NULL && pointerFile != NULL )
    {
        fprintf(pointerFile, "id,nombre,horasTrabajadas,sueldo\n");
        for (i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            fprintf(pointerFile, "%d,%s,%d,%d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo );
        }
        printf("Se completo el guardado con exito\n");
        okay = 1;
    }else
    {
        printf("Ha ocurrido un error, los datos no fueron guardados\n");
    }
    return okay;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* directorio del archivo
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 1 si se guarda con exito, 0 de lo contrario
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int okay = 0,i,quantity;
    Employee* auxEmployee = (Employee*) employee_new();
    FILE* pointerFile= fopen(path, "wb");

    if(path != NULL && pArrayListEmployee != NULL && pointerFile != NULL && auxEmployee != NULL )
    {
        for( i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            quantity = fwrite(auxEmployee, sizeof(Employee), 1, pointerFile );
            if (quantity<1)
            {
                printf("Ha ocurrido un error, los datos no fueron guardados\n");
                return okay;
            }
        }
        okay = 1;
        printf("Los datos fueron guardados con exito\n");
    }
    return okay;
}

