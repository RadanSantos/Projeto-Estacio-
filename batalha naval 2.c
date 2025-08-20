#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 3

// Inicializa o tabuleiro com 0 (água) usando recursão
void inicializarTabuleiro(int tabuleiro[TAM][TAM], int i, int j) {
    if (i >= TAM) return;

    tabuleiro[i][j] = AGUA;

    if (j + 1 < TAM) {
        inicializarTabuleiro(tabuleiro, i, j + 1);
    } else {
        inicializarTabuleiro(tabuleiro, i + 1, 0);
    }
}

// Exibe o tabuleiro usando recursão
void exibirTabuleiro(int tabuleiro[TAM][TAM], int i, int j) {
    if (i >= TAM) return;

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
    if (tamanho == 0) return;

    // Só posiciona se não ultrapassar os limites
    if (linha < TAM && coluna < TAM) {
        tabuleiro[linha][coluna] = NAVIO;
        posicionarNavioHorizontal(tabuleiro, linha, coluna + 1, tamanho - 1);
    }
}

// Posiciona navio verticalmente com recursão
void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    if (tamanho == 0) return;

    // Só posiciona se não ultrapassar os limites
    if (linha < TAM && coluna < TAM) {
        tabuleiro[linha][coluna] = NAVIO;
        posicionarNavioVertical(tabuleiro, linha + 1, coluna, tamanho - 1);
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int linhaHorizontal, colunaHorizontal;
    int linhaVertical, colunaVertical;

    // Inicializar o tabuleiro
    inicializarTabuleiro(tabuleiro, 0, 0);

    // Entrada do usuário para os navios
    printf("Digite as coordenadas do navio HORIZONTAL (linha coluna): ");
    scanf("%d %d", &linhaHorizontal, &colunaHorizontal);

    printf("Digite as coordenadas do navio VERTICAL (linha coluna): ");
    scanf("%d %d", &linhaVertical, &colunaVertical);

    // Validação simples para não ultrapassar os limites
    if (colunaHorizontal + TAM_NAVIO <= TAM) {
        posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal, TAM_NAVIO);
    } else {
        printf("Coordenadas invalidas para o navio horizontal!\n");
    }

    if (linhaVertical + TAM_NAVIO <= TAM) {
        posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical, TAM_NAVIO);
    } else {
        printf("Coordenadas invalidas para o navio vertical!\n");
    }

    // Exibir o tabuleiro
    printf("\nTabuleiro de Batalha Naval:\n\n");
    exibirTabuleiro(tabuleiro, 0, 0);

    return 0;
}
