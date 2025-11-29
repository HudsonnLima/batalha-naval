/*
 * Tema 5 - Jogo da Batalha Naval
 * Autor: Hudson Nascimento de Lima
 * Data: 29/11/2025
 * Desafio nível Mestre (versão intermediária) - CORRIGIDO
 *
 * Observação: erro relacionado a `abs()` corrigido ao incluir <stdlib.h>.
 */

#include <stdio.h>
#include <stdlib.h>  // necessário para abs()

#define TAM 10
#define H 7     // tamanho das matrizes de habilidade
#define AFETADO 5
#define NAVIO 3

// -------------------------------
// Função simples de criar habilidade em cone ↓
// -------------------------------
void criarCone(int cone[H][H]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            cone[i][j] = 0;

            int centro = H / 2;

            // forma de cone: faixa aumenta conforme a linha desce
            if (j >= centro - i && j <= centro + i) {
                cone[i][j] = 1;
            }
        }
    }
}

// -------------------------------
// Função simples de criar habilidade em cruz
// -------------------------------
void criarCruz(int cruz[H][H]) {
    int centro = H / 2;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// -------------------------------
// Função simples de octaedro (losango)
// -------------------------------
void criarOctaedro(int oct[H][H]) {
    int centro = H / 2;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {

            // distância de Manhattan (abs() está disponível via stdlib.h)
            int dist = abs(i - centro) + abs(j - centro);

            if (dist <= centro) {
                oct[i][j] = 1;
            } else {
                oct[i][j] = 0;
            }
        }
    }
}

// -------------------------------
// Sobrepor matriz 7x7 no tabuleiro 10x10
// -------------------------------
void aplicarHabilidade(int tab[TAM][TAM], int hab[H][H], int origemL, int origemC) {
    int inicioL = origemL - H / 2;
    int inicioC = origemC - H / 2;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {

            if (hab[i][j] == 1) {
                int l = inicioL + i;
                int c = inicioC + j;

                // valida dentro do tabuleiro
                if (l >= 0 && l < TAM && c >= 0 && c < TAM) {

                    // não sobrescreve navio
                    if (tab[l][c] != NAVIO) {
                        tab[l][c] = AFETADO;
                    }
                }
            }
        }
    }
}

int main() {

    char linhaChar[TAM] = {'A','B','C','D','E','F','G','H','I','J'};

    int tab[TAM][TAM];

    // -------------------------------
    // 1. Tabuleiro base
    // -------------------------------
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tab[i][j] = 0;
        }
    }

    // -------------------------------
    // 2. Colocar navios fixos
    // -------------------------------
    tab[2][3] = NAVIO; tab[2][4] = NAVIO; tab[2][5] = NAVIO;      // horizontal
    tab[5][7] = NAVIO; tab[6][7] = NAVIO; tab[7][7] = NAVIO;      // vertical
    tab[1][1] = NAVIO; tab[2][2] = NAVIO; tab[3][3] = NAVIO;      // diagonal ↘
    tab[1][8] = NAVIO; tab[2][7] = NAVIO; tab[3][6] = NAVIO;      // diagonal ↙

    // -------------------------------
    // 3. Criando as habilidades (7x7)
    // -------------------------------
    int cone[H][H], cruz[H][H], oct[H][H];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(oct);

    // -------------------------------
    // 4. Aplicando habilidades no tabuleiro
    // -------------------------------
    aplicarHabilidade(tab, cone, 4, 3);   // cone próximo do navio horizontal
    aplicarHabilidade(tab, cruz, 6, 2);   // cruz mais à esquerda
    aplicarHabilidade(tab, oct, 5, 5);    // octaedro na região central

    // -------------------------------
    // 5. Exibir tabuleiro completo
    // -------------------------------
    printf("    0 1 2 3 4 5 6 7 8 9\n");

    for (int i = 0; i < TAM; i++) {
        printf("%c | ", linhaChar[i]);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }

    return 0;
}
