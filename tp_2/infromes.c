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
void informes(eEmployee* arrayEmpleado,int len)
{
    int i;
    int flag = 0;
    system("cls");

    for(i=0;i<len;i++)
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
}
