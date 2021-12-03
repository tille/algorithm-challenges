#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

vector<int> g[MAXN]; // graph
int parent[MAXN]; // parent of each node after dfs
int low[MAXN]; // low node that can reach me
int dis[MAXN]; // my position in the tree
bool visited[MAXN]; 
map<string, int> index_of; // my index position
set<string> results; // results, yay!
string locations[MAXN]; // my name
int total; // number of nodes discovered in the graph

void ap(int u) {
  visited[u] = true;
  int children = 0;
  low[u] = dis[u] = ++total;

  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    
    if (!visited[v]) {
      children++;
      parent[v] = u;

      ap(v);

      if (parent[u] == -1 && children > 1) 
        results.insert(locations[u]);

      if (parent[u] != -1 && low[v] >= dis[u])
        results.insert(locations[u]);

      low[u] = min(low[u], low[v]); 
    } else if (v != parent[u])
      low[u] = min(low[u], dis[v]);
  }
}

void clear_all() {
  for (int i = 0; i < MAXN; ++i) {
    g[i].clear();
    parent[i] = -1;
    visited[i] = false;
    index_of.clear();
  }

  results.clear();
}

int main() {
  int n, r, test_case = 0;

  while (cin >> n && n) {
    if(test_case > 0) puts("");
    clear_all();

    test_case++;

    for (int i = 0; i < n; ++i) {
      cin >> locations[i];
      index_of[ locations[i] ] = i;
    }

    cin >> r;
    string from, to;

    while (r--) {
      cin >> from >> to;
      int node_a = index_of[from];
      int node_b = index_of[to];

      g[node_a].push_back(node_b);
      g[node_b].push_back(node_a);
    }
    
    total = 0;

    for (int i = 0; i < n; ++i) {
      if (visited[i] == false) ap(i);
    }

    set <string> :: iterator it;
    printf("City map #%d: %d camera(s) found\n", test_case, int(results.size()) );

    for (it = results.begin(); it != results.end(); ++it) {
      cout << *it << endl;
    }
  }
  return 0;
}
