#ifndef DEPORTES_H_INCLUDED
#define DEPORTES_H_INCLUDED


typedef struct{
int id;
char descripcion[20];

}eDeporte;


#endif // DEPORTES_H_INCLUDED
void mostrarDeporte(eDeporte x);
void mostrarDeportes(eDeporte sports[],int tam);
int cargarDescripcionDeporte (eDeporte sports[],int tam, int id,char descripcion[]);
