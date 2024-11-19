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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenamientoAscendente(size_t tam, int a[]){//recibe argumentos por referencia
    int i=0,j=0,indiceDelMinimo=0,auxSwap=0;
    //ordenamiento burbuja optimizado ascendente 
    for(i=0;i<tam;i++){
        indiceDelMinimo=i;
        for(j=i+1;j<tam;j++){
            if(a[j]<a[indiceDelMinimo]){
                indiceDelMinimo=j;
            }
        }
        if(indiceDelMinimo!=i){
            auxSwap=a[i];
            a[i]=a[indiceDelMinimo];
            a[indiceDelMinimo]=auxSwap;
        }
    }

    printf("\n\nNumeros ordenados de manera ascendente: \n");
    for(i=0;i<tam;i++){
        printf("%d ",a[i]);
    }

    return;
}

void ordenamientoDescendente(size_t tam, int a[]){//recibe argumentos por referencia
    int i=0,j=0,indiceDelMaximo=0,auxSwap=0;
    //ordenamiento burbuja optimizado descendente
    for(i=0;i<tam;i++){
        indiceDelMaximo=i;
        for(j=i+1;j<tam;j++){
            if(a[j]>a[indiceDelMaximo]){
                indiceDelMaximo=j;
            }
        }
        if(indiceDelMaximo!=i){
            auxSwap=a[i];
            a[i]=a[indiceDelMaximo];
            a[indiceDelMaximo]=auxSwap;
        }
    }

    printf("\n\nNumeros ordenados de manera descendente: \n");
    for(i=0;i<tam;i++){
        printf("%d ",a[i]);
    }

    return;
}

int funcionOpcion(){
    int solicitud;

     printf("\n\nIngresa el ordenamiento deseado: 1 ascendente y 2 descendente: ");
    scanf("%d",&solicitud);

    while(solicitud!=1 && solicitud!=2){
        printf("\nDebes ingresar 1 o 2");
        printf("\nIngresa el ordenamiento deseado: 1 ascendente y 2 descendente: ");
        scanf("%d",&solicitud);
    }

    return solicitud;
}



int main(){
    int tamano, opcion,i,j;
    srand(time(NULL));
    printf("Programa que ordena la cantidad de numeros elegida por el usuario en forma ascendente o descendente\n");

    printf("Ingresa la cantidad de numeros: ");
    scanf("%d",&tamano);

    while(tamano<1){
        printf("\nEl tamano debe ser un entero positivo");
        printf("\nIngresa la cantidad de numeros: ");
        scanf("%d",&tamano);
    }

    int a[tamano];
    int aOriginal [tamano];
    //generar los numeros e ir imprimiendo
    printf("\nEl arreglo original es: \n");
    for(i=0;i<tamano;i++){
        a[i]=(rand()%50) +1;
        aOriginal[i]=a[i];
        printf("%d ",a[i]);
    }

    opcion=funcionOpcion();

    

    if(opcion==1){
        ordenamientoAscendente(tamano,a);
    }else if(opcion==2){
        ordenamientoDescendente(tamano,a);
    }else{//
        printf("\nFallo en el flujo del programa\n");
    }
   
   

    
    return 0;
    
}