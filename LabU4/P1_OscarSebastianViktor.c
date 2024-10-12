/*
Programa en C que imprime todos los números primos menores o iguales a n, su cantidad y suma
Con 1<=n<=200
Creado por Oscar Pelayo Alonso Pérez, Viktor Chargoy Espino y Sebastian Juárez Vilchis
Laboratorio 3
11 de octubre de 2024
*/

#include <stdio.h>
#include <stdbool.h>

int main(){
    int num,sumaPrimos,cantidadPrimos,i,candidatoPrimo;
    bool esPrimo=1;
    printf("Programa en C que imprime todos los números primos menores o iguales a n, su cantidad y suma\n");
    printf("Ingrese un número (entero en el rango 1<=n<=200): ");
    scanf("%d",&num);


    while(num<1||200<num){
        printf("Error, fuera de rango");
        printf("Ingrese un número (entero en el rango 1<=n<=200): ");
        scanf("%d",&num);
    }
        sumaPrimos=0;
        cantidadPrimos=0;

        printf("\nLa lista de primos es: ");
    for(candidatoPrimo=2;candidatoPrimo<=num;candidatoPrimo++){
        //comprobar si es primo, recorriendo todos los numeros primos o compuestos menores a el y revisando que no sea divisible
        esPrimo=1;
        for(i=2;i<candidatoPrimo;i++){
            if(candidatoPrimo%i==0){
                esPrimo=0;
                break;
            }
        }

        if(esPrimo){
            printf(" %d,", candidatoPrimo);
            sumaPrimos+=candidatoPrimo;
            cantidadPrimos++;
        }

    }

    printf("/nHay %d primos menores o iguales a %d/n", cantidadPrimos, num);
    printf("Y su suma equivale a: %d\n",sumaPrimos);
    

    return 0;
}
