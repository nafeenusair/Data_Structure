#include <bits/stdc++.h>
using namespace std;
#define n 100

int arr[n];
int top = -1;

int isFull() {
    return top == n - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int x) {
    if (isFull()) {
        cout << "Stack overflow" << endl;
        return;
    }
    arr[++top] = x;
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    }

    return arr[top--];
}

int peek() {
    if (isEmpty()) {
        cout << "Empty Stack" << endl;
        return -1;
    }

    return arr[top];
}

void display() {
    if (isEmpty()) {
        cout << "Empty Stack" << endl;
        return;
    }

    for (int i = 0; i <= top; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    push(5);
    push(10);
    push(6);
    pop();

    display();
}