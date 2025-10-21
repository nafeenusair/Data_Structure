#include <bits/stdc++.h>
using namespace std;
#define max_size 100

int queueArray[100];
int front, rear = -1;

bool isFull() {
    return front == max_size;
}

bool isEmpty() {
    return front == -1 && rear ==-1;
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Stack Overflow" << endl;
        return;
    }
    else if (isEmpty()) {
        front = rear = 0;
        queueArray[front] = x;
    }
    else {
        rear = (rear + 1) % max_size;
        queueArray[rear] = x;
    }
}



int dequeue() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    }

    int x = queueArray[front];
    front = (front + 1) % max_size;
    return x;
}

int main() {
    enqueue(1);
    enqueue(2);
    dequeue();
    enqueue(3);

    int i = front;
    do {
        cout << queueArray[i] << " ";
        i = (i + 1) % max_size;
    } while (i != (rear + 1) % max_size);
}