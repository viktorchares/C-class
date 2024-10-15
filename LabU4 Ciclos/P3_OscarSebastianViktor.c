/*Programa que genera una sucesión ULAM de un entero positivo. La sucesión ULAM es una sucesión
de números enteros positivos que se genera de la siguiente manera:
Si es par, divídalo entre 2; si es impar, multiplíquelo por 3 y súmele 1.
Obtenga enteros sucesivamente repitiendo el proceso.
Al final, obtendrá el número 1, independientemente del entero inicial. Por ejemplo, cuando el entero
inicial es 26, la secuencia será: 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1.
Se desea contar con algún medio que permita explicar a los alumnos la sucesión de ULAM de cualquier
entero positivo, mostrando:
El listado de valores numéricos que se generan en la sucesión.
El porcentaje de valores pares generados.
El porcentaje de valores impares generados.*/
//Laboratorio 4
#include <stdio.h>
#include <math.h>
int main(){
    int num;
    float p,i,totalpar,totalimpar,total;
    p=0;
    i=1;
    printf("Programa que genera una sucesión ULAM de un entero positivo.\n");
    printf("Ingrese el inicial de la serie (entero positivo): ");
    scanf("%d",&num);
    if (num<1)
    {
        printf("El número debe ser positivo");
    }
    else{
        printf("El listado de números generados es: ");
        printf("%d,",num);
     while (num!=1)
    {
        if (num%2==0)
        {
            num=num/2;
            p++;
            
        }
        else
        {
            num=num*3+1;
            i++;
            
        }
        if (num==1){ 
            printf("%d.",num);
        }
        else{
            printf("%d,",num);
        } 
    } 
    }

    total = p + i;
    totalpar = (p * 100.0) / total;
    totalimpar = (i * 100.0) / total;
    printf("\nEl porcentaje de números pares es: %.2f%%", totalpar);
    printf("\nEl porcentaje de números impares es: %.2f%%", totalimpar);
    
    
    return 0;
}
