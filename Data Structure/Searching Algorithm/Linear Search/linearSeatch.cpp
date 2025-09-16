#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& n, int x) {
    for (int i = 0; i < n.size(); i++) {
        if (n[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> n = {9, 2, 4, 5, 7, 3, 6, 8, 1};
    int x = 10;
    int res = linearSearch(n, x);

    if (res == -1) {
        cout << "The value " << x << " is not in the array";
    } else {
        cout << "Your value is at index no: " << res + 1;
    }
}