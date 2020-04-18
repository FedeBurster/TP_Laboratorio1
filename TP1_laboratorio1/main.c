#include <stdio.h>
#include <stdlib.h>
#include "operacionesMatematicas.h"

int main()

{
    //Declaracion de variables
	int option, firstInteger=-9999, secondInteger=-9999, sum, difference, product, quotient, factoringA, factoringB;
	do
	{
		system("cls");
        //Menu y opciones
		printf("Menu\n");
		if (firstInteger<=-9999)
		{
			printf("\n1. Ingresar 1er operando ( A )");
		}
		else
		{
			printf("\n1. Ingresar 1er operando ( A = %d )", firstInteger);
		}
		if (secondInteger<=-9999)
		{
			printf("\n2. Ingresar 2do operando ( B )");
		}
		else
		{
			printf("\n2. Ingresar 2do operando ( B = %d )", secondInteger);
		}

		printf("\n3. Calcular todas las operaciones");
		printf("\n4. Informar resultados");
		printf("\n5. Salir");
		printf("\n\nSeleccione opcion: ");
		scanf("%d", &option);
		fflush(stdin);

        //Desarrolo de opciones
		switch(option)
		{

			case 1:
			printf("Ingrese el primer operando: ");
			scanf("%d", &firstInteger);
			break;

			case 2:
			printf("Ingrese el segundo operando: ");
			scanf("%d", &secondInteger);
			break;

			case 3:
			if (firstInteger == -9999 || secondInteger == -9999)
			{
				printf("\nPara continuar, primero complete la opcion 1 y la opcion 2.\n\nPresione ENTER para continuar.\n");
				fflush(stdin);
				while(getchar()!='\n');
			}
			else
			{
				sum = addition(firstInteger, secondInteger);
				difference = subtraction(firstInteger, secondInteger);
				product = multiplication(firstInteger, secondInteger);
				quotient = division(firstInteger, secondInteger);
				factoringA = factorial(firstInteger);
				factoringB = factorial(secondInteger);
				printf("Presione ENTER para continuar...");
				fflush(stdin);
				while(getchar()!='\n');
			}
			break;

			case 4:
			if (firstInteger == -9999 || secondInteger == -9999)
			{
				printf("\nPara continuar, primero complete la opcion 1 y la opcion 2.\n\nPresione ENTER para continuar.\n");
				fflush(stdin);
				while(getchar()!='\n');
			}
			else
			{
				printf("El resultado de %d + %d es: %d\n", firstInteger, secondInteger, sum);
				printf("El resultado de %d - %d es: %d\n", firstInteger, secondInteger, difference);
				printf("El resultado de %d * %d es: %d\n", firstInteger, secondInteger, product);
				printf("El resultado de %d / %d es: %d\n", firstInteger, secondInteger, quotient);
				printf("El factorial de A es: %d y El factorial de B es: %d\n", factoringA, factoringB);
				fflush(stdin);
				printf("Presione ENTER para continuar...");
				fflush(stdin);
				while(getchar()!='\n');
			}
			break;

			case 5:
			break;

			default:
			printf("Opcion no valida. Presione ENTER para continuar.");
			fflush(stdin);
			while(getchar()!='\n');
			break;
		}
	}while (option != 5);
	return 0;
}
