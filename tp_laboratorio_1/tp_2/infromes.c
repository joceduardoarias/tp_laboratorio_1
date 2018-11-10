#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "utn.h"
#include "informes.h"
float salarioPromedio(eEmployee* arrayEmpleado,int len)
{
    float promedio = -1;
    float acumulador = 0;
    int contador = 0;
    int i;
    for(i=0; i<len; i++)
    {
        if(arrayEmpleado[i].isEmpty == EMPLOYEE_USED)
        {
            acumulador = acumulador + arrayEmpleado[i].salary;
            contador++;
        }
    }
    promedio = (float)acumulador/contador;
    return promedio;
}
float salarioTotal(eEmployee* arrayEmpleado,int len)
{
    float total = -1;
    float acumulador = 0;
    int i;
    for(i=0; i<len; i++)
    {
        if(arrayEmpleado[i].isEmpty == EMPLOYEE_USED)
        {
            acumulador = acumulador + arrayEmpleado[i].salary;
        }
    }
    total = acumulador;
    return total;
}
int cantidadEmpleadoSalarioPromedioArriba(eEmployee* arrayEmpleado,int len)
{
    int i;
    int empleados = -1;
    int contador = 0;
    float auxPromedio;

    auxPromedio = salarioPromedio(arrayEmpleado,len);

    for(i=0; i<len; i++)
    {
        if(arrayEmpleado[i].isEmpty == EMPLOYEE_USED && arrayEmpleado[i].salary > auxPromedio)
        {
            contador++;
        }
    }
    empleados = contador;
    return empleados;
}
void informes(eEmployee* arrayEmpleado,int len,eSector* sector,int lenSec)
{
    int i;
    int flag = 0;
    int opcion;
    char seguir = 's';
    system("cls");
    do
    {
        printf("\n1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n3 Salir");
        opcion = getInt("\n Seleccione una opcion: ");
        switch(opcion)
        {
        case 1:
            system("cls");
            sortEmployeeByLastName(arrayEmpleado,len,sector,lenSec);
            mostrarEmployees(arrayEmpleado,len,sector,lenSec);
            system("pause");
            break;
        case 2:
            system("cls");
            for(i=0; i<len; i++)
            {
                if(arrayEmpleado[i].isEmpty == EMPLOYEE_USED)
                {
                    flag = 1;
                }
            }
            if(flag == 0)
            {
                printf("\n No hay datos cargados!!!");
            }
            else
            {
                printf("\n SALARIO TOTAL: %.2f\n SALARIO PROMEDIO: %.2f\nCANTODAD DE EMPLEADOS CON SALARIOS POR ARRIBA DEL PROMEDIO: %d\n",salarioTotal(arrayEmpleado,len),salarioPromedio(arrayEmpleado,len),cantidadEmpleadoSalarioPromedioArriba(arrayEmpleado,len));
            }
            printf("\n\n");
            system("pause");
            break;
        case 3:
            seguir = 'n';
            break;
        }

    }
    while(seguir =='s');


}
void cargarDescripcion(eSector* sector, int lenSec, int idSector, char descripcionSrt[])
{
    int i;
    for(i=0; i<lenSec; i++)
    {
        if(sector[i].id == idSector)
        {
            strcpy(descripcionSrt,sector[i].descripcion);
            break;
        }
    }
}
void sortEmployeeByLastName(eEmployee* arrayEmpleado,int len, eSector* sector,int lenSec)
{
    int i,j;
    char descripcionSrt1[51];
    char descripcionSrt2[51];
    eEmployee auxEmpleado;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<lenSec; j++)
        {
            cargarDescripcion(sector,lenSec,arrayEmpleado[i].sector,descripcionSrt1);
            cargarDescripcion(sector,lenSec,arrayEmpleado[j].sector,descripcionSrt2);

            if(strcmpi(descripcionSrt1,descripcionSrt2)>0)
            {
                auxEmpleado = arrayEmpleado[i];
                arrayEmpleado[i] = arrayEmpleado[j];
                arrayEmpleado[j] = auxEmpleado;

            }
            else
            {
                if(strcmpi(descripcionSrt1,descripcionSrt2)==0 && strcmpi(arrayEmpleado[i].lastName,arrayEmpleado[j].lastName)>0)
                {
                    auxEmpleado = arrayEmpleado[i];
                    arrayEmpleado[i] = arrayEmpleado[j];
                    arrayEmpleado[j] = auxEmpleado;
                }
            }
        }

    }
}
