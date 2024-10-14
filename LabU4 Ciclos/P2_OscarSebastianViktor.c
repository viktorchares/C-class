/*
Programa en C que pregunte cuantos números se van a introducir,
pida esos números (reales, rango: 0 a 150), no debe permitirse valores fuera del rango. Como
resultado, imprima el mayor, el menor y el promedio. Este programa debe ejecutarse al menos una vez
y para volver a pedir otro valor de n, se debe introducir la contraseña: 2024, de lo contrario no podrá
ejecutarse otra vez el programa, indicando que la contraseña es incorrecta y finalizará
Creado por Oscar Pelayo Alonso Pérez, Viktor Chargoy Espino y Sebastian Juárez Vilchis
Laboratorio 3
14 de octubre de 2024
*/

#include <stdio.h>
#include <stdlib.h>
int main() {
  int n, i,contrasena;
  float num, mayor, menor, promedio, suma = 0;

    contrasena=2024;
  do {
    printf("Ingrese la cantidad de números: ");
    scanf("%d", &n);
    if (n <= 0) {
      printf("Debe ingresar al menos un número.\n");
      continue;
    }
    // Inicializar mayor y menor con el primer número
    printf("Ingrese el número 1: ");
    scanf("%f", &num);
    if (num < 0 || num > 150) {
      printf("El número debe estar entre 0 y 150.\n");
      continue;
    }
    mayor = num;
    menor = num;
    suma = num;
    // Leer los demás números
    for (i = 2; i <= n; i++) {
      printf("Ingrese el número %d: ", i);
      scanf("%f", &num);
      if (num < 0 || num > 150) {
        printf("El número debe estar entre 0 y 150.\n");
        i--; // Reducir el contador para volver a solicitar el número
        continue;
      }
      // Actualizar mayor y menor
      if (num > mayor) {
        mayor = num;
      }
      if (num < menor) {
        menor = num;
      }
      suma += num;
    }
    promedio = suma / n;
    printf("El mayor número es: %.2f\n", mayor);
    printf("El menor número es: %.2f\n", menor);
    printf("El promedio de los números es: %.2f\n", promedio);
    printf("Ingrese la contraseña numerica para ejecutar nuevamente (2024 para continuar): ");
    scanf("%d", &contrasena);
  } while (contrasena == 2024 );
  printf("Contraseña incorrecta. Finalizando el programa.\n");
  return 0;
}