/* Creado por Oscar, Viktor y Sebas.
 Programa en lenguaje C que permita elegir el siguiente cambio de divisas:
 1.-Pesos a Dólares
 2.-Dólares a Euros
 3.-Euros a Pesos*/
#include <stdio.h>
#include <stdlib.h>
//Usamos la función para seleccionar el proceso de cambio de divisas
void menu(int *opcion){
    printf("Seleccione una opcion:\n");
    printf("1. Pesos a Dólares\n");
    printf("2. Dólares a Euros\n");
    printf("3. Euros a Pesos\n");
    scanf("%d", opcion);
}
float Convertir_Pesos_Dolares(){
    float pesos, dolares;
    printf("\nIngrese la cantidad en pesos que quiere convertir a dólares: ");
    scanf("%f", &pesos);
    dolares = pesos*.050;
    return dolares;
}
float Convertir_Dolares_Euros(){
    float dolares,euros;
    printf("\nIngrese la cantidad en dolares que quiere convertir a euros: ");
    scanf("%f", &dolares);
    euros = dolares*.94;
    return euros;
}
float Convertir_Euros_Pesos(){
    float euros,pesos;
    printf("\nIngrese la cantidad en euros que quiere convertir a pesos: ");
    scanf("%f", &euros);
    pesos = euros*21.30;
    return pesos;
}
int main(){
    int opcion;
    float resultado;
    menu(&opcion); //Llamamos la función menu
    switch(opcion){
        case 1:
            resultado = Convertir_Pesos_Dolares();
            printf("La cantidad de %f pesos equivale a: %.2f\n dolares",pesos, resultado);
            break;
        case 2:
            resultado = Convertir_Dolares_Euros();
            printf("La cantidad de %f dolares equivale a: %.2f\n euros", dolares, resultado);
            break;
        case 3:
            resultado = Convertir_Euros_Pesos();
            printf("La cantidad de %f euros equivale a: %.2f\n pesos",euros,resultado);
            break;
        default:
            printf("Opcion incorrecta\n");
            break;
    }
    printf("\nPrograma termiando\n");
    return 0;
}
