#include <stdio.h>
#include <stdlib.h>

int addition(int firstInteger, int secondInteger)
{
	return firstInteger+secondInteger;
}

int subtraction(int firstInteger, int secondInteger)
{
	return firstInteger-secondInteger;
}

int multiplication(int firstInteger, int secondInteger)
{
	return firstInteger*secondInteger;
}

int division(int firstInteger, int secondInteger)
{
	if (secondInteger == 0)
	{
		printf("No se puede dividir por 0\n");
		return 0;
	}
    return firstInteger/secondInteger;
}

int factorial(int integer)
{
	int indice;
	int resultado = integer;
	for (indice = integer-1; indice > 0; indice--)
	{
		resultado=resultado*indice;
	}
	return resultado;
}
