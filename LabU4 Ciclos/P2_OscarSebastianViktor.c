/*
Programa en C que pregunte cuantos números se van a introducir,
pida esos números (reales, rango: 0 a 150), no debe permitirse valores fuera del rango. Como
resultado, imprima el mayor, el menor y el promedio. Este programa debe ejecutarse al menos una vez
y para volver a pedir otro valor de n, se debe introducir la contraseña: 2024, de lo contrario no podrá
ejecutarse otra vez el programa, indicando que la contraseña es incorrecta y finalizará
Creado por Oscar Pelayo Alonso Pérez, Viktor Chargoy Espino y Sebastian Juárez Vilchis
Laboratorio 4
14 de octubre de 2024
*/

#include <stdio.h>

int main() {
  int n, i,contrasena;
  float numero, mayor, menor, promedio, suma = 0;

    contrasena=2024;
  do {
    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &n);
    while(n <= 0){
      printf("Debe ingresar al menos un numero.\n");
      printf("Ingrese la cantidad de numeros: ");
      scanf("%d", &n);
    }
    
    printf("Ingrese el numero 1: ");
    scanf("%f", &numero);
    while (numero < 0 || numero > 150) {
      printf("\nError, el numero debe estar entre 0 y 150\n");
      printf("Ingrese el numero 1: ");
      scanf("%f", &numero);
    }
    
    mayor=numero;
    menor=numero;
    suma=numero;
    
    for (i = 2; i <= n; i++) {
      printf("\nIngrese el número %d: ", i);
      scanf("%f", &numero);

      while (numero < 0 || numero > 150) {
          printf("\nError, el numero debe estar entre 0 y 150\n");
          printf("\nIngrese el número %d: ", i);
          scanf("%f", &numero);
     }
      

      if (numero > mayor) {
        mayor=numero;
      }
      if (numero < menor) {
        menor=numero;
      }
      suma+=numero;
    }

    promedio=suma/n;
    printf("El mayor numero es: %.2f\n", mayor);
    printf("El menor numero es: %.2f\n", menor);
    printf("El promedio de los numeros es: %.2f\n", promedio);

    printf("Ingrese la contraseña numerica para ejecutar nuevamente: ");
    scanf("%d", &contrasena);

  } while (contrasena==2024);
  printf("Contraseña incorrecta, finaliza el programa\n");
  return 0;
}