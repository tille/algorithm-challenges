#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

vector<vector<bool>> grid;

vi dx = {-1, 0, 1, 0};
vi dy = { 0, 1, 0,-1};

void markAdjacents(int i, int j) {
    int x, y;

    for (int k = 0; k < 4; ++k) {
        y = i + dy[k]; 
        x = j + dx[k];
        if (x >= 0 && x < 3 && y >= 0 && y < 3) {
            grid[y][x] = !grid[y][x];
        }
    }
}

int main() {
    int num;
    grid.resize(3, vector<bool>(3, true));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> num;
            num %= 2;
            if (num) {
                markAdjacents(i, j);
                grid[i][j] = !grid[i][j];
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << (!grid[i][j] ? 0 : 1);
        }
        cout << endl;
    }
    return 0;
}