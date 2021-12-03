#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

struct state{
  int x, y, gx, gy, count;

  state(){}
  state(int _x, int _y, int _gx, int _gy, int _c) {
    x = _x, y = _y, gx = _gx, gy = _gy, count = _c;
  }

  bool operator < (const state &other) const {
    pair<ii, ii> a = make_pair(make_pair(other.x, other.y), make_pair(other.gx, other.gy));
    pair<ii, ii> b = make_pair(make_pair(x, y), make_pair(gx, gy));
    return a < b;
  }
};

int dy[8] = {-2, -1, 0, 1, 2, 1, 0, 1};
int dx[8] = {0, 1, 2, 1, 0, -1, -2, -1};
map<state, int> memo;

bool valid_index(int y, int x) {
  return (y <= 100000 && y >= 0 && x <= 100000 && y >= 0);
}

state bfs(state &ini, char c) {
  memo.clear();
  queue<state> q;
  q.push(ini);

  while (q.size()) {
    state cur = q.front();
    q.pop();

    if (cur.x == cur.gx && cur.y == cur.gy) return cur;

    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        int new_y = cur.y + dy[i];
        int new_x = cur.x + dx[j];
        int new_gx = cur.gx;
        int new_gy = cur.gy;

        if (c == 'D') new_gx += 1;
        else new_gy += 1;

        if (valid_index(new_y, new_x) && valid_index(new_gx, new_gy)) {
          state next = state(new_y, new_x, new_gx, new_gy, cur.count + 1);

          if (memo.find(next) == memo.end()) {
            memo[next] = next.count;
            q.push(next);
          }
        }
      }
    }
  }

  return ini; // should never get here
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int xi[3];
  int yi[3];
  int ci[3];
  int x, y;

  while (cin >> x >> y && x + y > 0) {
    REP(i, 0, 2) cin >> xi[i] >> yi[i] >> ci[i];
    
    int ans = 1 << 30;
    REP(i, 0, 2) {
      state ini = state(x, y, xi[i], yi[i], 0); 
      state p1 = bfs(ini, ci[i]);

      REP(j, 0, 2) {
        if (j == i) continue;
        state ini2 = state(p1.x, p1.y, xi[j], yi[j], 0); 

        if (ci[i] == 'D') ini2.gx += p1.count;
        else ini2.gy += p1.count;

        state p2 = bfs(ini2, ci[j]);

        REP(k, 0, 2) {
          if (k == i || k == j) continue;
          state ini3 = state(p2.x, p2.y, xi[k], yi[k], 0); 
          state p3 = bfs(ini3, ci[k]);

          ans = min(p1.count + p2.count + p3.count, ans);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

