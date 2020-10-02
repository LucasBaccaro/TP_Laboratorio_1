#include <stdio.h>
#include <stdlib.h>
#include "Baccaro.h"
//MENU+


int menu(int num1,int num2)
{
    int opcion;
    system("cls");
    printf("***Menu de opciones***\n\n");
    printf("1. Ingresar 1er operando (A=%d) \n\n",num1);
    printf("2. Ingresar 2do operando (B=%d)\n\n",num2);
    printf("3. Calcular todas las operaciones \n A) Calcular la suma (A+B)\n B) Calcular la resta (A-B)\n C) Calcular la division (A/B)\n D) Calcular la multiplicacion (A*B)\n E) Calcular el factorial (A!) \n\n");
    printf("4. Mostrar resultados\n\n");
    printf(" A) El resultado de A+B es: r\n B) El resultado de A-B es: r\n C) El resultado de A/B es: r o No es posible dividir por cero\n D) El resultado de A*B es: r\n E) El factorial de A es: r1 y El factorial de B es: r2\n\n");
    printf("5 Salir\n\n");
    printf(">Ingrese opcion a realizar.");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
//SUMA
int suma(int num1, int num2)
{
    int resultado=num1+num2;
    return resultado;
}
//RESTA
int resta(int num1, int num2)
{
    int resultado=num1-num2;
    return resultado;
}
//DIVISION
float division(float num1,float num2)
{
    float resultado=num1/num2;
    return resultado;
}
//MULTIPLICACION
int multiplicacion(int num1,int num2)
{
    int resultado=num1*num2;
    return resultado;
}

//FACTORIAL
long int factorial(int num)
{
    int fact=1;

    for (int i= 1; i <= num; i++)
    {
        fact=fact * i;
    }
    return fact;
}

