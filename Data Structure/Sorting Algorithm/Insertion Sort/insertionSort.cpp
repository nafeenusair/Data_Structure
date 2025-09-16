#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& vec) {
    for (int i = 1; i < vec.size(); i++) {
        int temp = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > temp) {
            vec[j + 1] = vec[j];
            j--;
        }

        vec[j + 1] = temp;
    }
}

int main () {
    vector<int> n = {9, 2, 4, 5, 7, 3, 6, 8, 1};

    insertionSort(n);

    for (int i : n) {
        cout << i << " ";
    }
}