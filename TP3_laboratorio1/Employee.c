#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "LinkedList.h"
#include "burgos.h"

/** \brief Reserva espacio en memoria para un nuevo empleado
 *
 * \return Employee* puntero con la direcion de memoria del nuevo empleado
 *
 */
Employee* employee_new()
{
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));
    if (newEmployee != NULL)
    {
        newEmployee->id = 0;
        strcpy(newEmployee->nombre," ");
        newEmployee->sueldo = 0;
        newEmployee->horasTrabajadas = 0;
    }
    return newEmployee;
}

/** \brief Carga los datos en la estructura Employee
 *
 * \param idString char* cadena de caracteres con id del empleado
 * \param nameString char* cadena de caracteres con el nombre del empleado
 * \param hoursString char* cadena de caracteres con las horas trabajadas
 * \param salaryString char* cadena de caracteres con el sueldo del empleado
 * \return Employee* puntero al empleado con los datos cargados
 *
 */
Employee* employee_newParametros(char* idString,char* nameString,char* hoursString, char* salaryString)
{
    Employee* newEmployee = employee_new();
    if (newEmployee != NULL)
    {
        employee_setId(newEmployee, atoi(idString));
        employee_setNombre(newEmployee, nameString);
        employee_setHorasTrabajadas(newEmployee, atoi(hoursString));
        employee_setSueldo(newEmployee, atoi(salaryString));
    }
    return newEmployee;
}

/** \brief carga el campo ID con los datos ingresados
 *
 * \param this Employee* puntero al a estructura Employee
 * \param id int numero de ID del empleado
 * \return int devuelve 1 si se carga con exito, 0 de lo contrario
 *
 */
int employee_setId(Employee* this,int id)
{
    int okay = 0;
    if (this != NULL)
    {
        this->id = id;
        okay = 1;
    }
    return okay;
}

/** \brief carga el nombre con los datos ingresados
 *
 * \param this Employee* puntero a la estructura Employee
 * \param name char* cadena de caracteres a ser cargada
 * \return int devuelve 1 si se carga con exito, 0 de lo contrario
 *
 */
int employee_setNombre(Employee* this,char* name)
{
    int okay = 0;
    if (this != NULL)
    {
        strcpy(this->nombre, name);
        okay=1;
    }
    return okay;
}

/** \brief carga las horas trabajadas con los datos ingresados
 *
 * \param this Employee*  puntero a la estructura Employee
 * \param hours int horas trabajadas a cargar
 * \return int devuelve 1 si se carga con exito, 0 de lo contrario
 *
 */
int employee_setHorasTrabajadas(Employee* this,int hours)
{
    int okay=0;
    if (this != NULL)
    {
        this->horasTrabajadas = hours;
        okay = 1;
    }
    return okay;
}

/** \brief carga el sueldo con los datos ingresados
 *
 * \param this Employee* puntero a la estructura Employee
 * \param sueldo int sueldo a cargar
 * \return int devuelve 1 si se carga con exito, 0 de lo contrario
 *
 */
int employee_setSueldo(Employee* this,int salary)
{
    int okay = 0;
    if (this != NULL) {
        this->sueldo = salary;
        okay = 1;
    }
    return okay;
}

/** \brief agrega una estructura a la lista
 *
 * \param list LinkedList* lista donde agregar la estructura
 * \return devuelve 1 si se agrega con exito, 0 de lo contrario
 *
 */
int employee_register(LinkedList* list)
{
    int okay=0,id;
    Employee* auxEmployee = (Employee*) employee_new();

    system("cls");
    printf("Alta empleado\n");
    validateInt("Ingrese el ID: ", "Ha ocurrido un error.\nEl ID debe estar compuesto unicamente de caracteres numericos\nReingrese ID: ",0 , &id);
    if (validateId(list, id))
    {
        auxEmployee->id = id;
        validateString("Ingrese nombre: ", "Ha ocurrido un error.\nEl nombre debe estar compuesto unicamente de caracteres alfabeticos\nReingrese nombre: ", 128, auxEmployee->nombre);
        capsLock(auxEmployee->nombre);
        validateInt("Ingrese horas trabajadas: ", "Ha ocurrido un error.\nLas horas trabajadas deben estar compuestas unicamente de caracteres numericos\nReingrese horas trabajadas: ",0, &auxEmployee->horasTrabajadas);
        validateInt("ingrese sueldo: ", "Ha ocurrido un error.\nEl sueldo debe ser un valor positivo\nReingrese el sueldo: ",0, &auxEmployee->sueldo);
        if (ll_add(list, auxEmployee) == 0)
        {
            okay = 1;
            printf("\nEl alta se completo con exito\n");
        }
    }
    else
    {
        printf("El ID ingresada ya se encuentra en uso\n");
    }
    if (!okay)
    {
        employee_delete(auxEmployee);
    }
    return okay;
}


