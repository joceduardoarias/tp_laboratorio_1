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

float calcularSuma(float valor1, float valor2)
{
    float suma;
    suma = valor1 + valor2;
    return suma;
}
float calcularResta(float valor1,float valor2)
{
    float resta;
    resta = valor1 - valor2;
    return resta;
}
float calcularDivision(float valor1,float valor2)
{
    float division;
    if(valor2 == 0)
    {
        //printf("\nEl divisor debe ser un numero diferente de 0.");
    }
    else
    {
        division = valor1 / valor2;
    }
    return division;
}
float calcularMultipicacion(float valor1,float valor2)
{
    float multiplicacion;
    multiplicacion = valor1 * valor2;
    return multiplicacion;
}
float calcularFactorial(float valor1)
{
    float factorial = -1;

    if(valor1 < 0)
    {
        factorial = -1;
        //printf("\n ¡¡¡ERROR!!! El numero ingresado debe ser un entero positivo.\n");
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
void mostrarResultado(float a,float b,float suma,float resta,float multiplicacion,float division,float factorialA,float factorialB)
{

    if(factorialA == -1)
    {
        printf("\n ¡¡¡ERROR!!! El numero ingresado debe ser un entero positivo.\n");
    }
    else
    {
        printf("\nEl factorial de !%.2f es: %.2f ",a,factorialA);
    }
    if(factorialB == -1)
    {
        printf("\n ¡¡¡ERROR!!! El numero ingresado debe ser un entero positivo.\n");
    }
    else
    {
        printf("\nEl factorial de ! %.2f es: %.2f",b,factorialB);
    }
    printf("\nEl resultado de %.2f+%.2f es: %.2f",a,b,suma);
    printf("\nEl resultado de %.2f-%.2f es: %.2f",a,b,resta);
    printf("\nEl resultado de %.2f*%.2f es: %.2f\n",a,b,multiplicacion);

}
