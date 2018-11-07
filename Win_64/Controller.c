#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    system("cls");
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
    system("cls");
    char seguir = 's';
    char idSrt[128];
    char nombreSrt[128];
    char horasTrabajadasSrt[128];
    char sueldoSrt[128];
    Employee* this;
    int i;
    while(seguir == 's')
    {
        if(getStringNumeros("\n Ingrese Id: ",idSrt)!= 1)
        {
            printf("\n ingrese solo numeros");
            break;
        }

        if(getStringLetras("\n ingrese nombre: ",nombreSrt)!=1)
        {
            printf("\n ingrese solo letras");
            break;
        }
        if(getStringNumeros("\n cantidad horas trabajadas: ",horasTrabajadasSrt)!=1)
        {
            printf("\n ingrese solo numeros");
            break;
        }

        if(getStringNumerosFlotantes("\n Ingrese sueldo: ",sueldoSrt)!=1)
        {
            printf("\n ingrese solo numeros");
            break;
        }

        this =employee_newParametros(idSrt,nombreSrt,horasTrabajadasSrt,sueldoSrt);
        ll_add(pArrayListEmployee,this);
        seguir = getChar("\n continuar cargando datos (s/n)\n");
    }

    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        this = ll_get(pArrayListEmployee,i);

        printf("\n %d %s %d %.2f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
    }

    system("pause");
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
    system("cls");
    char seguir = 's';
    char idSrt[128];
    char nombreSrt[128];
    char horasTrabajadasSrt[128];
    char sueldoSrt[128];
    Employee* this;
    int auxId,auxHorasTrabajadas;
    float auxSueldo;
    int i,opcion;
    int flag = 0;
    while(seguir == 's')
    {
        if(getStringNumeros("\n Ingrese Id: ",idSrt)!= 1)
        {
            printf("\n ingrese solo numeros");
            break;
        }

        auxId = atoi(idSrt);
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this =(Employee*) ll_get(pArrayListEmployee,i);
            if(this->id == auxId)
            {

                flag = 1;
                break;
            }

        }

        if(flag == 1)
        {
            do
            {
                system("cls");
                printf("\n MODIFICACIONES \n1. NOMBRE\n2. HORAS TRABAJADAS\n3. SUELDOS\n4. SALIR\n");
                printf("\n %d %s %d %.2f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
                opcion = getInt("\n Seleccione un opcion: ");

                switch(opcion)
                {
                case 1:

                    if(getStringLetras("\n Ingrese nuevo nombre: ",nombreSrt)!=1)
                    {
                        printf("\n Ingrese solo letras!!!! \n");
                    }
                    seguir = getChar("\n confirmar modificacion (s/n): ");
                    if(seguir == 's')
                    {
                        employee_setNombre(this,nombreSrt);

                    }
                    else
                    {
                        printf("\n modificacion cancelada!!!\n");
                    }
                    system("pause");
                    break;
                case 2:

                    if(getStringNumeros("\n Ingrese nueva cantidad de horar trabajdas: ",horasTrabajadasSrt)!=1)
                    {
                        printf("\n Ingrese solo numeros!!!! \n");
                    }
                    auxHorasTrabajadas = atoi(horasTrabajadasSrt);
                    seguir = getChar("\n confirmar modificacion (s/n): ");
                    if(seguir == 's')
                    {
                        employee_setHorasTrabajadas(this,auxHorasTrabajadas);

                    }
                    else
                    {
                        printf("\n modificacion cancelada!!!\n");
                    }
                    system("pause");
                    break;
                case 3:

                    if(getStringNumerosFlotantes("\n Ingrese nuevo sueldo: ",sueldoSrt)!=1)
                    {
                        printf("\n Ingrese solo letras!!!! \n");
                    }
                    auxSueldo = atof(sueldoSrt);
                    seguir = getChar("\n confirmar modificacion (s/n): ");
                    if(seguir == 's')
                    {
                        employee_setSueldo(this,auxSueldo);

                    }
                    else
                    {
                        printf("\n modificacion cancelada!!!\n");
                    }
                    system("pause");
                    break;
                case 4:
                    seguir = 'n';
                    break;
                }

            }
            while(seguir =='s');
        }
        else
        {
            printf("\n El id ingresado no extiste!!!!");
        }
        seguir = getChar("\n continuar cargando datos (s/n)\n");
    }
    system("pause");
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
    system("cls");
    printf("\n BAJAS\n");
    int auxId,i,flag=0;
    char idSrt[128];
    Employee* this;
    if(getStringNumeros("\n Ingrese id para realizar baja:  ",idSrt)!=1)
    {
        printf("\n Ingrese solo numeros!!!\n");
    }
    auxId = atoi(idSrt);
    printf("\n %d",auxId);
    printf("\n antes\n");
    system("pause");
    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        this = (Employee*)ll_get(pArrayListEmployee,i);
        if(this->id == auxId)
        {
            flag = 1;
            break;
        }
    }
    printf("\n despues\n");

    system("pause");
    if(flag == 1)
    {
        ll_remove(pArrayListEmployee,i);
        printf("\n Empleado elimanado correctamente!!!");
    }
    else
    {
        printf("\n el id de empleado ingresadono  no existe!!!!");
    }
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
    system("cls");
    Employee* this;
    int i;

    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        this = ll_get(pArrayListEmployee,i);
        printf("\n %d %s %d %.2f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
    }
    system("pause");
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

    ll_sort(pArrayListEmployee,employeeByName,1);
    Employee* this;
        int i;

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this = ll_get(pArrayListEmployee,i);
            printf("\n %d %s %d %.2f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
        }

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
    system("cls");
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
