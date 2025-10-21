#include <bits/stdc++.h>
using namespace std;

bool DFS_treasure(vector<vector<int>>& maze, int r, int c, int R, int C, vector<pair<int, int>>& path) {
    if (r < 0 || r >= R || c < 0 || c >= C || maze[r][c] == 1) return false;
    int rNbr[] = {-1, 1, 0, 0};
    int cNbr[] = {0, 0, -1, 1};

    if (maze[r][c] == 999) {
        path.push_back({r,c});
        return true;
    }

    int curr = maze[r][c];
    maze[r][c] = 1;

    for (int k = 0; k < 4; k++) {
        int newR = r + rNbr[k];
        int newC = c + cNbr[k];

        if (DFS_treasure(maze, newR, newC, R, C, path)) {
            path.push_back({r, c});
            return true;
        }
    }

    maze[r][c] = curr;
    return false;
}

void solveMaze(vector<vector<int>>& maze) {
    if (maze.empty() || maze[0].empty()) return;
    int R = maze.size();
    int C = maze[0].size();
    vector<pair<int, int>> path;

    cout << "Path to treasure: ";

    if (DFS_treasure(maze, 0, 0, R, C, path)) {
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++) {
            cout << "(" << path[i].first << "," << path[i].second << ")" << " ";
        }
    }
    else {
        cout << "No Treasure" << endl;
        return;
    }
}

int main() {
    vector<vector<int>> maze = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 999, 0},
        {0, 0, 0, 1}
    };

    solveMaze(maze);
}