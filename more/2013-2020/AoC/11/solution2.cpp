#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 1<<30;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int const NAX = 2;
vector<string> board[NAX];
int cur = 1;
int nxt;

bool run(int it) {
  while(it--) {
    cur = (cur + 1) % 2;
    nxt = (cur + 1) % 2;
    int ans = 0;

    REP(i,0,board[cur].size()-1) {
      REP(j,0,board[cur][i].size()-1) {
        int adj = 0;
        REP(k,0,7) {
          int row = i;
          int col = j;
          
          while (true) {
            row = row + dr[k];
            col = col + dc[k];

            if (row < 0 || row >= board[cur].size()) break;
            if (col < 0 || col >= board[cur][i].size()) break;

            if (board[cur][row][col] == '#') {
              adj++;
              break;
            } else if (board[cur][row][col] == 'L') {
              break;
            }
          }
        }
        board[nxt][i][j] = board[cur][i][j];
        if (board[cur][i][j] == 'L' && adj == 0) board[nxt][i][j] = '#';
        else if (board[cur][i][j] == '#' && adj >= 5) board[nxt][i][j] = 'L';
        if (board[nxt][i][j] == board[cur][i][j]) ans++;
      }
    }
    if (ans == board[cur].size() * board[cur][0].size()) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  string s;

  while (cin >> s) {
    board[0].pb(s);
    board[1].pb(s);
  }

  while(!run(1));
  // run(3);

  int cont = 0;
  REP(i,0,board[cur].size()-1) {
    REP(j,0,board[cur][i].size()-1) {
      if (board[cur][i][j] == '#') cont++;
      // cout << board[nxt][i][j];
    }
    // cout << endl;
  }
  cout << cont << endl;

  return 0;
}