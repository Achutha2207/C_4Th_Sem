
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *queue;
int front = 0;
int rear = -1;
int **graph;
int *visited;
int num_vertices;

void enqueue(int vertex) {
    queue[++rear] = vertex;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return rear < front;
}

void bfs(int start_vertex) {
    visited[start_vertex] = 1;
    enqueue(start_vertex);

    while(!isEmpty()) {
        int current_vertex = dequeue();
        printf("Visited %d\n", current_vertex);

        for(int i = 0; i < num_vertices; i++) {
            if(graph[current_vertex][i] == 1 && !visited[i]) {
                printf(" Node %d --->>>  Node %d\n",current_vertex,i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
	clock_t start,end;
	double time;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    // Dynamically allocate memory for the graph and visited array.
    graph = (int **)malloc(num_vertices * sizeof(int *));
    for(int i = 0; i < num_vertices; i++) {
        graph[i] = (int *)malloc(num_vertices * sizeof(int));
    }

    visited = (int *)malloc(num_vertices * sizeof(int));

    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < num_vertices; i++) {
        for(int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for(int i = 0; i < num_vertices; i++) {
        visited[i] = 0;
    }

    queue = (int *)malloc(num_vertices * sizeof(int));

    printf("Enter the starting vertex: ");
    int start_vertex;
    scanf("%d", &start_vertex);

	start=clock();
    bfs(start_vertex);  // Start BFS traversal from the start_vertex.
	end=clock();

	time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Visited nodes array: ");
    for(int i = 0; i < num_vertices; i++) {
        printf("%d ", visited[i]);
    }
    printf("\n");

    // Free dynamically allocated memory.
    free(queue);
    free(visited);
    for(int i = 0; i < num_vertices; i++) {
        free(graph[i]);
    }
    free(graph);

	printf("The Time To Execute BFS Is %.f μs\n",time*(10e5));
    return 0;
}
