#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "employee.h"
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
void informes(eEmployee* arrayEmpleado,int len);

#endif // INFORMES_H_INCLUDED
