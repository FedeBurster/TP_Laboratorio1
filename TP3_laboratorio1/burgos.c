#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "burgos.h"
#include "Employee.h"

/** \brief valida si una cadena esta compuesta unicamente de caracteres alfabeticos
 *
 * \param message char* mensaje pide el ingreso de la cadena a validar
 * \param messageError char* mensaje de error si la cadena ingresada no cumple con los criterios
 * \param maxLengthString int cantidad maxima de caracteres que puede tener la cadena
 * \param auxString char* cadena de caracteres donde se guarda una vez validada
 * \return devuelve 1 si se pudo guardar la cadena de caracteres, 0 de lo contrario
 *
 */
int validateString(char* message, char* messageError, int maxLengthString, char* auxString)
{
    int okay = 0,auxInt;
    char aux[500];

    printf("%s", message);
    fflush(stdin);
    gets(aux);
    auxInt = atoi(aux) ;
    if(strlen(aux)<=maxLengthString || auxInt == 0)
    {
        okay = 1;
    }
    while(strlen(aux)>maxLengthString || auxInt != 0 )
    {
        printf("%s", messageError);
        fflush(stdin);
        gets(aux);
        auxInt = atoi(aux) ;
        if(strlen(aux)<=maxLengthString || auxInt == 0)
        {
            okay = 1;
        }
    }
    strcpy(auxString,aux);
    return okay;
}

/** \brief Pone en mayuscula la primera letra de cada palabra
 *
 * \param charString char* cadena de caracteres a modificar
 *
 */
void capsLock(char* charString)
{
    int length,i;
    length = strlen(charString);
    for (i=0; i<length; i++)
    {
        charString[i] = tolower(charString[i]);
    }
    for (i=0; i<length; i++)
    {
        if (i==0 || charString[i-1]==' ')
        {
            charString[i] = toupper(charString[i]);
        }
    }
}

/** \brief valida si la cadena de caracteres ingresada cumple los criterios de un numero flotante
 *
 * \param message char* mensaje pidiendo el ingreso
 * \param messageError char* mensaje de error si lo ingresado no cumple el criterio
 * \param negative int determina si el numero puede ser negativo o no
 * \param auxPointer float* puntero a la direccion de memoria donde se guarda una vez validado
 * \return devuelve 1 si el numero ingresado es valido, 0 de lo contrario
 */
int validateFloat(char* message, char* messageError, int negative, float* auxPointer)
{
    int okay = 0;
    int auxInt;
    printf("%s",message);
    fflush(stdin);
    auxInt = scanf("%f",auxPointer);
    if(!negative)
    {
        while((*auxPointer) < 0 || !auxInt)
        {
            printf("%s",messageError);
            fflush(stdin);
            auxInt = scanf("%f",auxPointer);
        }
        okay = 1;
    }
    else if(negative)
    {
        while(!auxInt)
        {
            printf("%s",messageError);
            fflush(stdin);
            auxInt = scanf("%f",auxPointer);
        }
        okay = 1;
    }
    return okay;
}

/** \brief valida si el entero ingresado cumple el criterio pedido
 *
 * \param message char* mensaje pidiendo el ingreso de un entero
 * \param messageError char* mensaje de error si el numero ingresado no cumple el criterio
 * \param negative int determina si el numero puede ser negativo o no
 * \param auxPointer int* puntero a la direccion de memoria donde se guarda el entero una vez validado
 * \return devuelve 1 si el numero ingresado es valido, 0 de lo contrario
 */
int validateInt(char* message, char* messageError, int negative, int* auxPointer)
{
    int okay = 0;
    int auxInt;

    printf("%s",message);
    fflush(stdin);
    auxInt = scanf("%d",auxPointer);
    if(negative == 0)
    {
        while((*auxPointer) < 0 || !auxInt)
        {
            printf("%s",messageError);
            fflush(stdin);
            auxInt = scanf("%d",auxPointer);
        }
        okay = 1;
    }
    else if(negative == 1)
    {
        while(!auxInt)
        {
            printf("%s",messageError);
            fflush(stdin);
            auxInt = scanf("%d",auxPointer);
        }
        okay = 1;
    }
    return okay;
}

/** \brief valida si el id ingresado se encuentra disponible
 *
 * \param list LinkedList* lista
 * \param id int ID a ser validado
 * \return devuelve 1 si el id esta disponible, 0 de lo contrario
 *
 */
int validateId(LinkedList* list, int id)
{
    int okay = 1,i;
    Employee* auxEmployee = (Employee*) employee_new();
    if (auxEmployee != NULL)
    {
        for (i=0; i<ll_len(list); i++)
        {
            auxEmployee = ll_get(list, i);
            if (auxEmployee->id == id)
            {
                okay = 0;
                break;
            }
        }
    }
    return okay;
}

/** \brief muestra el menu principal del programa
 *
 * \return devuelve la opcion ingresada por el usuario
 *
 */
int mainMenu()
{
    int respuesta = 0;

    system("cls");

    printf("Menu:\n");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf(" 3. Alta de empleado\n");
    printf(" 4. Modificar datos de empleado\n");
    printf(" 5. Baja de empleado\n");
    printf(" 6. Listar empleados\n");
    printf(" 7. Ordenar empleados\n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf(" 10. Salir\n\n");
    printf("Ingresar opcion: ");

    scanf("%d", &respuesta);
    fflush(stdin);
    return respuesta;
}
