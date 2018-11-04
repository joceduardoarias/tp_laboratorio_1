#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#define ESC 27
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char option = 's';
    LinkedList* listaEmpleados = ll_newLinkedList();
    menu();
    do{
        //printf("\n Ingrese option:");
        //scanf("%d",&option);
        switch(option)
        {
            case '1':
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case '3':
               controller_addEmployee(listaEmpleados);
                break;
        }
    }while((option = getch())!= ESC);
    return 0;
}
