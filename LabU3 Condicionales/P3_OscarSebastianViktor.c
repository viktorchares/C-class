/* 
Programa al cual se le proporciona la hora HH:MM:SS y nos calcula
la hora dentro de un segundo. Leeremos las horas, minutos y segundos como números enteros
(para la solución, usa estructuras anidadas)
Creado por Oscar Pelayo Alonso Pérez, Viktor Chargoy Espino y Sebastian Juárez Vilchis
Laboratorio 3
7 de octubre de 2024
*/
#include <stdio.h>

int main(){
    int horas, minutos, segundos;
    printf("Programa que calcula la hora un segundo despues de la ingresada\n");
    printf("Introduce la hora HH: ");
    scanf("%d",&horas);
        printf("\nIntroduce los minutos MM: ");
    scanf("%d",&minutos);
        printf("\nIntroduce los segundos: ");
    scanf("%d",&segundos);

    segundos++;

    if(segundos>=60){
        minutos+=segundos/60;
        segundos%=60;
        if(minutos>=60){
        horas+=minutos/60;
        minutos%=60;
            if(horas>=24){
            horas%=24;
            }
        }else if(horas>=24){
        horas%=24;
        }
    }else if(minutos>=60){
        horas+=minutos/60;
        minutos%=60;
        if(horas>=24){
        horas%=24;
        }
    }else if(horas>=24){
        horas%=24;
    }
    
    printf("\nLa hora un segundo despues es: ");
    if(horas<10)printf(" 0%d : ",horas);
    else printf(" %d : ",horas);

    if(minutos<10)printf(" 0%d : ",minutos);
    else printf(" %d : ",minutos);

    if(segundos<10)printf(" 0%d ",segundos);
    else printf(" %d ",segundos);


    printf("\nFinaliza programa");
    

    return 0;
    
}