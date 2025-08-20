#include <stdio.h>

#define TAM 10        // Tamanho do tabuleiro
#define AGUA 0        // Representa água
#define NAVIO 3       // Representa navio
#define HABILIDADE 5  // Representa área de efeito da habilidade
#define TAM_HAB 5     // Tamanho fixo das matrizes de habilidade (5x5)

// ---------- Protótipos ----------
void inicializarTabuleiro(int tabuleiro[TAM][TAM]);
void exibirTabuleiro(int tabuleiro[TAM][TAM]);
void criarCone(int habilidade[TAM_HAB][TAM_HAB]);
void criarCruz(int habilidade[TAM_HAB][TAM_HAB]);
void criarOctaedro(int habilidade[TAM_HAB][TAM_HAB]);
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna);

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);

    // Criando as matrizes de habilidade
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Colocando um navio fixo só para visualização
    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;

    // Aplicando habilidades em diferentes pontos
    aplicarHabilidade(tabuleiro, cone, 5, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 5, 7);

    // Exibindo tabuleiro final
    printf("Tabuleiro com habilidades:\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}

// ---------- Inicializa todo o tabuleiro com água ----------
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// ---------- Exibe o tabuleiro ----------
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == AGUA)
                printf(" ~ "); // água
            else if (tabuleiro[i][j] == NAVIO)
                printf(" N "); // navio
            else if (tabuleiro[i][j] == HABILIDADE)
                printf(" * "); // habilidade
        }
        printf("\n");
    }
}

// ---------- Cria matriz em formato de cone ----------
void criarCone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            habilidade[i][j] = 0;
            if (j >= TAM_HAB/2 - i && j <= TAM_HAB/2 + i && i < TAM_HAB) {
                habilidade[i][j] = 1;
            }
        }
    }
}

// ---------- Cria matriz em formato de cruz ----------
void criarCruz(int habilidade[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == centro || j == centro)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// ---------- Cria matriz em formato de octaedro (losango) ----------
void criarOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// ---------- Aplica a habilidade ao tabuleiro ----------
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha + (i - centro);
                int coluna = origemColuna + (j - centro);
                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                    if (tabuleiro[linha][coluna] == AGUA) {
                        tabuleiro[linha][coluna] = HABILIDADE;
                    }
                }
            }
        }
    }
}
