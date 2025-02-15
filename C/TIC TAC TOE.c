#include <stdio.h>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf(" %c ", board[i][j]);
        printf("\n");
    }
}

int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

void playGame() {
    int player = 1, choice;
    char mark;
    for (int turn = 0; turn < 9; turn++) {
        displayBoard();
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';
        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        if (board[row][col] != 'X' && board[row][col] != 'O')
            board[row][col] = mark;
        else {
            printf("Invalid move! Try again.\n");
            turn--;
            continue;
        }
        if (checkWinner()) {
            displayBoard();
            printf("Player %d wins!\n", player);
            return;
        }
    }
    displayBoard();
    printf("It's a draw!\n");
}

int main() {
    playGame();
    return 0;
}
