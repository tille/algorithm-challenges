#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

#define MAXN 1005

int visited[MAXN];
int scc[MAXN];

vector<int> g[MAXN];
vector<int> rev_g[MAXN];

vector<int> path;

void dfs(int node) {
  visited[node] = true;
  for (int i = 0; i < g[node].size(); ++i) {
    int next = g[node][i];
    if(!visited[next]) dfs(next);
  }
  path.push_back(node);
}

void topological_sort(int n) {
  path.clear();
  for (int i = 0; i < n+2; ++i) visited[i] = false;
  for (int i = 0; i < n; ++i) if(!visited[i]) dfs(i);
  reverse(path.begin(), path.end());
}

void dfs_2 (int node, int set_label) {
  scc[node] = set_label;
  for (int i = 0; i < rev_g[node].size(); ++i ) {
    int next = rev_g[node][i];

    if (scc[next] == -1)
      dfs_2(next, set_label);
  }
}

int kosaraju(int n) {
  for (int i = 0; i < n+2; ++i) scc[i] = -1;

  int set_label = 0;
  for (int i = 0; i < path.size(); ++i) {
    int node = path[i];

    if (scc[node] == -1)
      dfs_2(node, set_label++);
  }
  return set_label;
}

void reverse_graph(int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < g[i].size(); ++j) {
      int node = g[i][j];
      rev_g[node].push_back(i);
    }
  }
}

void clear_graph(int n) {
  while(--n > -1) {
    g[n].clear();
    rev_g[n].clear();
  }
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int num, t, n;

  cin >> t;

  REP(tc, 1, t) {
    cin >> n;

    clear_graph(n + 1);

    REP(i, 0, n - 1) {
      cin >> num;
      g[i].push_back(num - 1);
    }

    reverse_graph(n);
    topological_sort(n);
    kosaraju(n);

    for (int i = 0; i < n; ++i) {
      cout << scc[i] << endl;
    }
    cout << endl;
  }
   
  return 0;
}

