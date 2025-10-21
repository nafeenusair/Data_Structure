#include <bits/stdc++.h>
using namespace std;

int maxNode = 100;

void addEdge(vector<vector<int>>& graph, int a, int b) {
    graph[a].push_back(b);
    graph[b].push_back(a);
}

bool BFS(const vector<vector<int>>& graph, int startNode) {
    vector<int> color(maxNode, 0);
    queue<int> q;
    q.push(startNode);
    color[startNode] = 1;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        for (int neighbor : graph[currentNode]) {
            if (color[neighbor] == color[currentNode]) {
                return false;
            }
            else if (!color[neighbor]) {
                color[neighbor] = -color[currentNode];
                q.push(neighbor);
            }
        }
    }

    return true;
}

void display(const vector<vector<int>>& graph) {
    for (int i = 0; i < graph.size(); i++) {
        if (!graph[i].empty()) {
            cout << i << ": ";
            for (int neighbor : graph[i]) {
                cout << neighbor << " ";
            } cout << endl;
        }
    }
}

int main() {
    vector<vector<int>> graph(maxNode);

    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);
    display(graph);
    bool res = BFS(graph, 1);
    cout << res;
}