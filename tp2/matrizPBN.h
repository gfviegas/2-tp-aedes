//
//  matrizPBN.h
//  tp2
//
//  Created by Viegas on 12/11/17.
//  Copyright © 2017 Ciencia da Computacao - UFV. All rights reserved.
//

#ifndef matrizPBN_h
#define matrizPBN_h

#include <stdio.h>
#include <stdlib.h>

//typedef struct matrizPBN {
//    int
//} matrizPBN;

typedef struct {
    int** valores;
} matrizPBN;

int criaMatriz(matrizPBN* matriz, int N);
int printaMatriz(matrizPBN* matriz, int N);
int setaAdjacencia(matrizPBN* matriz, int n1, int n2);

#endif /* matrizPBN_h */
