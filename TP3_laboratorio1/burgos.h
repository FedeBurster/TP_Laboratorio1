#include "LinkedList.h"
#ifndef VALIDA_H_INCLUDED
#define VALIDA_H_INCLUDED



#endif // VALIDA_H_INCLUDED

int validateString(char* message, char* messageError, int maxLengthString, char* auxString);
int validateFloat(char* message, char* messageError, int negative, float* auxPointer);
int validateInt(char* message, char* messageError, int negative, int* auxPointer);
int validateId(LinkedList* lista, int id);

void capsLock(char* charString);

int mainMenu();
