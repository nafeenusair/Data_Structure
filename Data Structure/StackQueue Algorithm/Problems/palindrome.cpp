#include <bits/stdc++.h>
using namespace std;

vector<char> ch;

bool isEmpty() {
    return ch.empty();
}

void push(char c) {
    char lower = tolower(c);
    ch.push_back(lower);
}

char pop() {
    if (isEmpty()) {
        return -1;
    }
    char x = ch.back();
    ch.pop_back();
    return x;
}

bool checkPalindrome(const string& sen) {
    for (char c : sen) {
        if (c != ' ') {
            push(c);
        }
    }

    int i = 0;
    while (!isEmpty()) {
        char check = pop();
        cout << ch[i] << " & " << check << endl;;
        if (ch[i] != check) return false;
        i++;
    }

    return true;
}

int main() {
    string sen = "A man a plan a canal Panama";
    bool res = checkPalindrome(sen);
    cout << res;
}