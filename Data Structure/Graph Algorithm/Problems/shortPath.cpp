#include <bits/stdc++.h>
using namespace std;
int totalNodes = 100;

void addEdge(vector<vector<int>>& graph, int a, int b) {
    graph[a].push_back(b);
    graph[b].push_back(a);
}

void shortPath(vector<vector<int>>& graph) {
    vector<int> dist(graph.size(), -1);
}

int main() {
    vector<vector<int>> graph(totalNodes);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    shortPath(graph);
}