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

// Função para sobrepor a matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[SIZE][SIZE], int habilidade[5][5], int origemLinha, int origemColuna) {
    int tamanho = 5;
    int meio = tamanho / 2;

    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            int linhaTab = origemLinha - meio + i;
            int colTab = origemColuna - meio + j;

            // Verifica se está dentro dos limites do tabuleiro
            if(linhaTab >= 0 && linhaTab < SIZE && colTab >= 0 && colTab < SIZE) {
                if(habilidade[i][j] == 1 && tabuleiro[linhaTab][colTab] == 0) {
                    tabuleiro[linhaTab][colTab] = 5; // Marca a área afetada
                }
            }
        }
    }
}

int main() {
    int tabuleiro[SIZE][SIZE] = {0};

    // Exemplo de navios posicionados manualmente
    tabuleiro[2][2] = 3;
    tabuleiro[4][4] = 3;
    tabuleiro[6][6] = 3;