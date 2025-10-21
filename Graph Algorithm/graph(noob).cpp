#include <bits/stdc++.h>
using namespace std;

int main() {
    char vertex[26];
    int graph[100][100], noOfVertex;

    for (int i = 0; i < 26; i++) {
        vertex[i] = 'A' + i;
    }

    for (char x : vertex) {
        cout << x << " ";
    }

    cout << endl << "Number of Vertex?: ";
    cin >> noOfVertex;

    for (int i = 0; i < noOfVertex; i++) {
        for (int j = 0; j < noOfVertex; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < noOfVertex; i++) {
        for (int j = i + 1; j < noOfVertex; j++) {
            cout << vertex[i] << "-" << vertex[j] << ": ";
            cin >> graph[i][j];
            if (graph[i][j] == 1) graph[j][i] = 1;
        }
    }

    for (int i = 0; i < noOfVertex; i++) {
        cout << vertex[i] << ": ";
        for (int j = 0; j < noOfVertex; j++) {
            if (graph [i][j] == 1) cout << vertex[j] << " ";
        }
        cout << endl;
    }
}