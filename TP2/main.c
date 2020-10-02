#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arrayemployees.h"

#define TAM 1000
#define ASC 0


int main()
{
    int id=100;
    eEmpleado lista [TAM] ; //{{100,"juan","perez",15000,3,0},{101,"hol","perfgez",150450,2,0} };
    int seguir='s';
    int rta;
    int banderaAlta=0;
    int opcionMod;

    if(inicializarEmpleados(lista,TAM))
    {
        printf("Fallo\n");
    }
    else
    {
        printf("Inicializacion exitosa\n");
    }
    system("pause");
    while(seguir=='s')
    {
        switch(menu())
        {
        case 1:
            banderaAlta=1;
            mostrarPersonas(lista,TAM);

            if (altaEmpleado(lista,TAM,id)==0)
            {
                id++;
            }
            else
            {
                printf("No se pudo realizar la operacion\n");
            }
            system("pause");
            break;
        case 2:
            if(banderaAlta==1)
            {
                rta=modificarEmpleado(lista,TAM);
                if(rta==0)
                {
                    printf("Modificacion exitosa!!!\n");
                    system ("pause");
                }
                else if(rta==1)
                {
                    printf("Problemas con la modificacion,vuelva a intentar.\n");
                    system ("pause");
                }
                else
                {
                    printf("La modificacion ha sido cancelada por usuario\n");
                    system ("pause");
                }
            }
            else
            {
                printf("Debes dar de alta un empleado,para poder modificar.\n\n");
                 system("pause");
            }

            break;
        case 3:
            if(banderaAlta==1)
            {
                rta=bajaEmpleado(lista,TAM);
                if(rta==0)
                {
                    printf("Baja exitosa!!!\n");
                    system ("pause");
                }
                else if(rta==1)
                {
                    printf("Problemas con la baja,vuelva a intentar.\n");
                    system ("pause");
                }
                else
                {
                    printf("La baja ha sido cancelada por usuario\n");
                    system ("pause");
                }
            }
            else
            {
                printf("Debes dar de alta para poder utilizar la baja de empleados. \n\n");
                system ("pause");
            }

            break;
        case 4:
            if(banderaAlta==1)
            {
                mostrarPersonas(lista,TAM);

                printf("Seleccione que opcion desea\n\n1 >ORDENAR\n2>MAYOR SALARIO\n");
                scanf("%d",&opcionMod);

                if (opcionMod == 1)
                {
                    OrdenarEmpleadosPorApellido(lista,TAM,ASC);
                    mostrarPersonas(lista,TAM);

                    system("pause");
                }
                else if(opcionMod==2)
                {
                    PromedioEmpleados(lista,TAM);

                    system("pause");
                }
                else
                {
                    printf("Opcion invalida,ingrese opcion\n");
                    system("pause");
                }

            }
            else
            {
                printf("Debes dar de alta para mostrar empleados \n\n");
                system ("pause");
            }

            break;
        case 5:
            printf("Gracias por usar el programa \n");
            seguir='n';
            break;
        default:
            printf("Opcion invalida\n");
            system ("pause");
        }
        if(lista->isEmpty)
        {
            banderaAlta=0;
        }
    }
    return 0;
}
