/*
Programa en C que imprime una tabla de multiplicar de n*m
Creado por Oscar Pelayo Alonso Pérez, Viktor Chargoy Espino y Sebastian Juárez Vilchis
Laboratorio 4
14 de octubre de 2024
*/

#include <stdio.h>

int main() {
  int n, m, i,j, mult;
  float num, mayor, menor, promedio, suma = 0;

  printf("Programa que imprime la tabla de multiplicar de n columnas y m filas");
  printf("se sugiere que n<m por espacio de terminal y que n<40");
  printf("\nIngresa n: ");
  scanf("%d",&n);
  printf("\nIngresa m: ");
  scanf("%d",&m);

  while(n<1||m<1){
    printf("Ingresa numeros validos");
    printf("\nIngresa n: ");
    scanf("%d",&n);
    printf("\nIngresa m: ");
    scanf("%d",&m);

  }

  printf("\n     ");
  for(i=1;i<=n;i++){
    printf("%d  ", i);
    if(i<10)printf(" ");
    if(i<100)printf(" ");
  }

printf("\n");
printf("**   ");
  for(i=1;i<=n;i++){
    printf("**   ");
  }
printf("\n");

  for(i=1;i<=m;i++){
    printf("%d* ",i);
    if(i<10)printf(" ");
    if(i<100)printf(" ");
    for(j=1;j<=n;j++){
        mult=i*j;
        
        printf("%d  ",mult);
        if(mult<10)printf(" ");
        if(mult<100)printf(" ");
    }

    printf("\n");
  }

   
 // printf("Finaliza el programa.\n");
  return 0;
}