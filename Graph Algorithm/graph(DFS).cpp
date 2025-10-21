#include <bits/stdc++.h>
using namespace std;

int top = -1;
vector<int> vecStack;

void addEdge(vector<vector<int>>& graph, int a, int b) {
    graph[a].push_back(b);
    graph[b].push_back(a);
}

bool isEmpty() {
    if (top == -1) return true;
    return false;
}

void push(int x) {
    if (isEmpty()) {
        top = 0;
    }

    vecStack.push_back(x);
    top = vecStack.size() - 1;
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    }

    int x = vecStack[top--];
    return x;
}

int peek() {
    return vecStack[top];
}

void performDFS(vector<vector<int>>& graph, int startNode) {
    vector<bool> visited(graph.size(), false);
    push(startNode);

    cout << "DFS Traversal: ";
    while (!isEmpty()) {
        int currentNode = pop();

        if (!visited[currentNode]) {
            visited[currentNode] = true;
            cout << currentNode << " ";

            for (int neighbor : graph[currentNode]) {
                if (!visited[neighbor]) {
                    push(neighbor);
                }
            }
        }
    }
}

int main() {
    int choice;
    vector<vector<int>> graph(100);

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

    performDFS(graph, 10);
}