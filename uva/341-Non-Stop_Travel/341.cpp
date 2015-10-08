#include <bits/stdc++.h>

using namespace std;

const int MAXN = 15;
typedef pair<int, int> edge;
vector<edge> g[MAXN];
int d[MAXN];
int p[MAXN];

void dijkstra(int s) {
  for (int i = 0; i < MAXN; ++i) {
    d[i] = 1<<30; p[i] = -1;
  }

  priority_queue < edge, vector<edge>, greater<edge> > q;
  q.push(edge(0, s));

  while (q.size()) {
    int dist = q.top().first;
    int u = q.top().second; 
    q.pop();
    
    if (d[u] <= dist) continue;

    for (int i = 0; i < g[u].size(); ++i) {
      int weight = g[u][i].first;
      int v = g[u][i].second;

      if ((dist + weight) < d[v]) {
        d[v] = dist + weight;
        p[v] = u;
        q.push( edge(d[v], v));
      }
    }
  }
}

vector<int> find_path(int t) {
  vector<int> path;
  path.push_back(t);

  while (p[t] != -1) {
    path.push_back(p[t]);
    t = p[t];
  }

  reverse(path.begin(), path.end());
  return path;
}

void clear_graph() {
  for (int i = 0; i < MAXN; ++i) {
    g[i].clear();
  }
}

int main() {
  int test_case = 0, n, to, delay, from, r;
  clear_graph();

  while( cin >> n && n) {
    for (int i = 0; i < n; ++i) {
      cin >> r;

      while (r--) {
        cin >> to >> delay;
        g[i].push_back( edge(delay, to) );
      }
    }

    cin >> from >> to;
    dijkstra(from-1);
    cout << d[to-1] << endl;
  }
  return 0;
}
