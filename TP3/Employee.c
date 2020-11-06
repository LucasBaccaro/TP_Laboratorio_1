#include "Employee.h"
#include "utn.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/** \brief Crea un tipo de estructura y carga los campos
 *
 * \param  Recibe de parametro cuatro cadenas para cargar
 *
 * \return Retorna la estructura Employee* con los campos cargados
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* employee;

    employee=employee_new();

    if(employee!=NULL)
    {
        if(employee_setId(employee,atoi(idStr))
           && employee_setNombre(employee,nombreStr)
           && employee_setHorasTrabajadas(employee,atoi(horasTrabajadasStr))
           && employee_setSueldo(employee,atoi(sueldo)) ==0 )
        {

            free(employee);
            employee=NULL;
        }

    }

    return employee;

}

/** \brief Crea espacio en memoria y una nueva estructura.
 *
 * \return Devuelve una estructura inicializada.
 */
Employee* employee_new()
{
    Employee* employee= (Employee*) malloc(sizeof(Employee));

    if(employee != NULL)
    {
        employee->id=0;
        strcpy(employee->nombre," ");
        employee->horasTrabajadas=0;
        employee->sueldo=0;
    }

    return employee;
}

/** \brief Carga el ID a la estructura.
 *
 * \param Recibe puntero de  la estructura.
 * \param Toma el valor ID ingresado por el usuario.
 *
 * \return Retorna 1 si no es NULL.0 Si lo es.
 */
int employee_setId(Employee* this,int id)
{
    int validation=0;
    if(this!=NULL && id>0)
    {
        this->id=id;
        validation=1;
    }

    return validation;
}


/** \brief Genera un ID autoincremental
 *
 * \param Recibe puntero .
 *
 * \return Retorna el ID generado.
 */
int generateId(void* this)
{
    int validation=-1;

    validation= ll_len(this)+1;

    return validation;
}



/** \brief Carga la cadena en la estructura.
 *
 * \param Recibe puntero de estructura.
 * \param Recibe cadena de caracteres.
 *
 * \return Retorna 1 si no es NULL.0 Si lo es.
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int validation=0;

        if(this!=NULL)
        {
            strcpy(this->nombre,nombre);
            validation=1;
        }

    return validation;
}

/** \brief Carga las horas en la estructura.
 *
 * \param Recibe puntero de estructura.
 * \param Recibe un entero a cargar.
 * \return Retorna 1 si no es NULL.0 Si lo es.
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int validation=0;

        if(this!=NULL )
        {
            this->horasTrabajadas=horasTrabajadas;
            validation=1;
        }

    return validation;
}

/** \brief Carga el sueldo en la estructura.
 *
 * \param Recibe puntero de estructura.
 * \param Recibe un entero a cargar.
 *
 * \return Retorna 1 si no es NULL. 0 Si lo es.
 */
int employee_setSueldo(Employee* this,int sueldo)
{
   int validation=0;

    if(this!=NULL && sueldo<5000000 && sueldo>500)
    {
        this->sueldo=sueldo;
        validation=1;
    }

    return validation;
}

/** \brief Toma el valor del ID de una estructura.
 *
 * \param Recibe puntero de una estructura.
 * \param Recibe puntero a entero.
 *
 * \return Retorna 0 si es NULL. 1 si no lo es.
 */
int employee_getId(Employee* this,int* id)
{
    int validation=0;

    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
        validation=1;
    }
    return validation;
}

/** \brief Toma el valor del nombre de una estructura.
 *
 * \param Recibe puntero de una estructura.
 * \param Recibe puntero a cadena.
 *
 * \return Retorna 0 si es NULL. 1 si no lo es.
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int validation=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        validation=1;
    }

    return validation;
}

/** \brief Toma el valor de las horas trabajadas.
 *
 * \param Recibe puntero de una estructura.
 * \param Recibe puntero a entero.
 *
 * \return Retorna 0 si es NULL. 1 si no lo es.
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int validation=0;

    if(this!=NULL && horasTrabajadas>0)
    {
        *horasTrabajadas=this->horasTrabajadas;
        validation=1;
    }


    return validation;
}

/** \brief Toma el valor del sueldo.
 *
 * \param Recibe puntero de una estructura.
 * \param Recibe puntero a entero.
 *
 * \return Retorna 0 si es NULL. 1 si no lo es.
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int validation=0;

    if(this!=NULL && sueldo>0)
    {
        *sueldo=this->sueldo;
        validation=1;
    }


    return validation;
}



/** \brief Muestra un empleado.
 *
 * \param Recibe puntero de una estructura.
 *
 */
