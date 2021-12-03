#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef map<int, int> msi;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define maxn 10005

int cost[maxn];
int p[maxn];

void init(int n) {
  REP(i, 0, n - 1) p[i] = i;
}

int find(int u) {
  return p[u] == u ? u : p[u] = find(p[u]);
}

void link(int u, int v) {
  int a = find(u);
  int b = find(v);
  if (a != b) p[a] = b;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  int t, n, m, x, y;
  cin >> t;

  while (t--) {
    cin >> n >> m;

    init(n);
    REP(i, 0, n - 1) cin >> cost[i];

    REP(j, 0, m - 1) {
      cin >> x >> y;
      link(x, y);
    }

    msi res;
    REP(i, 0, n - 1) res[find(i)] += cost[i]; 
    bool valid = true;

    TRmsi(res, it) {
      if (it->second != 0) {
        valid = false;
        break;
      }
    }

    if(!valid) cout << "IMPOSSIBLE" << endl;
    else cout << "POSSIBLE" << endl;
  }
  return 0;
}

