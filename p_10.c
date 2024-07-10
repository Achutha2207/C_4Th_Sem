#include <stdio.h>
#include <stdlib.h>

// Global variables for item values, weights, and the knapsack DP table
int values[10], weights[10], v[11][21], knap, i, j, n;

// Function to return the maximum of two integers
int max(int x, int y) {
    return (x > y) ? x : y;
}

// Function to compute the maximum value that can be obtained with the given knapsack capacity
void knapsack() {
    // Iterate over each item
    for (i = 0; i <= n; i++) {
        // Iterate over each capacity from 0 to knap
        for (j = 0; j <= knap; j++) {
            // Initialize the first row and column to 0
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            } 
            // If the current item's weight is more than the current capacity, skip the item
            else if (weights[i-1] > j) {
                v[i][j] = v[i-1][j];
            } 
            // Otherwise, consider including the current item and take the maximum value
            else {
                v[i][j] = max(v[i-1][j], v[i-1][j-weights[i-1]] + values[i-1]);
            }
        }
    }
}

int main() {
    // Prompt the user for the number of items
    printf("Enter the number of items (max 10): ");
    scanf("%d", &n);
    
    // Input validation for number of items
    if (n > 10) {
        printf("Number of items should not exceed 10.\n");
        return 1;
    }
    
    // Prompt the user to enter the values of the items
    printf("Enter the values of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    
    // Prompt the user to enter the weights of the corresponding items
    printf("Enter the weights of the corresponding items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    
    // Prompt the user to enter the maximum capacity of the knapsack
    printf("Enter the maximum knapsack capacity: ");
    scanf("%d", &knap);
    
    // Call the knapsack function to compute the maximum value
    knapsack();
    
    // Print the maximum value that can be obtained
    printf("The maximum knapsack value is %d\n", v[n][knap]);
    
    // Optional: Print the DP table for reference
    printf("DP table:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= knap; j++) {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

