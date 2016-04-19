#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define maxn 10005

int cost[maxn], scc[maxn];
bool seen[maxn];
vi g[maxn], grev[maxn], topo;

int dfs(int u) {
  seen[u] = true;
  REP(i, 0, g[u].size() - 1) {
    int v = g[u][i];
    if (!seen[v]) dfs(v);
  }
  topo.push_back(u);
}

int dfs2(int u, int comp) {
  scc[u] = comp;
  REP(i, 0, grev[u].size() - 1) {
    int v = grev[u][i];
    if (scc[v] == -1) dfs2(v, comp);
  }
}

int kos(int n) {
  REP(i, 0, n - 1) { 
    REP(j, 0, g[i].size() - 1) {
      int v = g[i][j]; 
      grev[v].push_back(i);
    }
  }

  REP(i, 0, n - 1) if (!seen[i]) dfs(i);
  reverse(topo.begin(), topo.end());

  int comp = 0;
  REP(i, 0, n - 1) {
    int u = topo[i];
    if (scc[u] == -1) dfs2(u, comp++);
  }
  return comp;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  int t, x , y, n, m;
  cin >> t;

  while (t--) {
    cin >> n >> m;

    REP(i, 0, n) g[i].clear(), grev[i].clear();

    REP(j, 0, m - 1) {
      cin >> x >> y;
      g[x].push_back(y);
    }

    topo.clear();
    REP(i, 0, n) {
      scc[i] = -1;
      seen[i] = false;
    }
    cout << kos(n) << endl;
  }
  return 0;
}

