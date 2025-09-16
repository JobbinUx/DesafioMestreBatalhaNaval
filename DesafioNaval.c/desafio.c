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

     // Matriz de habilidade Cone (5x5)
    int cone[5][5];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            // Forma de cone: mais estreito no topo e mais largo na base
            if(j >= 2 - i && j <= 2 + i) cone[i][j] = 1;
            else cone[i][j] = 0;
        }
    }

     // Matriz de habilidade Cruz (5x5)
    int cruz[5][5];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(i == 2 || j == 2) cruz[i][j] = 1;
            else cruz[i][j] = 0;
        }
    }

     // Matriz de habilidade Octaedro (5x5)
    int octaedro[5][5];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(i + j == 2 || j - i == 2 || i - j == 2 || i + j == 6) octaedro[i][j] = 1;
            else if(i == 2 || j == 2) octaedro[i][j] = 1; // inclui o centro e cruz
            else octaedro[i][j] = 0;
        }
    }

     // Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 1, 2);     // origem do cone
    aplicarHabilidade(tabuleiro, cruz, 4, 4);     // origem da cruz
    aplicarHabilidade(tabuleiro, octaedro, 6, 6); // origem do octaedro

    // Exibir tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}

//Feito testes, não houve erros.
