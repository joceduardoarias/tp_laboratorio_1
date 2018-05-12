#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    printf("           ---Lista de Personas---\n\n");
    printf("       Nombre       Edad        DNI \n\n");
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
    printf("\n %12s \t %10d \t %4d\n",lista.nombre,lista.edad,lista.dni );

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

     EPersona personaAux;
    int i, j;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(stricmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                personaAux = lista[i];
                lista[i] = lista[j];
                lista[j] =  personaAux;
            }

        }
    }
    mostrarDatos(lista,tam);
}
void graficoEdad (EPersona lista[], int tam)
{
    int i, j, hasta18=0, de19a35=0, mayorDe35=0, bandera=0, mayor;

    for(j=0; j<tam; j++)
    {
        if(lista[j].edad<18 && lista[j].edad>0)
        {
            hasta18++;

        }
        else if(lista[j].edad>35)
        {
            mayorDe35++;
        }
        else if( lista[j].edad > hasta18)
        {
            de19a35++;
        }
    }

    if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
    {
        mayor = hasta18;
    }
    else
    {
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else
        {
            mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--)
    {
        printf("%02d|",i);

        if(i<= hasta18)
        {
            printf("*");
        }
        if(i<= de19a35)
        {
            bandera=1;
            printf("\t*");
        }
        if(i<= mayorDe35)
        {
            if(bandera==0)
                printf("\t\t*");
            if(bandera==1)
                printf("\t*");

        }
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35 \n\n");
    printf("\n   Hasta 18: %d\t de19a35: %d\tmayor de3 5%d\n", hasta18, de19a35, mayorDe35);
}
