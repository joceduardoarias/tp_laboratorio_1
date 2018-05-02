#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


float valorEntrada (void)
{
    float retorno;

    printf("\nIngrese valor: ");
    scanf("%f", &retorno);

    return retorno;
}

float calcularSuma(float valor1, float valor2)
{
    float retorno;
    retorno = valor1 + valor2;
    return retorno;
}
float calcularResta(float valor1,float valor2)
{
    float retorno;
    retorno = valor1 - valor2;
    return retorno;
}
float calcularDivision(float valor1,float valor2)
{
    float retorno;
    if(valor2 == 0)
    {
        printf("\nEl divisor debe ser un numero diferente de 0.");
    }
    else
    {
        retorno = valor1 / valor2;
    }
    return retorno;
}
float calcularMultipicacion(float valor1,float valor2)
{
    float retorno;
    retorno = valor1 * valor2;
    return retorno;
}
float calcularFactorial(float valor1)
{
    float retorno = -1;

    if(valor1 < 0)
    {
        retorno = -1;
        printf("\n ¡¡¡ERROR!!! El numero ingresado debe ser un entero positivo.\n");
    }
    else
    {
        if(valor1==0)
        {
        retorno = 1;
        }
        else
        {
        retorno = valor1* calcularFactorial(valor1-1);
        }
    }
    return retorno;
}
