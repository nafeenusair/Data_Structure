#include <bits/stdc++.h>
using namespace std;
int totalNode = 100;

void addEdge(vector<vector<int>>& graph, int a, int b) {
    graph[a].push_back(b);
}

bool checkConnection(const vector<vector<int>>& graph, int startNode) {
    vector<bool> visited(graph.size(), false);
    stack<int> s;
    visited[startNode] = true;
    s.push(startNode);

    for (int i = 0; i < graph.size(); i++) {
        while (!s.empty()) {
            int currentNode = s.top();
            s.pop();
            for (int neighbor : graph[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    s.push(neighbor);
                }
            }
        }
    }

    for (int i = 0; i < graph.size(); i++) {
        if (!graph[i].empty() && !visited[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> graph(totalNode);

    addEdge(graph, 1, 2);
    addEdge(graph, 2, 2);
    addEdge(graph, 3, 4);
    bool res = checkConnection(graph, 1);
    cout << res;
}