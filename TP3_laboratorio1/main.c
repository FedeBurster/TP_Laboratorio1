#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "burgos.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option = 0, flag=0;;
    LinkedList* auxList = ll_newLinkedList();
    do{
        option=mainMenu();
        switch(option)
        {
            case 1:
                if(!flag)
                {
                    if(controller_loadFromText("data.csv",auxList))
                    {
                        printf("La carga se completo con exito\n");
                        flag=1;
                    }
                    else
                    {
                        printf("Ocurrio un error al cargar el archivo\n");
                    }
                }
                else
                {
                    printf("Los datos del archivo ya han sido cargados\n");

                }
                system("pause");
                break;
            case 2:
                if(!flag)
                {
                    if(controller_loadFromBinary("data.bin",auxList))
                    {
                        printf("La carga se completo con exito\n");
                        flag=1;
                    }
                    else
                    {
                        printf("Ocurrio un error al cargar el archivo\n");
                    }
                }
                else
                {
                    printf("Los datos del archivo ya han sido cargados\n");
                }
                system("pause");
                break;
            case 3:
                if(flag)
                {
                    controller_addEmployee(auxList);
                }
                else
                {
                    printf("Se deben cargar los datos del archivo\n");
                }
                system("pause");
                break;
            case 4:
                if(flag)
                {
                    controller_editEmployee(auxList);
                }
                else
                {
                    printf("Se deben cargar los datos del archivo\n");
                }
                system("pause");
                break;
            case 5:
                if(flag)
                {
                    controller_removeEmployee(auxList);
                }
                else
                {
                    printf("Se deben cargar los datos del archivo\n");
                }
                system("pause");
                break;
            case 6:
                if(flag)
                {
                    controller_ListEmployee(auxList);
                }
                else
                {
                    printf("Se deben cargar los datos del archivo\n");
                }
                system("pause");
                break;
            case 7:
                if(flag)
                {
                    controller_sortEmployee(auxList);
                }
                else
                {
                    printf("Se deben cargar los datos del archivo\n");
                }
                system("pause");
                break;
            case 8:
                if(flag)
                {
                    controller_saveAsText("data.csv", auxList);
                }
                else
                {
                    printf("Se deben cargar los datos del archivo\n");
                }
                system("pause");
                break;
            case 9:
                if(flag)
                {
                    controller_saveAsBinary("data.bin", auxList);
                }
                else
                {
                    printf("Se deben cargar los datos del archivo\n");
                }
                system("pause");
                break;
            default:
                break;
        }
    }while(option != 10);
    ll_deleteLinkedList(auxList);
    return 0;
}
