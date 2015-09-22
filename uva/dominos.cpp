#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define MAXN 100002

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
  for (int i = 0; i < n; ++i) visited[i] = false;
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
  for (int i = 0; i < n; ++i) scc[i] = -1;

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

int main() {
  int t, n, m, x, y;
  cin >> t;
  
  while (t--) {
    cin >> n >> m; 

    while (m--) {
      cin >> x >> y;
      g[x-1].push_back(y-1);    
    }

    reverse_graph(n);
    topological_sort(n);
    cout << kosaraju(n) << endl;
  }

  return 0;
}
