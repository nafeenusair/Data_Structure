#include <bits/stdc++.h>
using namespace std;

vector<int> Stack1;
vector<int> Stack2;

bool isEmpty() {
    return Stack1.empty() && Stack2.empty();
}

void enqueue(int x) {
    Stack1.push_back(x);
}

int dequeue() {
    if(isEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    }

    if (Stack2.empty()) {
        while (!Stack1.empty()) {
            int x = Stack1.back();
            Stack1.pop_back();
            Stack2.push_back(x);
        }
    }

    int x = Stack2.back();
    Stack2.pop_back();
    return x;
}

int main() {
    enqueue(1);
    enqueue(2);
    int x = dequeue();
    bool y = isEmpty();

    cout << x << endl;
    cout << y << endl;
}