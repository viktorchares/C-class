/* 
Programa que calcula la letra para una calificacion entre 0 y 100
Creado por Oscar Pelayo Alonso Pérez, Viktor Chargoy Espino y Sebastian Juárez Vilchis
Laboratorio 3
8 de octubre de 2024
*/
#include <stdio.h>

int main() {
    float calificacion;

  //menú de opciones
    printf("Introduce una calificación entre 0 y 100: ");
    scanf("%f", &calificacion);

  //Procedimiento
    if (calificacion < 0 || calificacion > 100) {
        printf("Error: La calificación debe estar entre 0 y 100.\n");
    } else {
        // Determinar la calificación en letra
        if (calificacion >= 90) {
            printf("Calificación: A\n");
        } else if (calificacion >= 80) {
            printf("Calificación: B\n");
        } else if (calificacion >= 70) {
            printf("Calificación: C\n");
        } else {
            printf("Calificación: D\n");
        }
    }
    return 0;
    }
  