#include<stdio.h>

int count = 0, w[10], d, x[10];

void subset(int cs, int k, int r) {
    int i;
    x[k] = 1;
    if ((cs + w[k]) == d) { // Corrected condition to check if current sum matches desired sum
        printf("\n Subset solution = %d\n", ++count);
        for (i = 0; i <= k; i++) {
            if (x[i] == 1)
                printf("%d\n", w[i]);
        }
    } else if (cs + w[k] + w[k + 1] <= d && k + 1 < 10) { // Added bounds check for k+1
        subset(cs + w[k], k + 1, r - w[k]);
    }

    if ((cs + r - w[k] >= d) && (cs + w[k + 1] <= d) && k + 1 < 10) { // Added bounds check for k+1
        x[k] = 0;
        subset(cs, k + 1, r - w[k]);
    }
}

int main() {
    int sum = 0, i, n;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter the elements in ascending order\n");
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);
    printf("Enter the required sum\n");
    scanf("%d", &d);
    for (i = 0; i < n; i++)
        sum += w[i];

    if (sum < d) {
        printf("No solution exists\n");
    } else {
        printf("The solution is\n");
        count = 0;
        subset(0, 0, sum);
        if (count == 0) {
            printf("No solution exists\n");
        }
    }
    return 0;
}

