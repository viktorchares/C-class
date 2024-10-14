/* 
Programa que calcula el seno, coseno o tangente 
Creado por Oscar Pelayo Alonso Pérez, Viktor Chargoy Espino y Sebastian Juárez Vilchis
Laboratorio 3
8 de octubre de 2024
*/

#define M_PI 3.14159265358979323846
#include <stdio.h>
#include <math.h>

int main(){
    int opcion;
    float  angulo, resultado;
    printf("Programa que calcula el seno, coseno o tangente\n");

    printf("Introduce el angulo: ");
    scanf("%f",&angulo);
    angulo= angulo * M_PI /180;
    printf("\nIntroduce el numero de la opcion a calcular; 1. Seno, 2. Coseno, 3. Tangente: ");
    scanf("%d",&opcion);

    switch (opcion)
    {
    case 1:
        resultado=sin(angulo);
        printf("\nEl seno del angulo es: %.6f", resultado);
        break;

    case 2:
        resultado=cos(angulo);
        printf("\nEl coseno del angulo es: %.6f", resultado);
        break;

    case 3:
        resultado=tan(angulo);
        if(resultado <= -22877332.000000 ){
            printf("\nLa operacion es indefinida, division entre 0");
           break;
        }

        printf("\nLa tangente del angulo es: %.6f", resultado);
        break;
    
    default:
        printf("\nOpcion invalida");
        break;
    }

    printf("\nFinaliza programa");
    

    return 0;
    
}