
struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}typedef eEmployee;

int initEmployees(eEmployee* employee,int arrayLength);

int addEmployees(eEmployee* employee,int arrayLength,int* banderaId,int *banderaAlta);

int modifyEmployee(eEmployee* employee,int arrayLength);

int removeEmployee(eEmployee* employee,int arrayLength);

int sortEmployees(eEmployee* employee,int arrayLength);


