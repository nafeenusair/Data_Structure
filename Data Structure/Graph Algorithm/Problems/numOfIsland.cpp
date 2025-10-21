#include<bits/stdc++.h>
using namespace std;

bool isSafe(const vector<vector<int>>& graph, int r, int c, vector<vector<bool>>& visited) {
    int row = graph.size();
    int col = graph[0].size();

    return (r >= 0) && (r < row) && (c >= 0) && (c < col) && graph[r][c] == 1 && !visited[r][c];
}

void DFS(const vector<vector<int>>& graph, int r, int c, vector<vector<bool>>& visited) {
    vector<int> rNbr = {-1, 0, 0, 1};
    vector<int> cNbr = {0, -1, 1, 0};
    visited[r][c] = true;

    for (int k = 0; k < 4; k++) {
        int newR = r + rNbr[k];
        int newC = c + cNbr[k];

        if (isSafe(graph, newR, newC, visited)) {
            DFS(graph, newR, newC, visited);
        }
    }
}

int countIsland(const vector<vector<int>>& graph) {
    int row = graph.size();
    int col = graph[0].size();
    vector<vector<bool>> visited(row, vector<bool> (col, false));
    int count = 0;

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (graph[r][c] == 1 && !visited[r][c]) {
                DFS(graph, r, c, visited);
                ++count;
            }
        }
    }

    return count;
}

int main() {
    vector<vector<int>> graph = {{1, 1, 0, 0, 0},
                             {1, 1, 0, 1, 0},
                             {0, 0, 1, 0, 0},
                             {0, 0, 0, 1, 1}};

    cout << countIsland(graph) << endl;
}