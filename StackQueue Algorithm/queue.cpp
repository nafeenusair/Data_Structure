#include <bits/stdc++.h>
using namespace std;
#define n 100

int front, rear = -1;
int arr[n];

int isFull() {
    return rear == n - 1;
}

int isEmpty() {
    return front == -1 && rear == -1;
}

void enqueue(int x)
{
    if (isFull()) {
        cout << "Queue Overflow" << endl;
        return;
    }
    else if (isEmpty()) {
        front = rear = 0;
        arr[rear] = x;
    }
    else {
        arr[++rear] = x;
    }
}

int dequeue() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    } else if (front == rear) {
        int x = arr[front];
        front = rear = -1;
        return x;
    } else {
        int x = arr[front++];
        return x;
    }
}