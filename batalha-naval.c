/*
 * Tema 5 - Jogo da Batalha Naval
 * Autor: Hudson Nascimento de Lima
 * Data: 28/11/2025
 * Desafio nível Novato \o/
 * 
 * Iniciando com a posição dos navios.
 */

#include <stdio.h>

int main() {
    // Letras para identificar as linhas do tabuleiro
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};

    // Criando o tabuleiro 10x10 e inicializando com 0 (água)
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas iniciais dos navios
    int navioH_linha = 2; // linha C
    int navioH_coluna = 3; // coluna 3

    int navioV_linha = 5; // linha F
    int navioV_coluna = 7; // coluna 7

    int tamanhoNavio = 3;

    // Posicionando navio horizontal
    for (int i = 0; i < tamanhoNavio; i++) {
        if (navioH_coluna + i < 10) {
            tabuleiro[navioH_linha][navioH_coluna + i] = 3;
        }
    }

    // Posicionando navio vertical
    for (int i = 0; i < tamanhoNavio; i++) {
        if (navioV_linha + i < 10) {
            tabuleiro[navioV_linha + i][navioV_coluna] = 3;
        }
    }

    // Imprimindo o tabuleiro
    printf("   0 1 2 3 4 5 6 7 8 9\n"); // cabeçalho das colunas
    for (int i = 0; i < 10; i++) {
        printf("%c  ", linha[i]); // label da linha
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
