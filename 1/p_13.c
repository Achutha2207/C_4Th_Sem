#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1

int board[20];

int isSafe(int currentRow, int currentColumn) {
    int previousRow;

    // Check for conflicts with previously placed queens
    for (previousRow = 1; previousRow < currentRow; previousRow++) {
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

    printf("Enter the value of n (number of queens): ");
    scanf("%d", &boardSize);

    if (boardSize <= 0 || boardSize == 2 || boardSize == 3) {
        printf("The solution for %d does not exist.\n", boardSize);
        return 1; // Terminate the program if no solution exists
    }

    printf("The solution(s) to the N-Queens problem is/are:\n");
    solveNQueens(1, boardSize);

    return 0;
}

