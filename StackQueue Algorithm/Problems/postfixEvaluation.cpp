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

void postfixEvaluation(const string& postfix) {
    int res;

    for (int c : postfix) {
        if (c != ' ') {
            if (isdigit(c)) {
                push(c - '0');
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                if (ch.size() < 2) {
                    return;
                }
                char token = c;

                int a = ch.back();
                pop();
                int b = ch.back();
                pop();

                switch (token) {
                    case '+': res = a + b; break;
                    case '-': res = a - b; break;
                    case '*': res = a * b; break;
                    case '/':
                        if (b == 0) {
                            throw runtime_error("Division by 0, not possible");
                        }
                        res = a / b; break;
                    default:
                        throw runtime_error("Invalid Input");
                }
                push(res);
            }
        }
    }
    cout << res;
}

int main() {
    string postfix = "3 5 2 * +";
    postfixEvaluation(postfix);
}