//
//  main.c
//  tp2
//
//  Created by Viegas on 12/11/17.
//  Copyright © 2017 Ciencia da Computacao - UFV. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrizPBN.h"

#define K 2

#define MAX 250
#define BUFFERSIZE 255
#define FILENAMESIZE 200

//int permutacao() {
//    /* Nosso número na base n. Ele é um vetor
//     * de n+1 posições representando um número
//     * na base n.
//     */
//    int *num ;
//    /* input é a string de entrada, e str
//     * receberá cada permutação.
//     */
//    char input[MAX], str[MAX] ;
//    int n, r, i, j, k ;
//    
//    printf("Entre com o conjunto inicial: ") ;
//    scanf("%s", input) ;
//    
//    printf("Entre com o r: ") ;
//    scanf("%d", &r) ;
//    
//    /* Aqui elimina-se caracteres repetidos na entrada.
//     * Esse procedimento não faz parte do algoritmo, e
//     * só é feito por questões práticas.
//     */
//    n = strlen(input) ;
//    j = 0;
//    str[0] = 0 ;
//    for ( i = 0; i < n; i++ ) {
//        if ( strchr(str, input[i]) == NULL ) {
//            str[j] = input[i] ;
//            j++ ;
//            str[j] = 0 ;
//        }
//    }
//    strcpy(input, str) ;
//    n = strlen(input) ;
//    
//    /* Cria o nosso número. Ele é um vetor de
//     * r+1 posições, sendo que a última é
//     * reservada para indicar quando todos os
//     * números de tamanho r foram gerados. */
//    num = (int *) calloc( (r+1), sizeof(int)) ;
//    if ( num == NULL ) {
//        perror("calloc") ;
//        return -1;
//    }
//    
//    /* Termina quando a última posição do vetor
//     * for 1. */
//    while ( num[r] == 0 ) {
//        for ( i = 0; i < n; i++ ) {
//            /* processo de mapeamento. */
//            for ( j = 0, k = r-1; j < r; j++ ) {
//                str[k] = input[num[j]] ;
//                k-- ;
//            }
//            /* Mostra o resultado. */
//            str[r] = 0 ;
//            printf("%s\n", str) ;
//            
//            /* incrementa o algarismo menos significativo. */
//            num[0]++ ;
//        }
//        
//        /* Muda de "casa" e lança os vai uns. */
//        for ( i = 0; i < r; i++ ) {
//            if ( num[i] == n ) {
//                num[i] = 0 ;
//                num[i+1]++ ;
//            }
//        }
//    }
//    
//    return 0 ;
//}

int configuraMatriz(int* n, matrizPBN* M) {
    char* caminhoArquivo = "/Users/viegas/Desktop/UFV/AED I/Trabalhos/tp2/tp2/n7.txt";
    int linhaAtual = 1; // Inteiro que armazena a linha onde a palavra estará
    char nomeArquivo[FILENAMESIZE]; // Caminho pro arquivo
    char buffer[BUFFERSIZE]; // Buffer de uma linha (255 caracteres)
    char * palavraAtual; // Armazenará a palavra atual em cada iteração
    int n1, n2;
    FILE *arquivo = NULL; // Arquivo TXT lido
    
    //    printf("Entre o caminho do arquivo, com extensão: ");
    //    scanf(" %[^\n]s", nomeArquivo);
    
    arquivo = fopen(caminhoArquivo, "r");
    if (arquivo == NULL) {
        printf("O arquivo %s não existe. Encerrando a execução. \n", nomeArquivo);
        return 0;
    }
    
    while (fgets(buffer, BUFFERSIZE, (FILE*) arquivo)) {
        if (linhaAtual == 1) {
            palavraAtual = strtok (buffer, " \n\r\t");
            *n = atoi(palavraAtual);
            criaMatriz(M, *n);
        } else {
            palavraAtual = strtok (buffer, " \n\r\t");
            n1 = atoi(palavraAtual);
            
            palavraAtual = strtok (NULL, " \n\r\t");
            n2 = atoi(palavraAtual);
            
            setaAdjacencia(M, n1, n2);
        }
        
        linhaAtual++;
    }
    
    fclose(arquivo);
    
    return 1;
}

int main(int argc, const char * argv[]) {
    int n;
    matrizPBN M;
    
    configuraMatriz(&n, &M);
    printaMatriz(&M, n);
    
    return 0;
}
