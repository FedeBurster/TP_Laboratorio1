#include <stdio.h>
#include <stdlib.h>
#include "Burgos.h"
#define TAM 10

int main()
{
    int respuesta,banderaId=0,banderaAlta=3;//poner 0
    eEmployee employee[TAM];


    initEmployees(employee,TAM);
    do{
        respuesta=mainMenu();
        fflush(stdin);
        switch(respuesta)
        {
            case 1:
                addEmployees(employee,TAM,&banderaId,&banderaAlta);
                system("pause");
                break;
            case 2:
                if(banderaAlta<1)
                {
                    printf("\n\nPara modificar los datos de un empleado, se debe dar alta primero.\n\n");
                    system("pause");
                    break;
                }
                modifyEmployee(employee,TAM);
                break;
            case 3:
                if(banderaAlta<1)
                {
                    printf("\n\nPara modificar los datos de un empleado, se debe dar alta primero.\n\n");
                    system("pause");
                    break;
                }
                removeEmployee(employee,TAM);
                break;
            case 4:
                if(banderaAlta<1)
                {
                    printf("\n\nPara modificar los datos de un empleado, se debe dar alta primero.\n\n");
                    system("pause");
                    break;
                }

                break;
            case 0:
                break;
            default:
                printf("\n\nError, opcion no disponible.\n");
                system("pause");
                break;
        }
    }while(respuesta!=0);
    return 0;
}
