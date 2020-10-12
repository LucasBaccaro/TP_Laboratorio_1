
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arrayemployees.h"

#define TAM 1000
#define ASC 0

//MENU
int menu()
{
    int opcion;
    system("cls");
    printf("\n");
    printf("                                            | SISTEMA DE EMPLEADOS |                                                          ");
    printf("\n\n");
    printf("                                              |     1>ALTAS:    |\n\n\n\n");
    printf("                                              |   2>MODIFICAR:  |\n\n\n\n");
    printf("                                              |     3>BAJAS:    |\n\n\n\n");
    printf("                                              |   4>INFORMAR:   |\n\n\n\n");
    printf("                                              |    5>SALIR      |\n\n\n\n");
    printf("                                         | INGRESE OPCION A REALIZAR |\n\n\n\n");
    scanf("%d",&opcion);
    system("cls");

    return opcion;
}
//INICIALIZACION;
int inicializarEmpleados(eEmpleado empleados[],int tam)
{
    int error= 1;

    if(empleados!=NULL && tam >0)
    {
        for (int i=0; i<tam; i++)
        {
            empleados[i].isEmpty=1;
        }

        error= 0;
    }
    return error;
}
//PERSONA
void mostrarPersona (eEmpleado empleado)
{
    printf("%4d    %4s        %4s       %4.2f       %4d   \t\n\n",empleado.id,empleado.lastName,empleado.name,empleado.salary,empleado.sector);
}
//MOSTRAR EMPLEADOS;
int mostrarPersonas (eEmpleado empleados[],int tam)
{
    int error =1;
    int flag=0;
    if(empleados!=NULL && tam> 0)
    {
        printf("****Lista de empleados****\n\n");
        printf("|----|-------------|------------|-------------|-----------| \n");
        printf("| ID |  APELLIDO   |   NOMBRE   |   SALARIO   |   SECTOR  |  \n");
        printf("| ---|-------------|------------|-------------|-----------|\n");
        for(int i=0; i<tam; i++)
        {
            if(empleados[i].isEmpty==0)
            {
                mostrarPersona(empleados[i]);
                flag = 1;
            }
        }
        if (flag==0)
        {
            printf("No hay personas en la lista \n\n");
        }
        error =0;
    }
    return error;
}
//Buscarlibre(ALTA)
int buscarLibre(eEmpleado empleados[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(empleados[i].isEmpty ==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
//ALTA
int altaEmpleado(eEmpleado empleados[],int tam,int id)
{
    int error= 1;
    int indice;
    eEmpleado nuevoEmpleado;

    if(empleados!=NULL && tam >0 && id >0)
    {
        indice=buscarLibre(empleados,tam);
        if(indice==-1 )
        {
            printf("Sistema COMPLETO\n");
        }
        else
        {
            printf("**Sistema de altas**\n\n");
            nuevoEmpleado.id=id;
            nuevoEmpleado.isEmpty=0;

            printf("Ingrese apellido ");
            fflush(stdin);
            gets(nuevoEmpleado.lastName);

            printf("Ingrese nombre ");
            fflush(stdin);
            gets(nuevoEmpleado.name);

            nuevoEmpleado.salary=validarFlotante(empleados,"Ingrese salario ","Error,reingrese \n",10000,100000);
            nuevoEmpleado.sector=validarEntero(empleados,"Ingrese sector ","Error,reingrese \n",1,5);

            printf("Alta exitosa!!\n");

            empleados[indice]=nuevoEmpleado;
            error= 0;
        }
    }
    return error;
}
//BUSCAR EMPLEADO
int buscarEmpleado(eEmpleado empleados[],int tam,int id)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(empleados[i].id==id && empleados[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
//BAJA
int bajaEmpleado(eEmpleado empleados[],int tam)
{
    int error = 1;
    int indice;
    int id;
    char confirma;
    mostrarPersonas(empleados,tam);
    printf("**Sistema de bajas**\n\n");

    printf("Ingrese ID \n");
    scanf("%d",&id);
    if(empleados !=NULL && tam > 0 && id > 0)
    {
        indice=buscarEmpleado(empleados,tam,id);

        if(indice == -1)
        {
            printf("No existe en nuestro sistema el ID\n");
        }
        else
        {
            mostrarPersona(empleados[indice]);
            printf("Desea confirmar baja s/n?\n");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma=='s')
            {
                empleados[indice].isEmpty =1;
                error=0;
            }
            else
            {
                error =2;
            }
        }
    }
    return error;
}
//MODIFICACION
int modificarEmpleado (eEmpleado empleados[],int tam)
{
    int error = 1;
    int indice;
    int id;
    char confirma;
    int opcion;
    eEmpleado nuevaModificacion;

    printf("**Tabla de modificaciones**\n\n");
    mostrarPersonas(empleados,tam);

    printf("Ingrese el ID a modificar \n");
    scanf("%d",&id);
    if(empleados !=NULL && tam > 0 && id > 0)
    {
        indice=buscarEmpleado(empleados,tam,id);
        if(indice == -1)
        {
            printf("No existen los datos con ese ID\n");
        }
        else
        {
            printf("----|-------------|------------|--------------|-----------------|\n");
            printf("ID  |     APELLIDO|     NOMBRE |     SALARIO  |          SECTOR |\n");
            printf("----|-------------|------------|--------------|-----------------|\n");
            mostrarPersona(empleados[indice]);
            nuevaModificacion=empleados[indice];

            printf("Que desea modificar?\n");
            printf("1>APELLIDO\n2>NOMBRE\n3>SALARIO\n4>SECTOR\n");
            fflush(stdin);
            scanf("%d",&opcion);

            switch (opcion)
            {
            case 1:
                printf("Ingrese apellido a modificar ");
                fflush(stdin);
                gets(nuevaModificacion.lastName);
                break;
            case 2:
                printf("Ingrese nombre a modificar ");
                fflush(stdin);
                gets(nuevaModificacion.name);
                break;
            case 3:
                nuevaModificacion.salary=validarFlotante(empleados,"Ingrese salario a modificar ","Error,reingrese \n",10000,100000);
                break;
            case 4:
                nuevaModificacion.sector=validarEntero(empleados,"Ingrese sector a modificar ","Error,reingrese \n",1,5);
                break;
            }
            printf("Confirma cambio?? s/n ");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma=='s')
            {
                strcpy(empleados [indice] .lastName,nuevaModificacion.lastName);
                strcpy(empleados [indice] .name,nuevaModificacion.name);
                empleados[indice].salary=nuevaModificacion.salary;
                empleados[indice].sector=nuevaModificacion.sector;
                nuevaModificacion=empleados[indice];
                error=0;
            }
            else
            {
                error =2;
            }
        }
    }
    return error;
}
void OrdenarEmpleadosPorApellido(eEmpleado listaEmpleado[],int tam, int criterio)
{
    int i;
    int j;
    eEmpleado auxEmpleado;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listaEmpleado[i].lastName,listaEmpleado[j].lastName)>0 && criterio==0)
            {
                auxEmpleado=listaEmpleado[i];
                listaEmpleado[i]=listaEmpleado[j];
                listaEmpleado[j]=auxEmpleado;
            }
        }
    }
}
int validarEntero(eEmpleado listaEmpleado[],char mensaje[],char mensajeError[],int valores1,int valores2)
{
    int auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&auxiliar);
    while(auxiliar<valores1 || auxiliar>valores2)
    {
        printf("%s",mensajeError);
        fflush(stdin);
        scanf("%d",&auxiliar);

    }
    return auxiliar;
}

