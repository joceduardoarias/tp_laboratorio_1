#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "utn.h"
#define LEN_MAX 1000
#define LEN_SEC 5

int main()
{
    eEmployee empleado[LEN_MAX];
    eSector sector[LEN_SEC];
    char seguir = 's';
    int opcion;
    int i;
    initEmployee(empleado,LEN_MAX);
    setArrayEmployee(empleado,0,"Jose","Arias",45.23,9,1,EMPLOYEE_USED);
    setArrayEmployee(empleado,1,"Juan","Munoz",56.23,2,2,EMPLOYEE_USED);
    setArrayEmployee(empleado,2,"Luis","Cadena",95.23,1,3,EMPLOYEE_USED);

    setArraySector(sector,"RRHH",1,0);
    setArraySector(sector,"COMPRAS",2,1),
    setArraySector(sector,"CONTABILIDAD",3,2);
    setArraySector(sector,"SISTEMAS",4,3);
    setArraySector(sector,"VENTAS",5,4);

    do
    {
        system("cls");
        printf("\n1. ALTA \n2. BAJA \n3. MODIFICACION\n4. INFORMES\n5. SALIR");
        opcion = getInt("\n SELECCIONE UNA OPCION: ");

        switch(opcion)
        {
        case 1:
            addEmployee(empleado,LEN_MAX,sector,LEN_SEC);
            break;
        case 2:
            removeEmployee(empleado,LEN_MAX);
            break;
        case 3:
            modifyEmployee(empleado,LEN_MAX,sector,LEN_SEC);
            break;
        case 4:
            system("cls");
            printf("\n INFORMES");
            printf("\n ID\tNAME\tLASTNAME\tSALARY\tSECTOR");
            for(i=0; i<LEN_MAX; i++)
            {
                if(empleado[i].isEmpty == EMPLOYEE_USED )
                {
                    printf("\n %d \t%s\t%s\t\t%.2f \t%03d",empleado[i].id,empleado[i].name,empleado[i].lastName,empleado[i].salary,empleado[i].sector);
                }
            }
            printf("\n\n");
            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');
    return 0;
}
