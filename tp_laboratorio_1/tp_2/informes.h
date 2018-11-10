#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "employee.h"
#include "sector.h"
/** \brief calcula el salario promedio de los empleados
 *
 * \param Employee* arrayEmpleado
 * \param int len longitud del array
 * \return devuelve -1 si el array esta vacio o retorna el promedio
 */
 float salarioPromedio(eEmployee* arrayEmpleado,int len);
/** \brief calcula el total de los salrios
 * \param Employee* arrayEmpleado
 * \param int len longitud del array
 * \return devuelve -1 si el array esta vacio o retorna salario total
 */
float salarioTotal(eEmployee* arrayEmpleado,int len);
/** \brief calcula la cantidad de empleado cuyo promedio de salario
 *         esta por arriba del promedio.
 * \param Employee* arrayEmpleado
 * \param int len longitud del array
 * \return devuelve -1 si el array esta vacio o retorna un entero positivo
 */
int cantidadEmpleadoSalarioPromedioArriba(eEmployee* arrayEmpleado,int len);
/** \brief Informa Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
 * \param Employee* arrayEmpleado
 * \param int len longitud del array
 */
void informes(eEmployee* arrayEmpleado,int len,eSector* sector,int lenSec);
/** \brief  Listado de los empleados ordenados alfabéticamente por Apellido y Sector
 *
 * \param eEmployee* arrayEmpleado  array de empleados
 * \param len longitud del array empleados
 * \param eSector* sector array de sectores
 * \param lenSec longitud del array sector
* \return
 *
 */
void sortEmployeeByLastName(eEmployee* arrayEmpleado,int len, eSector* sector,int lenSec);
/** \brief carga la descripcion en una variable tipo cadena de caracteres luego de verificar que la
 *          esta este relacionada con el id recibido  como parametro
 * \param lenSec longitud del array sector
 * \param eSector* sector array de sectores
 * \param idSector es el id a relacionar
 * \param descripcionSrt es  array donde se va cargar la cadena encontrada
 */
 void cargarDescripcion(eSector* sector, int lenSec, int idSector, char descripcionSrt[]);

#endif // INFORMES_H_INCLUDED
