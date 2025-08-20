#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 4
#define AGUA '~'
#define NAVIO 'N'

// Inicializar o tabuleiro recursivamente
void inicializarTabuleiro(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha == TAM) return;

    tabuleiro[linha][coluna] = AGUA;

    if (coluna == TAM - 1)
        inicializarTabuleiro(tabuleiro, linha + 1, 0);
    else
        inicializarTabuleiro(tabuleiro, linha, coluna + 1);
}

// Exibir tabuleiro recursivamente
void exibirTabuleiro(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha == TAM) return;

    printf("%c ", tabuleiro[linha][coluna]);

    if (coluna == TAM - 1) {
        printf("\n");
        exibirTabuleiro(tabuleiro, linha + 1, 0);
    } else {
        exibirTabuleiro(tabuleiro, linha, coluna + 1);
    }
}

// Posicionar navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    if (tamanho == 0) return;

    if (linha < TAM && coluna < TAM) {
        tabuleiro[linha][coluna] = NAVIO;
        posicionarNavioHorizontal(tabuleiro, linha, coluna + 1, tamanho - 1);
    }
}

// Posicionar navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    if (tamanho == 0) return;

    if (linha < TAM && coluna < TAM) {
        tabuleiro[linha][coluna] = NAVIO;
        posicionarNavioVertical(tabuleiro, linha + 1, coluna, tamanho - 1);
    }
}

// Posicionar navio na diagonal principal (↘)
void posicionarNavioDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    if (tamanho == 0) return;

    if (linha < TAM && coluna < TAM) {
        tabuleiro[linha][coluna] = NAVIO;
        posicionarNavioDiagonalPrincipal(tabuleiro, linha + 1, coluna + 1, tamanho - 1);
    }
}

// Posicionar navio na diagonal secundária (↙)
void posicionarNavioDiagonalSecundaria(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    if (tamanho == 0) return;

    if (linha < TAM && coluna >= 0) {
        tabuleiro[linha][coluna] = NAVIO;
        posicionarNavioDiagonalSecundaria(tabuleiro, linha + 1, coluna - 1, tamanho - 1);
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro, 0, 0);

    // Dois navios horizontais/verticais
    posicionarNavioHorizontal(tabuleiro, 0, 0, TAM_NAVIO);   // Linha 0, col 0
    posicionarNavioVertical(tabuleiro, 2, 5, TAM_NAVIO);     // Linha 2, col 5

    // Dois navios diagonais
    posicionarNavioDiagonalPrincipal(tabuleiro, 4, 0, TAM_NAVIO); // ↘
    posicionarNavioDiagonalSecundaria(tabuleiro, 1, 9, TAM_NAVIO); // ↙

    printf("\nTabuleiro 10x10 com navios:\n\n");
    exibirTabuleiro(tabuleiro, 0, 0);

    return 0;
}
