#include <stdio.h>
#include <stdlib.h>
#include "MiBiblioteca.h"
int getInt (char mensaje[])
{
    int  retorno;

    printf("\n %s",mensaje);
    scanf("%d", &retorno);

    return retorno;
}
float getFloat (char mensaje[])
{
    float retorno;

    printf("\n %s",mensaje);
    scanf("%f", &retorno);

    return retorno;
}

void calcularSuma(float valor1, float valor2)
{
    float suma;
    suma = valor1 + valor2;
     printf("\n %.f + %.f = %.f \n", valor1,valor2,suma);
}
void calcularResta(float valor1,float valor2)
{
    float resta;
    resta = valor1 - valor2;
   printf("\n %.f - %.f = %.f \n", valor1,valor2,resta);
}
void calcularDivision(float valor1,float valor2)
{
    float division;
    if(valor2 == 0)
    {
        printf("\nEl divisor debe ser un numero diferente de 0.");
    }
    else
    {
        division = valor1 / valor2;
    }
    printf("\n %.f / %.f = %.2f \n", valor1,valor2,division);
}
void calcularMultipicacion(float valor1,float valor2)
{
    float multiplicacion;
    multiplicacion = valor1 * valor2;
    printf("\n %.f * %.f = %.f \n\n", valor1,valor2,multiplicacion);
}
float calcularFactorial(float valor1)
{
    float factorial = -1;

    if(valor1 < 0)
    {
        factorial = -1;
        printf("\n ¡¡¡ERROR!!! El numero ingresado debe ser un entero positivo.\n");
    }
    else
    {
        if(valor1==0)
        {
        factorial = 1;
        }
        else
        {
        factorial = valor1* calcularFactorial(valor1-1);
        }
    }
    return factorial;
}