float validarFlotante(eEmpleado listaEmpleado[],char mensaje[],char mensajeError[],float valores1,float valores2)
{
    float auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f",&auxiliar);
    while(auxiliar<valores1 || auxiliar>valores2)
    {
        printf("%s",mensajeError);
        fflush(stdin);
        scanf("%f",&auxiliar);

    }
    return auxiliar;
}

int PromedioEmpleados(eEmpleado listaEmpleado[], int tam)
{
    float promedioSalario;
    float salarioTotal = 0;
    int contador = 0;
    int promedioMax = 0;
    int i;
    int indice = -1;

    if(listaEmpleado != NULL && tam >= 0)
    {
        for(i = 0; i < tam; i++)
        {
            if(listaEmpleado[i].isEmpty == 0)
            {
                contador++;
                salarioTotal = salarioTotal + listaEmpleado[i].salary;
            }
        }
        promedioSalario = salarioTotal / (float)contador;
        for(i = 0; i < tam; i++)
        {
            if(listaEmpleado[i].isEmpty == 0 && listaEmpleado[i].salary > promedioSalario)
            {
                promedioMax++;
            }
        }
        printf("\nTotal de salarios : %.2f\nPromedio de salarios : %.2f\n", salarioTotal, promedioSalario);
        printf("\nCantidad de empleados que superan el salario promedio : %d \n", promedioMax);
        indice = 0;
    }

    return indice;
}



