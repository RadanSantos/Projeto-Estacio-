#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 3

// Inicializa o tabuleiro com 0 (água) usando recursão
void inicializarTabuleiro(int tabuleiro[TAM][TAM], int i, int j) {
    if (i >= TAM) return; // condição de parada

    tabuleiro[i][j] = AGUA;

    if (j + 1 < TAM) {
        inicializarTabuleiro(tabuleiro, i, j + 1);
    } else {
        inicializarTabuleiro(tabuleiro, i + 1, 0);
    }
}

// Exibe o tabuleiro usando recursão
void exibirTabuleiro(int tabuleiro[TAM][TAM], int i, int j) {
    if (i >= TAM) return; // fim da matriz

    printf("%d ", tabuleiro[i][j]);

    if (j + 1 < TAM) {
        exibirTabuleiro(tabuleiro, i, j + 1);
    } else {
        printf("\n");
        exibirTabuleiro(tabuleiro, i + 1, 0);
    }
}

// Posiciona navio horizontalmente com recursão
void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    if (tamanho == 0) return; // condição de parada
    tabuleiro[linha][coluna] = NAVIO;
    posicionarNavioHorizontal(tabuleiro, linha, coluna + 1, tamanho - 1);
}

// Posiciona navio verticalmente com recursão
void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    if (tamanho == 0) return; // condição de parada
    tabuleiro[linha][coluna] = NAVIO;
    posicionarNavioVertical(tabuleiro, linha + 1, coluna, tamanho - 1);
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializar o tabuleiro
    inicializarTabuleiro(tabuleiro, 0, 0);

    // Definir coordenadas iniciais dos navios
    int linhaHorizontal = 2, colunaHorizontal = 3;
    int linhaVertical = 5, colunaVertical = 7;

    // Posicionar os navios
    posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal, TAM_NAVIO);
    posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical, TAM_NAVIO);

    // Exibir o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");
    exibirTabuleiro(tabuleiro, 0, 0);

    return 0;
}
