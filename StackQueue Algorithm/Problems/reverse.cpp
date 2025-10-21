#include <bits/stdc++.h>
using namespace std;

vector<char> Stack;

bool isEmpty() {
    if (Stack.empty()) return true;
    return false;
}

void push(char word) {
    Stack.push_back(word);
}

char pop() {
    if (!isEmpty()) {
        char ch = Stack.back();
        Stack.pop_back();
        return ch;
    }
    else {
        cout << "Stack Underflow" << endl;
        return -1;
    }
}

void display(const string& reverse) {
    cout << "Reversed Word: " << reverse << endl;
}

void reverse(const string& word) {
    string reverse;

    for (char c : word) {
        if (c != ' ') {
            push(c);
        }
        else {
            while (!isEmpty()) {
                reverse += pop();
            }
            reverse += " ";
        }
    }

    while (!isEmpty()) {
        reverse += pop();
    }

    display(reverse);
}

int main() {
    string word = "Hello World";
    cout << "Original Input: " << word << endl;

    reverse(word);
}