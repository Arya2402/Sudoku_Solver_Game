#ifndef SUDOKU_H
#define SUDOKU_H

const int N = 9;

bool isValid(int board[N][N], int row, int col, int num);
bool solveSudoku(int board[N][N]);
void generateSudoku(int board[N][N]);
void removeNumbers(int board[N][N], int level);
void printBoard(int board[N][N]);

#endif