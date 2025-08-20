#include <stdio.h>

#define N 10   // tamanho do tabuleiro

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tabuleiro[i][j] == 0) printf(" ~ ");   // água
            else if (tabuleiro[i][j] == 3) printf(" N "); // navio
            else if (tabuleiro[i][j] == 5) printf(" * "); // área de habilidade
        }
        printf("\n");
    }
    printf("\n");
}

// Aplica matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[N][N], int habilidade[7][7], int origemX, int origemY) {
    int tam = 7;  // tamanho da matriz da habilidade
    int centro = tam / 2;

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if (habilidade[i][j] == 1) {
                int x = origemX + (i - centro);
                int y = origemY + (j - centro);

                if (x >= 0 && x < N && y >= 0 && y < N) {
                    if (tabuleiro[x][y] == 0) { // só marca se não for navio
                        tabuleiro[x][y] = 5;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[N][N] = {0};

    // Colocando alguns navios fixos
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[7][1] = 3;

    // Matrizes de habilidades 7x7
    int cone[7][7] = {0};
    int cruz[7][7] = {0};
    int octaedro[7][7] = {0};

    // Construindo cone
    for (int i = 0; i < 7; i++) {
        for (int j = 3 - i; j <= 3 + i; j++) {
            if (j >= 0 && j < 7 && i < 4) {
                cone[i][j] = 1;
            }
        }
    }

    // Construindo cruz
    for (int i = 0; i < 7; i++) {
        cruz[3][i] = 1;
        cruz[i][3] = 1;
    }

    // Construindo octaedro (losango)
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (abs(i - 3) + abs(j - 3) <= 3) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Exibindo tabuleiro inicial
    printf("=== Tabuleiro inicial ===\n");
    imprimirTabuleiro(tabuleiro);

    // Aplicando habilidades em posições fixas
    aplicarHabilidade(tabuleiro, cone, 2, 6);
    aplicarHabilidade(tabuleiro, cruz, 6, 3);
    aplicarHabilidade(tabuleiro, octaedro, 5, 8);

    // Exibindo tabuleiro final
    printf("=== Tabuleiro com habilidades ===\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
