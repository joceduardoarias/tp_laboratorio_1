#ifndef MIBIBLIOTECA_H_INCLUDED
#define MIBIBLIOTECA_H_INCLUDED
/** \brief pide un la entrada de un valor entero al usuario
 *\brief pedir un valor ingresado por el usuario .
 *\param mensaje es la cadena que muestra por consola
 *\return devuelve el valor ingresado por el usuario.
 */
int getInt (char mensaje[]);
/**
 *\brief pedir un valor ingresado por el usuario .
 *\param mensaje es la cadena que muestra por consola
 *\param retorno variable que guarda el valor ingresado por el usuario.
 *\return devuelve el valor ingresado por el usuario.
 */
float getFloat (char mensaje[]);
/**
 *\brief calcular la suma de dos valores .
 *\param valor1.
 *\param valor2.
 */
 float calcularSuma(float, float);
 /**\brief calcular la resta de dos valores .
 *\param valor1.
 *\param valor2.
 */
 float calcularResta(float,float);
 /**
 *\brief calcular la division entre dos valores .
 *\param valor1.
 *\param valor2.
 */
 float calcularDivision(float,float);
 /**
 *\brief calcular el producto entre dos valores .
 *\param valor1.
 *\param valor2.
 */
float calcularMultipicacion(float,float);
 /**
 *\brief calcula el factorial de un numero
 *\param valor1 ingresado por el usuario
 *\param valor2 ingresado por el usuario
 *\return retorno devuelve el factoerial de un numero
 */
float calcularFactorial(float);
 /**
 *\brief calcula todas las operaciones suma, resta,multiplicacion, division y factorial de n
 *\param valor1 ingresado por el usuario
 *\param valor2 ingreado por el usuario
 *\return retorna los resultados de todas la operaciones;
 */
 float calcularTodasLasOperaciones(float valor1, float valor2);

void mostrarResultado(float,float,float,float,float,float,float,float);

#endif // MIBIBLIOTECA_H_INCLUDED
