#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void printBoard(char *board) {
    for (int i = 0; i < SIZE * SIZE; i++) {
        if (i % SIZE == 0) printf("\n");
        printf(" %c ", board[i]);
    }
    printf("\n");
}

char checkWinner(char *board) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i * SIZE] == board[i * SIZE + 1] && board[i * SIZE + 1] == board[i * SIZE + 2])
            return board[i * SIZE];
    }
    for (int i = 0; i < SIZE; i++) {
        if (board[i] == board[SIZE + i] && board[SIZE + i] == board[2 * SIZE + i])
            return board[i];
    }
    if (board[0] == board[4] && board[4] == board[8])
        return board[0];
    if (board[2] == board[4] && board[4] == board[6])
        return board[2];
    for (int i = 0; i < SIZE * SIZE; i++) {
        if (board[i] != 'X' && board[i] != 'O')
            return '\0';
    }
    return 'D';
}

void playerMove(char *board) {
    int pos;
    printf("Escolha sua posição, jogador X: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > 9 || board[pos - 1] == 'X' || board[pos - 1] == 'O') {
        printf("Movimento inválido, tente novamente.\n");
        playerMove(board);
    } else {
        board[pos - 1] = 'X';
    }
}

void computerMove(char *board) {
    int pos;
    srand(time(NULL));
    do {
        pos = rand() % 9;
    } while (board[pos] == 'X' || board[pos] == 'O');
    board[pos] = 'O';
    printf("O computador escolheu a posição: %d\n", pos + 1);
}

int main() {
    char *board = (char *)malloc(SIZE * SIZE * sizeof(char));
    if (board == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < SIZE * SIZE; i++) {
        board[i] = '1' + i;
    }

    char winner = '\0';

    while (winner == '\0') {
        printBoard(board);
        playerMove(board);
        winner = checkWinner(board);
        if (winner != '\0') break;
        computerMove(board);
        winner = checkWinner(board);
    }

    printBoard(board);

    if (winner == 'X') {
        printf("Parabéns, jogador X, você venceu!\n");
    } else if (winner == 'O') {
        printf("O computador venceu!\n");
    } else {
        printf("O jogo terminou em empate!\n");
    }

    free(board);
    return 0;
}
