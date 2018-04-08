#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float a;
    float b;
    float resultado;
    //while(seguir=='s')
    do
    {
        printf("\n  >>> MENU CALCULADORA <<<\n" );
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                a = valorEntrada();
                break;
            case 2:
                b = valorEntrada();
                break;
            case 3:
                resultado = calcularSuma(a,b);
                printf("\n %.f + %.f = %.f \n", a,b,resultado);
                break;
            case 4:
                resultado = calcularResta(a,b);
                printf("\n %.f - %.f = %.f \n", a,b,resultado);
                break;
            case 5:
                resultado = calcularDivision(a,b);
                printf("\n %.f / %.f = %.2f \n", a,b,resultado);
                break;
            case 6:
                resultado = calcularMultipicacion(a,b);
                printf("\n %.f * %.f = %.f \n\n", a,b,resultado);
                break;
            case 7:
                resultado = calcularFactorial(a);
                printf("\n %.f! = %.f \n", a,resultado);
                break;
            case 8:
                resultado = calcularSuma(a,b);
                printf("\n %.f + %.f = %.f \n", a,b,resultado);

                resultado = calcularResta(a,b);
                printf("\n %.f - %.f = %.f \n", a,b,resultado);

                resultado = calcularDivision(a,b);
                printf("\n %.f / %.f = %.2f \n", a,b,resultado);

                resultado = calcularMultipicacion(a,b);
                printf("\n %.f * %.f = %.f \n\n", a,b,resultado);

                resultado = calcularFactorial(a);
                printf("\n %.f! = %.f \n", a,resultado);

                break;
            case 9:
                seguir = 'n';
                break;
        }

}while(seguir=='s');
    //printf("\n El 1er operando: %.f El segundo operando: %.f: \n resultado: %.2f", a,b,resultado);
    return 0;
}
