#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char archivo_sal[] = "C:\\Users\\Oalonso11\\Documents\\GitHub\\C-class\\LabU7_Archivos\\salida1.out";
FILE *punt_file_sal;

int funcionOpcion() {
    int solicitud;

    fprintf(punt_file_sal, "\nIngresa la operación deseada 1. Suma, 2. Multiplicacion o 3. Transpuesta de ambas matrices: ");
    printf("\n\nIngresa la operación deseada 1. Suma, 2. Multiplicacion o 3. Transpuesta de ambas matrices: ");
    scanf("%d", &solicitud);

    while (solicitud != 1 && solicitud != 2 && solicitud != 3) {
        printf("\nError, debes ingresar 1, 2 o 3");
        printf("\nIngresa la operación deseada 1. Suma, 2. Multiplicacion o 3. Transpuesta de ambas matrices: ");
        scanf("%d", &solicitud);
    }

    fprintf(punt_file_sal, "\nSeleccionaste la operacion %d\n", solicitud);
    return solicitud;
}

// Función para calcular la transpuesta de una matriz
void transponerMatriz(int filas, int columnas, int matriz[filas][columnas], FILE *punt_file_sal, char nombre) {
    printf("\nTranspuesta de la matriz %c:\n", nombre);
    fprintf(punt_file_sal, "\nTranspuesta de la matriz %c:\n", nombre);
    for (int j = 0; j < columnas; j++) {
        for (int i = 0; i < filas; i++) {
            printf("%d ", matriz[i][j]);
            fprintf(punt_file_sal, "%d ", matriz[i][j]);
        }
        printf("\n");
        fprintf(punt_file_sal, "\n");
    }
}

// Función para sumar matrices
void sumarMatrices(int filas, int columnas, int a[filas][columnas], int b[filas][columnas], FILE *punt_file_sal) {
    printf("\nResultado de la suma de las matrices A y B:\n");
    fprintf(punt_file_sal, "\nResultado de la suma de las matrices A y B:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", a[i][j] + b[i][j]);
            fprintf(punt_file_sal, "%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
        fprintf(punt_file_sal, "\n");
    }
}

// Función multi matrices
void multiplicarMatrices(int filasA, int columnasA, int columnasB, int a[filasA][columnasA], int b[columnasA][columnasB], FILE *punt_file_sal) {
    int c[filasA][columnasB];
    // Inicializar la matriz resultado
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            c[i][j] = 0;
        }
    }
    // Multiplicación
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            for (int k = 0; k < columnasA; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Imprimir resultado
    printf("\nResultado de la multiplicación de las matrices A y B:\n");
    fprintf(punt_file_sal, "\nResultado de la multiplicación de las matrices A y B:\n");
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            printf("%d ", c[i][j]);
            fprintf(punt_file_sal, "%d ", c[i][j]);
        }
        printf("\n");
        fprintf(punt_file_sal, "\n");
    }
}

int main() {
    int i, j, nfilasA, mcolumnasA, nfilasB, mcolumnasB, opcion = 0;
    srand(time(NULL));
    punt_file_sal = fopen(archivo_sal, "w");

    printf("Programa que pide el tamano de dos matrices para generarlas aleatoriamente de 0 a 3\n");
    printf("Puede realizar las operaciones de suma de ambas, multiplicacion y transpuesta, dadas las condiciones\n\n");
    fprintf(punt_file_sal, "Programa que pide el tamano de dos matrices para generarlas aleatoriamente de 0 a 3\n");
    fprintf(punt_file_sal, "Puede realizar las operaciones de suma de ambas, multiplicacion y transpuesta, dadas las condiciones\n\n");

    opcion = funcionOpcion();

    // Ingresar matriz A
    printf("Dame el numero de filas de la matriz A: ");
    scanf("%d", &nfilasA);
    printf("\nDame el numero de columnas de la matriz A: ");
    scanf("%d", &mcolumnasA);
    fprintf(punt_file_sal, "\nLa matriz A cuenta con %d filas y %d columnas\n", nfilasA, mcolumnasA);

    int a[nfilasA][mcolumnasA];
    for (i = 0; i < nfilasA; i++) {
        for (j = 0; j < mcolumnasA; j++) {
            a[i][j] = rand() % 4;
        }
    }

    // Imprimir matriz A
    printf("Se imprime la matriz generada A\n");
    fprintf(punt_file_sal, "Se imprime la matriz generada A\n");
    for (i = 0; i < nfilasA; i++) {
        for (j = 0; j < mcolumnasA; j++) {
            printf("%d ", a[i][j]);
            fprintf(punt_file_sal, "%d ", a[i][j]);
        }
        printf("\n");
        fprintf(punt_file_sal, "\n");
    }

    // Ingresar matriz B
    printf("Dame el numero de filas de la matriz B: ");
    scanf("%d", &nfilasB);
    printf("\nDame el numero de columnas de la matriz B: ");
    scanf("%d", &mcolumnasB);
    fprintf(punt_file_sal, "\nLa matriz B cuenta con %d filas y %d columnas\n", nfilasB, mcolumnasB);

    int b[nfilasB][mcolumnasB];
    for (i = 0; i < nfilasB; i++) {
        for (j = 0; j < mcolumnasB; j++) {
            b[i][j] = rand() % 4;
        }
    }

    // Imprimir matriz B
    printf("Se imprime la matriz generada B\n");
    fprintf(punt_file_sal, "Se imprime la matriz generada B\n");
    for (i = 0; i < nfilasB; i++) {
        for (j = 0; j < mcolumnasB; j++) {
            printf("%d ", b[i][j]);
            fprintf(punt_file_sal, "%d ", b[i][j]);
        }
        printf("\n");
        fprintf(punt_file_sal, "\n");
    }

    // Operaciones según opción
    switch (opcion) {
    case 1: // Suma
        if (nfilasA == nfilasB && mcolumnasA == mcolumnasB) {
            sumarMatrices(nfilasA, mcolumnasA, a, b, punt_file_sal);
        } else {
            printf("\nError: Las matrices deben tener el mismo tamaño para ser sumadas.\n");
            fprintf(punt_file_sal, "\nError: Las matrices deben tener el mismo tamaño para ser sumadas.\n");
        }
        break;

    case 2: // Multiplicación
        if (mcolumnasA == nfilasB) {
            multiplicarMatrices(nfilasA, mcolumnasA, mcolumnasB, a, b, punt_file_sal);
        } else {
            printf("\nError: Las dimensiones de las matrices no son compatibles para multiplicación.\n");
            fprintf(punt_file_sal, "\nError: Las dimensiones de las matrices no son compatibles para multiplicación.\n");
        }
        break;

    case 3: // Transpuesta
        transponerMatriz(nfilasA, mcolumnasA, a, punt_file_sal, 'A');
        transponerMatriz(nfilasB, mcolumnasB, b, punt_file_sal, 'B');
        break;
    }

    fclose(punt_file_sal);
    return 0;
}
