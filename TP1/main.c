#include <stdio.h>
#include <stdlib.h>
#include "Baccaro.h"
int main()
{
    char seguir= 's';
    int num1=0;
    int num2=0;
    int resultadoSuma;
    int resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    long int resultadoFactorialA;
    long int resultadoFactorialB;
    int banderaPrimerNumero=0;
    int banderaSegundoNumero=0;
    int banderaCalculos=0;
    while(seguir=='s')
    {
        switch(menu(num1,num2))
        {
        case 1:
            printf("Ingrese el primer numero:(A)  ");
            scanf("%d",&num1);
            banderaPrimerNumero=1;
            break;
        case 2:
            if (banderaPrimerNumero==1)
            {
                printf("ingrese el segundo numero:(B)  ");
                scanf("%d",&num2);
                banderaSegundoNumero=1;
            }
            else
            {
                printf ("STOP! Ingresa el primer numero para continuar\n" );
                system("pause");
            }
            break;
        case 3:
            if (banderaPrimerNumero==1 && banderaSegundoNumero==1)
            {
                printf ("Calculos realizados con exito!!\n");
                system("pause");
                resultadoSuma=suma(num1,num2);
                resultadoResta=resta(num1,num2);
                resultadoDivision=division(num1,num2);
                resultadoMultiplicacion=multiplicacion(num1,num2);
                resultadoFactorialA=factorial(num1);
                resultadoFactorialB=factorial(num2);
                banderaCalculos=1;
            }
            else
            {
                printf("STOP! Para resolver calculos,debes ingresar los numeros\n");
                system("pause");
            }
            break;
        case 4:
            if(banderaPrimerNumero==1 && banderaSegundoNumero==1 && banderaCalculos==1)
            {
                printf("El resultado de la suma es %d\n",resultadoSuma);
                printf("El resultado de la resta es %d\n",resultadoResta);
                if(num2==0)
                {
                    printf("No se puede dividir por 0\n");
                }
                else
                {
                    resultadoDivision=division(num1,num2);
                    printf("El resultado de la division es %.2f\n",resultadoDivision);
                }

                printf("El resultado de la multiplicacion es %.f\n",resultadoMultiplicacion);
                printf("El resultado de factorial es %ld \n",resultadoFactorialA);
                printf("El resultado de factorial es %ld \n",resultadoFactorialB);
                banderaPrimerNumero=0;
                banderaSegundoNumero=0;
                banderaCalculos=0;
                system("pause");
            }
            else
            {
                printf("STOP! Para ver los resultados,primero debes RESOLVERLOS! con la opcion 3\n");
                system("pause");
            }

            break;
        case 5:

            printf("Gracias por usar el programa  ");
            seguir='n';
            break;
        }
    }
    return 0;
}







