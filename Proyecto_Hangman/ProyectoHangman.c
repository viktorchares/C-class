
/*
Creado por Oscar Pelayo Alonso Pérez, Viktor Chargoy Espino y Sebastian Juárez Vilchis
Proyecto
12 de noviembre de 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//declaramos todas las palabras con caracter nulo /0 al final
// char [cual palabra][longitud]
char comida [6][15]={ "hamburguesa\0", "enchiladas\0","chilaquiles\0","burritos\0","quesadilla\0","tiramisu\0" };
char deportes [6][15]={"basquetbol\0","futbol\0","natacion\0","esgrima\0","volleybol\0","escalada\0"};
char  frutas [6][15]={"manzana\0","platano\0","guayaba\0","papaya\0","melon\0","melocoton\0",};
char  paises [6][15]={"australia\0","irlanda\0","polonia\0","monaco\0","marruecos\0","inglaterra\0"};
// deportes, frutas, paises, comida 6 de cada una en ese orden



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

            break;

    
    }

    return; 
}

//------------------------------------------------------------------------------------------------------------------
//Comprueba a partir de la letra seleccionada, si es valida, no ha sido ingresada anteriormente y si esta en la palabra o no

int comprobarIntentoCorrecto(char letra){//se recorre el arreglo para determinar si la letra es correcta 1 o no 0,
//o si la letra ya habia sido ingresada anteriormente -1
//igualmente si la letra es minuscula de la a-z o es invalida -2
int valorRetornable=-10,i=0,j=0,indiceDeMinimo;
char auxiliarEnIntercambio;


//primero comprobamos si la letra es valida
if(97<=letra && letra<=122){//si es valida continuamos con lo demas

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
            avancePalabra[2*i]=letra;//el avance de la palabra secreta tiene espacios
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

    }else{//la letra si estaba en la palabra
        printf("\nEncontraste la letra %c de la palabra secreta *aplausos* \n",letra);
    }
}

}else{//si no imprimimos que no es valida y guardamos en la valiable de retorno una bandera -2
printf("\nEl caracter ingresado es invalido, recuerda ingresar una letra minuscula no eñe\n");
valorRetornable=-2;
}

return valorRetornable;

}


//------------------------------------------------------------------------------------------------------------------
//funcion que ya teniendo la palabra aleatoria simula el juego de ahorcados


void jugarAhorcados(){//simula el juego ya teniendo la palabra
    int i=0,vidas=5;
    letrasFueraDePalabra[0]='\0';
    cantidadAvance=0;
    char letra;
    for(i=0;i<2*largoPalabra;i++){//tomamos i con el coble de valor para poner espacios
        if(palabraSecreta[i/2]=='\0'){
            avancePalabra[i]='\0';
            break;
        }else{
             if(i%2==0)avancePalabra[i]='_';//si es par ponemos espacio de letra
             else avancePalabra[i]=' ';//si es impar ponemos un espacio vacio

        }
    }
    while(vidas>0 && cantidadAvance<largoPalabra-1){
        printf("Este es el avance y la cantidad de vidas:\n");
        printf("%s\n",avancePalabra);
        if(vidas<5)printf("\nLas letras que NO estan en la palabra son: %s\n",letrasFueraDePalabra);
        printf("Cuentas con %d vidas disponibles\n", vidas);
        //aqui poner funcion que imprima muneco colgado
        printf("\nIngresa una letra minuscula no eñe: ");
        scanf(" %c", &letra);
        int estadoDelIntento=comprobarIntentoCorrecto(letra);
        // retorna 0 si pierde vida, 1 si es correcta la palabra, -1 si ya estaba ocupada y -2 si es invalida
        if(estadoDelIntento==0)vidas--;
        

    }

    if(vidas<1){
        printf("\n Ya no tienes vidas, perdiste\n");
        //imprimir muneco de 0 vidas
    }else if(cantidadAvance>=largoPalabra-1){//si tiene vidas y salio del ciclo es porque gano
        printf("\n Felicidades, ganaste el juego de ahorcados\n");
        printf("La palabra secreta era: %s",palabraSecreta);
    }

    return;
}




int main(){
    //plantamos la semilla al valor random
    srand(time(NULL));
    printf("Este programa emula el juego de ahorcados\n");
    int opcionSeleccionada=seleccionarOpcion();
    //printf("\n Opcion %d\n",opcionSeleccionada);
    obtenerPalabraRandom(opcionSeleccionada);
    //llamamos a funcion que simula
    jugarAhorcados();

    
}

