/*Problema 1. Realizar un programa en lenguaje C que permita elegir en ordenar números en forma ascendente y descendente.
▪ La cantidad de números a ordenar la elige el usuario.
▪ Los números son generados aleatoriamente en el rango de 1 a 50.
▪ El ordenamiento de los números se debe realizar utilizando algún método de ordenamiento visto en clase.
▪ Utilice subrutinas para el ordenamiento de los números y para elegir la opción de impresión ascendente o descendente.
En la impresión de salida, debe mostrarse:
▪ La lista original de los números generados.
▪ La lista ordenada de los números en forma solicitada.

Creado por Oscar Pelayo Alonso Pérez, Viktor Chargoy Espino y Sebastian Juárez Vilchis
Laboratorio 6
10 de noviembre de 2024
*/

void ordenamientoAscendente(int tam){
    int i=0;
    int a[tam];
    //generar los numeros e ir imprimiendo
    for(i=0;i<tam;i++){
        a[i]=(rand()%50) +1;
    }

    //ordenamiento burbuja ascendente 
}

void ordenamientoDescendente(int tam){

}
int funcionOpcion(){
    int solicitud;

     printf("\nIngresa el ordenamiento deseado: 1 ascendente y 2 descendente: ");
    scanf("%d",&solicitud);

    while(solicitud!=1 && solicitud!=2){
        printf("\nDebes ingresar 1 o 2");
        printf("\nIngresa el ordenamiento deseado: 1 ascendente y 2 descendente: ");
        scanf("%d",&solicitud);
    }

    return solicitud;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int tamano, opcion,i,j;
    srand(time(NULL));
    printf("Programa que ordena la cantidad de numeros elegida por el usuario en forma ascendente o descendente\n");

    printf("Ingresa la cantidad de numeros: ");
    scanf("%d",&tamano);

    while(tamano<1){
        printf("\nEl tamano debe ser un entero positivo");
        printf("Ingresa la cantidad de numeros: ");
        scanf("%d",&tamano);
    }
    opcion=funcionOpcion();


    if(opcion==1){
        ordenamientoAscendente(tamano);
    }else if(opcion==2){
        ordenamientoDescendente(tamano);
    }else{//
        printf("\nFallo en el flujo del programa\n");
    }
   
   

    
    return 0;
    
}