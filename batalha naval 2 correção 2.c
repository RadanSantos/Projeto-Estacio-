#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 3

// Protótipos das funções
void inicializarTabuleiro(int tabuleiro[TAM][TAM], int i, int j);
void exibirTabuleiro(int tabuleiro[TAM][TAM], int i, int j);
void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho);
void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho);

int main() {
    int tabuleiro[TAM][TAM];
    int linhaHorizontal, colunaHorizontal;
    int linhaVertical, colunaVertical;

    inicializarTabuleiro(tabuleiro, 0, 0);

    printf("Digite as coordenadas do navio HORIZONTAL (linha coluna): ");
    scanf("%d %d", &linhaHorizontal, &colunaHorizontal);

    printf("Digite as coordenadas do navio VERTICAL (linha coluna): ");
    scanf("%d %d", &linhaVertical, &colunaVertical);

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

    printf("\nTabuleiro de Batalha Naval:\n\n");
    exibirTabuleiro(tabuleiro, 0, 0);

    return 0;
}
