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
  d[s] = 0;
  q.push(edge(0, s));

  while (q.size()) {
    int dist = q.top().first;
    int u = q.top().second; 
    q.pop();
    
    if (d[u] < dist) continue;

    for (int i = 0; i < g[u].size(); ++i) {
      int v = g[u][i].first;
      int weight = g[u][i].second;

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
  vector<int> path;

  while( cin >> n && n) {
    test_case++;
    clear_graph();
    path.clear();

    for (int i = 0; i < n; ++i) {
      cin >> r;

      while (r--) {
        cin >> to >> delay;
        g[i].push_back( edge(to-1, delay) );
      }
    }

    cin >> from >> to;
    from--; to--;
    dijkstra(from);

    int t = to;
    path.push_back(t+1);

    while (p[t] != -1) {
      path.push_back(p[t]+1);
      t = p[t];
    }
    reverse(path.begin(), path.end());

    printf("Case %d: Path = ", test_case);
    for (int i = 0; i < path.size(); ++i) {
      printf("%d", path[i]);
      if (i != path.size()-1) printf(" ");
    }
    printf("; %d second delay\n", d[to]);
  }
  return 0;
}
