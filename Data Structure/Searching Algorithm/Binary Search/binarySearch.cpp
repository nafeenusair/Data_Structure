#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& vec, int target) {
    int low = 0;
    int high = vec.size() - 1;

    while (low <= high) {
        int middle = low + (high - low) / 2;
        int value = vec[middle];

        if (value < target) low = middle + 1;
        else if (value > target) high = middle - 1;
        else return middle;
    }

    return -1;
}

int main() {
    int max_Val = 100000;
    int target = 100001;

    vector<int> arr;
    for (int i = 1; i <= max_Val; i++) {
        arr.push_back(i);
    }

    int res = binarySearch(arr, target);

    if (res == -1) {
        cout << "Element not Found";
    } else {
        cout << "Element found at " << res;
    }
}
