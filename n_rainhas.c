#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função para verificar se é seguro colocar uma rainha em tabuleiro[linha][coluna]
bool ehSeguro(int** tabuleiro, int linha, int coluna, int N) {
    int i, j;

    // Verificar a coluna à esquerda
    for (i = 0; i < coluna; i++)
        if (tabuleiro[linha][i])
            return false;

    // Verificar a diagonal superior à esquerda
    for (i = linha, j = coluna; i >= 0 && j >= 0; i--, j--)
        if (tabuleiro[i][j])
            return false;

    // Verificar a diagonal inferior à esquerda
    for (i = linha, j = coluna; j >= 0 && i < N; i++, j--)
        if (tabuleiro[i][j])
            return false;

    return true;
}

// Função recursiva para resolver o problema das N-Rainhas
bool resolverNRainhasUtil(int** tabuleiro, int coluna, int N) {
    if (coluna >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (ehSeguro(tabuleiro, i, coluna, N)) {
            tabuleiro[i][coluna] = 1;

            if (resolverNRainhasUtil(tabuleiro, coluna + 1, N))
                return true;

            tabuleiro[i][coluna] = 0; // BACKTRACK
        }
    }
    return false;
}

// Função para imprimir a solução
void imprimirSolucao(int** tabuleiro, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(tabuleiro[i][j] ? " R " : " . ");
        printf("\n");
    }
}

// Função principal para resolver o problema das N-Rainhas
void resolverNRainhas(int N) {
    int** tabuleiro = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        tabuleiro[i] = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tabuleiro[i][j] = 0;

    if (!resolverNRainhasUtil(tabuleiro, 0, N)) {
        printf("Solução não existe\n");
        return;
    }

    imprimirSolucao(tabuleiro, N);

    for (int i = 0; i < N; i++)
        free(tabuleiro[i]);
    free(tabuleiro);
}

int main() {
    int N;
    printf("Digite o tamanho do tabuleiro (N): ");
    scanf("%d", &N);
    resolverNRainhas(N);
    return 0;
}