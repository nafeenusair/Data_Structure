#include <bits/stdc++.h>
using namespace std;

vector<char> Stack;

bool isEmpty() {
    return Stack.empty();
}

void push(char x) {
    Stack.push_back(x);
}

char pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return '\0';
    }

    char x = Stack.back();
    Stack.pop_back();
    return x;
}

bool checkParentheses(const string& ch) {
    Stack.clear();

    for (char c : ch) {
        if (c == '(' || c == '[' || c == '{') push(c);
        else {
            if (!isEmpty()) {
                char c2 = pop();
                if (c == ')' && c2 != '(' ||
                    c == ']' && c2 != '[' ||
                    c == '}' && c2 != '{') return false;
            }
            else {
                return false;
            }
        }
    }

    if (isEmpty()) {
        return true;
    }
}

int main() {
    string parentheses = "()[]{}";
    bool res = checkParentheses(parentheses);
    cout << res;
}