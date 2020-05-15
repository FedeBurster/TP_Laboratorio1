#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include <string.h>

int initEmployees(eEmployee* employee,int arrayLength){

    int i;

    for(i=0;i<arrayLength;i++)
    {
        employee[i].isEmpty=1;
    }

    return 0;
}

int addEmployees(eEmployee* employee,int arrayLength,int* banderaId,int *banderaAlta){

    int i;
    char auxFloat[50];
    system("cls");

    for(i=0;i<arrayLength;i++)
    {
        if(employee[i].isEmpty==1)
        {
            printf("Alta de empleado\n\nIngrese el nombre del empleado: ");
            scanf("%s",employee[i].name);
            fflush(stdin);
            if(esSoloLetras(employee[i].name)==0)
            {
                printf("\nError, solo se aceptan caracteres alfabeticos para el campo nombre.\n\n");
                system("pause");
                return -1;
            }
            printf("\nIngrese el apellido del empleado: ");
            scanf("%c",employee[i].lastName);
            fflush(stdin);
            if(esSoloLetras(employee[i].lastName)==0)
            {
                printf("\nError, solo se aceptan caracteres alfabeticos para el campo apellido.\n\n");
                system("pause");
                return -1;
            }
            printf("\nIngrese el sueldo del empleado: ");
            scanf("%s",auxFloat);
            fflush(stdin);
            if(validarStringFloat(auxFloat)==0)
            {
                printf("\nError, los caracteres ingresados no corresponden al campo sueldo.\n\n");
                system("pause");
                return -1;
            }
            employee[i].salary = atof(auxFloat);

            printf("\nIngrese el sector del empleado: ");
            scanf("%s",auxFloat);
            fflush(stdin);
            if(validarStringInt(auxFloat)==0)
            {
                printf("\nError, solo se aceptan caracteres numericos para el campo sector.\n\n");
                system("pause");
                return -1;
            }
            employee[i].sector=atoi(auxFloat);
            *banderaId = *banderaId+1;
            employee[i].id=*banderaId;
            printf("\nSe le ha asignado el ID %d al empleado.",employee[i].id);
            printf("\nEl alta se ha completado con exito.\n\n");
            employee[i].isEmpty=0;
            *banderaAlta=*banderaAlta+1;
            return 0;
        }
    }
    return -1;
}

int modifyEmployee(eEmployee* employee,int arrayLength){


    int id,i,respuesta;
    char auxString[50];
    printf("\n\nIngrese el ID del empleado a modificar ");
    scanf("%d",&id);
    fflush(stdin);
    for(i=0;i<arrayLength;i++)
    {
        if(id==employee[i].id && employee[i].isEmpty==0)
        {
            system("cls");
            printf("Menu modificacion\n\n");
            printf("1)Modificar nombre\n2)Modificar apellido\n3)Modificar sueldo\n4)Modificar sector\n0)Volver al menu principal");
            printf("\n\nIngresar opcion: ");
            scanf("%d",&respuesta);
            fflush(stdin);
            switch(respuesta)
            {
                case 1:
                    printf("\n\nIngrese el nuevo nombre: ");
                    scanf("%s",auxString);
                    fflush(stdin);
                    if(esSoloLetras(auxString)==0)
                    {
                        printf("\nError, solo se aceptan caracteres alfabeticos para el campo nombre.\n\n");
                        system("pause");
                        return -1;
                    }
                    strcpy(employee[i].name,auxString);
                    printf("\nEl nombre fue modificado con exito.\n");
                    system("pause");
                    return 0;
                case 2:
                    printf("\n\nIngrese el nuevo apellido: ");
                    scanf("%s",auxString);
                    fflush(stdin);
                    if(esSoloLetras(auxString)==0)
                    {
                        printf("\nError, solo se aceptan caracteres alfabeticos para el campo apellido.\n\n");
                        system("pause");
                        return -1;
                    }
                    strcpy(employee[i].lastName,auxString);
                    printf("\nEl apellido fue modificado con exito.\n");
                    system("pause");
                    return 0;
                case 3:
                    printf("\nIngrese el nuevo sueldo del empleado: ");
                    scanf("%s",auxString);
                    fflush(stdin);
                    if(validarStringFloat(auxString)==0)
                    {
                        printf("\nError, los caracteres ingresados no corresponden al campo sueldo.\n\n");
                        system("pause");
                        return -1;
                    }
                    employee[i].salary = atof(auxString);
                    printf("\nEl sueldo fue modificado con exito.\n");
                    system("pause");
                    return 0;
                case 4:
                    printf("\nIngrese el nuevo sector del empleado: ");
                    scanf("%s",auxString);
                    fflush(stdin);
                    if(validarStringInt(auxString)==0)
                    {
                        printf("\nError, solo se aceptan caracteres numericos para el campo sector.\n\n");
                        system("pause");
                        return -1;
                    }
                    employee[i].sector=atoi(auxString);
                    printf("\nEl sector fue modificado con exito.\n");
                    system("pause");
                    return 0;
                case 0:
                    return 0;
                default:
                    printf("\n\nOpcion inexistente.\n");
                    return 0;
            }
        }
    }
    printf("No se ha encontrado un empleado con el id ingresado.\n\n");
    system("pause");
    return -1;
}

int removeEmployee(eEmployee* employee, int arrayLength)
{
    int id,i;
    printf("\n\nIngrese el ID del empleado a dar de baja: ");
    scanf("%d",&id);
    fflush(stdin);

    for(i=0;i<arrayLength;i++)
    {
        if(id==employee[i].id && employee[i].isEmpty==0)
        {
            employee[i].isEmpty=1;
            printf("\nSe ha dado de baja al empleado con exito.\n");
            system("pause");
            return 0;
        }
    }
    printf("\nError, no se ha encontrado un empleado que coincida con el ID ingresado.\n");
    system("pause");
    return -1;
}
int sortEmployees(eEmployee* employee,int arrayLength)
{
    int c,d,i;
    eEmployee auxEmployee;

    for (c = 0 ; c < arrayLength - 1; c++)
    {
        for (d = 0 ; d < arrayLength - c - 1; d++)
        {
            if((employee[c].isEmpty==0 && employee[d].isEmpty==0)&&(employee[d].sector > employee[d+1].sector))
            {
                auxEmployee = employee[d];
                employee[d]   = employee[d+1];
                employee[d+1] = auxEmployee;
            }else if((employee[c].isEmpty==0 && employee[d].isEmpty==0)&&(employee[d].sector == employee[d+1].sector))
            {
                if()
            }
        }
    }
    return -1;
}
