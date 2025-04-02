#include <iostream>
#include "sudoku.h"
using namespace std;

int main() {
    srand(time(0));
    string name;
    cout << "Enter your name: ";
    cin >> name;
    
    int board[N][N];
    generateSudoku(board);
    int solution[N][N];
    memcpy(solution, board, sizeof(board));
    
    int level;
    cout << "\nHello, " << name << "! Select your difficulty level:\n1. Noob\n2. Pro\n3. Legend\nEnter your choice (1-3): ";
    cin >> level;
    if (level < 1 || level > 3) {
        cout << "Invalid choice! Defaulting to Pro level.\n";
        level = 2;
    }
    
    cout << "\nHere is your Sudoku puzzle, " << name << "! Good luck!\n";
    removeNumbers(board, level);
    printBoard(board);
    
    string choice;
    cout << "\nHey " << name << ", did you really solve the Sudoku? (yes/no): ";
    cin >> choice;
    
    if (choice == "yes") {
        string checkSolution;
        cout << "\nDo you want to see the solution for checking? (yes/no): ";
        cin >> checkSolution;
        if (checkSolution == "yes") {
            cout << "\nHere is the solution, " << name << "! Well done!\n";
            printBoard(solution);
        } else {
            cout << "Good job, " << name << "! Keep practicing! 💪\n";
        }
    } else {
        string wantSolution;
        cout << "\nDo you want to see the solution? (yes/no): ";
        cin >> wantSolution;
        if (wantSolution == "yes") {
            cout << "\nBetter luck next time, " << name << "! Here is the solution:\n";
            printBoard(solution);
        } else {
            cout << "Good job, " << name << "! Keep trying! 💪\n";
            cout << "\nIf you need the solution later, type 'answer'.\n";
        }
    }
    return 0;
}
