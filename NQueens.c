#include <stdio.h>

#define N 5   // change this for different sizes

int board[N][N];

// function to print solution
void printBoard() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// check if safe to place queen
int isSafe(int row, int col) {
    int i, j;

    // check column
    for(i = 0; i < row; i++) {
        if(board[i][col] == 1)
            return 0;
    }

    // check left diagonal
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1)
            return 0;
    }

    // check right diagonal
    for(i = row, j = col; i >= 0 && j < N; i--, j++) {
        if(board[i][j] == 1)
            return 0;
    }

    return 1;
}

// solve using backtracking
void solve(int row) {
    if(row == N) {
        printBoard();
        return;
    }

    for(int col = 0; col < N; col++) {
        if(isSafe(row, col)) {
            board[row][col] = 1;
            solve(row + 1);
            board[row][col] = 0; // backtrack
        }
    }
}

int main() {
    solve(0);
    return 0;
}