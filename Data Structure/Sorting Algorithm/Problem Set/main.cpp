#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& vec) {
    bool found = false;

    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (abs(vec[j]) > abs(vec[j + 1])) {
                swap(vec[j], vec[j+1]);
                found = true;
            }
        }
        if (!found) break;
    }
}

void insertionSort(vector<int>& vec) {
    for (int i = 1; i < vec.size(); i++) {
        int temp = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > temp) {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = temp;
    }
}

void selectionSort(vector<int>& vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[min]) {
                min = j;
            }
        }
        swap(vec[i], vec[min]);
    }
}

void median(vector<int>& vec) {
    int n = vec.size();
    if (n % 2 != 0) {
        int mid = n/2;
        cout << vec[mid];
    } else {
        int mid = n/2;
        cout << (vec[mid] + vec[mid-1]) / 2;
    }
}

void smallDif(vector<int>& vec) {
    int min = abs(vec[0] - vec[1]);
    for (int i = 0; i < vec.size() - 1; i++) {
        int diff = abs(vec[i] - vec[i+1]);
        if (diff < min) min = diff;
    }

    cout << min << endl;
}

int main() {
    vector<int> vec = {-10, 5,-3, 7,-2};
    bubbleSort(vec);
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;
    smallDif(vec);
}