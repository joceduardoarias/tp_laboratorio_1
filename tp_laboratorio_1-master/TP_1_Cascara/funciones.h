#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
 *\brief pedir un valor ingresado por el usuario .
 *\param retorno variable que guarda el valor ingresado por el usuario.
 *\return devuelve el valor ingresado por el usuario.
 */
float valorEntrada (void);

/**
 *\brief calcular la suma de dos valores .
 *\param valor1.
 *\param valor2.
 *\return retorno la suma de valor1 + valor2.
 */
 float calcularSuma(float, float);

 /**\brief calcular la resta de dos valores .
 *\param valor1.
 *\param valor2.
 *\return retorno la resta de valor1 - valor2.
 */
 float calcularResta(float,float);

 /**
 *\brief calcular la division entre dos valores .
 *\param valor1.
 *\param valor2.
 *\return retorno el cociente del valor1 / valor2.
 */
 float calcularDivision(float,float);

 /**
 *\brief calcular el producto entre dos valores .
 *\param valor1.
 *\param valor2.
 *\return retorno el producto entre el valor1 * valor2.
 */

 float calcularMultipicacion(float,float);
 /**
 *\brief calcula la multiplicacion entre dos valores
 *\param valor1 ingresado por el usuario.
 *\param valor2 ingresado por usuario.
 *\return retorno devuelve el resultado de multiplicar valor1 y valor2.
 */
 float calcularFactorial(float);
 /**
 *\brief calcula el factorial de un numero
 *\param valor1 ingresado por el usuario
 *\param valor2 ingresado por el usuario
 *\return retorno devuelve el factoerial de un numero
 */

 float calcularTodasLasOperaciones(float valor1, float valor2);
 /**
 *\brief calcula todas las operaciones suma, resta,multiplicacion, division y factorial de n
 *\param valor1 ingresado por el usuario
 *\param valor2 ingreado por el usuario
 *\return retorna los resultados de todas la operaciones;
 */

#endif // FUNCIONES_H_INCLUDED
