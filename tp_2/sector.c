#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "sector.h"

static int findNextIdSector(eSector* sectores, int lenSector);

void initSector(eSector* sectores, int lenSector )
{
    int i;
    for(i=0; i<lenSector; i++)
    {
        sectores[i].isEmpty = SECTOR_EMPTY;
    }
}
int buscarPrimeraOcurrenciaSector(eSector* sectores, int lenSector, int valor)
{
    int i;
    int index = -1;
    for(i=0; i<lenSector; i++)
    {
        if(sectores[i].isEmpty == valor || sectores[i].isEmpty == SECTOR_DELETE)
        {
            index = i;
            break;
        }
    }
    return index;
}
int buscarPrimeraOcurrenciaSectorId(eSector* sectores, int lenSector, int auxId)
{
    int i;
    int index = -1;
    for(i=0; i<lenSector; i++)
    {
        if(sectores[i].id == auxId)
        {
            index = i;
            break;
        }
    }
    return index;
}
static int findNextIdSector(eSector* sectores, int lenSector)
{
    int i;
    int maxId = -1;
    int retorno = -1;

    if(sectores != NULL && lenSector > 0)
    {
        for(i=0; i<lenSector; i++)
        {
            if(sectores[i].isEmpty == SECTOR_USED || sectores[i].isEmpty == SECTOR_DELETE )
            {
                if(sectores[i].id > maxId || maxId == -1)
                {
                    maxId = sectores[i].id;
                }
            }
        }
        retorno = maxId + 1;
    }
    return retorno;
}
void setArraySector(eSector* sectores,char descripcion[],int auxId,int index,int estado)
{
    strcpy(sectores[index].descripcion,descripcion);
    sectores[index].id = auxId;
    sectores[index].isEmpty = estado;
}
void addSector(eSector* sectores, int lenSector)
{

    char seguir = 's';
    int auxId;
    char descripcionSrt[51];
    int indexLugarLibre;

    while(seguir == 's')
    {
        indexLugarLibre = buscarPrimeraOcurrenciaSector(sectores,lenSector,SECTOR_EMPTY);
        if(indexLugarLibre == -1)
        {
            printf("\n No espacio para cargar datos\n");
            break;
        }

        auxId = findNextIdSector(sectores,lenSector);
        if(getStringLetras("\n Ingrese descripcion: ",descripcionSrt)!= 1)
        {
            printf("\n Ingrese solo letras!!!");
            break;
        }

        setArraySector(sectores,descripcionSrt,auxId,indexLugarLibre,SECTOR_USED);
        printf("\n Alta exitosa!!!\n");
        seguir = getChar("\n Continuar cargando datos (s/n): ");
        printf("\n\n");

    }

}
void printSector(eSector* sectores, int lenSector, int index)
{

    printf("\n %03d  %s ", sectores[index].id,sectores[index].descripcion);
}
void removeSector(eSector* sectores, int lenSector)
{
    char seguir = 's';
    int indexResultadoBusqueda;
    int auxId;

    char idSrt[51];

    while(seguir == 's')
    {
        if(getStringNumeros("\n Ingrese ID sector a dar de baja: ", idSrt)!= 1)
        {
            printf("\n Ingrese solo numeros!!!");
            break;
        }
        auxId = atoi(idSrt);
        if(buscarPrimeraOcurrenciaSectorId(sectores,lenSector,auxId) == -1)
        {
            printf("\n El ID ingresado no existe!!!");
            break;
        }
        indexResultadoBusqueda = buscarPrimeraOcurrenciaSectorId(sectores,lenSector,auxId);
        printSector(sectores,lenSector,indexResultadoBusqueda);
        seguir = getChar("\n Confirmar baja (s/n): ");
        if(seguir == 's')
        {
            sectores[indexResultadoBusqueda].isEmpty = SECTOR_DELETE;
            printf("\n Baja exitosa!!!");
            seguir = 'n';
        }
        else
        {
            printf("\n Baja cancelada!!!");
            seguir = 'n';
        }
    }

}
void modifySector(eSector* sectores, int lenSector)
{
    int auxId;
    int indexResultadoBusqueda;
    char seguir = 's';

    char descripcionSrt[51];
    char idSrt[51];

    while(seguir == 's')
    {
        if(getStringNumeros("\n ID de sector a modificar: ",idSrt)!=1)
        {
            printf("\n Ingrese solo numeros: ");
            break;
        }
        auxId = atoi(idSrt);

        if(buscarPrimeraOcurrenciaSectorId(sectores,lenSector,auxId)== -1)
        {
            printf("\n El ID no existe!!!");
            break;
        }
        indexResultadoBusqueda = buscarPrimeraOcurrenciaSectorId(sectores,lenSector,auxId);
        printSector(sectores,lenSector,indexResultadoBusqueda);
        if(getStringLetras("\n Ingrese nueva descripcion: ",descripcionSrt)!= 1)
        {
            printf("\n Ingrese solo letras!!!!");
            break;
        }

        seguir = getChar("\n Confirmar modifiacion: ");
        if(seguir == 's')
        {
            strcpy(sectores[indexResultadoBusqueda].descripcion,descripcionSrt);
            printf("\n Modificacion exitosa!!!");
        }
        else
        {
            printf("\n Modificacion cancelada!!!");
        }

        seguir = getChar("\n Salir (s/n): ");
    }

}
void controllerSector(eSector* sectores, int lenSector)
{
    char seguir = 's';
    int opcion;

    do
    {
        printf("\n1. ALTA\n2. BAJAS \n3. MODIFICACION\n4. LISTAR \n5. SALIR\n");
        opcion = getInt("\nSeleccione una opcion: \n");
        switch(opcion)
        {
        case 1:
            system("cls");
            addSector(sectores,lenSector);
            system("pause");
            break;
        case 2:
            system("cls");
            removeSector(sectores,lenSector);
            system("pause");
            break;
        case 3:
            system("cls");
            modifySector(sectores,lenSector);
            system("pause");
            break;
        case 4:
            system("cls");
            listarSectores(sectores,lenSector);
            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            system("cls");
            printf("\n seleccione una opcion correcta\n");
            system("pause");
            break;
        }
    }
    while(seguir == 's');
}
void listarSectores(eSector* sectores, int lenSector)
{
    int i;

    for(i=0; i<lenSector; i++)
    {
        if(sectores[i].isEmpty == SECTOR_USED)
        {
            printSector(sectores,lenSector,i);
        }
    }
    printf("\n\n");
}
