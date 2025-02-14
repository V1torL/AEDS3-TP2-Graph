#include "fileHandler.h"



// Lê do arquivo quantos casos de teste tem nesse arquivo
int getNumberOfTests(FILE *inputFile){
    int nTests;
    if( inputFile == NULL){
        printf("Arquivo de entrada incorreto!");
        exit(1);
    }
    fscanf(inputFile, "%d ", &nTests);

    return nTests;
}


void freeMatrix(int **matrix){

}

void readMatrix(FILE *inputFile, int *nrows, int *ncols, int ***matrix){

    fscanf(inputFile, "%d %d", nrows, ncols);

    *matrix = (int **)malloc(*nrows * sizeof(int *));
    for (int i = 0; i < *nrows; i++) {
        (*matrix)[i] = (int *)malloc(*ncols * sizeof(int));
    }

    // lê os elementos da matrix
    for (int i = 0; i < *nrows; i++) {
        for (int j = 0; j < *ncols; j++) {
            fscanf(inputFile, "%d", &((*matrix)[i][j]));
        }
    }

}