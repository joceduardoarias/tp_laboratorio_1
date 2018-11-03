#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* lista;
    Employee* nuevoEmpleado;
    int cantidadLeida;
    int index;
    int flag= 0;
    char idSrt[50],nombreSrt[50],horasSrt[50],sueldoSrt[50];

    lista= fopen(path,"r");
    if(lista==NULL)
    {
        printf("\n no se abrio correctamente el archivo");

    }

    fscanf(lista,"%[^,],%[^,],%[^,],%[^\n]\n",idSrt,nombreSrt,horasSrt,sueldoSrt);
    while(!feof(lista))
    {

        cantidadLeida = fscanf(lista,"%[^,],%[^,],%[^,],%[^\n]\n",idSrt,nombreSrt,horasSrt,sueldoSrt);
        if(cantidadLeida == 4)
        {
            nuevoEmpleado = employee_newParametros(idSrt,nombreSrt,horasSrt,sueldoSrt);
            ll_add(pArrayListEmployee,nuevoEmpleado);
            printf("\n %d %s %d %.2f\n",nuevoEmpleado->id,nuevoEmpleado->nombre,nuevoEmpleado->horasTrabajadas,nuevoEmpleado->sueldo);
        }
        else if(cantidadLeida != 4)
        {
            if(!feof(lista))
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
    fclose(lista);
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

void menu()
{
    printf("\n**************************************************** \n");
    printf("\nMenu: \n");
    printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n");
    printf("\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). \n");
    printf("\n3. Alta de empleado \n");
    printf("\n4. Modificar datos de empleado \n");
    printf("\n5. Baja de empleado \n");
    printf("\n6. Listar empleados \n");
    printf("\n7. Ordenar empleados \n");
    printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto). \n");
    printf("\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario). \n");
    printf("\n10. Salir \n");
    printf("\n**************************************************** \n");
}
