/*
 * Tema 5 - Jogo da Batalha Naval
 * Autor: Hudson Nascimento de Lima
 * Data: 29/11/2025
 * Desafio nível Aventureiro \o/
 *
 * Objetivo:
 *  - Criar um tabuleiro 10x10
 *  - Posicionar 4 navios (2 normais + 2 diagonais)
 *  - Todos com tamanho 3
 *  - Garantir limites e evitar sobreposições
 *  - Exibir o tabuleiro
 */

#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define OCUPADO 3

// -----------------------------------------------------------
// Função para verificar se é possível posicionar um navio
// sem sair do tabuleiro e sem sobrepor outro navio
// -----------------------------------------------------------
int podeColocar(int tab[TAM][TAM], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < NAVIO; i++) {
        int l = linha + dx * i;
        int c = coluna + dy * i;

        // Verifica bordas
        if (l < 0 || l >= TAM || c < 0 || c >= TAM) {
            return 0; // não pode
        }

        // Verifica sobreposição
        if (tab[l][c] == OCUPADO) {
            return 0; // não pode
        }
    }
    return 1; // tudo ok
}

// -----------------------------------------------------------
// Função para posicionar o navio no tabuleiro
// -----------------------------------------------------------
void colocarNavio(int tab[TAM][TAM], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < NAVIO; i++) {
        tab[linha + dx * i][coluna + dy * i] = OCUPADO;
    }
}

int main() {

    // Letras para as linhas
    char linhaChar[TAM] = {'A','B','C','D','E','F','G','H','I','J'};

    // -----------------------------------------------------------
    // 1. Criando o tabuleiro e preenchendo com água (0)
    // -----------------------------------------------------------
    int tabuleiro[TAM][TAM];
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // -----------------------------------------------------------
    // 2. Definição das coordenadas iniciais dos 4 navios
    //    (fixas conforme regras do desafio)
    // -----------------------------------------------------------

    // Navio horizontal → direita
    int n1_l = 2;  // linha C
    int n1_c = 3;  // coluna 3
    int dx1 = 0, dy1 = 1;

    // Navio vertical → para baixo
    int n2_l = 5;  // linha F
    int n2_c = 7;  // coluna 7
    int dx2 = 1, dy2 = 0;

    // Navio diagonal ↘ (linha e coluna aumentam)
    int n3_l = 1;  // linha B
    int n3_c = 1;  // coluna 1
    int dx3 = 1, dy3 = 1;

    // Navio diagonal ↙ (linha aumenta, coluna diminui)
    int n4_l = 1;  // linha B
    int n4_c = 8;  // coluna 8
    int dx4 = 1, dy4 = -1;

    // -----------------------------------------------------------
    // 3. Validação + posicionamento
    // -----------------------------------------------------------

    if (podeColocar(tabuleiro, n1_l, n1_c, dx1, dy1))
        colocarNavio(tabuleiro, n1_l, n1_c, dx1, dy1);

    if (podeColocar(tabuleiro, n2_l, n2_c, dx2, dy2))
        colocarNavio(tabuleiro, n2_l, n2_c, dx2, dy2);

    if (podeColocar(tabuleiro, n3_l, n3_c, dx3, dy3))
        colocarNavio(tabuleiro, n3_l, n3_c, dx3, dy3);

    if (podeColocar(tabuleiro, n4_l, n4_c, dx4, dy4))
        colocarNavio(tabuleiro, n4_l, n4_c, dx4, dy4);

    // -----------------------------------------------------------
    // 4. Exibindo o tabuleiro completo
    // -----------------------------------------------------------
    printf("    0 1 2 3 4 5 6 7 8 9\n");

    for (int i = 0; i < TAM; i++) {
        printf("%c | ", linhaChar[i]); // label da linha
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
