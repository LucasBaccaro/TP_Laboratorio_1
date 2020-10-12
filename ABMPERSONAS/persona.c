#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "persona.h"
#include "fecha.h"
#include "deportes.h"
#include "dataStore.h"

#define TAM 10

#define TAM_D 7
int inicializarPersona(ePersona gente[],int tam)
{
    int error= 1;

    if(gente!=NULL && tam >0)
    {
        for (int i=0; i<tam; i++)
        {
            gente[i].isEmpty=1;
        }

        error= 0;
    }
    return error;
}

//MOSTRAR EMPLEADOS;

//Buscarlibre(ALTA)
int buscarLibre(ePersona gente[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(gente[i].isEmpty ==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
//ALTA
int altaPersona(ePersona gente[],int tam,int legajo)
{
    int error= 1;
    int indice;
    ePersona nuevaPersona;

    if(gente!=NULL && tam >0 && legajo >0)
    {
        system("cls");
        printf("**Alta Persona**\n");
        indice=buscarLibre(gente,tam);
        if(indice==-1 )
        {
            printf("Sistema COMPLETO\n");
        }
        else
        {
            nuevaPersona.legajo=legajo;
            nuevaPersona.isEmpty=0;

            printf("Ingrese apellido\n ");
            fflush(stdin);
            gets(nuevaPersona.nombre);

            printf("Ingrese sexo\n ");
            fflush(stdin);
            scanf("%c",&nuevaPersona.sexo);

            printf("Ingrese Altura\n ");
            scanf("%f",&nuevaPersona.altura);

            printf("Ingrese fecha a modificar dd/mm/aa");
            scanf("%d/%d/%d",&nuevaPersona.fNac.dia,&nuevaPersona.fNac.mes,&nuevaPersona.fNac.anio);

            printf("Alta exitosa!!\n");

            gente[indice]=nuevaPersona;
            error= 0;
        }
    }
    return error;
}
int mostrarPersonas (ePersona gente[],int tam,eDeporte sports[], int tamD )
{
    int error =1;
    int flag=0;
    if(gente!=NULL && tam> 0)
    {
        printf("****Lista de gente****\n\n");
        printf("|--------|-----------|---------|------------------------|----------------|----------------------|\n");
        printf("| LEGAJO |  NOMBRE   |         |   SEXO          ALTURA |         FECHA  |              DEPORTE |\n");
        printf("| -------|-----------|---------|------------------------|----------------|-----------------  ---|\n");
        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty==0)
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


//BAJA
int bajaPersona(ePersona gente[],int tam,eDeporte sports[],int tamD)
{
    int error = 1;
    int indice;
    int legajo;
    char confirma;
    mostrarPersonas(gente,tam,sports,tamD);
    printf("**Sistema de bajas**\n\n");

    printf("Ingrese ID \n");
    scanf("%d",&legajo);
    if(gente !=NULL && tam > 0 && legajo > 0)
    {
        indice=buscarPersona(gente,tam,legajo);

        if(indice == -1)
        {
            printf("No existe en nuestro sistema el ID\n");
        }
        else
        {
            mostrarPersona(gente[indice],sports,tamD);
            printf("Desea confirmar baja s/n?\n");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma=='s')
            {
                gente[indice].isEmpty =1;
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



//BUSCAR EMPLEADO
int buscarPersona(ePersona gente[],int tam,int legajo)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(gente[i].legajo==legajo && gente[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int modificarPersona (ePersona gente[],int tam,eDeporte sports[],int tamD)
{
    int error = 1;
    int indice;
    int id;
    char confirma;
    int opcion;
    ePersona nuevaModificacion;

    printf("**Tabla de modificaciones**\n\n");
    mostrarPersonas(gente,tam,sports,tamD);

    printf("Ingrese el ID a modificar \n");
    scanf("%d",&id);
    if(gente !=NULL && tam > 0 && id > 0)
    {
        indice=buscarPersona(gente,tam,id);
        if(indice == -1)
        {
            printf("No existen los datos con ese ID\n");
        }
        else
        {
            printf("|--------|-----------|---------|------------|--------------|\n");
            printf("| LEGAJO |  NOMBRE   |   SEXO  |   ALTURA   |   FECHA NAC  |\n");
            printf("| -------|-----------|---------|------------|--------------|\n");
            mostrarPersona(gente[indice],sports,tamD);
            nuevaModificacion=gente[indice];

            printf("Que desea modificar?\n");
            printf("1>NOMBRE\n2>SEXO\n3>ALTURA\n4>FECHA\n");
            fflush(stdin);
            scanf("%d",&opcion);

            switch (opcion)
            {
            case 1:
                printf("Ingrese nombre a modificar ");
                fflush(stdin);
                gets(nuevaModificacion.nombre);
                break;
            case 2:
                printf("Ingrese sexo a modificar ");
                fflush(stdin);
                scanf("%c",&nuevaModificacion.sexo);
                break;
            case 3:
                printf("Ingrese altura a modificar");
                scanf("%f",&nuevaModificacion.altura);
                break;
            case 4:
                printf("Ingrese fecha a modificar dd/mm/aa");
                scanf("%d/%d/%d",&nuevaModificacion.fNac.dia,&nuevaModificacion.fNac.mes,&nuevaModificacion.fNac.anio);
                break;
            }
            printf("Confirma cambio?? ");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma=='s')
            {
                strcpy(gente[indice].nombre,nuevaModificacion.nombre);
                gente[indice].sexo=nuevaModificacion.sexo;
                gente[indice].altura=nuevaModificacion.altura;
                gente[indice].fNac.dia=nuevaModificacion.fNac.dia;
                gente[indice].fNac.mes=nuevaModificacion.fNac.mes;
                gente[indice].fNac.anio=nuevaModificacion.fNac.anio;

                nuevaModificacion=gente[indice];
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

int ordenarPersonaNombre(ePersona gente[],int tam,int criterio)
{
    int error = 1;
    ePersona auxPersona;
    if(gente !=NULL && tam>0 && criterio >= 0 && criterio <=1)
    {
        for(int i=0; i<tam -1; i++)
        {
            for(int j=i+1; j <tam; j++)
            {
                if (strcmp(gente[i].nombre,gente[j].nombre) > 0 && criterio ==0)
                {
                    auxPersona=gente[i];
                    gente[i]=gente[j];
                    gente[j]=auxPersona;
                }
                else if (strcmp(gente[i].nombre,gente[j].nombre) < 0 && criterio ==1)
                {
                    auxPersona=gente[i];
                    gente[i]=gente[j];
                    gente[j]=auxPersona;
                }
            }
        }

        error =0;
    }
    return error;
}

int ordenarPersonaSexoAltura(ePersona gente[],int tam,int criterioSex,int criterioAlt )
{
    int error = 1;
    ePersona auxPersona;
    if(gente !=NULL && tam> 0 && criterioSex >= 0 && criterioSex <=1 && criterioAlt >= 0 && criterioAlt <=1)
    {
        for(int i=0; i<tam -1; i++)
        {
            for(int j=i+1; j <tam; j++)
            {
                if (criterioSex == 0 && gente[i].sexo > gente[j].sexo)
                {
                    auxPersona=gente[i];
                    gente[i]=gente[j];
                    gente[j]=auxPersona;
                }
                else if (criterioSex == 1 && gente[i].sexo < gente[j].sexo)
                {
                    auxPersona=gente[i];
                    gente[i]=gente[j];
                    gente[j]=auxPersona;
                }
                else if (gente[i].sexo == gente[j].sexo && gente[i].altura > gente[j].altura)
                {
                    auxPersona=gente[i];
                    gente[i]=gente[j];
                    gente[j]=auxPersona;
                }
            }
        }
        error =0;
    }
    return error;
}

int harcodearPersonas(ePersona gente[],int tam,int cant)
{
    int retorno=-1;
    if( gente != NULL && tam > 0 && cant <= tam)
    {
        retorno=0;
        for (int i=0; i<cant; i++)
        {
            gente[i].legajo =legajos[i];
            strcpy(gente[i].nombre,nombres[i]);
            gente[i].sexo = sexos[i];
            gente[i].altura = alturas[i];
            gente[i].fNac.dia=dias[i];
            gente[i].fNac.mes=meses[i];
            gente[i].fNac.anio=anios[i];
            gente[i].fNac =fechas[i];
            gente[i].idDeporte=iDdeportes[i];
            gente[i].isEmpty=0;
            retorno++;
        }
    }
    return retorno;
}

void mostrarPersona (ePersona x,eDeporte sports[],int tam )
{
    char descDeporte[20];
   if(cargarDescripcionDeporte(sports,tam,x.idDeporte,descDeporte)==0)
   {
       printf(" %4d     %10s              %c             %3.2f            %02d/%02d/%d           %s\n",x.legajo,x.nombre,x.sexo,x.altura,x.fNac.dia,x.fNac.mes,x.fNac.anio,descDeporte);
   }else
   {
       printf("Problemas\n");
   }
}

