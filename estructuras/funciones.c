#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void mostrarEmpleado(eEmpleado emp)
{
    printf("\n nombre: %s", emp.nombre);
    printf("\n legajo: %d", emp.legajo);
    printf("\n sexo: %c", emp.sexo);
    printf("\n sueldo: %.2f", emp.sueldo);
    printf("ingrese fecha de ingreso d m a: " ,emp.fechaIngreso.dia,emp.fechaIngreso.mes,emp.fechaIngreso.anio);
}
eEmpleado cargarEstrutura()
{
    eEmpleado retorno;// declaro una variable tipo eEmpleado para guardar datos que voy a retornar

    printf("\n nombre: ");
    fflush(stdin);
    gets(retorno.nombre);
    printf("\n legajo: ");
    scanf("%d", &retorno.legajo);
    printf("\n sexo: ");
    fflush(stdin);
    scanf("%c", &retorno.sexo);
    printf("\n sueldo: ");
    scanf("%f", &retorno.sueldo);
    printf("ingrese fecha de ingreso d m a: ");
    scanf("%d %d %d ", &retorno.fechaIngreso.dia,&retorno.fechaIngreso.mes,&retorno.fechaIngreso.anio);

    return retorno;
}

