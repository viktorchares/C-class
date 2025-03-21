/* 
 Programa en lenguaje C que permite elegir el siguiente cambio de divisas:
 1.- Pesos a Dólares
 2.- Dólares a Euros
 3.- Euros a Pesos

 Creado por Oscar Pelayo Alonso Pérez, Viktor Chargoy Espino y Sebastian Juárez Vilchis
Laboratorio 6
10 de noviembre de 2024
*/
#include <stdio.h>
#include <stdlib.h>
//Usamos la función para seleccionar el proceso de cambio de divisas
void menu(int *opcion) {
    printf("Seleccione una opcion:\n");
    printf("1. Pesos a Dólares\n");
    printf("2. Dólares a Euros\n");
    printf("3. Euros a Pesos\n");
    scanf("%d", opcion);

    while(*opcion <1 || 3 < *opcion){
        printf("Debes ingresar el valor 1, 2 o el 3\n");
        printf("Seleccione una opcion:\n");
        printf("1. Pesos a Dólares\n");
        printf("2. Dólares a Euros\n");
        printf("3. Euros a Pesos\n");
        scanf("%d", opcion);
    }
}

float comprobarPositivos(float entrada){
    while(entrada<0){
        printf("\nError, debes ingresar un entero positivo\n");
        printf("Ingresa la cantidad: ");
        scanf("%f",&entrada);
    }
    return entrada;
}
float Convertir_Pesos_Dolares() {
    float pesos, dolares;
    printf("\nIngrese la cantidad en pesos que quiere convertir a dólares: ");
    scanf("%f",&pesos);
    pesos=comprobarPositivos(pesos);
    dolares = pesos*0.050;
    return dolares;
}
float Convertir_Dolares_Euros() {
    float dolares, euros;
    printf("\nIngrese la cantidad en dólares que quiere convertir a euros: ");
    scanf("%f",&dolares);
    dolares=comprobarPositivos(dolares);
    euros = dolares*0.94;
    return euros;
}
float Convertir_Euros_Pesos() {
    float euros, pesos;
    printf("\nIngrese la cantidad en euros que quiere convertir a pesos: ");
    scanf("%f",&euros);
    euros=comprobarPositivos(euros);
    pesos = euros*21.30;
    return pesos;
}
int main() {
    int opcion;
    float resultado;
    menu(&opcion); // Llamamos la función menu
    switch(opcion) {
        case 1: {
            resultado = Convertir_Pesos_Dolares();
            printf("La cantidad ingresada: %.2f pesos\n", resultado / 0.050); //Esto se hacae para poder sacar la cantidad sin convertirla
            printf("Equivale a: %.2f dólares\n", resultado);
            break;
        }
        case 2: {
            resultado = Convertir_Dolares_Euros();
            printf("La cantidad ingresada: %.2f dólares\n", resultado / 0.94);
            printf("Equivale a: %.2f euros\n", resultado);
            break;
        }
        case 3: {
            resultado = Convertir_Euros_Pesos();
            printf("La cantidad ingresada: %.2f euros\n", resultado / 21.30); 
            printf("Equivale a: %.2f pesos\n", resultado);
            break;
        }
        default:
            printf("Opción incorrecta\n");
            break;
    }
    printf("\nPrograma terminado\n");
    return 0;
}
