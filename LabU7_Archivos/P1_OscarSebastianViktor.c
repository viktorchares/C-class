/*Realizar un programa en lenguaje C que realice operaciones con dos matrices A, B. Las operaciones
que se pueden realizar en el programa deben ser elegibles por el usuario a través de un menú: Suma,
Multiplicación y Transpuesta de ambas matrices. El programa debe solicitar al usuario el tamaño de las
matrices. Las matrices A y B deben ser generadas con valores aleatorios en el rango de 0 a 3.
Considere las condiciones para que las operaciones, puedan ser realizadas.
El programa debe generar un archivo de salida (.txt) donde se muestre toda la interacción de una
ejecución entre el programa y el usuario, esta interacción debe incluir: título (lo que hace el programa),
menú, las matrices generadas (matrices de entrada y matrices de salida). Las condiciones para las
operaciones con las matrices las define el programador.

Creado por Oscar Pelayo Alonso Pérez, Viktor Chargoy Espino y Sebastian Juárez Vilchis
Laboratorio 7
23 de noviembre de 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    char archivo_sal[]= "C:\\Users\\vikch\\Documents\\GitHub\\C-class\\LabU7_Archivos\\salida1.out";
    //char archivo_sal[]= "salida1.out";
    FILE *punt_file_sal;

int funcionOpcion(){
    int solicitud;

     fprintf(punt_file_sal,"\nIngresa la operación deseada 1. Suma, 2. Multiplicacion o 3. Transpuesta de ambas matrices: ");
     printf("\n\nIngresa la operación deseada 1. Suma, 2. Multiplicacion o 3. Transpuesta de ambas matrices: ");
    scanf("%d",&solicitud);

    while(solicitud!=1 && solicitud!=2 && solicitud!=3 ){
        printf("\nError, debes ingresar 1, 2 o 3");
        printf("\nIngresa la operación deseada 1. Suma, 2. Multiplicacion o 3. Transpuesta de ambas matrices: ");
        scanf("%d",&solicitud);
    }

    fprintf(punt_file_sal,"\n Seleccionaste la operacion %d \n",solicitud);
    return solicitud;
}


int main(){

    int i,j,nfilasA,mcolumnasA,nfilasB,mcolumnasB,opcion=0;
    srand(time(NULL));
    punt_file_sal= fopen(archivo_sal,"w");
    printf("Programa que pide el tamano de dos matrices para generarlas aleatoriamente de 0 a 3\n");
    printf("Puede realizar las operaciones de suma de ambas, multiplicacion y transpuesta, dadas las condiciones\n\n");
    fprintf(punt_file_sal,"Programa que pide el tamano de dos matrices para generarlas aleatoriamente de 0 a 3\n");
    fprintf(punt_file_sal,"Puede realizar las operaciones de suma de ambas, multiplicacion y transpuesta, dadas las condiciones\n\n");

    opcion=funcionOpcion();

    //ingresar matriz A --------------------------------------------------------------------
    printf("Dame el numero de filas de la matriz A: ");
    scanf("%d",&nfilasA);

    while(nfilasA<1){
        printf("\nEl tamano debe ser un entero positivo");
        printf("\nDame el numero de filas de la matriz A: ");
        scanf("%d",&nfilasA);
    }

    printf("\nDame el numero de columnas de la matriz A: ");
    scanf("%d",&mcolumnasA);

    while(mcolumnasA<1){
        printf("\nEl tamano debe ser un entero positivo");
        printf("\nDame el numero de columnas de la matriz A: ");
        scanf("%d",&mcolumnasA);
    }
    
    fprintf(punt_file_sal,"\n La matriz A cuenta con %d filas y %d columnas\n",nfilasA,mcolumnasA);

    int a[nfilasA][mcolumnasA];
    //generar la matriz
    for(i=0;i<nfilasA; i++){
        for(j=0; j<mcolumnasA ; j++){
            a[i][j]=rand()%4;
        }
    }

    //imprimir la matriz
    printf("Se imprime la matriz generada A\n");
    fprintf(punt_file_sal,"Se imprime la matriz generada A\n");
    for(i=0;i<nfilasA; i++){
        for(j=0; j<mcolumnasA ; j++){
           printf("%d ", a[i][j]);
            fprintf(punt_file_sal,"%d ", a[i][j]);
        }
        printf("\n");
        fprintf(punt_file_sal,"\n");
    }

    //ingresar matriz B --------------------------------------------------------------------
    printf("Dame el numero de filas de la matriz B: ");
    scanf("%d",&nfilasB);

    while(nfilasB<1){
        printf("\nEl tamano debe ser un entero positivo");
        printf("\nDame el numero de filas de la matriz B: ");
        scanf("%d",&nfilasB);
    }

    printf("\nDame el numero de columnas de la matriz B: ");
    scanf("%d",&mcolumnasB);

    while(mcolumnasB<1){
        printf("\nEl tamano debe ser un entero positivo");
        printf("\nDame el numero de columnas de la matriz B: ");
        scanf("%d",&mcolumnasA);
    }
    
    fprintf(punt_file_sal,"\n La matriz B cuenta con %d filas y %d columnas\n",nfilasB,mcolumnasB);

    int b[nfilasB][mcolumnasB];
    //generar la matriz
    for(i=0;i<nfilasB; i++){
        for(j=0; j<mcolumnasB ; j++){
            b[i][j]=rand()%4;
        }
    }

    //imprimir la matriz
    printf("Se imprime la matriz generada B\n");
    fprintf(punt_file_sal,"Se imprime la matriz generada B\n");
    for(i=0;i<nfilasB; i++){
        for(j=0; j<mcolumnasB ; j++){
           printf("%d ", b[i][j]);
            fprintf(punt_file_sal,"%d ", b[i][j]);
        }
        printf("\n");
        fprintf(punt_file_sal,"\n");
    }

    //agregar operaciones, comprobaciones
    switch (opcion)
    {
    case 1://suma
        /* code */
        break;
    case 2://multiplicacion
        /* code */
        break;
    case 3://transpuesta de ambas matrices
        /* code */
        break;
    
    default:
        break;
    }
   
   

    
    return 0;
    
}