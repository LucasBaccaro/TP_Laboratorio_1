#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int validation=0;
    char buffer[4][40];
    int max;
    Employee* auxEmployee=NULL;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

    while(!feof(pFile))
    {
        max=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        if(max<4)
        {
            break;
        }
        auxEmployee=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

        if(auxEmployee!=NULL)
        {
            ll_add(pArrayListEmployee,auxEmployee);
            validation=1;
        }

    }


    return validation;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int validation=0;
    int max;
    Employee* employee;

        while(!feof(pFile))
        {

             employee = employee_new();

            if(employee !=NULL)
            {

                max = fread(employee,sizeof(Employee),1,pFile);

                    if(max <1)
                    {
                    break;

                    }
                    else
                    {
                        ll_add(pArrayListEmployee,employee);
                        validation=1;
                    }

            }

        }

    return validation;
}
