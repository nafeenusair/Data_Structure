#include <bits/stdc++.h>
using namespace std;

vector<int> Stack;

bool isEmpty() {
    return Stack.empty();
}

void push(int x) {
    Stack.push_back(x);
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    }

    int x = Stack.back();
    Stack.pop_back();
    return x;
}

void findMiddle(){
    int n = (Stack.size());
    n /= 2;

    cout << n << endl;
    int mid = Stack[n];
    cout << mid;
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    findMiddle();
}