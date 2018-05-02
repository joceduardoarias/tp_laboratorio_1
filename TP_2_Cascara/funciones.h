#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[],int tam, int dni);
/** \brief
 *  Inicializa la estructura  asignando un valor a la variable estado.
 * \param lista el array se pasa como parametro.
 * \param tam se pasa el tamaño del array.
 */
void inicializarLista(EPersona lista[], int tam);
/** \brief
 *  carga los datos ingresados por EL usuario en cada uno de los ficheros.
 * \param lista el array se pasa como parametro.
 * \param  tam se pasa el tamaño del array.
 */
void altaPersonas(EPersona lista[], int tam);
/** \brief
 *  layout de los datos ingresado por el usuario.
 * \param lista el array se pasa como parametro.
 * \param tam se pasa el tamaño del array.
 */
 void bajaPersonas(EPersona lista[], int tam);
/** \brief
 *  eliminar registros ingresado por el usuario.
 * \param lista el array se pasa como parametro.
 * \param tam se pasa el tamaño del array.
 */
void mostrarDatos(EPersona lista[], int tam);
/** \brief
 *  layout de los datos ingresado por el usuario.
 * \param lista el array se pasa como parametro.
 * \param tam se pasa el tamaño del array.
 */
 void mostrarDato(EPersona lista);
 /** \brief
  *  ordena los registros en orden alfabetico
  * \param lista el array se pasa como parametro.
  * \param tam se pasa el tamaño del array.
  */
  void ordenarCaracteres(EPersona lista[], int tam );
#endif // FUNCIONES_H_INCLUDED

