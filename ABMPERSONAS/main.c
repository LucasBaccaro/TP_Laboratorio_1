#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "persona.h"
#include "fecha.h"
#include "deportes.h"


#define TAM 10
#define TAM_D 8
#define ASC 0
#define DEC 1


char menu();
//informes
int mostrarXsexo(ePersona gente[],int tam,eDeporte sports[],int tamD,int sexo);
int mostrarXanio(ePersona gente[],int tam,eDeporte sports[],int tamD,int anio);
//int mostrarXdeporte(ePersona gente[],int tam,eDeporte sports[],int tamD);
int main()

{
    char seguir= 's';
    char confirma;
    char sexo;
    int anio;
    int proximoLegajo=20000;
    int rta;
    int informes;

    eDeporte deportes[TAM_D]=
    {
        {1000, "No Practica"},
        {1001, "Bicicleta"},
        {1002, "Patin"},
        {1003, "Esqui"},
        {1004, "Surf"},
        {1005, "Skate"},
        {1006,"Ajedrez"},
        {1007,"Natacion"},
        {1008,"Volley"},
        {1009,"Handball"}
    };

    ePersona lista[TAM];

    if(inicializarPersona(lista,TAM))
    {
        printf("Fallo\n");
    }
    else
    {
        printf("Inicializacion exitosa\n");
    }
    proximoLegajo+= harcodearPersonas(lista,TAM,TAM_D);
    system("pause");

    do
    {
        switch(menu())
        {
        case 'a':
            mostrarPersonas(lista,TAM,deportes,TAM_D);
            if (altaPersona(lista,TAM,deportes,TAM_D,proximoLegajo)==0)
            {
                proximoLegajo++;
            }
            else
            {
                printf("No se pudo realizar la operacion\n");
            }
            system("pause");
            break;
        case 'b':
            rta=bajaPersona(lista,TAM,deportes,TAM_D);
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
            break;
        case 'c':
            rta=modificarPersona(lista,TAM,deportes,TAM_D);
            if(rta==0)
            {
                printf("Modificacion exitosa!!!\n");
            }
            else if(rta==1)
            {
                printf("Problemas con la modificacion,vuelva a intentar.\n");
            }
            system("pause");
            break;
        case 'd':
            mostrarPersonas(lista,TAM,deportes,TAM_D);
            system("pause");
            break;
        case 'e':
            ordenarPersonaSexoAltura(lista,TAM,DEC,ASC); //MENOR A MAYOR...F....M...
            printf("Ordenado con exito");
            system("pause");
            break;
        case 'f':
            printf("Ingrese que informe desea\n");
            printf("1>Mostrar por sexo\n");
            printf("2>Mostrar por anio\n");
            printf("3>Ordenar por sexo y altura");
            scanf("%d",&informes);
            switch(informes)
            {
            case 1:
                printf("Ingrese sexo");
                fflush(stdin);
                scanf("%c",&sexo);
                mostrarXsexo(lista,TAM,deportes,TAM_D,sexo);
                system("pause");
                break;
            case 2:
                printf("Ingrese anio");
                scanf("%d",&anio);
                mostrarXanio(lista,TAM,deportes,TAM_D, anio);
                system("pause");
                break;
            case 3:
                break;
            }
            break;
        case 'g':

            break;
        case 'h':

            break;
        case 'i':
            mostrarDeportes(deportes,TAM_D);
            system("pause");
            break;
        case 'z':
            printf("Confirma salida?\n");
            fflush(stdin);
            scanf("%c",&confirma);
            confirma=tolower(confirma);
            if (confirma=='s')
            {
                seguir='n';
            }
            break;
        }
    }
    while(seguir=='s');
    return 0;
}


char menu()
{
    char opcion;
    system("cls");
    printf("ABM PERSONAS\n");
    printf("A>ALTA\n");
    printf("B>BAJA\n");
    printf("C>MODIFICAR\n");
    printf("D>LISTAR\n");
    printf("E>ORDENAR\n");
    printf("F>INFORMES\n");
    printf("G>\n");
    printf("H>\n");
    printf("I>LISTAR DEPORTES\n");
    printf("LISTAR POR DEPORTE\n");
    printf("Z>SALIR\n");
    printf("INGRESE OPCION:\n ");
    fflush(stdin);
    opcion=tolower(getchar());
    return opcion;
}

int mostrarXsexo(ePersona gente[],int tam,eDeporte sports[],int tamD,int sexo)
{
    int error =1;
    int flag=0;
    if(gente!=NULL && tam> 0 && (sexo == 'f' || sexo == 'm'))
    {
        printf("****Lista de gente****\n\n");
        printf("|--------|-----------|---------|------------|---------------|------------|\n");
        printf("| LEGAJO |  NOMBRE   |   SEXO  |   ALTURA   |   FECHA NAC   |    DEPORTE |\n");
        printf("| -------|-----------|---------|------------|---------------|------------|\n");
        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty==0 && gente[i].sexo == sexo)
            {
                mostrarPersona(gente[i],sports,tamD);
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

int mostrarXanio(ePersona gente[],int tam,eDeporte sports[],int tamD,int anio)
{
    int error =1;
    int flag=0;
    if(gente!=NULL && tam> 0 && anio > 0)
    {
        printf("****Lista de gente****\n\n");
        printf("|--------|-----------|---------|------------|--------------|-------------|\n");
        printf("| LEGAJO |  NOMBRE   |   SEXO  |   ALTURA   |   FECHA NAC  |  DEPORTES   |\n");
        printf("| -------|-----------|---------|------------|--------------|-------------|\n");
        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty==0 && gente[i].fNac.anio == anio)
            {
                mostrarPersona(gente[i],sports,tamD);
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


/*int mostrarXdeporte(ePersona gente[],int tam,eDeporte sports[],int tamD)
{
    int error=1;
    int idDeporteSeleccionado;
    if(gente !=NULL&& sports!= NULL&& tam>0 && tamD>0)
    {
        system("cls");
        printf("**Informe de programas por deporte**\n\n");
        mostrarDeportes(sports,tamD)
        printf("Ingrese deporte ");
        scanf("%d,",&idDeporteSeleccionado);

        printf("L)

        error=0;
    }
    return error;
}*/



