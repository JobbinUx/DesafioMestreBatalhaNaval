#include <stdio.h>

#define SIZE 10

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(tabuleiro[i][j] == 0) printf("~ "); // Água
            else if(tabuleiro[i][j] == 3) printf("N "); // Navio
            else if(tabuleiro[i][j] == 5) printf("* "); // Área afetada
                    }
        printf("\n");
    }
    printf("\n");
}