#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
void inicializarLista(EPersona lista[], int tam)
{
    int i;
    for(i=0; i< tam; i++)
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
    int i;
    int indice = -1;
    for(i=0; i < tam; i++)
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


            lista[indice]= nuevaPersona;

            printf("\nAlta exitosa!!!\n\n");

        }
    }

}
void mostrarDatos(EPersona lista[], int tam)
{
    int i;
    system("cls");
    printf("      ---Lista de Personas---\n\n");
    printf("  Nombre   Edad   DNI \n\n");
    for(i=0; i< tam; i++)
    {
        if(lista[i].estado == 0)
        {
            mostrarDato(lista[i]);
        }
    }
}
void mostrarDato(EPersona lista)
{
    printf("\n %s \t %10d  \t%d\n",lista.nombre,lista.edad,lista.dni );
    printf("\n");
}
void bajaPersonas(EPersona lista[], int tam)
{
    int dni;
    int esta;
    char confirma;

    system("cls");
    printf("---Baja registro---\n\n");

    printf("Ingrese dni: ");
    scanf("%d", &dni);

    esta = buscarPorDni(lista, tam, dni);

    if(esta == -1)
    {
        printf("\nEl dni  %d no se encuentra en el sistema\n\n", dni);

    }
    else
    {

        mostrarDato(lista[esta]);

        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            lista[esta].estado = 1;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }

    }
}
void ordenarCaracteres(EPersona lista[], int tam )
{
    int j,i,aux;

    for(int j=1; j<tam; j++)
    {
        aux=strcmp(lista[j].nombre,lista[j+1].nombre);
        if(temp2>0)
            strcpy(lista[0].nombre,lista[j].nombre);
        strcpy(lista[j].nombre,lista[j+1].nombre);
        strcpy(lista[j+1].nombre,lista[0].nombre);
    }

    for( i=1; i<tam; i++)
    {
        mostrarDato(lista[i]);
    }

}
