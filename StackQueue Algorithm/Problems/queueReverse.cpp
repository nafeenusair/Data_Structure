#include <bits/stdc++.h>
using namespace std;

vector<int> Queue;

bool isEmpty() {
    return Queue.empty();
}

void enqueue(int x) {
    Queue.push_back(x);
}

int dequeue() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    }


    int x = Queue.front();
    Queue.erase(Queue.begin());
    return x;
}

void display() {
    for (int x : Queue) {
        cout << x << " ";
    }
}

void reverseQueue() {
    if (isEmpty()) {
        return;
    }

    int x = dequeue();
    reverseQueue();
    enqueue(x);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    reverseQueue();
    display();
}