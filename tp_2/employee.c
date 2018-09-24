#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "utn.h"
static int id_findNexId(eEmployee* arrayEmpleado,int len);
void initEmployee(eEmployee* arrayEmployee, int len )
{
    int i;
    for(i=0; i<len; i++)
    {
        arrayEmployee[i].isEmpty = EMPLOYEE_EMPTY;
    }
}
int buscarPrimeraOcurrencia(eEmployee* arrayEmpleado, int len, int valor)
{
    int i;
    int retorno = -1;
    for(i=0; i<len; i++)
    {
        if(arrayEmpleado[i].isEmpty == valor)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int buscarPrimeraOcurrenciaId(eEmployee* arrayEmpleado, int len, int valor)
{
    int i;
    int retorno = -1;
    for(i=0; i<len; i++)
    {
        if(arrayEmpleado[i].id == valor)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
void setArrayEmployee(eEmployee*  arrayEmpleado,int index,char* name,char* lastName,float salary,int sector,int id,int isEpmty)
{
    arrayEmpleado[index].id = id;
    strcpy(arrayEmpleado[index].name,name);
    strcpy(arrayEmpleado[index].lastName,lastName);
    arrayEmpleado[index].salary = salary;
    arrayEmpleado[index].sector = sector;
    arrayEmpleado[index].isEmpty = isEpmty;
}
static int id_findNexId(eEmployee* arrayEmpleado,int len)
{
    int i;
    int maxId = -1;
    int retorno = -1;
    if(arrayEmpleado != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            if(arrayEmpleado[i].isEmpty == EMPLOYEE_USED || arrayEmpleado[i].isEmpty == EMPLOYEE_DELETE)
            {
                if(arrayEmpleado[i].id > maxId || maxId == -1)
                {
                    maxId = arrayEmpleado[i].id;
                }
            }
        }
        retorno = maxId+1;
    }
    return retorno;
}
void addEmployee(eEmployee* arrayEmpleado,int len)
{
    char seguir = 's';
    int indiceLugarLibre;
    //int contador = 0;

    int auxId;
    float auxSalario;
    int auxSector;

    //char idSrt[51];
    char nombreSrt[51];
    char apellidoSrt[51];
    char salarioSrt[51];
    char sectorSrt[51];
    system("cls");

    while(seguir == 's')
    {
        system("cls");
        printf("\n ALTA");
        indiceLugarLibre = buscarPrimeraOcurrencia(arrayEmpleado,len,EMPLOYEE_EMPTY);
        if(indiceLugarLibre == -1)
        {
            printf("\n NO HAY ESPACIO PARA CARGAR DATOS!!!");
            break;
        }
        auxId = id_findNexId(arrayEmpleado,len);
        /*
        if(getStringNumeros("\n Ingrese Id: ",idSrt) != 1)
        {
            printf("\n INGRESE SOLO NUMEROs!!!");
            break;
        }
        auxId = atoi(idSrt);
        if(buscarPrimeraOcurrenciaId(arrayEmpleado,len,auxId)!= -1)
        {
            printf("\n EL ID YA EXISTE!!!");
            break;
        }
        */
        if(getStringLetras("\n Ingrese nombre: ",nombreSrt) != 1)
        {
            printf("\n INGRESE SOLO LETRAS!!!");
            break;
        }
        if(getStringLetras("\n Ingrese apellido: ",apellidoSrt) != 1)
        {
            printf("\n INGRESE SOLO LETRAS!!!");
            break;
        }

        if(getStringNumerosFlotantes("\n Ingrese el salario: ",salarioSrt) != 1)
        {
            printf("\n INGRESE SOLO NUMEROS!!!");
            break;
        }
        auxSalario = atof(salarioSrt);
        if(getStringNumeros("\n Ingrese sector: ",sectorSrt) != 1)
        {
            printf("\n INGRESE SOLO NUMEROs!!!");
            break;
        }
        auxSector = atoi(sectorSrt);
        setArrayEmployee(arrayEmpleado,indiceLugarLibre,nombreSrt,apellidoSrt,auxSalario,auxSector,auxId,EMPLOYEE_USED);
        seguir = getChar("\n CONTINUAR (S/N): ");
    }
    printf("\n\n");
    system("pause");
}
void printEmployee(eEmployee* arrayEmpleado,int len, int index)
{
    printf("\n ID\tNAME\tLASTNAME\tSALARY\tSECTOR");
    printf("\n %d \t%s\t%s\t\t%.2f \t%03d",arrayEmpleado[index].id,arrayEmpleado[index].name,arrayEmpleado[index].lastName,arrayEmpleado[index].salary,arrayEmpleado[index].sector);

}