/** \brief Libera el espacio en memoria
 *
 * \param this Employee* la direccion de memoria a ser liberada
 *
 */
void employee_delete(Employee* this)
{
    free(this);
}

/** \brief Pide id del empleado y muestra menu para modificar sus datos
 *
 * \param lista LinkedList* lista de estructuras empleado
 * \return int devuelve 1 si se modifica con exito, 0 de lo contrario
 *
 */
int employee_modify(LinkedList* list)
{
    int okay = 0, i, id, index, flag=0;
    char answer;
    Employee* auxEmployee = (Employee*) employee_new();

    if (list != NULL && auxEmployee !=NULL)
    {
        system("cls");
        printf("Modificar empleado\n");
        do
        {
            validateInt("Ingrese el ID del empleado a modificar (0 para mostrar empleados): ","Ha ocurrido un error\nIngrese el ID del empleado a modificar (0 para mostrar empleados): ", 0, &id );
            if (id == 0)
            {
                listEmployees(list);
            }
            else
            {
                for (i=0; i<ll_len(list); i++)
                {
                    auxEmployee = ll_get(list, i);
                    if (auxEmployee->id == id)
                    {
                        index = i;
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                {
                    system("cls");
                    printf("Modificar: \n");
                    printf("  ID        Nombre  Horas trabajadas  Sueldo\n");
                    listEmployee(list, index);
                    printf("\n\nContinuar (s/n)? ");
                    fflush(stdin);
                    answer = getchar();
                    answer = tolower(answer);
                    if (answer == 's')
                    {
                        if (modifyEmployee(list, index))
                        {
                            okay = 1;
                        }
                    }
                    else if (answer != 's')
                    {
                        printf("Se ha cancelado la modificacion\n");
                    }

                    break;
                }
                else
                {
                    printf("El ID ingresado no esta relacionado a ningun empleado\n");
                    break;
                }
            }
        }
        while (flag == 0);
    }
    return okay;
}

/** \brief Muestra en pantalla la lista completa
 *
 * \param lista LinkedList* lista de estructuras
 *
 */
void listEmployees(LinkedList* list)
{
    int i;
    printf("  ID        Nombre  Horas trabajadas  Sueldo\n");
    for (i=0; i<ll_len(list); i++)
    {
        listEmployee(list, i);
    }
}

/** \brief Muestra por pantalla un elemento de la lista
 *
 * \param lista LinkedList* lista de estructuras
 * \param index int indice en la lista
 *
 */
void listEmployee(LinkedList* lista, int index)
{
    Employee* auxEmployee = (Employee*) employee_new();
    auxEmployee = ll_get(lista, index);
    printf("%4d  %12s  %8d          %d \n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
}

/** \brief permite modificar al empleado segun quiera el usuario
 *
 * \param lista LinkedList* lista de estructuras
 * \param index int indice en la lista
 * \return int devuelve la opcion elegida por el usuario
 *
 */
int modifyEmployee(LinkedList* list, int index)
{
    int option;
    do
    {
        option = menuModifyEmployee();
        switch(option)
        {
        case 1:
            modifyID(list, index);
            system("pause");
            break;
        case 2:
            modifyName(list, index);
            system("pause");
            break;
        case 3:
            modifyHours(list, index);
            system("pause");
            break;
        case 4:
            modifySalary(list, index);
            system("pause");
            break;
        }
    }
    while(option != 5);
    return option;
}


/** \brief Muestra menu de opciones modificar
 *
 * \return int devuelve la opcion elegida por el usuario
 *
 */
int menuModifyEmployee()
{
    int option;
    system("cls");
    printf("Modificar empleado\n\n1. Modificar ID\n2. Modificar Nombre\n");
    printf("3. Modificar Horas trabajadas\n4. Modificar Sueldo\n5. Salir\n");
    validateInt("Ingrese opcion: ", "Opcion no disponible\nIngrese opcion: ", 0, &option);
    return option;
}

/** \brief Desarrolla la opcion para modificar el ID del empleado
 *
 * \param lista LinkedList* lista de estructuras
 * \param index int indice en la lista
 * \return int devuelve 1 si modifica con exito, 0 de lo contrario
 *
 */
int modifyID(LinkedList* list,int  index)
{
    int okay = 0,id;
    Employee* auxEmployee = (Employee*) employee_new();
    auxEmployee = ll_get(list, index);
    if(auxEmployee != NULL)
    {
        validateInt("Ingrese nuevo ID: ", "Ha ocurrido un error\nEl ID debe estar compuesto unicamente de caracteres numericos\nIngrese nuevo ID: ",0, &id);
        if(validateId(list, id))
        {
            printf("Se modifico el ID %d por %d de manera exitosa\n", auxEmployee->id, id);
            auxEmployee->id = id;
            okay = 1;
        }
        else
        {
            printf("El id ingresada se encuentra en uso\n");
        }
    }
    else
    {
        printf("\nHa ocurrido un error, no se modifico el ID\n");
    }
    return okay;
}



/** \brief Desarrolla la opcion para modificar el nombre del empleado
 *
 * \param lista LinkedList* lista de estructuras
 * \param index int indice en la lista
 * \return int devuelve 1 si modifica con exito, 0 de lo contrario
 *
 */
int modifyName(LinkedList* list,int  index)
{
    int okay = 0;
    char name[128];
    Employee* auxEmployee = (Employee*) employee_new();
    auxEmployee = ll_get(list, index);
    if (auxEmployee != NULL)
    {
        validateString("Ingrese nuevo nombre: ", "Ha ocurrido un error\nEl nombre debe estar compuesto de caracteres alfabeticos unicamente\nIngrese nuevo nombre: ", 128, name);
        capsLock(name);
        printf("Se modifico el nombre %s por %s de manera exitosa\n", auxEmployee->nombre, name);
        strcpy(auxEmployee->nombre, name);
        okay = 1;
    }
    else
    {
        printf("\nHa ocurrido un error, no se modifico el nombre\n");
    }
    return okay;
}

/** \brief Desarrolla la opcion para modificar las horas trabajadas del empleado
 *
 * \param lista LinkedList* lista de estructuras
 * \param index int indice en la lista
 * \return int devuelve 1 si modifica con exito, 0 de lo contrario
 *
 */
int modifyHours(LinkedList* lista,int  index)
{
    int okay = 0,hours;
    Employee* auxEmployee = (Employee*) employee_new();
    auxEmployee = ll_get(lista, index);
    if (auxEmployee != NULL)
    {
        validateInt("Ingrese horas trabajdas: ", "Ha ocurrido un error\nLas horas trabajadas debe ser un valor positivo\nIngrese horas trabajdas: ",0, &hours);
        printf("Se modificaron las %d horas trabajadas por %d con exito\n", auxEmployee->horasTrabajadas, hours);
        auxEmployee->horasTrabajadas = hours;
        okay = 1;
    }
    else
    {
        printf("\nHa ocurrido un error, no se modificaron las horas trabajadas\n");
    }
    return okay;
}

/** \brief Desarrolla la opcion para modificar el sueldo del empleado
 *
 * \param lista LinkedList* lista de estructuras
 * \param index int indice en la lista
 * \return int devuelve 1 si modifica con exito, 0 de lo contrario
 *
 */
int modifySalary(LinkedList* lista,int  index)
{
    int okay = 0,salary;
    Employee* auxEmployee = (Employee*) employee_new();
    auxEmployee = ll_get(lista, index);
    if (auxEmployee != NULL)
    {
        validateInt("Ingrese sueldo: ", "Ha ocurrido un error\nEl sueldo debe ser un valor positivo\nIngrese sueldo: ",0, &salary);
        printf("Se modifico el sueldo %d por %d con exito\n", auxEmployee->sueldo, salary);
        auxEmployee->sueldo = salary;
        okay = 1;
    }
    else
    {
        printf("\nHa ocurrido un error, no se modifico el sueldo\n");
    }
    return okay;
}

/** \brief Borra un elemento de la lista por ID
 *
 * \param lista LinkedList* lista que se editara
 * \return int
 *
 */
int removeEmployee(LinkedList* lista)
{
    int okay = 0,i,id,index,flag=0;
    char answer;
    Employee* auxEmployee = (Employee*) employee_new();
    if(lista != NULL)
    {
        system("cls");
        printf("Baja empleado\n");
        do
        {
            validateInt("Ingrese Id para dar de baja (0 para mostrar lista): ","Ha ocurrido un error\nIngrese Id para dar de baja (0 para mostrar lista): ", 0, &id );
            if(id == 0)
            {
                listEmployees(lista);
            }
            else
            {
                for(i=0; i<ll_len(lista); i++)
                {
                    auxEmployee = ll_get(lista, i);
                    if (auxEmployee->id == id)
                    {
                        index = i;
                        flag = 1;
                        break;
                    }
                }
                if(flag)
                {
                    system("cls");
                    printf("Baja: \n");
                    printf("  ID        Nombre  Horas trabajadas  Sueldo\n");
                    listEmployee(lista, index);
                    printf("\n\nContinuar (s/n)? ");
                    fflush(stdin);
                    answer = getchar();
                    answer = tolower(answer);
                    if(answer == 's' && ll_remove(lista, index)==0)
                    {
                        printf("Se ha completado la baja\n");
                        okay = 1;
                    }
                    else if(answer != 's')
                    {
                        printf("Se ha cancelado la baja\n");
                    }
                    else
                    {
                        printf("Ha ocurrido un error durante la baja\n");
                    }
                }
                else
                {
                    printf("El ID no se encuentra en uso\n");
                    flag = 1;
                }
            }
        }
        while(flag == 0);
    }
    return okay;
}

/** \brief Llama a la funcion que ordena la lista segun el criterio seleccionado
 *
 * \param lista LinkedList* lista a ordenar
 * \return int
 *
 */
int switchSortEmployees(LinkedList* lista)
{
    int option,sortBy= -1;
    do
    {
        option = menuSortEmployees();
        if(option < 5)
        {
            while(sortBy != 0 && sortBy !=1)
            {
                validateInt("\n0. ordenar de manera descendiente \n1. Ordenar de manera ascendente\nIngresar: ","Ha ocurrido un error, ingresar 1 o 0\n0. ordenar de manera descendiente \n1. Ordenar de manera ascendente\nIngresar: ",0, &sortBy);
            }
        }
        switch(option)
        {
        case 1:
            ll_sort(lista, sortByID, sortBy);
            break;
        case 2:
            ll_sort(lista, sortByName, sortBy);
            break;
        case 3:
            ll_sort(lista, sortByHours, sortBy);
            break;
        case 4:
            ll_sort(lista, sortBySalary,sortBy);
            break;
        }
    }
    while(option != 5);
    return option;
}

/** \brief Muestra menu de ordenamiento
 *
 * \return int numero de opcion seleccionada
 *
 */
int menuSortEmployees()
{
    int option;
    system("cls");
    printf("Ordenar empleados\n\n");
    printf("1. Ordenar por ID.\n2. Ordenar por Nombre.\n3. Ordenar por Horas trabajadas.\n");
    printf("4. Ordenar por Sueldo.\n5. Salir\n");
    validateInt("Ingresar opcion: ", "Ha ocurrido un error.\nElija opcion: ", 0, &option);
    return option;
}

/** \brief Ordena dos empleados por ID
 *
 * \param employee1 void* primer empleado a ordenar
 * \param employee2 void* segundo empleado a ordenar
 * \return int devuelve 1 el primero es mayor, -1 si es menor, 0 si son iguales
 *
 */
int sortByID(void* employee1, void* employee2)
{
    int answer,idEmployee1,idEmployee2;

    employee_getId(employee1, &idEmployee1);
    employee_getId(employee2, &idEmployee2);
    if(idEmployee1 > idEmployee2)
    {
        answer = 1;
    }
    else if(idEmployee1 < idEmployee2)
    {
        answer = -1;
    }
    else
    {
        answer = 0;
    }
    return answer;
}

/** \brief Ordena dos empleados por sueldo
 *
 * \param employee1 void* primer empleado a ordenar
 * \param employee2 void* segundo empleado a ordenar
 * \return int devuelve 1 el primero es mayor, -1 si es menor, 0 si son iguales
 *
 */
int sortBySalary(void* employee1, void* employee2)
{
    int answer;
    int salaryEmployee1;
    int salaryEmployee2;

    employee_getSueldo(employee1, &salaryEmployee1);
    employee_getSueldo(employee2, &salaryEmployee2);

    if (salaryEmployee1 > salaryEmployee2)
    {
        answer = 1;
    }
    else if (salaryEmployee1 < salaryEmployee2)
    {
        answer = -1;
    }
    else
    {
        answer =0;
    }
    return answer;
}

/** \brief Ordena dos empleados por Horas trabajadas
 *
 * \param employee1 void* primer empleado a ordenar
 * \param eemployee2 void* segundo empleado a ordenar
 * \return int devuelve 1 el primero es mayor, -1 si es menor, 0 si son iguales
 *
 */
int sortByHours(void* employee1, void* employee2)
{
    int answer,hoursEmployee1,hoursEmployee2;

    employee_getHorasTrabajadas(employee1,&hoursEmployee1);
    employee_getHorasTrabajadas(employee2,&hoursEmployee2);
    if (hoursEmployee1 > hoursEmployee2)
    {
        answer = 1;
    }
    else if (hoursEmployee1 < hoursEmployee2)
    {
        answer = -1;
    }
    else
    {
        answer =0;
    }
    return answer;
}

/** \brief Ordena dos empleados por Nombre
 *
 * \param employee1 void* primer empleado a ordenar
 * \param employee2 void* segundo empleado a ordenar
 * \return int devuelve 1 el primero es mayor, -1 si es menor, 0 si son iguales
 *
 */
int sortByName(void* employee1, void* employee2)
{
    int answer;
    char employeeName1[128];
    char employeeName2[128];

    employee_getNombre(employee1, employeeName1);
    employee_getNombre(employee2, employeeName2);
    if(strcmp(employeeName1, employeeName2) > 0)
    {
        answer = 1;
    }
    else if(strcmp(employeeName1, employeeName2) < 0)
    {
        answer = -1;
    }
    else
    {
        answer =0;
    }
    return answer;
}


/** \brief Carga el Id de un empleado en una variable
 *
 * \param this Employee* puntero al employee
 * \param id int* puntero a la variable
 * \return int devuelve 1 si carga con exito, 0 de lo contrario
 *
 */
int employee_getId(Employee* this,int* id)
{
    int okay = 0;
    if (this != NULL && id !=NULL)
    {
        *id = this->id;
        okay = 1;
    }
    return okay;
}

/** \brief Carga el sueldo de un employee en una variable
 *
 * \param this Employee* puntero al employee
 * \param sueldo int* puntero a la variable
 * \return int devuelve 1 si carga con exito, 0 de lo contrario
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int okay = 0;
    if (this != NULL && sueldo !=NULL)
    {
        *sueldo = this->sueldo;
        okay = 1;
    }
    return okay;
}

/** \brief Carga las horas trabajadas de un employee en una variable
 *
 * \param this Employee* puntero al employee
 * \param horas int* puntero a la variable
 * \return int devuelve 1 si carga con exito, 0 de lo contrario
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horas)
{
    int okay = 0;
    if (this != NULL && horas !=NULL)
    {
        *horas = this->horasTrabajadas;
        okay = 1;
    }
    return okay;
}

/** \brief Carga las horas trabajadas de un employee en una variable
 *
 * \param this Employee* puntero a la estructura employee
 * \param nombre char* nombre a cargar
 * \return int devuelve 1 si carga con exito, 0 de lo contrario
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int okay = 0;
    if (this != NULL && nombre !=NULL)
    {
        strcpy(nombre,this->nombre );
        okay = 1;
    }
    return okay;
}
