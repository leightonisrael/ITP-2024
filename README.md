# Projeto Unidade III

## Integrantes
- Israel Leighton
- Paulo Rogério
- Matheus Amorim

## Descrição do Projeto

Este projeto consiste em três programas em linguagem C que abordam diferentes desafios. O primeiro programa simula o jogo da velha, o segundo resolve o problema das N-Rainhas, e o terceiro é um desafio bônus que calcula e analisa as diferentes formas de posicionar as N-Rainhas em um tabuleiro.

## Problema 1: Jogo da Velha

### Descrição

O objetivo é criar um programa que simule o jogo da velha. O tabuleiro é inicialmente exibido com números de 1 a 9 e conforme o jogador escolhe uma posição, o número é substituído por 'X'. O computador jogará como 'O', escolhendo uma posição aleatória das disponíveis.

### Execução

```bash
gcc jogo_da_velha.c -o jogo_da_velha
./jogo_da_velha
```

## Problema 2: N-Rainhas

### Descrição

O objetivo é criar um programa que posicione N rainhas em um tabuleiro de xadrez de tamanho NxN de forma que nenhuma rainha possa atacar outra. Isso significa que nenhuma rainha deve compartilhar a mesma linha, coluna ou diagonal com outra.

### Execução

```bash 
gcc n_rainhas.c -o n_rainhas
./n_rainhas
```


# Obserações

Como foi solicitado, usamos: `Alocação de Memória`, `Vetores ou Matrizes`, `Ponteiros` e `Funções`.

## Problema 1: Jogo da Velha

``Alocação de memória dinâmica``
A memória para o tabuleiro do jogo é alocada dinamicamente usando malloc.

```
char *board = (char *)malloc(SIZE * SIZE * sizeof(char));
```

``Vetores ou matrizes``

O tabuleiro do jogo é representado por um vetor de caracteres.

```
char board[SIZE * SIZE];
```

``Ponteiros``

O tabuleiro é manipulado usando um ponteiro 
```
char *board
```
``Funções``

O código usa várias funções para modularizar o jogo:

```
void printBoard(char *board)
char checkWinner(char *board)
void playerMove(char *board)
void computerMove(char *board)
```

## Problema 2: N-Rainhas

``Alocação de memória dinâmica``

A memória para o tabuleiro NxN é alocada dinamicamente usando malloc.

```
int** tabuleiro = (int*)malloc(N * sizeof(int*));
for (int i = 0; i < N; i++)
    tabuleiro[i] = (int*)malloc(N * sizeof(int));
```

``Vetores ou matrizes``

O tabuleiro NxN é representado por uma matriz de inteiros.

```
int** tabuleiro;
```

``Ponteiros``

O tabuleiro é manipulado usando ponteiros duplos
```
 int **tabuleiro
```
``Funções``

O código usa várias funções para modularizar a solução do problema:

```
bool ehSeguro(int **tabuleiro, int linha, int coluna, int N)
bool resolverNRainhasUtil(int **tabuleiro, int coluna, int N)
void imprimirSolucao(int **tabuleiro, int N)
void resolverNRainhas(int N)
```