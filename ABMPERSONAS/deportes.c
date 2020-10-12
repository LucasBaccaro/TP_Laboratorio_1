#include <stdio.h>
#include <string.h>
#include "deportes.h"


void mostrarDeportes(eDeporte sports[],int tam)
{
    printf("****Lista de deportes****\n\n");
    printf("|--------|-------------------|\n");
    printf("| ID          DESCRIPCION    |\n");
    printf("| -------|-------------------|\n");
    for(int i=0; i<tam; i++)
    {
        mostrarDeporte(sports[i]);
    }
    printf("\n\n");

}

void mostrarDeporte(eDeporte x)
{
    printf("%d        %s\n",x.id,x.descripcion);
}

int cargarDescripcionDeporte (eDeporte sports[],int tam, int id,char descripcion[])
{
    int error =1;
    if(sports!=NULL && tam > 0 && id > 0 && descripcion != NULL)
    {
        for(int i=0; i < tam ; i++)
        {
            if(sports[i].id == id)
            {
                strcpy(descripcion,sports[i].descripcion);
                error = 0;
                break;
            }
        }
    }
    return error;
}

int validarIdDeporte(eDeporte sports[],int tam, int id)
{
    int esValido = 0;
    for (int i=0; i < tam; i++)
    {
        if(sports[i].id == id)
        {
            esValido=1;
            break;
        }
    }
    return esValido;
}
