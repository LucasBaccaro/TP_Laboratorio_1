#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int menu();


int main()
{
    int validation;
    int validation2;
    int flag1=0;
    char exit='n';
    LinkedList* employeeList = ll_newLinkedList();
    do{
        system("cls");
        switch(menu())
        {
            case 1:
                if(flag1==0)
                {
                    validation=controller_loadFromText("data.csv",employeeList);
                    if(validation==1)
                    {
                    printf("Se cargaron exitosamente los datos!!!\n");
                    flag1=1;
                    }
                    else
                    {
                    printf("Error al cargar!!!\n");
                    }
                }
                else
                {
                   printf("Los datos ya se encuentran cargados!!!\n");
                }

                system("pause");

                break;
            case 2:
                if(flag1==0)
                {
                    validation2=controller_loadFromBinary("data.bin",employeeList);
                    if(validation2==1)
                    {
                        printf("Se cargaron exitosamente los datos!!!\n");
                        flag1=1;
                    }
                    else
                    {
                        printf("Error al cargar los datos!!!\n");

                    }
                }else
                {
                    printf("Los datos ya se encuentran cargados!!!\n");
                }
                system("pause");

                break;
            case 3:
                if(flag1)
                {
                     controller_addEmployee(employeeList);

                }else
                {

                    printf("No hay datos cargados...!!\n");
                }
                system("pause");
                break;
            case 4:
                if(flag1)
                {
                    controller_editEmployee(employeeList);
                }
                else
                {
                    printf("No hay datos cargados!!!\n");
                }
                system("pause");
                break;
            case 5:
                if(flag1)
                {
                    controller_removeEmployee(employeeList);

                }
                else
                {
                    printf("No hay datos cargados!!!\n");
                }
                system("pause");
                break;
            case 6:
                if(flag1)
                {
                  controller_ListEmployee(employeeList);
                }
                else
                {
                    printf("No hay datos cargados!!!\n");
                }

                system("pause");
                break;
            case 7:
                if(flag1)
                {
                    if(controller_sortEmployee(employeeList))
                    {
                    printf("Empleados Ordenados!!!!\n");
                    }


                }else
                {
                    printf("No hay datos cargados!!!\n");
                }
                system("pause");
                break;
            case 8:
                if(flag1)
                {
                    validation=controller_saveAsText("data.csv",employeeList);
                    if(validation==1)
                    {
                    printf("Se guardo de manera exitosa!!!!\n");


                    }else
                    {
                    printf("Ocurrio un error al guardar!\n");
                    }

                }else
                {
                    printf("No hay datos cargados!!!\n");
                }

                system("pause");
                break;
            case 9:
                if(flag1)
                {
                    validation=controller_saveAsBinary("data.bin",employeeList);
                    if(validation == 1)
                    {
                    printf("Se Guardo de manera exitosa!!!!\n");
                    }else
                    {
                    printf("Ocurrio un Error al Guardar!!!!\n");
                    }


                }else
                {
                    printf("No hay datos cargados!!!\n");
                }
                 system("pause");
                break;

            case 10:
                printf("Confirma salir? s/n: \n");
                fflush(stdin);
                scanf("%c",&exit);
                exit=tolower(exit);
                printf("Saliendo...!\n");
                break;
            default:
                {
                    printf("Error, opcion invalida\n");
                }
        }
    }while(exit=='n');
    return 0;
}


/** \brief Menu de opciones.
 *
 * \return retorna la opcion seleccionada.
 */
int menu()
{
    int option;
    printf("---------------------------------------------------------------------------\n");
    printf("----------------------------TRABAJO PRACTICO 3-----------------------------\n");
    printf("---------------------------------------------------------------------------\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");
    getInt(&option,"Ingrese opcion: \n","Error, reingrese opcion: \n",1,10,3);

    return option;
}
