//
//  matrizPBN.c
//  tp2
//
//  Created by Viegas on 12/11/17.
//  Copyright © 2017 Ciencia da Computacao - UFV. All rights reserved.
//

#include "matrizPBN.h"

int criaMatriz(matrizPBN* matriz, int N) {
    int i;
    
    if (N < 1) {
        printf("Entrada N inválida. \n");
        return 0;
    }
    
    matriz->valores = (int **) calloc(N, sizeof(int *));
    if (matriz->valores == NULL) {
        printf("Memória insuficiente ao alocar a matriz. \n");
        return 0;
    }
    
    for (i = 0; i < N; i++) {
        matriz->valores[i] = (int *) calloc(N, sizeof(int));
        if (matriz->valores[i] == NULL) {
            printf("Memória insuficiente ao alocar vetor da matriz. \n");
            return 0;
        }
        
        matriz->valores[i][i] = -1;
    }
    
    return 1;
}


int printaMatriz(matrizPBN* matriz, int N) {
    int i, j;
    
    printf("Printando matriz..\n");
    for (i = 0; i < N; i++) {
        printf(" | ");
        for (j = 0; j < N; j++) {
            printf("\t %d ", matriz->valores[i][j]);
        }
        printf(" | \n");
    }
    
    
    return 1;
}
