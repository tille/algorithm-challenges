#include <bits/stdc++.h>

using namespace std;

#define MAXN 20000

typedef pair<int, int> point;
typedef pair<int, int> dist_point; // dist, point index (ordered)
set<point> points;
vector<int> g[MAXN];
int visited[MAXN];
int nodes_reach;

void dfs(int u) {
  visited[u] = true;
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (!visited[v]) dfs(v);
  }
  nodes_reach++;
}

void create_graph() {
  set<point> :: iterator i;
  set<point> :: iterator j;
  set<dist_point> results; 
  int u, v;

  for (i = points.begin(), u = 0; i != points.end(); ++i, ++u) {
    results.clear();

    for (j = points.begin(), v = 0; j != points.end(); ++j, ++v) {
      if (u == v) continue;

      int c1 = (*i).first - (*j).first;
      int c2 = (*i).second - (*j).second;
      int dist = sqrt(c1*c1 + c2*c2); // dist between *i and *j

      results.insert( dist_point(dist, v) );
    }

    int s = points.size();
    if (s >= 1) {
      j = results.begin();
      g[u].push_back( (*j).second );
    }

    if (s >= 2) {
      j = results.begin(); j++;
      g[u].push_back( (*j).second );
    }
  }
}

int main() {
  int n, a, b;

  while (cin >> n && n) {
    nodes_reach = 0;
    points.clear();

    for (int i = 0; i < n; ++i) {
      g[i].clear();
      visited[i] = false;

      cin >> a >> b;
      points.insert( point(a, b) );
    }

    create_graph();

    dfs(0);
    if (nodes_reach == n) cout << "All stations are reachable." << endl;
    else cout << "There are stations that are unreachable." << endl;
  }
  return 0;
}
