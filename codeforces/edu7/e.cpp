#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

vector<int> g[500005];
vector<int> z;
int a[500005];
int n, to, from, ans;

int dfs(int v, int p, int d) {
  int c = 0;
  REP(i, 0, g[v].size() - 1) {
    to = g[v][i];
    if (to == p) continue; 
    c++;
    dfs(to, v, d + 1);
  }
  if (!c) z.push_back(d);
}

int solve(int v) {
  z.clear();
  dfs(v, 0, 0);
  sort(z.begin(), z.end());

  a[0] = z[0];
  REP(i, 1, z.size() - 1) {
    a[i] = max(a[i - 1] + 1, z[i]);
  }
  return a[z.size() - 1];
}

int main() {
  scanf("%d", &n);

  REP(i, 0, n - 2) {
    scanf("%d%d", &from, &to);
    to--; from--;
    g[from].push_back(to);
    g[to].push_back(from);
  }

  ans = 0;
  REP(i, 0, g[0].size() - 1) {
    ans = max(ans, solve(g[0][i]) + 1);
  }

  printf("%d\n", ans);
  return 0;
}
