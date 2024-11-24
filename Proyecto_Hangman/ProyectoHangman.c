
/*
El juego consiste en adivinar una palabra en el menor número de
intentos posibles. Primero se deben marcar tantas rayas como letras tenga la palabra secreta.
El jugador tendrá que ir colocando letras para formar la palabra, si la letra está entre los
caracteres de la palabra secreta se sustituye en el lugar de la raya. Cada vez que se solicita
una letra, el jugador podrá adivinar la palabra secreta, si la letra no está entre los caracteres de
la palabra secreta o bien el jugador adivina erróneamente la palabra secreta, el jugador pierde
una oportunidad. El jugador tendrá un cierto número de oportunidades para adivinar la palabra
secreta. El jugador gana si la palabra está completa o bien si adivina la palabra secreta antes
de perder todas sus oportunidades. El jugador pierde si agota sus oportunidades.

Creado por Oscar Pelayo Alonso Pérez, Viktor Chargoy Espino y Sebastian Juárez Vilchis
Proyecto
12 de noviembre de 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char palabraSecreta[15]={0};//aqui se guardara la palabra secreta
char avancePalabra[30]={0};//aqui se guardara el avance
char letrasFueraDePalabra[30]={0};//aqui se guardan las letras intentadas que quitan vidas
char letrasYaIngresadas[30]={0};//aqui se guardan las letras ya ingresadas anteriormente

int largoPalabra=0;// el largo de la palabra incluyendo el caracter nulo /0
int cantidadAvance=0;//se guarda la cantidad de espacios adivinados
int cantidadLetrasIngresadas=0;//numero de letras diferentes ingresadas
int letraInvalidaActual=0;//cuenta las letras que no son parte de la palabra secreta y las comas, puntos.

//------------------------------------------------------------------------------------------------------------------
//Funcion de menu

int seleccionarOpcion(){//despliega el menu de opciones y retorna la opcion seleccionada
    int opcion=-1,conteoEntradasFallidas=0;//declarar variable
    //desplegamos el menu

    do{
        if(conteoEntradasFallidas++ > 0)printf("\nOpcion no valida, la entrada debe ser 1, 2, 3 o 4\n");//si no es la primera ejecucion, imprime
        if(conteoEntradasFallidas>10000)conteoEntradasFallidas=1;//para evitar un overflow de variable, que no se pase del tamano maximo
        printf("\nElige el numero del tema deseado\n");
        printf("1. Deportes\n");
        printf("2. Frutas\n");
        printf("3. Paises\n");
        printf("4. Comida\n");
        printf("Introduce el numero: ");
        //leemos e inicializamos la opcion
        scanf("%d", &opcion);

    }while(opcion<1 && 4<opcion);//se comprueba la validez de la opcion
    
    
    //se devuelve la opcion
    return opcion;
}



//------------------------------------------------------------------------------------------------------------------
//Obtener la palabra aleatoria de la categoria seleccionada

void obtenerPalabraRandom(int opcion){//obtiene la palabra de la categoria seleccionada, la almacena en variable global
    //declaramos todas las palabras con caracter nulo /0 al final
    // char [cual palabra][longitud]
    char comida [6][15]={ "hamburguesa\0", "enchiladas\0","chilaquiles\0","burritos\0","quesadilla\0","tiramisu\0" };
    char deportes [6][15]={"basquetbol\0","ciclismo\0","natacion\0","esgrima\0","volleybol\0","escalada\0"};
    char  frutas [6][15]={"manzana\0","platano\0","guayaba\0","maracuya\0","mandarina\0","melocoton\0",};
    char  paises [6][15]={"australia\0","irlanda\0","polonia\0","nigeria\0","marruecos\0","finlandia\0"};
    // deportes, frutas, paises, comida 6 de cada una en ese orden

    int numpalabra=rand()%6;
    int i=0;
    largoPalabra=0;
    
    switch (opcion) {
        case 1:
            for(i=0;i<15;i++){
                //copiamos caracter
                palabraSecreta[i]=deportes[numpalabra][i];
                //aumentamos contador de tamano
                largoPalabra++;
                //si la palabra termino, dejamos de copiar
                if(deportes[numpalabra][i]=='\0')break;
            }
            break;
        case 2:
            for(i=0;i<15;i++){
                palabraSecreta[i]=frutas[numpalabra][i];
                largoPalabra++;
                if(frutas[numpalabra][i]=='\0')break;
            }
            break;
        case 3:
            for(i=0;i<15;i++){
                palabraSecreta[i]=paises[numpalabra][i];
                largoPalabra++;
                if(paises[numpalabra][i]=='\0')break;
            }

            break;
        case 4:
            for(i=0;i<15;i++){
                palabraSecreta[i]=comida[numpalabra][i];
                largoPalabra++;
                if(comida[numpalabra][i]=='\0')break;
            }
            break;
        default:
            printf("\nCodigo de error, no se pudo asignar la palabra secreta\n");
            break;

    
    }

    return; 
}

//------------------------------------------------------------------------------------------------------------------
//funcion que ya teniendo la palabra aleatoria crea los espacios donde se imprimiran las letras tipo _ _ _ _ ... _ _ _
void generarEspaciosParaAdivinar(){
    int i=0;
    cantidadAvance=0;
    for(i=0;i<2*largoPalabra;i++){//tomamos i con el coble de valor para poner espacios
        if(palabraSecreta[i/2]=='\0'){
            avancePalabra[i]='\0';
            break;
        }else{
             if(i%2==0)avancePalabra[i]='_';//si es par ponemos espacio de letra
             else avancePalabra[i]=' ';//si es impar ponemos un espacio vacio

        }
    }
}

//------------------------------------------------------------------------------------------------------------------
//Impresion del muñeco de acuerdo al caso
void imprimirMuneco(int vidas){

    switch (vidas)
    {
    case 5:
        printf("                                                       \n");
        printf("    |______________________                            \n");
        printf("    |                     |                            \n");
        printf("    |                     |                            \n");
        printf("    |                    ,,,                           \n");
        printf("    |                   (o_o)                          \n");
        printf("    |                  \\  |  /                         \n");
        printf("    |                   \\ | /                          \n");
        printf("    |                    \\|/                           \n");
        printf("    |                     |                            \n");
        printf("    |                     |                            \n");
        printf("    |                    / \\                          \n");
        printf("    |                   /   \\                         \n");
        printf(" ___|___               /     \\                        \n");
        printf("                                                       \n");
        break;
    
    case 4:
        printf("                                                       \n");
        printf("    |______________________                            \n");
        printf("    |                     |                            \n");
        printf("    |                     |                            \n");
        printf("    |                    ,,,                           \n");
        printf("    |                   (o_o)                          \n");
        printf("    |                  \\  |  /                         \n");
        printf("    |                   \\ | /                          \n");
        printf("    |                    \\|/                           \n");
        printf("    |                     |                            \n");
        printf("    |                     |                            \n");
        printf("    |                    /                             \n");
        printf("    |                   /                              \n");
        printf(" ___|___               /                               \n");
        printf("                                                       \n");
        break;
    
    case 3:
        printf("                                                       \n");
        printf("    |______________________                            \n");
        printf("    |                     |                            \n");
        printf("    |                     |                            \n");
        printf("    |                    ,,,                           \n");
        printf("    |                   (o_o)                          \n");
        printf("    |                  \\  |  /                         \n");
        printf("    |                   \\ | /                          \n");
        printf("    |                    \\|/                           \n");
        printf("    |                     |                            \n");
        printf("    |                     |                            \n");
        printf("    |                                                  \n");
        printf("    |                                                  \n");
        printf(" ___|___                                               \n");
        printf("                                                       \n");
        break;

    case 2:
        printf("                                                       \n");
        printf("    |______________________                            \n");
        printf("    |                     |                            \n");
        printf("    |                     |                            \n");
        printf("    |                    ,,,                           \n");
        printf("    |                   (o_o)                          \n");
        printf("    |                     |  /                         \n");
        printf("    |                     | /                          \n");
        printf("    |                     |/                           \n");
        printf("    |                     |                            \n");
        printf("    |                     |                            \n");
        printf("    |                                                  \n");
        printf("    |                                                  \n");
        printf(" ___|___                                               \n");
        printf("                                                       \n");
        break;
    
    case 1:
        printf("                                                       \n");
        printf("    |______________________                            \n");
        printf("    |                     |                            \n");
        printf("    |                     |                            \n");
        printf("    |                    ,,,                           \n");
        printf("    |                   (o_o)                          \n");
        printf("    |                     |                            \n");
        printf("    |                     |                            \n");
        printf("    |                     |                            \n");
        printf("    |                     |                            \n");
        printf("    |                     |                            \n");
        printf("    |                                                  \n");
        printf("    |                                                  \n");
        printf(" ___|___                                               \n");
        printf("                                                       \n");
        break;
    
    case 0:
        printf("\n                                                     \n");
        printf("    |______________________                            \n");
        printf("    |                     |                            \n");
        printf("    |                     |                            \n");
        printf("    |                    ,,,                           \n");
        printf("    |                   (x_x)                          \n");
        printf("    |                                                  \n");
        printf("    |                                                  \n");
        printf("    |                                                  \n");
        printf("    |                                                  \n");
        printf("    |                                                  \n");
        printf("    |                                                  \n");
        printf("    |                                                  \n");
        printf(" ___|___                                               \n");
        printf("                                                       \n");
        break;

    case 12345://es una bandera, solo entra si gana
        printf("                                                      \n");
        printf("    |______________________  Salvaste al ahorcado     \n");
        printf("    |                     |                            \n");
        printf("    |                     |                            \n");
        printf("    |                         ,,,                           \n");
        printf("    |                        (o.o)                          \n");
        printf("    |                       \\  |  /                         \n");
        printf("    |                        \\ | /                          \n");
        printf("    |                         \\|/                           \n");
        printf("    |                          |                            \n");
        printf("    |                          |                            \n");
        printf("    |                         / \\                          \n");
        printf("    |                        /   \\                         \n");
        printf(" ___|___                    /     \\                        \n");
        printf("                                                       \n");
        break;

    default://no deberia entrar aqui
        printf("\nEsto es un error o el muneco es un ser inmortal :o\n");
        printf("\nNo deberias estar aqui si eres un ser mortal\n");
        break;
    }



}
    

//------------------------------------------------------------------------------------------------------------------
//Comprueba a partir de la letra seleccionada, si es valida, no ha sido ingresada anteriormente y si esta en la palabra o no

int comprobarIntentoCorrecto(char letra){//se recorre el arreglo para determinar si la letra es correcta 1 o no 0,
//o si la letra ya habia sido ingresada anteriormente -1
//igualmente si la letra es minuscula de la a-z o es invalida -2
int valorRetornable=-10,i=0,j=0,indiceDeMinimo;
char auxiliarEnIntercambio;


//primero comprobamos si la letra es valida
if('a'<=letra && letra<='z'){//si es valida continuamos con lo demas

//Compara si ya habia sido ingresada la letra antes
for(i=0;i<cantidadLetrasIngresadas;i++){
    if(letra==letrasYaIngresadas[i]){
        printf("\nError, la letra %c ya habia sido ingresada anteriormente\n",letra);
        valorRetornable=-1;
    }
}

if(valorRetornable==-10){//es valida y no ha sido ingresada, comprobar si esta en la palabra
    letrasYaIngresadas[cantidadLetrasIngresadas]=letra;
    cantidadLetrasIngresadas++;
    for(i=0;i<largoPalabra;i++){
        if(letra==palabraSecreta[i]){
            avancePalabra[2*i]=letra;//el avance de la palabra secreta tiene espacios, por ende es 2*i
            cantidadAvance++;
            valorRetornable=1;
        }
    }

    if(valorRetornable==-10){//letra incorrecta, imprimir letras incorrectas
        if(letraInvalidaActual>0)letrasFueraDePalabra[letraInvalidaActual-1]=',';//corriges el punto por coma
        letrasFueraDePalabra[letraInvalidaActual]=letra;//colocas la letra
        letrasFueraDePalabra[letraInvalidaActual+1]='.';//pones un punto al final
        letrasFueraDePalabra[letraInvalidaActual+2]='\0';//terminas en NULL para poderlo imprimir como string
        letraInvalidaActual+=2;
        //ordenar con buble sort las letras que no estan en la palabra


        //ordenamiento puede ser una funcion
        for(i=0;i<letraInvalidaActual;i+=2){
            indiceDeMinimo=i;
            for(j=i;j<letraInvalidaActual;j+=2){
                if(letrasFueraDePalabra[j]<letrasFueraDePalabra[indiceDeMinimo]){
                    indiceDeMinimo=j;
                }
            }
            if(indiceDeMinimo!=i){
                auxiliarEnIntercambio=letrasFueraDePalabra[i];//guardamos la letra en i
                letrasFueraDePalabra[i]=letrasFueraDePalabra[indiceDeMinimo];//le asignamos la letra menor alfabeticamente a i
                letrasFueraDePalabra[indiceDeMinimo]=auxiliarEnIntercambio;//ponemos la letra antes en i en el lugar donde sacamos la minima
            }

        }

        printf("\nLa letra '%c' no esta en la palabra, pierdes una vida\n",letra);
        valorRetornable=0;

    }else if(valorRetornable==1){//la letra si estaba en la palabra
        printf("\nEncontraste la letra %c de la palabra secreta ;D \n",letra);
    }
}

}else{//si no imprimimos que no es valida y guardamos en la valiable de retorno una bandera -2
printf("\nEl caracter ingresado es invalido, recuerda ingresar una letra minuscula no eñe\n");
valorRetornable=-2;
}

return valorRetornable;

}

//------------------------------------------------------------------------------------------------------------------
//funcion que ya teniendo la palabra aleatoria y los espacios simula el juego de ahorcados


void jugarAhorcados(){//simula el juego ya teniendo la palabra
    int i=0,vidas=5;
    letrasFueraDePalabra[0]='\0';
    cantidadAvance=0;
    char letra;
    
    while(vidas>0 && cantidadAvance<largoPalabra-1){
        printf("Este es el avance y la cantidad de vidas:\n");
        printf("%s\n",avancePalabra);
        if(vidas<5)printf("\nLas letras que NO estan en la palabra son: %s\n",letrasFueraDePalabra);
        printf("Cuentas con %d vidas disponibles\n", vidas);
        //aqui poner funcion que imprima muneco colgado
        imprimirMuneco(vidas);
        printf("\nIngresa una letra minuscula no eñe: ");
        scanf(" %c", &letra);
        int estadoDelIntento=comprobarIntentoCorrecto(letra);
        //checar si se implementa la caracteristica de que si se sabe la palabra la pueda poner entera
        // retorna 0 si pierde vida, 1 si es correcta la palabra, -1 si ya estaba ocupada y -2 si es invalida
        if(estadoDelIntento==0)vidas--;
        

    }

    //termina el juego, por completar la palabra entera o por terminarse las vidas
    if(vidas<1){
        printf("\n Ya no tienes vidas, perdiste\n");
        //imprimir muneco de 0 vidas
        imprimirMuneco(0);
        printf("La palabra secreta era: %s",palabraSecreta);

    }else if(cantidadAvance>=largoPalabra-1){//si tiene vidas y salio del ciclo es porque gano
        printf("\n Felicidades, ganaste el juego de ahorcados\n");
        printf("La palabra secreta era: %s",palabraSecreta);
        imprimirMuneco(12345);
    }

    return;
}




int main(){
    //plantamos la semilla al valor random
    srand(time(NULL));
    printf("Este programa emula el juego de ahorcados\n");
    int opcionSeleccionada=seleccionarOpcion();//seleccionamos la opcion de categoria y desplegamos menu
    //printf("\n Opcion %d\n",opcionSeleccionada);
    obtenerPalabraRandom(opcionSeleccionada);//obtenemos la palabra random a partir de la categoria

    generarEspaciosParaAdivinar();//generamos los espacios de la palabra tipo _ _ _ _ ... _ _ _
    
    jugarAhorcados();//llamamos a funcion que simula el juego

    
}

