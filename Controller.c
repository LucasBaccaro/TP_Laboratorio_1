#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    int validation=0;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f=fopen(path,"r");
        if(f!=NULL)
        {
            validation=parser_EmployeeFromText(f,pArrayListEmployee);
        }
        else
        {
            printf("No se pudo abrir el archivo\n");
            system("pause");
        }
    }

    fclose(f);

    return validation;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    int result=0;


        if(path != NULL && pArrayListEmployee != NULL){

            f= fopen(path,"rb");

            if(f==NULL)
            {
                result=0;
            }
            else{
                result = parser_EmployeeFromBinary(f,pArrayListEmployee);
            }
        }

         fclose(f);

    return result;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int validation=-1;

    int auxSueldo=0;
    int auxHorasTrabajadas=0;
    char auxNombre[30];
    int auxId;

    auxId=generateId(pArrayListEmployee);

    if(getNameOrLastName(auxNombre,"Ingrese nombre:\n","Reingrese nombre:\n",2,40,3)==0)
    {
        if(getInt(&auxHorasTrabajadas,"Ingrese horas trabajadas:\n","Reingrese horas trabajadas:\n",1,1500,3)==0)
        {
            if(getInt(&auxSueldo,"Ingrese sueldo:\n","Reingrese sueldo:\n",500,500000,3)==0)
            {
                Employee* employee=employee_new();
                employee_setId(employee,auxId);
                employee_setNombre(employee,auxNombre);
                employee_setHorasTrabajadas(employee,auxHorasTrabajadas);
                employee_setSueldo(employee,auxSueldo);

                if(!ll_add(pArrayListEmployee,employee))
                {
                    printf("Alta exitosa!!!\n");
                    validation=1;

                }
            }
        }
    }

    return validation;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int validation=0;
    char confirm;
    int id;
    int len;
    int index;
    int option;
    char name[30];
    int hours;
    int salary;

    len=ll_len(pArrayListEmployee);
    Employee* employee=employee_new();

    for(int i=0;i<len;i++)
    {
        showOneEmployee((Employee*)ll_get(pArrayListEmployee,i));
    }
    if(getInt(&id,"Ingrese ID a modificar:\n","Reingrese ID a modificar:\n",1,2000,3)==0)
    {
        for(int i=0;i<len;i++)
        {
            employee=(Employee*)ll_get(pArrayListEmployee,i);
            if(employee->id==id)
            {
                index=i;
                system("cls");
                printf("Empleado a modificar\n");
                printf(" ID     Nombre     Horas    Sueldo\n");
                showOneEmployee(employee);
                break;

            }
        }
    }

    if(index!=-1)
    {
         printf("\n1. Modificar nombre\n");
        printf("2. Modificar horas trabajadas\n");
        printf("3. Modificar sueldo\n");
        if(getInt(&option,"Que desea modificar?: \n","Reingrese opcion: \n",1,3,3)==0)
        {
            switch(option)
            {
                case 1:
                    getNameOrLastName(name,"Ingrese nuevo nombre: \n","Reingrese nuevo nombre: \n",1,30,3);
                    printf("Confirma editar nombre?: \n");
                    fflush(stdin);
                    scanf("%c",&confirm);
                    confirm=tolower(confirm);
                    if(confirm=='s')
                    {
                    strcpy(employee->nombre,name);
                    ll_remove(pArrayListEmployee,index);
                    ll_push(pArrayListEmployee,index,employee);
                    validation=1;
                    printf("Modificacion exitosa!!!!\n");
                    }

                    break;
                case 2:
                    getInt(&hours,"Ingrese nuevas horas trabajadas: \n","Reingrese nuevas horas trabajadas: \n",1,2500,3);
                    printf("Confirma editar horas trabajadas?: \n");
                    fflush(stdin);
                    scanf("%c",&confirm);
                    confirm=tolower(confirm);
                    if(confirm=='s')
                    {
                        employee->horasTrabajadas=hours;
                        ll_remove(pArrayListEmployee,index);
                        ll_push(pArrayListEmployee,index,employee);
                        validation=1;
                        printf("Modificacion exitosa!!!!\n");
                    }

                    break;
                case 3:
                    getInt(&salary,"Ingrese nuevo salario: \n","Reingrese nuevo salario: \n",200,2000000,3);
                    printf("Confirma modificar sueldo?: \n");
                    fflush(stdin);
                    scanf("%c",&confirm);
                    if(confirm=='s')
                    {
                        employee->sueldo=salary;
                        ll_remove(pArrayListEmployee,index);
                        ll_push(pArrayListEmployee,index,employee);
                        validation=1;
                        printf("Modificacion exitosa!!!!\n");
                    }
                    break;
            }
        }
    }
    return validation;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int validation=0;
    int id;
    char confirm;
    int index;

    int len;

    len=ll_len(pArrayListEmployee);

    for(int i=0;i<len;i++)
    {
        showOneEmployee((Employee*) ll_get(pArrayListEmployee,i));
    }

    if(getInt(&id,"Ingrese ID a dar de baja: \n","Reingrese ID a dar de baja: \n",1,2000,3)==0)
    {
        Employee* employee=employee_new();

        for(int i=0;i<len;i++)
        {
            employee=((Employee*) ll_get(pArrayListEmployee,i));
            if(employee->id==id)
            {
                index=i;
                break;
            }
        }
        if(index!=-1)
        {
            printf(" ID     Nombre     Horas    Sueldo\n");
            showOneEmployee(employee);
            printf("Confirma baja?:\n");
            fflush(stdin);
            scanf("%c",&confirm);
            confirm=tolower(confirm);

            if(confirm=='s')
            {
                ll_remove(pArrayListEmployee,index);
                validation=1;
                printf("Baja exitosa!!!!\n");
            }
            else
            {
                printf("Se ha cancelado la baja\n");
            }
        }
    }

    return validation;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len=ll_len(pArrayListEmployee);
    Employee* auxEmployee;

    printf("ID   NOMBRE   HORAS   SUELDO\n");
    for(int i=0;i<len;i++)
    {
        auxEmployee=(Employee*) ll_get(pArrayListEmployee,i);
        if(auxEmployee!=NULL)
        {
            showOneEmployee(auxEmployee);
        }
    }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int validation=0;
    int order;

    system("cls");
    switch(menuSort())
    {
        case 1:
            if(getInt(&order,"Ingrese orden ascendente(1) o descendente(0): \n","Reingrese orden ascendente(1) o descendente(0): \n",0,1,3)==0)
            {
                if(order==1)
                {
                    printf("Ordenando empleados...\n");
                    ll_sort(pArrayListEmployee,compareById,order);
                    validation=1;
                }
                else
                {
                    printf("Ordenando empleados...\n");
                    ll_sort(pArrayListEmployee,compareById,order);
                    validation=1;
                }
            }
            break;
        case 2:
            if(getInt(&order,"Ingrese orden ascendente(1) o descendente(0): \n","Reingrese orden ascendente(1) o descendente(0): \n",0,1,3)==0)
            {
                if(order==1)
                {
                    printf("Ordenando empleados...\n");
                    ll_sort(pArrayListEmployee,compareByName,order);
                    validation=1;
                }
                else
                {
                    printf("Ordenando empleados...\n");
                    ll_sort(pArrayListEmployee,compareByName,order);
                    validation=1;
                }
            }
            break;
        case 3:
            if(getInt(&order,"Ingrese orden ascendente(1) o descendente(0): \n","Reingrese orden ascendente(1) o descendente(0): \n",0,1,3)==0)
            {
                if(order==1)
                {
                    printf("Ordenando empleados...\n");
                    ll_sort(pArrayListEmployee,compareByHours,order);
                    validation=1;
                }
                else
                {
                    printf("Ordenando empleados...\n");
                    ll_sort(pArrayListEmployee,compareByHours,order);
                    validation=1;
                }
            }
            break;
        case 4:
            if(getInt(&order,"Ingrese orden ascendente(1) o descendente(0): \n","Reingrese orden ascendente(1) o descendente(0): \n",0,1,3)==0)
            {
                if(order==1)
                {
                    printf("Ordenando empleados...\n");
                    ll_sort(pArrayListEmployee,compareBySalary,order);
                    validation=1;
                }
                else
                {
                    printf("Ordenando empleados...\n");
                    ll_sort(pArrayListEmployee,compareBySalary,order);
                    validation=1;
                }
            }
            break;
    }
    return validation;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

    FILE* f;
    Employee* auxEmployee;
    int validation=0;
    int id;
    char name[130];
    int hours;
    int salary;

    int len=ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        if(len>0)
        {
            f=fopen(path,"w");

            if(f!=NULL)
            {
                 for(int i=0;i<len;i++)
                {
                    auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
                    employee_getId(auxEmployee,&id);
                    employee_getNombre(auxEmployee,name);
                    employee_getHorasTrabajadas(auxEmployee,&hours);
                    employee_getSueldo(auxEmployee,&salary);
                    fprintf(f,"%d,%s,%d,%d\n",id,name,hours,salary);
                }
                fclose(f);
                validation=1;
            }
        }
    }

    return validation;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    Employee* auxEmployee;
    int len = ll_len(pArrayListEmployee);
    int validation = 0;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        if(len>0)
        {
            f=fopen(path,"wb");
            if(f!=NULL)
            {
                for(int i=0; i<len;i++)
                {
                    auxEmployee=ll_get(pArrayListEmployee,i);
                    if(auxEmployee!=NULL)
                    {
                        fwrite(auxEmployee,sizeof(Employee),1,f);
                    }
                }
            validation=1;
            fclose(f);
            }

        }
    }

    return validation;
}
