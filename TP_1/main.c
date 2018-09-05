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
    float resultadoA,resultadoB;

    do
    {
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
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!) - Calcular el factorial (B!) \n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        opcion = getInt("\n Seleccione una opcion: ");
        system("cls");
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
            calcularSuma(a,b);
            system("pasue");
            break;
        case 4:
            system("cls");
            calcularResta(a,b);
            system("pause");
            break;
        case 5:
            system("cls");
            calcularDivision(a,b);
            system("pause");
            break;
        case 6:
            system("cls");
            calcularMultipicacion(a,b);
            system("pause");
            break;
        case 7:
            system("cls");
            resultadoA = calcularFactorial(a);
            resultadoB = calcularFactorial(b);
            printf("\n %.f! = %.f \n %.f! = %.f \n",a,resultadoA,b,resultadoB);
            system("pause");
            break;
        case 8:
            system("cls");
            calcularSuma(a,b);

            calcularResta(a,b);

            calcularDivision(a,b);

            calcularMultipicacion(a,b);
            resultadoA = calcularFactorial(a);
            resultadoB = calcularFactorial(b);
            printf("\n %.f! = %.f \n %.f! = %.f \n",a,resultadoA,b,resultadoB);
            system("pause");
            break;
        case 9:
            seguir = 'n';
            break;
        }

    }
    while(seguir=='s');
    return 0;
}
