#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#endif // ARRAYEMPLOYEES_H_INCLUDED
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmpleado;
/** \brief Muestra el menu.
 *
 * \return devuelve entero.
 *
 */
int menu();

/** \brief Inicia empleados.
 *
 * \param lista empleados.
 * \param tamaño.
 * \return int.
 *
 */
int inicializarEmpleados(eEmpleado empleados[],int tam);
/** \brief muestra persona.
 *
 * \param un empleado.
 * \return nada.
 *
 */
void mostrarPersona (eEmpleado empleado);
/** \brief muestra todas personas.
 *
 * \param lista empleados.
 * \param tamaño.
 * \return entero.
 *
 */
int mostrarPersonas (eEmpleado empleados[],int tam);
/** \brief Dar de alta
 *
 * \param empleados
 * \param tamaño
 * \param id
 * \return retorna entero
 *
 */
int altaEmpleado(eEmpleado empleados[],int tam,int id);
/** \brief busca lugar libre en el array empty
 *
 * \param empleados[] eEmpleado
 * \param tam int
 * \return retorna entero
 *
 */
int buscarLibre(eEmpleado empleados[],int tam);
/** \brief Dar de baja a un empleado
 *
 * \param empleados[] eEmpleado
 * \param tam int
 * \return retorna entero
 *
 */
int bajaEmpleado(eEmpleado empleados[],int tam);
/** \brief Busca empleado por ID
 *
 * \param empleados[] eEmpleado
 * \param tam
 * \param id
 * \return retorna entero
 *
 */
int buscarEmpleado(eEmpleado empleados[],int tam,int id);
/** \brief Modifica empleado
 *
 * \param eEmpleado empleados[]
 * \param tamaño
 * \return retorna entero
 *
 */
int modificarEmpleado (eEmpleado empleados[],int tam);
/** \brief Ordena alfabeticamente de la A a la Z los apellidos
 *
 * \param listaEmpleado[] eEmpleado
 * \param cant int
 * \param criterio int
 * \return nada
 *
 */
void OrdenarEmpleadosPorApellido(eEmpleado listaEmpleado[],int cant, int criterio);
/** \brief Valida un entero entre dos max y min
 *
 * \param listaEmpleado[] eEmpleado
 * \param Mensaje
 * \param Mensaje de error
 * \param minimo
 * \param maximo
 * \return entero
 *
 */
int validarEntero(eEmpleado listaEmpleado[],char mensaje[],char mensajeError[],int valores1,int valores2);
/** \brief Valida un flotante entre dos max y min
 *
 * \param listaEmpleado[] eEmpleado
 * \param Mensaje
 * \param mensaje de error
 * \param valores1 minimo
 * \param valores2 maximo
 * \return float
 *
 */
float validarFlotante(eEmpleado listaEmpleado[],char mensaje[],char mensajeError[],float valores1,float valores2);
/** \brief Promedio de empleados
 *
 * \param listaEmpleado[] eEmpleado
 * \param tamaño
 * \return entero
 *
 */
int PromedioEmpleados(eEmpleado listaEmpleado[], int tam);
