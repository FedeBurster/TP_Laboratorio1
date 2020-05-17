
struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}typedef eEmployee;


/** \brief To indicate that all positions in the array are empty,
 * this function puts the flag (isEmpty) in TRUE in all
 * positions of the array
 * \param list Employee* Pointer to array of employees
 * \param array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee* employee,int arrayLength);

/** \brief adds in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param Array length
 * \param Flag used as ID counter
 * \param Flag used to count amount of arrays in use
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployees(eEmployee* employee,int arrayLength,int* banderaId,int *banderaAlta);


/** \brief modifies contents inside array employee
 *
 * \param list employee*
 * \param array length
 * \param Flag used to count amount of arrays in use
 * \return int -1 if an error occurs, 0 if Ok
 *
 */
int modifyEmployee(eEmployee* employee,int arrayLength,int *banderaAlta);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param array length
 * \param Flag used to count amount of arrays in use
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(eEmployee* employee,int arrayLength,int *banderaAlta);


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(eEmployee* employee,int arrayLength);


/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param array lenght
 * \param Flag used to count amount of arrays in use
 * \return int -1 if an error occurs, 0 if Ok
 *
 */
int printEmployees(eEmployee* employee,int arrayLength,int *banderaAlta);

/** \brief find an Employee by Id and returns the index position in array.
 *
 * \param list Employee*
 * \param array length
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or -1
pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee* employee, int arrayLength,int id);
