#include <iostream>
#include <limits.h> // for INT_MAX
using namespace std;

int nodes;

int min(int a, int b) {
    return (a > b) ? b : a;
}

// inputs -> weight matrix
// output -> distance matrix with all pairs shortest path 
// functions -> min , floyds 

void floyds(int nodes, int weights[20][20], int distance[20][20]) {
    // initialize distance matrix to weight matrix
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            distance[i][j] = weights[i][j];
        }
    }

    // assign minimum values
    for (int k = 0; k < nodes; k++) {
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }
}

int main() {
    cout << "Enter Number Of Nodes " << endl;
    cin >> nodes;

    int weights[20][20];
    int distance[20][20];

    cout << "Enter The Weights Of Edges (use a large number for infinity, e.g., 9999)" << endl;

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cin >> weights[i][j];
            if (i != j && weights[i][j] == 0) {
                weights[i][j] = INT_MAX; // No direct edge
            }
        }
    }

    floyds(nodes, weights, distance);

    cout << "All Pairs Shortest Path Matrix Is " << endl;

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            if (distance[i][j] == INT_MAX) {
                cout << "INF\t";
            } else {
                cout << distance[i][j] << "\t";
            }
        }
        cout << endl;
    }
    return 0;
}

