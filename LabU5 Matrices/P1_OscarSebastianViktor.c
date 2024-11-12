/*Realice un programa que genere una matriz de m filas, n columnas. Asigne
los valores a la matriz con números aleatorios entre 10 y 30. Como resultado imprima la matriz, el
mayor, el menor y el promedio de los números. Además, indique cuantas veces aparece cada número
en la matriz. Ejemplo:

Creado por Oscar Pelayo Alonso Pérez, Viktor Chargoy Espino y Sebastian Juárez Vilchis
Laboratorio 5
5 de noviembre de 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i,j,contador,nfilas,mcolumnas,busqueda,mayor, menor,suma;
    float promedio;
    int conteo[31];
    srand(time(NULL));
    printf("Programa que pide el tamano de una matriz para generarla aleatoriamente\n");
    printf("Ademas, cuenta sus elementos, obtiene el promedio, numero menor y mayor\n\n");

    printf("Dame el numero de filas de la matriz: ");
    scanf("%d",&nfilas);

    while(nfilas<1){
        printf("\nEl tamano debe ser un entero positivo");
        printf("\nDame el numero de filas de la matriz: ");
        scanf("%d",&nfilas);
    }

    printf("\nDame el numero de columnas de la matriz: ");
    scanf("%d",&mcolumnas);

    while(mcolumnas<1){
        printf("\nEl tamano debe ser un entero positivo");
        printf("\nDame el numero de columnas de la matriz: ");
        scanf("%d",&mcolumnas);
    }
   
    int a[nfilas][mcolumnas];
    //generar la matriz
    for(i=0;i<nfilas; i++){
        for(j=0; j<mcolumnas ; j++){
            a[i][j]=rand()%21 +10;
        }
    }

    //imprimir la matriz
    printf("Se imprime la matriz generada\n");
    for(i=0;i<nfilas; i++){
        for(j=0; j<mcolumnas ; j++){
           printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    //dejamos contadores en 0
    for(i=0;i<31;i++)conteo[i]=0;

    //contar, buscar menor, mayor, promedio y contar
    promedio=0;
    suma=0;
    menor=a[0][0];
    mayor=a[0][0];

    for(i=0;i<nfilas; i++){
        for(j=0; j<mcolumnas ; j++){
            suma+=a[i][j];
            conteo[a[i][j]]++;

            if(a[i][j]<menor)menor=a[i][j];
            if(a[i][j]>mayor)mayor=a[i][j];

        }
    }
    promedio=(float)suma/((float)(nfilas*mcolumnas));

    printf("\nEl menor de los numeros generados es: %d",menor);
    printf("\nEl mayor es: %i",mayor);
    printf("\nY el promedio de los numeros generados es: %.4f\n",promedio);

    printf("\nCada numero aparece este numero de veces:\n");
    for(i=10;i<31;i++){
        if(conteo[i]>0){
            printf("\nEl numero %d aparece %d veces",i,conteo[i]);
        }
    }
    
    return 0;
    
}