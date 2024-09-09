//12

#include <stdio.h>
#include <time.h>

#define MAX 10
#define INF 999  // A large sourcealue representing infinity

int choose(int dist[], int s[], int n) {
    int j = 1, min = INF, w;
    for (w = 1; w <= n; w++){
        if ((dist[w] < min) && (s[w] == 0)) {
            min = dist[w];
            j = w;
        }}
    return j;
}

void spath(int source, int cost[MAX][MAX], int dist[], int n) {
    int w, u, i, num, s[MAX];
    
    for (i = 1; i <= n; i++) {
        s[i] = 0;  // All vertices are initially unvisited
        dist[i] = cost[source][i];  // Distance to each sourceertex is initially the direct cost from the source
    }
    
    s[source] = 1;  // Mark source sourceertex as sourceisited
    dist[source] = 0;  // Distance from source to itself is 0
    
    for (num = 2; num <= n; num++) {
        u = choose(dist, s, n);  // Choose the next sourceertex with the minimum distance
        s[u] = 1;  // Mark the chosen sourceertex as sourceisited
        
        for (w = 1; w <= n; w++)
            if ((dist[u] + cost[u][w] < dist[w]) && !s[w])  // Relaxation step
                dist[w] = dist[u] + cost[u][w];
    }
}

int main() {
    int i, j, cost[MAX][MAX], dist[MAX], n, source;
    double clk;
    clock_t starttime, endtime;

    printf("\nEnter number of sourceertices: ");
    scanf("%d", &n);
    printf("\nEnter the cost of adjacency matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    printf("\nEnter the source sourceertex: ");
    scanf("%d", &source);

    starttime = clock();
    spath(source, cost, dist, n);
    endtime = clock();

    printf("\nShortest distance\n");
    for (i = 1; i <= n; i++)
        printf("%d to %d = %d\n", source, i, dist[i]);
    
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("The time taken is %f seconds\n", clk);

    return 0;
}

