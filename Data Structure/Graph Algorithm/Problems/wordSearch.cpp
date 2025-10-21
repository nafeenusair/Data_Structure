#include <bits/stdc++.h>
using namespace std;

bool DFS(vector<vector<char>>& grid, int r, int c, string& word, int index) {
    int row = grid.size();
    int col = grid[0].size();

    if (r < 0 || r >= row || c < 0 || c >= col) return false;

    vector<int> rNbr = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> cNbr = {-1, 0, 1, -1, 1, -1, 0, 1};

    if (grid[r][c] != word[index]) return false;
    if (index == word.length() - 1) return true;

    char original = grid[r][c];
    grid[r][c] = '#';
    bool found = false;

    for (int k = 0; k < 8; k++){
        int newR = r + rNbr[k];
        int newC = c + cNbr[k];

        if (DFS(grid, newR, newC, word, index + 1)) {
            found = true;
            break;
        }
    }
    grid[r][c] = original;
    return found;
}

bool isExist(vector<vector<char>>& grid, string& word) {
    int row = grid.size();
    int col = grid[0].size();

    if (word.length() > row * col) return false;

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (grid[r][c] == word[0]) {
                if (DFS(grid, r, c, word, 0)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> grid = {{'A', 'B', 'C', 'E'},
                                 {'S', 'F', 'C', 'S'},
                                 {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";

    bool res = isExist(grid, word);
    cout << res;
}