#include <stdio.h>

#define MAX_SIZE 100  // Define a maximum size for the input set

void findSubset(int w[], int x[], int n, int k, int cs, int index) {
    // If current sum equals target sum, print the subset
    if (cs == k) {
        printf("Subset found: ");
        for (int i = 0; i < n; i++) {
            if (x[i] == 1) {
                printf("%d ", w[i]);
            }
        }
        printf("\n");
        return;
    }

    // If current sum exceeds the target sum or we have considered all elements
    //bounding condition for pruning the branches
    if (cs > k || index >= n) {
        return;
    }

    // Include the current element
    x[index] = 1;
    findSubset(w, x, n, k, cs + w[index], index + 1);

    // Exclude the current element and backtrack
    x[index] = 0;
    findSubset(w, x, n, k, cs, index + 1);
}

int main() {
    int n, k;
    int w[MAX_SIZE];  // Input set
    int x[MAX_SIZE];  // Array to track inclusion (1) or exclusion (0) of elements

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        x[i] = 0;  // Initialize inclusion array to 0
    }

    printf("Enter the target sum: ");
    scanf("%d", &k);

    printf("Subsets with the target sum %d:\n", k);
    findSubset(w, x, n, k, 0, 0);

    return 0;
}

