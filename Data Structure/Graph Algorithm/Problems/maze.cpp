#include <bits/stdc++.h>
using namespace std;

bool DFS_maze(vector<vector<int>>& maze, int r, int c, int R, int C, vector<pair<int, int>>& path) {
    if (r < 0 || r >= R || c < 0 || c >= C || maze[r][c] != 1) return false;
    int DR[] = {-1, 1, 0, 0};
    int DC[] = {0, 0, -1, 1};


    if (r == R - 1 && c == C - 1) {
        path.push_back({r, c});
        return true;
    }

    path.push_back({r, c});
    maze[r][c] = 2;

    for (int k = 0; k < 4; k++) {
        int newR = r + DR[k];
        int newC = c + DC[k];

        if (DFS_maze(maze, newR, newC, R, C, path)) {
            return true;
        }
    }

    path.pop_back();
    maze[r][c] = 1;
    return false;
}

void solveMaze(vector<vector<int>>& maze) {
    if (maze.empty() || maze[0].empty()) return;

    int R = maze.size();
    int C = maze[0].size();
    vector<pair<int, int>> path;

    cout << "Path from (0,0) to (" << R-1 <<"," << C-1 << ") : ";
    if (maze[0][0] == 0) {
        cout << "((0,0) path is closed" << endl;
        return;
    }

    if (DFS_maze(maze, 0, 0, R, C, path)) {
        for (int i = 0; i < path.size(); i++) {
            cout << "(" << path[i].first << "," << path[i].second << ")";
        }
    }
    else {
        cout << "Path not found" << endl;
        return;
    }
}

int main() {
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                  {1, 1, 1, 0},
                                  {0, 1, 0, 0},
                                  {0, 1, 1, 1}};
    solveMaze(maze);
}