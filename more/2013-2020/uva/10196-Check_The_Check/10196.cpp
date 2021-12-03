#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)

string board[9];
int TC = 1, temp, ans;

char knight[2] = {'N', 'n'};
char queen[2]  = {'Q', 'q'};
char bishop[2] = {'B', 'b'};
char rook[2]   = {'R', 'r'};
char pawn[2]   = {'P', 'p'};

int black_row, black_col;
int white_row, white_col;
  
// knight deltas
int dy[8] = {-2, -2, 1, -1, 1, -1,  2,  2};
int dx[8] = {-1,  1,-2, -2, 2,  2, -1,  1};

// pawn deltas
int px[2] = {-1, 1};

bool valid_index(int y, int x) {
  return (y >= 0 && y < 8 && x >= 0 && x < 8);
}

bool check_cross(int x, int y, char p) {
  int i;

  i = x - 1; while (valid_index(y, i) && board[y][i] == '.') i--;
  if (valid_index(y, i) && board[y][i] == p) 
    return true;

  i = x + 1; while (valid_index(y, i) && board[y][i] == '.') i++;
  if (valid_index(y, i) && board[y][i] == p) 
    return true;

  i = y - 1; while (valid_index(i, x) && board[i][x] == '.') i--;
  if (valid_index(i, x) && board[i][x] == p) 
    return true;

  i = y + 1; while (valid_index(i, x) && board[i][x] == '.') i++;
  if (valid_index(i, x) && board[i][x] == p) 
    return true;

  return false;
}

bool check_diagonals(int x, int y, char p) {
  int i, j;

  i = y - 1; j = x - 1; 
  while (valid_index(i, j) && board[i][j] == '.') { i--; j--; }
  if (valid_index(i, j) && board[i][j] == p)
    return true;

  i = y - 1; j = x + 1; 
  while (valid_index(i, j) && board[i][j] == '.') { i--; j++; }
  if (valid_index(i, j) && board[i][j] == p)
    return true;

  i = y + 1; j = x - 1; 
  while (valid_index(i, j) && board[i][j] == '.') { i++; j--; }
  if (valid_index(i, j) && board[i][j] == p)
    return true;

  i = y + 1; j = x + 1; 
  while (valid_index(i, j) && board[i][j] == '.') { i++; j++; }
  if (valid_index(i, j) && board[i][j] == p)
    return true;

  return false;
}

bool check(int color) {
  int y = (color) ? white_row : black_row;
  int x = (color) ? white_col : black_col;

  // check knights
  REP(i, 0, 7) {
    int r = y + dy[i]; int c = x + dx[i];
    if (valid_index(r, c) && board[r][c] == knight[color])
      return true; 
  }

  // check pawns
  int pr = (color) ? y - 1 : y + 1;
  REP(i, 0, 1) { 
    int c = x + px[i];
    if (valid_index(pr, c) && board[pr][c] == pawn[color])
      return true; 
  }

  if (check_cross(x, y, rook[color])) return true;
  if (check_diagonals(x, y, bishop[color])) return true;

  // check queen
  if (check_cross(x, y, queen[color])) return true;
  if (check_diagonals(x, y, queen[color])) return true;

  return false;
}

bool read_board() {
  white_col = -1;
  REP(i, 0, 7) {
    cin >> board[i];
    temp = board[i].find("k");
    if (temp != string::npos) { black_row = i; black_col = temp; }
    temp = board[i].find("K");
    if (temp != string::npos) { white_row = i; white_col = temp; }
  }
  return (white_col != -1);
}

int main() {
  while (read_board()) {
    ans = (check(0)) ? 1 : (check(1)) ? 2 : 3; // 0-black, 1-white
    switch (ans) {
      case 1:
        printf("Game #%d: black king is in check.\n", TC);
        break;
      case 2:
        printf("Game #%d: white king is in check.\n", TC);
        break;
      case 3:
        printf("Game #%d: no king is in check.\n", TC);
        break;
    }; TC++;
  }
  return 0;
}
