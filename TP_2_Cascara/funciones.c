#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
void inicializarLista(EPersona lista[], int tam)
{
    for(int i=0; i< tam; i++)
    {
        lista[i].estado =1;
    }
}
int obtenerEspacioLibre(EPersona lista[], int tam)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {
        if(lista[i].estado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int buscarPorDni(EPersona lista[],int tam, int dni)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(lista[i].estado == 0 && lista[i].dni == dni)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void altaPersonas(EPersona lista[], int tam)
{
    EPersona nuevaPersona;
    int indice;
    int esta;
    int dni;

    system("cls");
    printf("---Alta empleado---\n\n");
    indice = obtenerEspacioLibre(lista,tam);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede ingresar una nueva persona.\n\n");
    }
    else
    {
        printf("Ingrese dni: ");
        scanf("%d", &dni);

        esta = buscarPorDni(lista,tam,dni);
        if(esta != -1)
        {
            printf("\nEl dni %d ya esta dado de alta en el sistema\n", dni);

        }
        else
        {
            nuevaPersona.estado = 0;
            nuevaPersona.dni = dni;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevaPersona.nombre);

            printf("Ingrese edad: ");
            fflush(stdin);
            scanf("%d", &nuevaPersona.edad);

            printf("Ingrese dni: ");
            scanf("%d", &nuevaPersona.dni);

            lista[indice]= nuevaPersona;

            printf("\nAlta exitosa!!!\n\n");

        }
    }

}
