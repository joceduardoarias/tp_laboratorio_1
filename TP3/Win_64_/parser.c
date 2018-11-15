#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    //FILE* pArchivo;
    Employee* nuevoEmpleado;
    int cantidadLeida;
    char idSrt[50],nombreSrt[50],horasSrt[50],sueldoSrt[50];

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idSrt,nombreSrt,horasSrt,sueldoSrt);
    while(!feof(pFile))
    {

        cantidadLeida = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idSrt,nombreSrt,horasSrt,sueldoSrt);
        if(cantidadLeida == 4)
        {
            nuevoEmpleado = employee_newParametros(idSrt,nombreSrt,horasSrt,sueldoSrt);
            ll_add(pArrayListEmployee,nuevoEmpleado);
            printf("\n %d %s %d %.2f\n",nuevoEmpleado->id,nuevoEmpleado->nombre,nuevoEmpleado->horasTrabajadas,nuevoEmpleado->sueldo);
        }
        else if(cantidadLeida != 4)
        {
            if(!feof(pFile))
            {
                printf("\n error!!!");
                system("pause");
                break;
            }
            else
            {
                printf("\n leyo todo el archivo!!");
            }
        }
    }

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee auxEmpleado;
    Employee* nuevoEmpleado;
    int cantidaLeida;
    char idSrt[50],nombreSrt[50],horasTrabajadasSrt[50],sueldoSrt[50];
    while(!feof(pFile))
    {
        cantidaLeida = fread(&auxEmpleado,sizeof(Employee),1,pFile);
        sprintf(idSrt,"%d",auxEmpleado.id);
        strcpy(nombreSrt,auxEmpleado.nombre);
        sprintf(horasTrabajadasSrt,"%d",auxEmpleado.horasTrabajadas);
        sprintf(sueldoSrt,"%f",auxEmpleado.sueldo);
        nuevoEmpleado = employee_newParametros(idSrt,nombreSrt,horasTrabajadasSrt,sueldoSrt);
        if(cantidaLeida == 1 && nuevoEmpleado != NULL)
        {
//            nuevoEmpleado->id = auxEmpleado.id;
//            strcpy(nuevoEmpleado->nombre,auxEmpleado.nombre);
//            nuevoEmpleado->horasTrabajadas = auxEmpleado.horasTrabajadas;
//            nuevoEmpleado->sueldo = auxEmpleado.sueldo;
            ll_add(pArrayListEmployee,nuevoEmpleado);
            printf("\n %d %s %d %.2f\n",nuevoEmpleado->id,nuevoEmpleado->nombre,nuevoEmpleado->horasTrabajadas,nuevoEmpleado->sueldo);
        }
        else if(cantidaLeida != 1)
        {
            if(!feof(pFile))
            {
                printf("\n Error \n");
                break;
            }
            else
            {
                printf("\n Archivo cargado correctamente\n");
            }
        }
    }
    return 1;
}
