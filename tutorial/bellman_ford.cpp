
struct edge { 
  int to, weight;
  edge(){};

  edge(int next_node, int edge_weight) { 
    to = next_node;
    weight = edge_weight;
  }
};

int dist[MAXN];
// int previ[MAXN];
vector<edge> g[MAXN];

bool update_dist(int n) {
  bool updated = false;

  for (int u = 0; u < n; ++u) {
    for (int v = 0; v < g[u].size(); ++v) {
      int next = g[u][v].to;
      int weight = g[u][v].weight;

      if(dist[u] >= 1<<30) continue; // avoid overflow at plus INF + weight

      // if (dist[next] > dist[u] + weigth) prev[next] = u;
      if (dist[next] > dist[u] + weight) {
        dist[next] = dist[u] + weight;
        updated = true;
      }
    }
  }
  return updated;
}

// receives 'start' and number of nodes in the graph
void bellman_ford(int s, int n) {
  for (int u = 0; u <= n; ++u) {
    dist[u] = 1<<30;
    // previ[u] = -1;
  }

  dist[s] = 0;
  valid_nodes = n-1; // you should be able to reach each node in the graph in max n-1 movements

  while (valid_nodes--)
    update_dist(n);
}

// usage: bellman_ford(0, n)
// if there is no negative cycles then dist[n-1] is the shortest path
// after bellman_ford if you run update_dist(n) and returns true then there is a negative cycle
// if dist[n-1] == 1<<30 there is no path to reach such node.
