#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
//
int employee_register(LinkedList* lista);
void employee_delete(Employee* this);
int employee_modify(LinkedList* lista);
int removeEmployee(LinkedList* lista);

void listEmployees(LinkedList* lista);
void listEmployee(LinkedList* lista, int index);

int modifyEmployee(LinkedList* lista, int index);
int menuModifyEmployee();
int modifyID(LinkedList* lista,int  index);
int modifyName(LinkedList* lista,int  index);
int modifySalary(LinkedList* lista,int  index);
int modifyHours(LinkedList* lista,int  index);

int switchSortEmployees(LinkedList* lista);
int sortByID(void* e1, void* e2);
int sortByHours(void* e1, void* e2);
int sortByName(void* e1, void* e2);
int sortBySalary(void* e1, void* e2);

int employee_getId(Employee* this,int* id);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_getHorasTrabajadas(Employee* this,int* horas);
int employee_getNombre(Employee* this,char* nombre);

int menuSortEmployees();

#endif // employee_H_INCLUDED
