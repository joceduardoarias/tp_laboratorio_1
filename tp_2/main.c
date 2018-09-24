#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "utn.h"
#define LEN_MAX 1000

int main()
{
    eEmployee empleado[LEN_MAX];
    char seguir = 's';
    int opcion;
    int indiceLugarLibre;
    int indexResultadoBusqueda;
    int i;
    //int contador = 0;

    int auxId;
    float auxSalario;
    int auxSector;

    char idSrt[51];
    char nombreSrt[51];
    char apellidoSrt[51];
    char salarioSrt[51];
    char sectorSrt[51];
    initEmployee(empleado,LEN_MAX);
    setArrayEmployee(empleado,0,"Jose","Arias",45.23,9,1,EMPLOYEE_USED);
    setArrayEmployee(empleado,1,"Juan","Munoz",56.23,2,2,EMPLOYEE_USED);
    setArrayEmployee(empleado,2,"Luis","Cadena",95.23,1,3,EMPLOYEE_USED);
    do
    {   system("cls");
        printf("\n1. ALTA \n2. BAJA \n3. MODIFICACION\n4. INFORMES\n5. SALIR");
        opcion = getInt("\n SELECCIONE UNA OPCION: ");

        switch(opcion)
        {
        case 1:
            addEmployee(empleado,LEN_MAX);
            break;
        case 2:
            system("cls");
            printf("\n BAJA");
            if(getStringNumeros("\nIngrese Id: ",idSrt) != 1)
            {
                printf("\n INGRESE SOLO NUMEROs!!!");
                break;
            }
            auxId = atoi(idSrt);
            if(buscarPrimeraOcurrenciaId(empleado,LEN_MAX,auxId) == -1)
            {
                printf("\n EL ID NO EXISTE!!!");
                break;
            }
            indexResultadoBusqueda = buscarPrimeraOcurrenciaId(empleado,LEN_MAX,auxId);
            printf("\n ID\tNAME\tLASTNAME\tSALARY\tSECTOR");
            printf("\n %d \t%s\t%s\t\t%.2f \t%03d",empleado[indexResultadoBusqueda].id,empleado[indexResultadoBusqueda].name,empleado[indexResultadoBusqueda].lastName,empleado[indexResultadoBusqueda].salary,empleado[indexResultadoBusqueda].sector);
            seguir = getChar("\n CONTINUAR S/N: ");
            if(seguir == 's')
            {
                empleado[indexResultadoBusqueda].isEmpty = EMPLOYEE_DELETE;
                printf("\n BAJA EXITOSA");
            }
            else
            {
                printf("\n BAJA CANCELADA");
                seguir = 's';
            }
            system("pause");
            break;
        case 3:
            system("cls");
            do
            {   system("cls");
                printf("\n *******MENU DE MODIFICACIONES********");
                printf("\n\n");
                printf("\n1. NOMBRE \n2. APELLIDO\n3. SALARIO\n4. SECTOR\n5. SALIR");
                opcion = getInt("\n Seleccione una opcion: ");
                switch(opcion)
                {
                case 1:
                    system("cls");
                    if(getStringNumeros("\nIIngrese ID empleado:",idSrt)!= 1)
                    {
                        printf("\n Ingrese solo numeros!!!\n");
                        break;
                    }
                    auxId = atoi(idSrt);
                    if(buscarPrimeraOcurrenciaId(empleado,LEN_MAX,auxId)== -1)
                    {
                        printf("\n El ID no existe!!!\n");
                        break;
                    }
                    indexResultadoBusqueda = buscarPrimeraOcurrenciaId(empleado,LEN_MAX,auxId);
                    printEmployee(empleado,LEN_MAX,indexResultadoBusqueda);
                    if(getStringLetras("\n Ingrese nuevo nombre: ",nombreSrt)!= 1)
                    {
                        printf("\n Ingrese solo letras!!!\n");
                        break;
                    }
                    seguir = getChar("\n CONFIRMAR (S/N): ");
                    if(seguir == 's')
                    {
                        strcpy(empleado[indexResultadoBusqueda].name,nombreSrt);
                        printf("\n Modificacion confirmada\n");
                    }
                    else
                    {
                        seguir = 'n';
                    }
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    if(getStringNumeros("\nIIngrese ID empleado:",idSrt)!= 1)
                    {
                        printf("\n Ingrese solo numeros!!!\n");
                        break;
                    }
                    auxId = atoi(idSrt);
                    if(buscarPrimeraOcurrenciaId(empleado,LEN_MAX,auxId)== -1)
                    {
                        printf("\n El ID no existe!!!\n");
                        break;
                    }
                    indexResultadoBusqueda = buscarPrimeraOcurrenciaId(empleado,LEN_MAX,auxId);
                    printEmployee(empleado,LEN_MAX,indexResultadoBusqueda);
                    if(getStringLetras("\n Ingrese nuevo Apellido: ",apellidoSrt)!= 1)
                    {
                        printf("\n Ingrese solo letras!!!\n");
                        break;
                    }
                    seguir = getChar("\n CONFIRMAR (S/N): ");
                    if(seguir == 's')
                    {
                        strcpy(empleado[indexResultadoBusqueda].lastName,apellidoSrt);
                        printf("\n Modificacion confirmada\n");
                    }
                    else
                    {
                        seguir = 'n';
                    }
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    if(getStringNumeros("\nIIngrese ID empleado:",idSrt)!= 1)
                    {
                        printf("\n Ingrese solo numeros!!!\n");
                        break;
                    }
                    auxId = atoi(idSrt);
                    if(buscarPrimeraOcurrenciaId(empleado,LEN_MAX,auxId)== -1)
                    {
                        printf("\n El ID no existe!!!\n");
                        break;
                    }
                    indexResultadoBusqueda = buscarPrimeraOcurrenciaId(empleado,LEN_MAX,auxId);
                    printEmployee(empleado,LEN_MAX,indexResultadoBusqueda);
                    if(getStringNumerosFlotantes("\n Ingrese nuevo salario: ",salarioSrt)!= 1)
                    {
                         printf("\n Ingrese solo numeros!!!\n");
                        break;
                    }
                    auxSalario = atof(salarioSrt);
                    getChar("\n CONFIRMAR (S/N): \n");
                    if(seguir == 's')
                    {
                        empleado[indexResultadoBusqueda].salary = auxSalario;
                        printf("\n Modificacion Exitosa!!!");
                    }
                    else
                    {
                        printf("\n MODIFICACION CANCELADA!!!");
                    }
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    if(getStringNumeros("\nIIngrese ID empleado:",idSrt)!= 1)
                    {
                        printf("\n Ingrese solo numeros!!!\n");
                        break;
                    }
                    auxId = atoi(idSrt);
                    if(buscarPrimeraOcurrenciaId(empleado,LEN_MAX,auxId)== -1)
                    {
                        printf("\n El ID no existe!!!\n");
                        break;
                    }
                    indexResultadoBusqueda = buscarPrimeraOcurrenciaId(empleado,LEN_MAX,auxId);
                    printEmployee(empleado,LEN_MAX,indexResultadoBusqueda);
                    if(getStringNumeros("\n Ingrese nuevo sector: ",sectorSrt)!= 1)
                    {
                         printf("\n Ingrese solo numeros!!!\n");
                        break;
                    }
                    auxSector = atoi(sectorSrt);
                    getChar("\n CONFIRMAR (S/N): \n");
                    if(seguir == 's')
                    {
                        empleado[indexResultadoBusqueda].sector = auxSector;
                        printf("\n Modificacion Exitosa!!!");
                    }
                    else
                    {
                        printf("\n MODIFICACION CANCELADA!!!");
                    }
                    system("pause");
                    break;
                case 5:
                    seguir = 'n';
                    break;
                }
            }
            while(seguir == 's');
            system("pause");
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
