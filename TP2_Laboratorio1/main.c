#include <stdio.h>
#include <stdlib.h>
#include "Burgos.h"
#define TAM 1000

int main()
{
    int respuesta,banderaId=0,banderaAlta=0;
    eEmployee employee[TAM];

    initEmployees(employee,TAM);
    do{
        respuesta=mainMenu();
        switch(respuesta)
        {
            case 1:
                addEmployees(employee,TAM,&banderaId,&banderaAlta);
                break;
            case 2:
                modifyEmployee(employee,TAM,&banderaAlta);
                break;
            case 3:
                removeEmployee(employee,TAM,&banderaAlta);
                break;
            case 4:
                sortEmployees(employee,TAM);
                printEmployees(employee,TAM,&banderaAlta);
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
