#include <stdio.h>
#include <string.h>

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
void colocarNavio(int tabuleiro[TAM][TAM], int numero);

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

// Colocar um navio digitado pelo jogador
void colocarNavio(int tabuleiro[TAM][TAM], int numero) {
    int linha, coluna;
    char direcao[3];

    printf("\nDigite a linha inicial do navio %d (0-9): ", numero);
    scanf("%d", &linha);
    printf("Digite a coluna inicial do navio %d (0-9): ", numero);
    scanf("%d", &coluna);
    printf("Digite a direcao (H=Horizontal, V=Vertical, DP=Diagonal Principal, DI=Diagonal Inversa): ");
    scanf("%s", direcao);

    // Verificação simples de limites
    if ((direcao[0] == 'H' && coluna + TAM_NAVIO > TAM) ||
        (direcao[0] == 'V' && linha + TAM_NAVIO > TAM) ||
        (strcmp(direcao, "DP") == 0 && (linha + TAM_NAVIO > TAM || coluna + TAM_NAVIO > TAM)) ||
        (strcmp(direcao, "DI") == 0 && (linha + TAM_NAVIO > TAM || coluna - TAM_NAVIO < -1))) {
        printf("⚠️ Posição inválida! Tente novamente.\n");
        colocarNavio(tabuleiro, numero);
        return;
    }

    // Coloca o navio na direção escolhida
    if (direcao[0] == 'H') posicionarNavioHorizontal(tabuleiro, linha, coluna, TAM_NAVIO);
    else if (direcao[0] == 'V') posicionarNavioVertical(tabuleiro, linha, coluna, TAM_NAVIO);
    else if (strcmp(direcao, "DP") == 0) posicionarNavioDiagonalPrincipal(tabuleiro, linha, coluna, TAM_NAVIO);
    else if (strcmp(direcao, "DI") == 0) posicionarNavioDiagonalInversa(tabuleiro, linha, coluna, TAM_NAVIO);
    else {
        printf("⚠️ Direção inválida! Tente novamente.\n");
        colocarNavio(tabuleiro, numero);
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    inicializarTabuleiro(tabuleiro, 0, 0);

    printf("\n=== BATALHA NAVAL ===\n");
    printf("Tabuleiro vazio:\n\n");
    exibirTabuleiro(tabuleiro, 0, 0);

    // Jogador posiciona 4 navios
    colocarNavio(tabuleiro, 1);
    colocarNavio(tabuleiro, 2);
    colocarNavio(tabuleiro, 3);
    colocarNavio(tabuleiro, 4);

    printf("\nTabuleiro final com navios:\n\n");
    exibirTabuleiro(tabuleiro, 0, 0);

    return 0;
}
