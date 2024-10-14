/*Programa en C que nos indica si un número entero, leído de teclado, tiene
1, 2, 3, o más de 3 dígitos. Considerar valores negativos
Creado por Oscar Pelayo Alonso Pérez, Viktor Chargoy Espino y Sebastian Juárez Vilchis
Laboratorio 3
6 de octubre de 2024
*/

#include <stdio.h>

int main(){
    int num;
    printf("Programa que lee un número e indica la cantidad de dígitos que tiene.\n");
    printf("Ingrese un número (entero): ");
    scanf("%d",&num);
    if(num>999 || num<-999){
        printf("El número tiene más de 3 dígitos");
    }
    else if (num<=999 && num>=100)
    {
        printf("El número tiene 3 dígitos");
    }
    else if (num>=-999 && num<=-100)
    {
       printf("El número tiene 3 dígitos");  
    }
    else if (num<=99 && num>=10)
    {
        printf("El número tiene 2 dígitos");
    }
    else if (num>=-99 && num<=-10)
    {
        printf("El número tiene 2 dígitos");
    }
    else
    {
        printf("El número tiene un dígito");
    }

    return 0;
}
