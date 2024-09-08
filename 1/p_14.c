#include<stdio.h>

int count = 0, a[10], target, b[10];
int n;
void subset(int cs, int index, int ts) {

    b[index] = 1;
    if ((cs + a[index]) == target) { // Corrected condition to checindex if current sum matches desired sum
        printf("\n Subset solution = %d\n", ++count);
        for (int i = 0; i<=index; i++) {
            if (b[i] == 1){
                printf("%d\t", a[i]);}
        }printf("\n");
    } else if (cs + a[index] + a[index + 1] <= target && index + 1 < n) { // Added bounds checindex for index+1
        subset(cs + a[index], index + 1, ts - a[index]);
    }

    if ((cs + ts - a[index] >= target)&& index + 1 < n&&(cs + a[index + 1] <=target)) { // Added bounds checindex for index+1
        b[index] = 0;
        subset(cs, index + 1, ts - a[index]);
    }
}

int main() {
    int sum = 0;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter the elements in ascending order\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the required sum\n");
    scanf("%d", &target);
    for (int i = 0; i < n; i++)
        sum += a[i];

    if (sum < target) {
        printf("No solution ebists\n");
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

