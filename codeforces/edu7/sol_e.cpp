#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 500500;

int n;
vector<int> g[N];

inline bool read() {
  if (!(cin >> n)) return false;
  forn(i, n) g[i].clear();
  forn(i, n - 1) {
    int x, y;
    assert(scanf("%d%d", &x, &y) == 2);
    x--, y--;
    g[x].pb(y), g[y].pb(x);
  }
  return true;
}

vector<int> z;

void dfs(int v, int p, int d) {
  int c = 0;
  forn(i, sz(g[v])) {
    int to = g[v][i];
    if (to == p) continue;
    c++;
    dfs(to, v, d + 1);
  }
  if (!c) z.pb(d);
}

int solve(int v, int p) {
  z.clear();
  dfs(v, p, 0);
  sort(all(z));
  if (v == 2) {
    for (int k = 0; k < z.size(); ++k) {
      cout << z[k] << " ";
    }
    cout << endl;
  }
  forn(i, sz(z)) {
    if (i) z[i] = max(z[i - 1] + 1, z[i]);
  }
  return z.back();
}

inline void solve() {
  int ans = 0;
  forn(i, sz(g[0]))
    ans = max(ans, solve(g[0][i], 0) + 1);
  cout << ans << endl;
}

int main() {
#ifdef SU1
  assert(freopen("input.txt", "rt", stdin));
  //assert(freopen("output.txt", "wt", stdout));
#endif

  cout << setprecision(10) << fixed;
  cerr << setprecision(5) << fixed;

  while (read()) {
    solve();
    //break;
  }

  return 0;
}
