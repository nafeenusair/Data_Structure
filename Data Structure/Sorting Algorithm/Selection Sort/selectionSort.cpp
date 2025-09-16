#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[min] > vec[j]) {
                min = j;
            }
        }
        swap(vec[i], vec[min]);
    }
}

int main () {
    vector<int> n = {9, 2, 4, 5, 7, 3, 6, 8, 1};

    selectionSort(n);

    for (int i : n) {
        cout << i << " ";
    }
}