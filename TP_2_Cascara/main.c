#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 20


int main()
{
    char seguir='s';
    int opcion=0;
    EPersona lista [TAM] = { {"Jose",26,0,95431123},{"Juan", 27,0,95434123},{"Maria",20,0,96431123},{"Julio",30,0,95431123},{"Daniela",18,0,96431123}} ;
    inicializarLista(lista,TAM);
    for(int i=0; i< TAMSEC; i++)
    {
        lista[i].estado = 0;
    }
    while(seguir=='s')
    {
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
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
