#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

struct line {
  int pos, ini, end;
  string dir;

  line() {};
  line(string _dir, int _pos, int _ini, int _end) {
    dir = _dir, pos = _pos, ini = _ini, end = _end;
  }
};

vector<int> match, vis, match2;
vector<int> g[1000000]; // bigger than (maxn * maxn)
string arr[805];

int aug(int l, int left_size) {
  if (vis[l]) return 0;
  vis[l] = 1;
  REP(j, 0, g[l].size() - 1) {
    int r = g[l][j];
    if (match[r] == -1 || aug(match[r], left_size)) {
      match[r] = l;
      match2[l] = r + left_size;
      return 1;
  } }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  int r, c, ini;
  vector<line> vlines, hlines;
  int tc = 0;

  while (cin >> r >> c) {
    // if (tc++) cout << endl;

    vlines.clear();
    hlines.clear();

    REP(i, 0, r - 1) cin >> arr[i];

    // find horizontal segments
    REP(i, 0, r - 1) {
      int open = false;
      REP(j, 0, c - 1) {
        if (arr[i][j] == '*' && !open) ini = j, open = true;
        if (arr[i][j] == '.' && open) {
          // if (j - ini > 1) 
            hlines.push_back(line("hline", i, ini, j - 1));
          open = false;
        }
      }
      // if (open && c - ini > 1) 
      if (open) hlines.push_back(line("hline", i, ini, c - 1));
    }

    // find vertical segments
    REP(j, 0, c - 1) {
      int open = false;
      REP(i, 0, r - 1) {
        if (arr[i][j] == '*' && !open) ini = i, open = true;
        if (arr[i][j] == '.' && open) {
          // if (i - ini > 1)
            vlines.push_back(line("vline", j, ini, i - 1));
          open = false;
        }
      }
      // if (open && r - ini > 1) 
      if (open) vlines.push_back(line("vline", j, ini, r - 1));
    }

    int n = vlines.size() + hlines.size();
    REP(i, 0, n) g[i].clear();

    // create bipartite graph
    REP(i, 0, vlines.size() - 1) {
      REP(j, 0, hlines.size() - 1) {
        if (hlines[j].ini <= vlines[i].pos && hlines[j].end >= vlines[i].pos &&
            vlines[i].ini <= hlines[j].pos && vlines[i].end >= hlines[j].pos) {
          g[i].push_back(j);
          g[vlines.size() + j].push_back(i);
        }
      }
    }

    match.assign(hlines.size(), -1);
    match2.assign(vlines.size(), -1);

    REP(l, 0, vlines.size() - 1) {
      vis.assign(vlines.size(), 0);
      aug(l, vlines.size());
    }

    vector<line> ans;

    // REP(i, 0, n - 1) {
    //   cout << "node: " << i << endl;
    //   cout << "friends " << g[i].size() << endl;
    // }
    // break;

    vector<bool> seen(n, false);
    REP(i, 0, match.size() - 1) {
      if (match[i] == -1) {
        int r = vlines.size() + i;

        queue<int> q;
        q.push(r);
        seen[r] = true;
        while (q.size()) {
          int cur = q.front();
          q.pop();

          REP(j, 0, g[cur].size() - 1) {
            int l = g[cur][j];

            if (!seen[l]) {
              line res = vlines[l];
              ans.push_back(res);
              seen[l] = true;
              if (match2[l] != -1) {
                q.push(match2[l]);
                seen[match2[l]] = true;
              }
            }
          }
        }

      }
    }

    REP(i, vlines.size(), n - 1) {
      if (!seen[i]) {
        line res = hlines[i - vlines.size()];
        ans.push_back(res);
      }
    }

    cout << ans.size() << endl;
    REP(i, 0, ans.size() - 1) {
      line v = ans[i];
      cout << v.dir << " " << v.pos + 1 << " " << v.ini + 1 << " " << v.end + 1 << endl;
    }

    // REP(i, 0, vlines.size() - 1) {
    //   line u = vlines[i];
    //   cout << "node: ";
    //   // cout << u.dir << " " << u.pos + 1 << " " << u.ini + 1 << " " << u.end + 1 << endl;
    //   cout << i + 1 << endl;
    //   REP(j, 0, g[i].size() - 1) {
    //     line v = hlines[ g[i][j] ];
    //     // cout << " " << v.dir << " " << v.pos + 1 << " " << v.ini + 1 << " " << v.end + 1 << endl;
    //     cout << g[i][j] + 1 << " ";
    //   }
    //   cout << endl;
    // }
  }
   
  return 0;
}

