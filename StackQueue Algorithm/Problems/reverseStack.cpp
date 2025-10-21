#include <bits\stdc++.h>
using namespace std;

vector<int> Stack;

bool isEmpty() {
    return Stack.empty();
}

void push(int data) {
    Stack.push_back(data);
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    }

    int data = Stack.back();
    Stack.pop_back();
    return data;
}

void reverseElement(vector<int>& Stack) {
    if (isEmpty()) {
        cout << "Stack is Empty" << endl;
        return;
    }

    cout << "Reversed Element: ";
    while (!isEmpty()) {
        int x = pop();
        cout << x << " ";
    }
}

int main() {
    push(1);
    push(2);
    push(3);

    cout << "Entered element: ";
    for (int x : Stack) {
        cout << x << " ";
    } cout << endl;

    reverseElement(Stack);
}