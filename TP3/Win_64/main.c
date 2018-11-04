#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    do{
        system("cls");
            menu();
        //printf("\n Ingrese option:");
        //scanf("%d",&option);
        switch(option)
        {
            case '1':
                system("cls");
                controller_loadFromText("data.csv",listaEmpleados);
                system("pause");
                break;
            case '3':
               controller_addEmployee(listaEmpleados);
                break;
            case '4':
                controller_editEmployee(listaEmpleados);
                break;
            case '5':
                controller_removeEmployee(listaEmpleados);
                break;
            case '6':
                system("cls");
                controller_ListEmployee(listaEmpleados);
                system("pause");
                break;
        }
    }while((option = getch())!= ESC);
    return 0;
}
