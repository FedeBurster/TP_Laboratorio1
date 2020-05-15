#include <stdio.h>
#include <stdlib.h>
#include "Burgos.h"


int mainMenu()
{
    int respuesta;

    system("cls");
    printf("MENU DE OPCIONES\n\nEmpleados:\n\t1)Alta\n\t2)Modificar\n\t3)Baja\n\t4)Listar\n\t0)SALIR");
    printf("\n\nIngrese la opcion que desee realizar: ");
    scanf("%d", &respuesta);
    fflush(stdin);
    return respuesta;
}

