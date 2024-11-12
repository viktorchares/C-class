/*Programa que genera una matriz de m filas, n columnas con
números aleatorios entre 1 y 100. El programa solicita al usuario el tamaño de la matriz. Ordenar filas y columnas de la
matriz. Como salida visualiza: la matriz inicial, y las matrices ordenadas por filas y
columnas*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));
    int f,c,i,j,k,aux;
    printf("Ingrese el tamaño de la matriz: ");
    scanf("%d,%d",&f,&c);
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
    printf("El programa ha finalizado")
  
    return 0;
}

    


