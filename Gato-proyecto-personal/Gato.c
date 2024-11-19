/* 
Esta es la cabecera
Programa para jugar gato
Creado por Viktor Chargoy Espino 183003
Algoritmos y programación 7 a.m. Martes y Jueves con Ever Juárez
10 de septiembre de 2024 inicio
*/

#include <stdio.h>
#include <stdbool.h>


bool VerificarVictoria(long long int casillasOcupadas){
    if((casillasOcupadas%(2*3*5)==0||casillasOcupadas%(7*11*13)==0||casillasOcupadas%(17*23*29)==0)  ||(casillasOcupadas%(2*7*17)==0||casillasOcupadas%(3*11*23)==0||casillasOcupadas%(5*13*29)==0)  ||(casillasOcupadas%(2*11*29)==0)||casillasOcupadas%(5*11*17)==0)
    {
        return 1;
    }
    return 0;
}

void ImprimirTablero(size_t size, char charTablero[]){
printf("%c | %c | %c\n",charTablero[0],charTablero[1],charTablero[2]);
    printf("-------------\n");
    printf("%c | %c | %c\n",charTablero[3],charTablero[4],charTablero[5]);
    printf("-------------\n");
    printf("%c | %c | %c\n",charTablero[6],charTablero[7],charTablero[8]);
    printf("-------------\n");

}

int leerNumeroValido(size_t size,long long int identificadorTablero[],long long int casillasOcupadas,bool jugador){
    long long int entrada=-1;
    long long int contadorErrores=0;
    char letraJugador='s';
    if(jugador)letraJugador='X';
    else letraJugador='O';
    while(1){
        printf("Elige el numero de la casilla que quieres tirar y este disponible para el jugador %c\n",letraJugador);
        scanf("%lld",&entrada);

        if(entrada>=0&& entrada<=8){
            if(casillasOcupadas%identificadorTablero[entrada]!=0){
                break;
            }
        }else{
            printf("Entrada invalida\n");
        }

        if(contadorErrores>7&&entrada==-5){
            printf("Hasta luego, espero lo hayas disfrutado");
            break;
        }
        contadorErrores++;
        if(contadorErrores%7==0){
            printf("Dame bien el dato, o si ya te cansaste y no quieres jugar escribe un -5\n");
        }
    }

    return entrada;
}

int main (){
long long int identificadorTablero[9]={2,3,5,7,11,13,17,23,29}; //vamos a ver las casillas ocupadas mediante numeros primos
char charTablero[9]={'0','1','2','3','4','5','6','7','8'};
long long int casillasOcupadas=1;
long long int casillasJugador[2]={1,1};
long long int turno=0,entrada=-1;
bool gano=0;
ImprimirTablero(9,charTablero);
printf("Este es un juego de gato de 2 jugadores: ");
for(turno=0;turno<9&&!gano;turno++){
    entrada=leerNumeroValido(9,identificadorTablero,casillasOcupadas,(turno%2==0));
    if(entrada==-5)break;
    casillasOcupadas*=identificadorTablero[entrada];

    if(turno%2==0){
        casillasJugador[0]*=identificadorTablero[entrada];
        charTablero[entrada]='X';
            gano=VerificarVictoria(casillasJugador[0]);
            if(gano){
                printf("Gana el jugador A\n");
                break;
            }

    }else{
        casillasJugador[1]*=identificadorTablero[entrada];
        charTablero[entrada]='O';
            gano=VerificarVictoria(casillasJugador[1]);
            if(gano){
                printf("Gana el jugador B\n");
                break;
            }

    }
    
    ImprimirTablero(9,charTablero);


}
    if(turno>=9)printf("\n El juego quedo engatado\n");
    ImprimirTablero(9,charTablero);
}