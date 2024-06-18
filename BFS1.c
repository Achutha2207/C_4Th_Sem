#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int node) {
    if(rear == MAX-1)
        printf("\nQueue is Full!!");
    else {
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = node;
    }
}

int dequeue() {
    if(front == -1 || front > rear) {
        printf("\nQueue is Empty!!");
        return -1;
    } else {
        int data = queue[front];
        front++;
        if(front > rear)
            front = rear = -1;
        return data;
    }
}

void BFS(int v, int n) {
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(v);

    while(front != -1) {
        int current = dequeue();
        visited[current] = 1;
        printf("%d ", current);

        for(int i = 0; i < n; i++) {
            if(adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, v;
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter the starting city: ");
    scanf("%d", &v);
printf("End Code\n");
    printf("Cities reachable from city %d are: ", v);
    BFS(v, n);

    return 0;
}

