
vector<int> g[MAXN]; // graph
int parent[MAXN]; // parent of each node after dfs
int low[MAXN]; // low node that can reach me
int dis[MAXN]; // my position in the tree
bool visited[MAXN]; 
int total; // number of nodes discovered in the graph
int articulation_point[MAXN];

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
        articulation_point[u] = true;

      if (parent[u] != -1 && low[v] >= dis[u])
        articulation_point[u] = true;

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
    articulation_point[i] = false;
  }
}

// usage: 

// edges must be bi-directional
g[node_a].push_back(node_b);
g[node_b].push_back(node_a);

total = 0; // number of nodes discovered initialized with zero

// shoot dfs from each node looking for articulation points
for (int i = 0; i < n; ++i) {
  if (visited[i] == false) ap(i);
}

// the number of articulation points in the graph is the number 
// of nodes marked as true in Array articulation_points.
