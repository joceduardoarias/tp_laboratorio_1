#include <stdio.h>
#include <stdlib.h>
#include "MiBiblioteca.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int flagA=0;
    int flagB=0;
    float a;
    float b;
    float resultadoA,resultadoB,suma,resta,multipicacion,division;

    do
    {    system("cls");
        printf("\n  >>> MENU CALCULADORA <<<\n" );
        if(flagA==0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%.2f)\n", a);
        }
        if(flagB == 0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%.2f)\n",b);
        }
        printf("3- Calcular todas las operaciones: \n a. Calcular la suma (A+B)\n b. Calcular la resta (A-B)\n c. Calcular la division (A/B)\n d. Calcular la multiplicacion (A*B)\n e. Calcular el factorial (A!)\n4- Informar resultados\n5- Salir\n");
        opcion = getInt("\n Seleccione una opcion: ");

        switch(opcion)
        {
        case 1:
            system("cls");
            flagA = 1;
            a = getFloat("\nIngrese un numero: ");
            system("pause");
            break;
        case 2:
            system("cls");
            flagB = 1;
            b = getFloat("\nIngrese un numero: ");
            system("pause");
            break;
        case 3:
            system("cls");
            suma = calcularSuma(a,b);
            resta = calcularResta(a,b);
            multipicacion = calcularMultipicacion(a,b);
            division = calcularDivision(a,b);
            resultadoA = calcularFactorial(a);
            resultadoB = calcularFactorial(b);
            system("pause");
            break;
        case 4:
            system("cls");
            mostrarResultado(a,b,suma,resta,multipicacion,division,resultadoA,resultadoB);
            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        }

    }
    while(seguir=='s');
    return 0;
}
