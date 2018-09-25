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
void addEmployee(eEmployee* arrayEmpleado,int len, eSector* sector,int lenSec)
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
    //char sectorSrt[51];
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
        /*if(getStringNumeros("\n Ingrese sector: ",sectorSrt) != 1)
        {
            printf("\n INGRESE SOLO NUMEROs!!!");
            break;
        }*/
        auxSector = seleccionarSector(sector,lenSec);
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
void removeEmployee(eEmployee* arrayEmpleado,int len)
{
    char seguir = 's';

    int indexResultadoBusqueda;

    int auxId;

    char idSrt[51];

    system("cls");
    printf("\n BAJA");
    while(seguir == 's')
    {
        if(getStringNumeros("\nIngrese Id: ",idSrt) != 1)
        {
            printf("\n INGRESE SOLO NUMEROs!!!");
            break;
        }
        auxId = atoi(idSrt);
        if(buscarPrimeraOcurrenciaId(arrayEmpleado,len,auxId) == -1)
        {
            printf("\n EL ID NO EXISTE!!!");
            break;
        }
        indexResultadoBusqueda = buscarPrimeraOcurrenciaId(arrayEmpleado,len,auxId);
        printf("\n ID\tNAME\tLASTNAME\tSALARY\tSECTOR");
        printf("\n %d \t%s\t%s\t\t%.2f \t%03d",arrayEmpleado[indexResultadoBusqueda].id,arrayEmpleado[indexResultadoBusqueda].name,arrayEmpleado[indexResultadoBusqueda].lastName,arrayEmpleado[indexResultadoBusqueda].salary,arrayEmpleado[indexResultadoBusqueda].sector);
        seguir = getChar("\n CONTINUAR S/N: ");
        if(seguir == 's')
        {
            arrayEmpleado[indexResultadoBusqueda].isEmpty = EMPLOYEE_DELETE;
            printf("\n BAJA EXITOSA");
            seguir = getChar("\n SALIR S/N: ");
        }
        else
        {
            printf("\n BAJA CANCELADA");
            seguir = 'n';
        }
    }
    printf("\n\n");
    system("pause");
}
void modifyEmployee(eEmployee* arrayEmpleado,int len, eSector* sector,int lenSec)
{
    char seguir = 's';
    int opcion;
    int indexResultadoBusqueda;


    int auxId;
    float auxSalario;
    int auxSector;

    char idSrt[51];
    char nombreSrt[51];
    char apellidoSrt[51];
    char salarioSrt[51];
    char sectorSrt[51];

    do
    {
        system("cls");
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
            if(buscarPrimeraOcurrenciaId(arrayEmpleado,len,auxId)== -1)
            {
                printf("\n El ID no existe!!!\n");
                break;
            }
            indexResultadoBusqueda = buscarPrimeraOcurrenciaId(arrayEmpleado,len,auxId);
            printEmployee(arrayEmpleado,len,indexResultadoBusqueda);
            if(getStringLetras("\n Ingrese nuevo nombre: ",nombreSrt)!= 1)
            {
                printf("\n Ingrese solo letras!!!\n");
                break;
            }
            seguir = getChar("\n CONFIRMAR (S/N): ");
            if(seguir == 's')
            {
                strcpy(arrayEmpleado[indexResultadoBusqueda].name,nombreSrt);
                printf("\n Modificacion confirmada\n");
            }
            else
            {
                seguir = 'n';
            }
            printf("\n\n");
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
            if(buscarPrimeraOcurrenciaId(arrayEmpleado,len,auxId)== -1)
            {
                printf("\n El ID no existe!!!\n");
                break;
            }
            indexResultadoBusqueda = buscarPrimeraOcurrenciaId(arrayEmpleado,len,auxId);
            printEmployee(arrayEmpleado,len,indexResultadoBusqueda);
            if(getStringLetras("\n Ingrese nuevo Apellido: ",apellidoSrt)!= 1)
            {
                printf("\n Ingrese solo letras!!!\n");
                break;
            }
            seguir = getChar("\n CONFIRMAR (S/N): ");
            if(seguir == 's')
            {
                strcpy(arrayEmpleado[indexResultadoBusqueda].lastName,apellidoSrt);
                printf("\n Modificacion confirmada\n");
            }
            else
            {
                seguir = 'n';
            }
            printf("\n\n");
            system("pause");
            break;
        case 4:
            if(getStringNumeros("\n Ingrese ID empleado:",idSrt)!=1)
            {
                printf("\n Ingrese solo numeros");
                break;
            }
            auxId = atoi(idSrt);
            if(buscarPrimeraOcurrenciaId(arrayEmpleado,len,auxId)== -1)
            {
                printf("\n El ID %d no existe!!!",auxId);
                break;
            }
            indexResultadoBusqueda = buscarPrimeraOcurrenciaId(arrayEmpleado,len,auxId);
            auxSector = seleccionarSector(sector,lenSec);
            seguir = getChar("\n CONTINUAR (S/N): ");
            if(seguir == 's')
            {
                arrayEmpleado[indexResultadoBusqueda].sector = auxSector;
                printf("\n Modificacion exitosa!!!\n");
            }
            else
            {
            printf("\n Modificacion cancelada!!!");
            }
            system("pause");
            break;
        case 3:
            if(getStringNumeros("\n Ingrese ID empleado:",idSrt)!=1)
            {
                printf("\n Ingrese solo numeros");
                break;
            }
            auxId = atoi(idSrt);
            if(buscarPrimeraOcurrenciaId(arrayEmpleado,len,auxId)== -1)
            {
                printf("\n El ID %d no existe!!!",auxId);
                break;
            }
            indexResultadoBusqueda = buscarPrimeraOcurrenciaId(arrayEmpleado,len,auxId);
            printEmployee(arrayEmpleado,len,buscarPrimeraOcurrenciaId(arrayEmpleado,len,auxId));
            if(getStringNumerosFlotantes("\n Ingrese nuevo salario: ",salarioSrt)!= 1)
            {
                printf("\n Ingrese solo numeros");
                break;
            }
            auxSalario = atof(salarioSrt);
            seguir = getChar("\n CONTINUAR (N/S): ");
            if(seguir == 's')
            {
                arrayEmpleado[indexResultadoBusqueda].salary = auxSalario;
                printf("\n Modificacion de salario exitosa!!!");
                break;
            }
            else
            {
                printf("\n Modificacion cancelada!!!");
                break;
            }
            printf("\n\n");
            system("pause");
        case 5:
            seguir = 'n';
            break;
        }
    }
    while(seguir=='s');
}
void setArraySector(eSector* sectores,char descripcion[],int idSector,int index)
{
    strcpy(sectores[index].descripcion,descripcion);
    sectores[index].idSector = idSector;
}
int seleccionarSector(eSector* sectores,int lenSec)
{
     int idSector= -1;
     char sectorStr[51];
     int i;
     system("cls");
    printf("\n ID \t\t DESCRIPCION \n");
     for(i=0;i<lenSec;i++)
     {
        printf("\n %03d \t\t %s",sectores[i].idSector,sectores[i].descripcion);
     }
     if(getStringNumeros("\n SELECCIONE UNA OPCION: ",sectorStr)!= 1)
     {
         printf("\n Ingrese solo numeros");
     }
     else
     {
         idSector = atoi(sectorStr);
     }
    return idSector;
    system("pause");
}
