# 🛳️ Tema 5 – Batalha Naval  
## Nível Aventureiro – Matrizes, Operações e Áreas de Efeito

Este exercício faz parte do curso de lógica e programação em C, no qual evoluímos o jogo **Batalha Naval** a cada desafio.  
No nível **Aventureiro**, o objetivo é expandir o tabuleiro e trabalhar com operações em matrizes usando incrementos `[i][j]`.

---

## 🎯 Objetivos do Desafio

1. Criar um tabuleiro **7x7** usando matrizes.
2. Posicionar dois navios:
   - Um **navio horizontal** (3 células).
   - Um **navio vertical** (3 células).
3. Preencher o restante do tabuleiro com **água (0)**.
4. Usar apenas lógica intermediária:
   - loops `for`
   - incrementos `i` e `j`
   - nada avançado demais
5. Exibir o tabuleiro completo na tela.

---

## 🧠 Conceitos Trabalhados

- Criação e manipulação de matrizes bidimensionais  
- Laços de repetição `for` aninhados  
- Atribuição de valores por coordenada  
- Estruturação visual de tabuleiros  
- Uso consistente de índices `[i][j]`

---

## 📌 Regras de Posicionamento dos Navios

### Navio Horizontal  
- Tamanho: **3 células**  
- Posição inicial: Linha **C** (índice 2), coluna 3  
- Preenchimento:  
  ```
  tabuleiro[2][3] = 3  
  tabuleiro[2][4] = 3  
  tabuleiro[2][5] = 3  
  ```

### Navio Vertical  
- Tamanho: **3 células**  
- Posição inicial: Linha **F** (índice 5), coluna 1  
- Preenchimento:  
  ```
  tabuleiro[5][1] = 3  
  tabuleiro[6][1] = 3  
  tabuleiro[7][1] = 3   ❌ (fora do 7×7 → não será inserido)
  ```

---

## 🧩 Resultado: Tabuleiro 7x7

O programa exibe o tabuleiro com:

- Letras A–G para identificar linhas  
- Colunas 0–6  
- Valores:
  - `0` = água  
  - `3` = partes do navio  

---

## 💻 Código-Fonte Completo

```c
#include <stdio.h>

int main() {
    // Letras para as linhas
    char linha[7] = {'A','B','C','D','E','F','G'};

    // Criando e inicializando o tabuleiro 7x7 com água (0)
    int tabuleiro[7][7];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Tamanho dos navios
    int tamanhoNavio = 3;

    // Coordenadas do navio horizontal
    int navioH_linha = 2; // Linha C
    int navioH_coluna = 3;

    // Coordenadas do navio vertical
    int navioV_linha = 5; // Linha F
    int navioV_coluna = 1;

    // Posicionando navio horizontal
    for (int i = 0; i < tamanhoNavio; i++) {
        if (navioH_coluna + i < 7) {
            tabuleiro[navioH_linha][navioH_coluna + i] = 3;
        }
    }

    // Posicionando navio vertical
    for (int i = 0; i < tamanhoNavio; i++) {
        if (navioV_linha + i < 7) {
            tabuleiro[navioV_linha + i][navioV_coluna] = 3;
        }
    }

    // Imprimindo o tabuleiro
    printf("   0 1 2 3 4 5 6\n");
    for (int i = 0; i < 7; i++) {
        printf("%c  ", linha[i]);
        for (int j = 0; j < 7; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

---

