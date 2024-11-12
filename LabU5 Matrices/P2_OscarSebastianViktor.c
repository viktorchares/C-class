/*Programa que genera una matriz de m filas, n columnas con
números aleatorios entre 1 y 100. El programa solicita al usuario el tamaño de la matriz. Ordenar filas y columnas de la
matriz. Como salida visualiza: la matriz inicial, y las matrices ordenadas por filas y
columnas

Creado por Oscar Pelayo Alonso Pérez, Viktor Chargoy Espino y Sebastian Juárez Vilchis
Laboratorio 5
5 de noviembre de 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int f,c,i,j,k,aux;
    printf("Programa que pide el tamano de una matriz para generarla aleatoriamente, ordenando por filas y columnas\n");
    printf("Ingrese el tamaño de la matriz: \n");
    //scanf("%d,%d",&f,&c);

    printf("Ingrese el numero de filas de la matriz: ");
    scanf("%d",&f);

    while(f<1){
        printf("\nEl tamano debe ser un entero positivo");
        printf("\nIngrese el numero de filas de la matriz: ");
        scanf("%d",&f);
    }

    printf("\nIngrese el numero de columnas de la matriz: ");
    scanf("%d",&c);

    while(c<1){
        printf("\nEl tamano debe ser un entero positivo");
        printf("\nIngrese el numero de columnas de la matriz: ");
        scanf("%d",&c);
    }

    int matriz[f][c];
    for(i=0;i<f;i++){
        for(j=0;j<c;j++){
            matriz[i][j]=rand()%100+1;
        }
    }
    printf("Matriz inicial: \n");
    for(i=0;i<f;i++){
        for(j=0;j<c;j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }

    //ordenar filas por metodo burbuja
    printf("Matriz ordenada por filas:\n");
    for (i=0;i<f;i++) {
        for (j=0;j<c-1;j++) {
            for (k=j+1;k<c;k++) {
                if (matriz[i][j]>matriz[i][k]) {
                    aux=matriz[i][j];
                    matriz[i][j]=matriz[i][k];
                    matriz[i][k]=aux;
                }
            }
        }
    }
     for (i=0;i<f;i++) {
        for (j=0;j<c;j++) {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
     printf("Matriz ordenada por columnas:\n");
    for (j=0;j<c;j++) { 
        for (i=0;i<f-1;i++) {
            for (k=i+1;k<f;k++) {
                if (matriz[i][j]>matriz[k][j]) {
                    aux=matriz[i][j];
                    matriz[i][j]=matriz[k][j];
                    matriz[k][j]=aux;
                }
            }
        }
    }
    for (i=0;i<f;i++) {
        for (j=0;j<c;j++) {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("El programa ha finalizado");
  
    return 0;
}

    


