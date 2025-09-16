#include <bits/stdc++.h>
using namespace std;

int linearSearch(const vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        if (target == vec[i]) {
            return i;
        }
    }
    return -1;
}

vector<int> linearSearchM(const vector<int>& vec, int target) {
    vector<int> vec1;

    for (int i = 0; i < vec.size(); i++) {
        if (target == vec[i]) {
            vec1.push_back(i);
        }
    }
    return vec1;
}

int linearWithCond(const vector<int>& vec, int target) {
    for (int i : vec) {
        if (target < i) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<int>& vec, int target) {
    int low = 0;
    int high = vec.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (vec[mid] == target) return mid;
        else if (target < vec[mid])  high = mid - 1;
        else if (target > vec[mid]) low = mid + 1;
    }

    return -1;
}

int DecBinarySearch(const vector<int>& vec, int target) {
    int low = 0;
    int high = vec.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (vec[mid] == target) return mid;
        else if (vec[mid] > target) low = mid + 1;
        else if (vec[mid] < target) high = mid - 1;
    }

    return -1;
}

pair<int, int> firstAndlast(vector<int> vec, int target) {
    int low = 0;
    int high = vec.size() - 1;
    int first = -1, last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (vec[mid] == target) {
            first = mid;
            high = mid - 1;
        }
        else if (vec[mid] > target) high = mid - 1;
        else low = mid + 1;
    }

    low = 0;
    high = vec.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (vec[mid] == target) {
            last = mid;
            low = mid + 1;
        }
        else if (vec[mid] > target) high = mid - 1;
        else low = mid + 1;
    }

    return {first, last};
}

int occurrences(const vector<int>& vec, int target) {
    int count = 0;

    for (int x : vec) {
        if (x == target) {
            count++;
        }
    }

    return count;
}

int sortedAdd(const vector<int>& vec, int target) {
    int i;
    for (i = 0; i < vec.size(); i++) {
        if (vec[i] > target) return i;
    }

    if (i > vec.size()) {
        return i+1;
    }
    return i;
}

int closestElement(const vector<int>& vec, int target) {
    int low = 0;
    int high = vec.size() - 1;
    int closest = vec[0];

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (abs(vec[mid] - target) < abs(closest - target)) {
            closest = vec[mid];
        }

        if (vec[mid] == target) return mid;
        else if (target < vec[mid])  high = mid - 1;
        else if (target > vec[mid]) low = mid + 1;
    }

    return closest;
}

int largestElement(const vector<int>& vec) {
    int low = 0, high = vec.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (vec[mid] < vec[mid+1]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    //problem1
    //vector<int> vec = {5, 3, 8, 1, 9};
    //int target = 8;
    //int firstOccur = linearSearch(vec, target);
    //if (firstOccur == -1) {
    //    cout << "Target value is not in array";
    //} else {
    //    cout << "Value found at: " << firstOccur;
    //}

    //problem2
    //vector<int> vec2 = {4, 2, 3, 2, 4, 2};
    //int target2 = 2;
    //vector<int> multiOccur = linearSearchM(vec2, target2);
    //for (int x : multiOccur) {
    //    cout << x << " ";
    //}

    //problem3
    //vector<int> vec = {3, 5, 7, 2, 8, 10};
    //int target = 6;
    //int value = linearWithCond(vec, target);
    //if (value == -1) {
    //    cout << "Target value is not in array";
    //} else {
    //    cout << "Value: " << value;
    //}

    //problem4
    //vector<int> vec = {1, 3, 5, 7, 9};
    //int target = 5;
    //int res = binarySearch(vec, target);
    //cout << res;

    //problem5
    //vector<int> vec = {9, 7, 5, 3, 1};
    //int target = 3;
    //int res = DecBinarySearch(vec, target);
    //cout << res;

    //problem6
    //vector<int> vec = {1, 2, 2, 2, 3, 4};
    //int target = 2;
    //pair<int, int> res = firstAndlast(vec, target);
    //cout << res.first << " " << res.second;

    //problem7
    //vector<int> vec = {1, 3, 5, 6};
    //int target = 7;
    //int res = sortedAdd(vec, target);
    //cout << res;

    //problem8
    //vector<int> vec = {2, 4, 4, 4, 6, 7};
    //int target = 4;
    //int res = occurrences(vec, target);
    //cout << res;

    //problem9
    //vector<int> vec = {1, 3, 8, 10, 15};
    //int target = 12;
    //int res = closestElement(vec, target);
    //cout << res;

    //problem10
    //vector<int> vec = {1, 3, 8, 12, 4, 2};
    //int res = largestElement(vec);
    //cout << res;
}