void showOneEmployee(Employee* employee)
{
    if(employee==NULL)
    {
        printf("Error\n");
    }else
    {
        printf("%4d  %10s  %5d    %5d\n",employee->id,employee->nombre,employee->horasTrabajadas,employee->sueldo);

    }
}

/** \brief Menu de ordenamiento.
 *
 * \return retorna la opcion seleccionada.
 */
int menuSort()
{

    int option;

    printf("1. Ordenar empleados por ID\n");
    printf("2. Ordenar empleados por nombre\n");
    printf("3. Ordenar empleados por horas trabajadas\n");
    printf("4. Ordenar empleados por sueldo\n");
    getInt(&option,"Ingrese opcion: \n","Error,reingrese opcion: \n",1,4,3);

    return option;

}



/** \brief Compara por ID.
 *
 * \param Recibe puntero a ser casteado.
 * \param Recibe puntero a ser casteado.
 *
 * \return Retorna el resultado de la comparacion.
 */
int compareById(void* e1,void* e2)
{
    int comparison;

    Employee* employee1;
    Employee* employee2;

    if(e1!=NULL && e2!= NULL)
    {
        employee1=(Employee*) e1;
        employee2=(Employee*) e2;

        if(employee1->id > employee2->id)
        {
            comparison=1;
        }
        else if(employee1->id < employee2->id)
        {
            comparison=-1;
        }
        else
        {
            comparison=0;
        }
    }
    return comparison;
}


/** \brief Compara por nombre.
 *
 * \param Recibe puntero a ser casteado.
 * \param Recibe puntero a ser casteado.
 *
 * \return Retorna el resultado de la comparacion.
 */
int compareByName(void* e1,void* e2)
{
    int comparison;

    Employee* employee1;
    Employee* employee2;

    if(e1!=NULL && e2!= NULL)
    {
        employee1=(Employee*) e1;
        employee2=(Employee*) e2;

        if(strcmp(employee1->nombre,employee2->nombre)>0)
        {
            comparison=1;
        }
        else if(strcmp(employee1->nombre,employee2->nombre)<0)
        {
            comparison=-1;
        }
        else
        {
            comparison =0;
        }
    }

    return comparison;
}

/** \brief Compara por horas trabajadas.
 *
 * \param Recibe puntero a ser casteado.
 * \param Recibe puntero a ser casteado.
 *
 * \return Retorna el resultado de la comparacion.
 */
int compareByHours(void* e1,void* e2)
{
    int comparison;

    Employee* employee1;
    Employee* employee2;

    if(e1!=NULL && e2!= NULL)
    {
        employee1= (Employee*) e1;
        employee2= (Employee*) e2;

        if(employee1->horasTrabajadas > employee2->horasTrabajadas)
        {
            comparison=1;
        }
        else if(employee1->horasTrabajadas < employee2->horasTrabajadas)
        {
            comparison=-1;
        }
        else
        {
            comparison=0;
        }
    }
    return comparison;
}

/** \brief Compara por salario.
 *
 * \param Recibe puntero a ser casteado.
 * \param Recibe puntero a ser casteado.
 *
 * \return Retorna el resultado de la comparacion.
 */
int compareBySalary(void* e1,void* e2)
{
    int comparison;

    Employee* employee1;
    Employee* employee2;

    if(e1!=NULL && e2!= NULL)
    {
        employee1= (Employee*) e1;
        employee2= (Employee*) e2;

        if(employee1->sueldo > employee2->sueldo)
        {
            comparison=1;
        }
        else if(employee1->sueldo < employee2->sueldo)
        {
            comparison=-1;
        }
        else
        {
            comparison=0;
        }
    }
    return comparison;
}
