#include <bits/stdc++.h>
using namespace std;
#define V 4

void init(int adjMatrix[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int adjMatrix[][V], int i, int j) {
    adjMatrix[i][j] = 1;
    adjMatrix[j][i] = 1;
}

void printMatrix(int adjMatrix[][V]) {
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        } cout << endl;
    }
}

int main() {
    int adjMatrix[V][V];

    init(adjMatrix);
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 1, 2);

    printMatrix(adjMatrix);
}