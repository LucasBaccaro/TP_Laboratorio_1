#include "fecha.h"
#include "deportes.h"

#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED


typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float altura;
    eFecha fNac;
    int isEmpty;
    int idDeporte;
} ePersona;

int inicializarPersona(ePersona gente[],int tam);
int buscarLibre(ePersona gente[],int tam);
int altaPersona(ePersona gente[],int tam,eDeporte sports[],int tamD,int legajo);
int bajaPersona(ePersona gente[],int tam,eDeporte sports[],int tamD);
int buscarPersona(ePersona gente[],int tam,int legajo);
int modificarPersona (ePersona gente[],int tam,eDeporte sports[],int tamD);
int ordenarPersonaNombre(ePersona gente[],int tam,int criterio);
int ordenarPersonaSexo (ePersona gente[],int tam,int criterio);
int ordenarPersonaSexoAltura(ePersona gente[],int tam,int criterioSex,int criterioAlt );
void mostrarPersona (ePersona x,eDeporte sports[],int tam );
int mostrarPersonas (ePersona gente[],int tam, eDeporte sports[],int tamD);
int harcodearPersonas(ePersona gente[],int tam,int cant);
#endif // PERSONA_H_INCLUDED
#define ASC 0
#define DEC 1
