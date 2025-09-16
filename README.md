# DesafioMestreBatalhaNaval
Batalha Naval Desafio curso GTI

Batalha Naval com Habilidades Especiais
Descrição

Este é um projeto em C que simula um tabuleiro de Batalha Naval 10x10 e adiciona habilidades especiais com áreas de efeito distintas: Cone, Cruz e Octaedro. O programa permite visualizar como cada habilidade afeta o tabuleiro, destacando as posições atingidas.

Funcionalidades

Tabuleiro de 10x10 com navios posicionados manualmente.

Três habilidades especiais com matrizes de efeito:

Cone: Área triangular que se abre do topo para a base.

Cruz: Área em forma de cruz, centrada no ponto de origem.

Octaedro: Área em forma de losango, centrada no ponto de origem.

Sobreposição dinâmica das matrizes de habilidades sobre o tabuleiro.

Exibição do tabuleiro no console com símbolos:

~ → Água

N → Navio

* → Área afetada pela habilidade

Estrutura do Código

main():

Inicializa o tabuleiro e posiciona navios.

Cria as matrizes de habilidades usando loops e condicionais.

Aplica as habilidades ao tabuleiro.

Exibe o tabuleiro final.

aplicarHabilidade():

Sobrepõe a matriz de habilidade ao tabuleiro, respeitando limites.

exibirTabuleiro():

Imprime o tabuleiro no console com símbolos representativos.

Como Executar

Compile o código com um compilador C:

gcc batalha_naval.c -o batalha_naval


Execute o programa:

./batalha_naval


Observe no console as áreas afetadas pelas habilidades especiais.

Observações

O programa não implementa efeitos de dano; serve apenas para visualização das áreas de efeito.

As posições dos navios e das habilidades são definidas diretamente no código.

O tamanho das matrizes de habilidades é fixo em 5x5 para simplificação.