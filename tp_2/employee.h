#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#define EMPLOYEE_EMPTY 0
#define EMPLOYEE_USED 1
#define EMPLOYEE_DELETE 2
#include "sector.h"
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
void initEmployee(eEmployee* arrayEmployee, int len );
/** \brief busca en la estructura por el valor recibido y devuelve el indice
 *
 * \param   eEmployee array a recorrer
 * \param   len longitud del array
 * \param   valor es el valor a buscar dentro del array
 * \return  devuelve -1 si no encuctra coincidencia o retornao el indice
 *
 */
int buscarPrimeraOcurrencia(eEmployee* arrayEmpleado, int len, int valor);
/** \brief busca en la estructura el valor que coincida con el Id recibido
 * \param   eEmployee array a recorrer
 * \param   len longitud del array
 * \param   valor es el valor a buscar dentro del array
 * \return  devuelve -1 si no encuctra coincidencia o retornao el indice
 *
 */
int buscarPrimeraOcurrenciaId(eEmployee* arrayEmpleado, int len, int valor);
/** \brief  carga los datos ingresados y validados por el ususario en el array
 * \param   arrayEmpleado es el array a manipular
 * \param   index es el indice de posicion dentro del array
 * \param   name nombre del empleado
 * \param   lastname es el apellido del empleado
 * \param   salary salario del empleado
 * \param   sector sector del empleado
 * \param   id identificacion del empleado
 * \param   isEmpty es el flag del estado del empleado dentro del sistema
 */
void setArrayEmployee(eEmployee*  arrayEmpleado,int index,char* name,char* lastName,float salary,int sector,int id,int isEpmty);
/** \brief carga un nuevo empleado en el array
 * \param   arrayEmpleado es el array a manipular
 * \param   len es la logitud ddel array
 */
void addEmployee(eEmployee* arrayEmpleado,int len, eSector* sector,int lenSec);
/** \brief Imprime por pantalla uno de los empleados cargados
 * \param   arrayEmpleado es el array a manipular
 * \param   len es la logitud ddel array
 */
void printEmployee(eEmployee* arrayEmpleado,int len, int index);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param Employee* arrayEmpleado
 * \param int len longitud del array
 */
void removeEmployee(eEmployee* arrayEmpleado,int len);
/** \brief modificar datos del empleado atraves del id
 * \param Employee* arrayEmpleado
 * \param int len longitud del array
 */
void modifyEmployee(eEmployee* arrayEmpleado,int len, eSector* sector,int lenSec);

/** \brief despliega un menu de opcciones para que el usuario selccione el sector
 * \param eSectores* es el array a analizar
  * \param lenSec longitud del array
 * \return devuelve un entero validado correspondiente al id sector o -1 si un error
 *
 */
int seleccionarSector(eSector* sectores,int lenSec);
/** \brief chequea que el array este cargado
 * \param eSectores* es el array a analizar
 * \param lenSec longitud del array
 * \return devuelve 1 si esta cargado o (-1) si esta vacio
 */
int checkArrayEmpty(eEmployee* arrayEmpleado,int len);


#endif // EMPLOYEE_H_INCLUDED
