#include "fecha.h"

#ifndef DATASTORE_H_INCLUDED
#define DATASTORE_H_INCLUDED




char nombres[10][20]={
    "Juan",
    "Analia",
    "Aldo",
    "Magali",
    "Miguel",
    "Esteban",
    "Valentina",
    "Gaston",
    "Gustavo",
    "Irene"
};
char sexos[10]={'m','f','m','f','m','m','f','m','m','f'};
int legajos[10]={20000,20001,20002,20003,20004,20005,20006,20007,20008,20009};
float alturas[10]={1.78, 1.55, 1.88, 1.77, 1.66, 1.22, 1.28, 1.44, 1.99, 1.15};
int dias[10]={15,10,18,65,85,84,65,97,34,19};
int meses[10]={1,12,8,6,4,3,4,7,5,3};
int anios[10]={2000,1199,4555,1224,1994,9658,4512,7777,1964,1877};
int iDdeportes[10]={1000,1001,1002,1003,1004,1005,1006,1007,1008,1009};


eFecha fechas[10]={

        {13,12,54},
        {14,12,44},
        {15,12,52},
        {16,12,12},
        {16,12,18},
        {16,12,59},
        {16,12,77},
        {16,12,82},
        {16,19,14},
        {16,17,55}
};


#endif // DATASTORE_H_INCLUDED


