#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "utn.h"
#include "informes.h"
#include "sector.h"
#define LEN_MAX 3
#define LEN_SEC 5

int main()
{
    eEmployee empleado[LEN_MAX];
    eSector sector[LEN_SEC];
    char seguir = 's';
    int opcion;

    initEmployee(empleado,LEN_MAX);
    initSector(sector,LEN_SEC);

    setArrayEmployee(empleado,0,"Jose","Arias",45.23,9,1,EMPLOYEE_USED);
    setArrayEmployee(empleado,1,"Juan","Munoz",56.23,2,2,EMPLOYEE_USED);
    setArrayEmployee(empleado,2,"Luis","Cadena",95.23,1,3,EMPLOYEE_USED);

    setArraySector(sector,"RRHH",1,0,SECTOR_USED);
    setArraySector(sector,"COMPRAS",2,1,SECTOR_USED);
    setArraySector(sector,"CONTABILIDAD",3,2,SECTOR_USED);
    setArraySector(sector,"SISTEMAS",4,3,SECTOR_USED);
    setArraySector(sector,"VENTAS",5,4,SECTOR_USED);

    do
    {
        printf("\n1. ABM EMPLOYEE \n2. ABM SECTOR \n3. INFORMES\n4. SALIR");
        opcion = getInt("\n Seleccione una opccion: ");
        switch(opcion)
        {
        case 1:
            controllerEmployee(empleado,LEN_MAX,sector,LEN_SEC);
            break;
        case 2:
            controllerSector(sector,LEN_SEC);
            break;
        case 4:
            seguir = 'n';
            break;
        default :

            system("cls");
            printf("\n Ingrese una opcion correcta!!!");
            system("pause");
            break;
        }
    }
    while(seguir == 's');

    return 0;
}
