#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

char m[25][25];
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
int M, N;
int v[25][25];

int dfs(int x, int y, char o) {
  stack<int> s; int res = 0;
  s.push(x); s.push(y);

  if (m[x][y] == o) {
    v[x][y] = 1;
    res++;
  } else return res;

  while (s.size()) {
    int uy = s.top(); s.pop();
    int ux = s.top(); s.pop();

    REP(i, 0, 3) {
      int vx = ux + dx[i];
      int vy = (uy + dy[i] + N) % N;

      if (vx >= 0 && vx <= M - 1 && m[vx][vy] == o && v[vx][vy] == 0) {
        s.push(vx); s.push(vy);
        v[vx][vy] = 1;
        res++;
      }
    }
  }
  return res;
}

int dfs_mark(int x, int y, int o) {
  stack<int> s;
  s.push(x); s.push(y);
  v[x][y] = 1;

  while (s.size()) {
    int uy = s.top(); s.pop();
    int ux = s.top(); s.pop();

    REP(i, 0, 3) {
      int vx = ux + dx[i];
      int vy = (uy + dy[i] + N) % N;

      if (vx >= 0 && vx <= M - 1 && m[vx][vy] == o && v[vx][vy] == 0) {
        s.push(vx); s.push(vy);
        v[vx][vy] = 1;
      }
    }
  }
}

int main() {
  while (cin >> M >> N) {

    REP(i, 0, M - 1) {
      REP(j, 0, N - 1) {
        cin >> m[i][j];
        v[i][j] = 0;
      }
    }

    int x, y;
    cin >> x >> y;
    char land = m[x][y];
    dfs_mark(x, y, land);

    // REP(i, 0, M - 1) {
    //   REP(j, 0, N - 1) {
    //     cout << v[i][j];
    //   }
    //   cout << endl;
    // }

    int ans = 0;
    int regions;

    REP(i, 0, M - 1) {
      REP(j, 0, N - 1) {
        if (m[i][j] == land && !v[i][j]) {
          regions = dfs(i, j, land);
          ans = max(ans, regions);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

