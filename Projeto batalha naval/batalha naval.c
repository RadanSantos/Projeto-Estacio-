#include <stdio.h>

#define TAM 10      // tamanho fixo do tabuleiro
#define NAVIO 3     // valor que representa o navio
#define AGUA 0      // valor que representa água
#define TAM_NAVIO 3 // tamanho fixo dos navios

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
}

// Função para posicionar um navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // 1. Inicializar o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // 2. Definir coordenadas iniciais dos navios
    int linhaHorizontal = 2, colunaHorizontal = 3; // navio horizontal
    int linhaVertical = 5, colunaVertical = 7;     // navio vertical

    // 3. Posicionar os navios no tabuleiro
    posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal);
    posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical);

    // 4. Exibir o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
