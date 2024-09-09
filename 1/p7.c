#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *a, n;

void heapify(int a[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i; // left child
    int right = 2 * i + 1; // right child

    // If left child is larger than root
    if (left <= n && a[left] > a[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right <= n && a[right] > a[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2; i >= 1; i--)
        heapify(a, n, i);

    // One by one extract an element from heap
    for (int i = n; i >= 2; i--) {
        // Move current root to end
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;

        // Call max heapify on the reduced heap
        heapify(a, i - 1, 1);
    }
}

int main() {
    int r;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Allocate memory for the array
    a = (int *)malloc((n + 1) * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Do you want to give the values or randomly allocate? [0/1]: ");
    scanf("%d", &r);

    if (r == 0) {
        printf("Enter the elements:\n");
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
    } else {
        printf("The random elements are:\n");
        for (int i = 1; i <= n; i++) {
            a[i] = rand() % 100;
            printf("%d\t", a[i]);
        }
        printf("\n");
    }

    clock_t s, e;
    double t;

    s = clock();

    heap_sort(a, n);

    e = clock();

    t = (double)(e - s) / CLOCKS_PER_SEC;

    printf("Sorted elements:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
    printf("The time required to compute heap sort is %f seconds\n", t);

    // Free allocated memory
    free(a);

    return 0;
}

