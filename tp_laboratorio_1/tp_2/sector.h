#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED
#define SECTOR_EMPTY 0
#define SECTOR_USED 1
#define SECTOR_DELETE 2
typedef struct
{
    char descripcion[51];
    int id;
    int isEmpty;
} eSector;
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list eSector* Pointer to array of employees
* \param int lenSector length
*/
void initSector(eSector* sectores, int lenSector );

/** \brief busca en la estructura por el valor recibido y devuelve el indice
 *
 * \param   eSector array a recorrer
 * \param  lenSector longitud del array
 * \param   valor es el valor a buscar dentro del array
 * \return  devuelve -1 si no encuctra coincidencia o retornao el indice
 *
 */
int buscarPrimeraOcurrenciaSector(eSector* sectores, int lenSector, int valor);
/** \brief busca en la estructura por el valor recibido y devuelve el indice
 *
 * \param   eSector array a recorrer
 * \param  lenSector longitud del array
 * \param   valor es el valor a buscar dentro del array
 * \return  devuelve -1 si no encuctra coincidencia o retornao el indice
 *
 */
int buscarPrimeraOcurrenciaSectorId(eSector* sectores, int lenSector, int auxId);
/** \brief carga un nuevo empleado en el array
  * \param   eSector array a recorrer
  * \param  lenSector longitud del array
 */
void addSector(eSector* sectores, int lenSector);
/** \brief  Busca en el array el id mas alto  entre los usados y los borrados
 * \param   eSector array a recorrer
 * \param  lenSector longitud del array
 * \return int return (-1) si hay un error [longitud invalida o puntero NULL] - (proximo ID) si ok
 */
//static int findNextIdSector(eSector* sectores, int lenSector);
/** \brief carga la descripcion y id de los sectores de la empresa
 * \param eSectores* es el array a analizar
 * \param char descripcion es la cadena de caracteres a cargar en el array
 * \param int idSector
 * \param int index indece de lugar en el array
 * \param lenSec longitud del array
 */
void setArraySector(eSector* sectores,char descripcion[],int auxId,int index,int estado);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param   eSector array a recorrer
 * \param  lenSector longitud del array
 */
void removeSector(eSector* sectores, int lenSector);
/** \brief Imprime por pantalla uno de los sectores cargados
 * \param   eSector array a recorrer
 * \param  lenSector longitud del array
 * \param index es la posicion dentro del array do
 */
void printSector(eSector* sectores, int lenSector, int index);
/** \brief modificar datos del sector atraves del id
* \param   eSector array a recorrer
* \param  lenSector longitud del array
*/
void modifySector(eSector* sectores, int lenSector);
/** \brief controla el alta, bajas y modificaciones de los sectores
 * \param   eSector array a recorrer
 * \param  lenSector longitud del array
 */
void controllerSector(eSector* sectores, int lenSector);
/** \brief muestra los valores cargados en array
 * \param   eSector array a recorrer
 * \param  lenSector longitud del array
 */
void listarSectores(eSector* sectores, int lenSector);
#endif // SECTOR_H_INCLUDED
