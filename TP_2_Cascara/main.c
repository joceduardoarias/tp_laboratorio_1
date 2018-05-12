#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 20


int main()
{
    int i;
    char seguir='s';
    int opcion=0;
    EPersona lista [TAM]; //{ {"Jose",26,0,95431123},{"Juan", 27,0,95434123},{"Maria",20,0,96431123},{"Julio",30,0,95431123},{"Daniela",18,0,96431123}} ;
    inicializarLista(lista,TAM);
    /*for(i=0; i< 5; i++)
    {
        lista[i].estado = 0;
    }*/
    for(i=0; i< TAM; i++)
    {
        lista[i].edad = 0;
    }
    while(seguir=='s')
    {   system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:

            altaPersonas(lista,TAM);
            system("pause");
            break;
        case 2:
            bajaPersonas(lista,TAM);
            system("pause");
            break;
        case 3:

            //mostrarDatos(lista,TAM);
             ordenarCaracteres(lista,TAM);
             system("pause");
            break;
        case 4:
             graficoEdad(lista,TAM);
             system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
