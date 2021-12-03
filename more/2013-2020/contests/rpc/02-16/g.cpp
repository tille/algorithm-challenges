#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

struct state {
  int p1_x, p1_y, p2_x, p2_y;
  string path;

  state() {}
  state(int a, int b, int c, int d, const string &e) {
    p1_x = a; p1_y = b;
    p2_x = c; p2_y = d;
    path = e;
  }

  bool operator < (const state &a) const {
    pair<ii, ii> g1 = make_pair( make_pair(p1_x, p1_y), make_pair(p2_x, p2_y) );
    pair<ii, ii> h1 = make_pair( make_pair(a.p1_x, a.p1_y), make_pair(a.p2_x, a.p2_y) );
    return g1 < h1;
  }
};

int t, m, n;
char g[55][55];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

pair<int, string> bfs(int y1, int x1, int y2, int x2) {
  map<state, int> v;
  if (x1 == x2 && y1 == y2) return make_pair(0, "");

  state ini(x1, y1, x2, y2, "");
  queue<state> q;
  q.push(ini);
  v[ini] = 1;

  while (q.size()) {
    state cur = q.front(); q.pop();

    REP(i, 0, 3) {
      int ix1 = (cur.p1_x + dx[i] + n) % n;
      int iy1 = (cur.p1_y + dy[i] + m) % m;
      int ix2 = (cur.p2_x + dx[i] + n) % n;
      int iy2 = (cur.p2_y + dy[i] + m) % m;
      if (g[iy1][ix1] == 'X') { ix1 = cur.p1_x; iy1 = cur.p1_y; }
      if (g[iy2][ix2] == 'X') { ix2 = cur.p2_x; iy2 = cur.p2_y; }

      string dir;
      if (i == 0) dir = "N";
      else if (i == 1) dir = "E";
      else if (i == 2) dir = "S";
      else dir = "W";
      state next = state(ix1, iy1, ix2, iy2, cur.path + dir);

      if (g[iy1][ix1] == 'G' || g[iy2][ix2] == 'G') continue; 
      else if (v[next] == 1) continue;

      if (ix1 == ix2 && iy1 == iy2) 
        return make_pair(cur.path.size() + 1, cur.path + dir);

      v[next] = 1;
      q.push(next);
    }
  }

  pair<int, string> ans = make_pair(-1, "nothing");
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> m >> n;

    vector<ii> c;
    REP(i, 0, m - 1) {
      REP(j, 0, n - 1) {
        cin >> g[i][j];
        if (g[i][j] == 'P') c.push_back(make_pair(i, j));
      }
    }

   pair<int, string> ans = bfs(c[0].first, c[0].second, c[1].first, c[1].second);
   if (ans.first == -1) { 
     cout << "IMPOSSIBLE" << endl;
   } else {
     cout << ans.first << " " << ans.second << endl;
   }
  }
  return 0;
}

