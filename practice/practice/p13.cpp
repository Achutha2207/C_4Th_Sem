#include <stdio.h>
#include <math.h>
#define FALSE 0
#define TRUE 1
#include <iostream>

using namespace std;

int board[20];

int isSafe(int currentRow, int currentColumn) {
    int previousRow;

    // Check for conflicts with previously placed queens
    for (previousRow = 1; previousRow <= currentRow; previousRow++) {
        if ((board[previousRow] == currentColumn) ||  // Same column
            (abs(board[previousRow] - currentColumn) == abs(previousRow - currentRow))) {  // Same diagonal
            return FALSE;
        }
    }
    return TRUE;
}

void solveNQueens(int currentRow, int boardSize) {
    int currentColumn, row;

    // Try to place a queen in every column of the current row
    for (currentColumn = 1; currentColumn <= boardSize; currentColumn++) {
        if (isSafe(currentRow, currentColumn)) {
            board[currentRow] = currentColumn;  // Place queen

            // If all queens are placed
            if (currentRow == boardSize) {
                // Print the board
                for (row = 1; row <= boardSize; row++) {
                    printf("%d\t", board[row]);
                }
                printf("\n");
            } else {
                // Recursively place the rest of the queens
                solveNQueens(currentRow + 1, boardSize);
            }
        }
    }
}

int main() {
    int boardSize;

    cout << "Enter the value of n (number of queens): ";
    cin >> boardSize;

    if (boardSize <= 0 || boardSize == 2 || boardSize == 3) {
        cout << "The solution for " << boardSize << " does not exist." << endl;
        return 1; // Terminate the program if no solution exists
    }

    cout << "The solution(s) to the N-Queens problem is/are:" << endl;
    solveNQueens(1, boardSize);

    return 0;
}

