# 🚢 Batalha Naval --- Nível Aventureiro

## Posicionamento de Navios Horizontais, Verticais e Diagonais

## 📌 Descrição do Projeto

Este projeto implementa o posicionamento de **quatro navios** em um
tabuleiro 10x10 do jogo **Batalha Naval**, utilizando a linguagem C.

Este é o **Nível Aventureiro** da evolução proposta, onde além dos
navios horizontais e verticais (introduzidos no nível anterior), agora o
programa também posiciona **navios na diagonal**, exigindo um tratamento
adicional de limites e validação de sobreposição.

O código demonstra de forma clara:

-   manipulação de **matrizes bidimensionais**,\
-   uso de **loops aninhados**,\
-   verificação de coordenadas,\
-   e aplicação de lógica simples para evitar colisões.

------------------------------------------------------------------------

## ⚓ Funcionalidades

-   Criação de um tabuleiro **10x10**, inicializado com `0` (água).
-   Posicionamento de **quatro navios** de tamanho fixo 3:
    -   **2 navios** horizontais ou verticais.
    -   **2 navios** colocados **na diagonal** (↘ e ↙).
-   Validação de:
    -   limites do tabuleiro,
    -   sobreposição entre navios.
-   Representação dos navios com o valor `3`.
-   Exibição amigável do tabuleiro, com linhas (`A–J`) e colunas
    (`0–9`).

------------------------------------------------------------------------

## 🧠 Lógica do Código

### 1. Criação e inicialização do tabuleiro

``` c
int tabuleiro[TAM][TAM];
for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
        tabuleiro[i][j] = 0; // água
    }
}
```

------------------------------------------------------------------------

### 2. Coordenadas iniciais dos navios

Coordenadas definidas diretamente no código, conforme simplificação
permitida pelo nível:

-   1 navio horizontal\
-   1 navio vertical\
-   2 navios diagonais (↘ e ↙)

Todos com tamanho **3**.

------------------------------------------------------------------------

### 3. Validação antes de posicionar

O programa verifica:

-   se o navio cabe na direção desejada,\
-   se não ultrapassa o limite do tabuleiro,\
-   se nenhuma posição já está ocupada.

Trecho do validador:

``` c
if (l < 0 || l >= TAM || c < 0 || c >= TAM)
    return 0;
if (tab[l][c] == OCUPADO)
    return 0;
```

------------------------------------------------------------------------

### 4. Posicionamento do navio

``` c
tab[linha + dx * i][coluna + dy * i] = OCUPADO;
```

Cada navio usa um vetor direção (`dx`, `dy`):

-   Horizontal → (0, 1)\
-   Vertical → (1, 0)\
-   Diagonal ↘ → (1, 1)\
-   Diagonal ↙ → (1, -1)

------------------------------------------------------------------------

### 5. Exibição do tabuleiro

``` c
printf("    0 1 2 3 4 5 6 7 8 9
");
for (int i = 0; i < TAM; i++) {
    printf("%c | ", linhaChar[i]);
    for (int j = 0; j < TAM; j++) {
        printf("%d ", tabuleiro[i][j]);
    }
    printf("
");
}
```

------------------------------------------------------------------------

## ▶️ Como Executar

1.  Salve o código como `batalha_naval.c`
2.  Compile:

``` bash
gcc batalha_naval.c -o batalha_naval
```

3.  Execute:

``` bash
./batalha_naval
```

O tabuleiro será exibido no console com os navios posicionados.

------------------------------------------------------------------------

## 🧪 Saída Esperada (exemplo ilustrativo)

Os valores podem variar conforme as coordenadas definidas, mas o formato
é assim:

        0 1 2 3 4 5 6 7 8 9
    A | 0 0 0 0 0 0 0 0 0 0
    B | 0 3 0 0 0 0 0 0 3 0
    C | 0 0 3 3 3 0 0 0 0 0
    D | 0 0 0 0 0 0 0 3 0 0
    E | 0 0 0 0 0 0 0 3 0 0
    F | 0 0 0 0 0 0 0 3 0 0
    G | 0 0 0 0 0 0 0 0 0 0
    H | 0 0 0 0 0 0 0 0 0 0
    I | 0 0 0 0 0 0 0 0 0 0
    J | 0 0 0 0 0 0 0 0 0 0

------------------------------------------------------------------------

## 📝 Observações

-   As coordenadas dos navios são definidas diretamente no código,
    conforme instruções do desafio.
-   A validação impede sobreposição e saída dos limites.
-   Este nível **não envolve ataques, acertos ou lógica de jogo** ---
    apenas posicionamento.
-   O código está documentado e organizado para facilitar entendimento.

------------------------------------------------------------------------

## 👨‍💻 Autor

**Hudson Nascimento de Lima**
