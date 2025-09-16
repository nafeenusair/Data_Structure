#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& vec)
{
    bool found = false;

    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if(vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                found = true;
            }
        }
        if(!found) break;
    }
}

int main() {
    vector<int> n = {9, 2, 4, 5, 7, 3, 6, 8, 1};

    bubbleSort(n);

    for (int i : n) {
        cout << i << " ";
    }
}