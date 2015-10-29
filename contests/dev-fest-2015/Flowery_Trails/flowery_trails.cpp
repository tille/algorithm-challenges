#include <bits/stdc++.h>

using namespace std;

#define MAXN 10005

typedef pair<int, int> edge;

int dist[MAXN][2];
vector<edge> g[MAXN];

void dijkstra(int s, int dir) {
  for (int i = 0; i < MAXN; ++i) dist[i][dir] = 1<<30;

  priority_queue< edge, vector<edge>, greater<edge> > q;

  q.push(edge(0, s));
  dist[s][dir] = 0;

  while (q.size()) {
    int d = q.top().first;
    int u = q.top().second;
    q.pop();

    if (d > dist[u][dir]) continue;

    for (int i = 0; i < g[u].size(); ++i) {
      int v = g[u][i].first;
      int weight = g[u][i].second;

      if (dist[u][dir] + weight < dist[v][dir]) {
        dist[v][dir] = dist[u][dir] + weight;
        q.push(edge(dist[v][dir], v));
      }
    }
  }
}

int best_weight(int n) {
  int res = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < g[i].size(); ++j) {
      int v = g[i][j].first;
      int w = g[i][j].second;

      if (dist[i][0] + dist[v][1] + w == dist[0][1]) {
        res += w;
      }
    }  
  }

  return res;
}

int main() {
  int p, t, u, v, l, last = 0;
  cin >> p >> t;

  while (t--) {
    cin >> u >> v >> l;
    if (u == v) continue; // necessary?

    g[u].push_back(edge(v, l));
    g[v].push_back(edge(u, l));

    last = max(last, max(u, v));
  }

  dijkstra(0, 0);
  dijkstra(last, 1);

  int result = best_weight(last) * 2;
  cout << result << endl;

  return 0;
}
