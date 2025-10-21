#include <bits/stdc++.h>
using namespace std;

vector<int> vecQueue;
int totalNode = 100;
int front, rear = -1;

void addEdge(vector<vector<int>>& graph, int a, int b) {
    graph[a].push_back(b);
    graph[b].push_back(a);
}

bool isEmpty() {
    if (front == -1 && rear == -1) return true;
    return false;
}

void enqueue(int n) {
    if (isEmpty()) {
        front = 0;
    }

    vecQueue.push_back(n);
    rear = vecQueue.size() - 1;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow" << endl;
        return {};
    }

    int x = vecQueue[front];
    if (front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
    return x;
}

void performBFS(vector<vector<int>>& graph, int startNode) {
    vector<bool> visited(totalNode, false);
    visited[startNode] = true;
    enqueue(startNode);

    cout << "BFS Traverse: ";
    while (!isEmpty()) {
        int currentNode = dequeue();
        cout << currentNode << " ";

        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                enqueue(neighbor);
            }
        }
    }
    cout << endl;
}

void printGraph(const vector<vector<int>>& graph) {
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
    vector<vector<int>> graph(totalNode);
    int choice;

    while (true) {
        cout << "1. Add edge" << endl <<
                "2. Exit" << endl <<
                "Your choice: ";
        cin >> choice;
        if (choice == 1) {
            if (!graph.empty()) {
                int a, b;
                cout << "Enter row and column: ";
                cin >> a >> b;
                addEdge(graph, a, b);
            }
            else {
                cout << "List is Full" << endl;;
                break;
            }
        }
        else if (choice == 2) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            throw runtime_error("Invalid Entry! Please try again");
        }
    } cout << endl;

    performBFS(graph, 10);
    printGraph(graph);
}