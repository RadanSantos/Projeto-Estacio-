#include <stdio.h>

#define TAM 10
#define NAVIO 1
#define AGUA 0
#define TAM_NAVIO 3

// Protótipos
void inicializarTabuleiro(int tabuleiro[TAM][TAM], int i, int j);
void exibirTabuleiro(int tabuleiro[TAM][TAM], int i, int j);
void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho);
void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho);
void posicionarNavioDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho);
void posicionarNavioDiagonalInversa(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho);

// Inicializar recursivamente
void inicializarTabuleiro(int tabuleiro[TAM][TAM], int i, int j) {
    if (i >= TAM) return;
    tabuleiro[i][j] = AGUA;
    if (j < TAM - 1) inicializarTabuleiro(tabuleiro, i, j + 1);
    else inicializarTabuleiro(tabuleiro, i + 1, 0);
}

// Exibir recursivamente
void exibirTabuleiro(int tabuleiro[TAM][TAM], int i, int j) {
    if (i >= TAM) return;
    if (tabuleiro[i][j] == AGUA) printf(" ~ ");
    else printf(" N ");
    if (j < TAM - 1) exibirTabuleiro(tabuleiro, i, j + 1);
    else {
        printf("\n");
        exibirTabuleiro(tabuleiro, i + 1, 0);
    }
}

// Navio horizontal
void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    if (tamanho == 0) return;
    if (linha < TAM && coluna < TAM) {
        tabuleiro[linha][coluna] = NAVIO;
        posicionarNavioHorizontal(tabuleiro, linha, coluna + 1, tamanho - 1);
    }
}

// Navio vertical
void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    if (tamanho == 0) return;
    if (linha < TAM && coluna < TAM) {
        tabuleiro[linha][coluna] = NAVIO;
        posicionarNavioVertical(tabuleiro, linha + 1, coluna, tamanho - 1);
    }
}

// Navio diagonal principal
void posicionarNavioDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    if (tamanho == 0) return;
    if (linha < TAM && coluna < TAM) {
        tabuleiro[linha][coluna] = NAVIO;
        posicionarNavioDiagonalPrincipal(tabuleiro, linha + 1, coluna + 1, tamanho - 1);
    }
}

// Navio diagonal inversa
void posicionarNavioDiagonalInversa(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    if (tamanho == 0) return;
    if (linha < TAM && coluna >= 0) {
        tabuleiro[linha][coluna] = NAVIO;
        posicionarNavioDiagonalInversa(tabuleiro, linha + 1, coluna - 1, tamanho - 1);
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    inicializarTabuleiro(tabuleiro, 0, 0);

    // Posiciona 4 navios fixos para teste
    posicionarNavioHorizontal(tabuleiro, 0, 0, TAM_NAVIO);
    posicionarNavioVertical(tabuleiro, 2, 5, TAM_NAVIO);
    posicionarNavioDiagonalPrincipal(tabuleiro, 5, 0, TAM_NAVIO);
    posicionarNavioDiagonalInversa(tabuleiro, 0, 9, TAM_NAVIO);

    printf("\nTabuleiro de Batalha Naval:\n\n");
    exibirTabuleiro(tabuleiro, 0, 0);

    return 0;
}
