#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "sudoku.h"

using namespace std;

bool isValid(int board[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }
    
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

bool solveSudoku(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board))
                            return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void generateSudoku(int board[N][N]) {
    memset(board, 0, sizeof(int) * N * N);
    srand(time(0));
    solveSudoku(board);
}

void removeNumbers(int board[N][N], int level) {
    srand(time(0));
    int blanks = (level == 1) ? 30 : (level == 2) ? 40 : 50;
    
    while (blanks > 0) {
        int row = rand() % N;
        int col = rand() % N;
        if (board[row][col] != 0) {
            board[row][col] = 0;
            blanks--;
        }
    }
}

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------------------------------\n";
    }
    cout << "\n";
}
