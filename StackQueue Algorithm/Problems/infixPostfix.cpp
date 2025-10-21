#include <bits/stdc++.h>
using namespace std;

vector<char> ch;

bool isEmpty() {
    return ch.empty();
}

void push(int x) {
    ch.push_back(x);
}

char pop() {
    if (isEmpty()) {
        return -1;
    }
    char c = ch.back();
    ch.pop_back();
    return c;
}

int priority(char p) {
    if (p == '^') return 3;
    else if (p == '*' || p == '/') return 2;
    else if (p == '+' || p == '-') return 1;
    return 0;
}

void display(const string& postfix) {
    cout << postfix << endl;
}

void toPostfix(const string& infix) {
    string postfix = "";

    for (char c : infix) {
        if (c != ' ') {
            if (isalnum(c)) {
                postfix += c;
            }
            else if (c == '(') {
                push(c);
            }
            else if (c == ')') {
                while (int x = pop() != '(') {
                    postfix += pop();
                }
            }
            else {
                while (!isEmpty() && priority(c) < priority(ch.back())) {
                    char x = pop();
                    postfix += x;
                }
                push(c);
            }
        }
    }

    while (!isEmpty()) {
        postfix += pop();
    }

    display(postfix);
}

int main() {
    string infix = "3 + 5 * 2";
    toPostfix(infix);
}