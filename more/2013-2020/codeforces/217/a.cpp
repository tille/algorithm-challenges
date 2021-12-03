#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> tt;

int board[8][8];
int c1, r1, r2, c2;

int bfs_king() {
    queue<tt> q;
    tt a = make_tuple(r1, c1, 0);
    q.push(a);
    board[r1][c1] = 1;

    int dr[] = {1,-1,0, 0,1,-1,-1, 1};
    int dc[] = {0, 0,1,-1,1, 1,-1,-1};
    while (q.size()) {
        tt cur = q.front();
        int cur_row = get<0>(cur);
        int cur_col = get<1>(cur);
        int cur_val = get<2>(cur);
        q.pop();

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                int next_row = cur_row + dr[i];
                int next_col = cur_col + dc[i];

                if (board[next_row][next_col] == -1 && 
                    next_row < 8 && next_col < 8 &&
                    next_row >= 0 && next_col >= 0) {

                    tt to = make_tuple(next_row, next_col, cur_val + 1);
                    if (next_row == r2 && next_col == c2) {
                        return cur_val + 1;
                    }
                    board[next_row][next_col] = 1;
                    q.push(to);
                }
            }
        }
    }
}

int bfs_rook() {
    queue<tt> q;
    tt a = make_tuple(r1, c1, 0);
    q.push(a);
    board[r1][c1] = 1;

    int dr[] = {-1, 1,  0, 0};
    int dc[] = {0,  0, -1, 1};

    while (q.size()) {
        tt cur = q.front();
        int cur_row = get<0>(cur);
        int cur_col = get<1>(cur);
        int cur_val = get<2>(cur);
        q.pop();


        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                int next_row = cur_row;
                int next_col = cur_col;
                
                while (next_row < 8 && next_col < 8 &&
                       next_row >= 0 && next_col >= 0) {
                    
                    next_row = next_row + dr[i];
                    next_col = next_col + dc[i];

                    if (board[next_row][next_col] == -1 &&
                        next_row < 8 && next_col < 8 &&
                        next_row >= 0 && next_col >= 0) {

                        tt to = make_tuple(next_row, next_col, cur_val + 1);
                        if (next_row == r2 && next_col == c2) {
                            return cur_val + 1;
                        }
                        board[next_row][next_col] = 1;
                        q.push(to);
                    }
                }
            }
        }
    }
}

int bfs_bishop() {
    queue<tt> q;
    tt a = make_tuple(r1, c1, 0);
    q.push(a);
    board[r1][c1] = 1;

    int dr[] = {-1, -1,  1, 1};
    int dc[] = {-1,  1, -1, 1};

    while (q.size()) {
        tt cur = q.front();
        int cur_row = get<0>(cur);
        int cur_col = get<1>(cur);
        int cur_val = get<2>(cur);
        q.pop();


        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                int next_row = cur_row;
                int next_col = cur_col;
                
                while (next_row < 8 && next_col < 8 &&
                       next_row >= 0 && next_col >= 0) {
                    
                    next_row = next_row + dr[i];
                    next_col = next_col + dc[i];

                    if (board[next_row][next_col] == -1 &&
                        next_row < 8 && next_col < 8 &&
                        next_row >= 0 && next_col >= 0) {

                        tt to = make_tuple(next_row, next_col, cur_val + 1);
                        if (next_row == r2 && next_col == c2) {
                            return cur_val + 1;
                        }
                        board[next_row][next_col] = 1;
                        q.push(to);
                    }
                }
            }
        }
    }
    return 0;
}

void clear_graph() {
    for (int i = 0; i < 8; ++i) 
        for(int j = 0; j < 8; ++j) 
            board[i][j] = -1;
}

int main() {
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;

    clear_graph();
    int a = bfs_rook();
    clear_graph();
    int b = bfs_bishop();
    clear_graph();
    int c = bfs_king();
    printf("%d %d %d\n", a, b, c);
    return 0;
}