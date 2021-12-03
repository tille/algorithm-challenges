#include <bits/stdc++.h>

using namespace std;

#define MAXN 505

typedef pair<int, int> edge;
int intersections[MAXN]; // 0-house, 1-fire station
vector<edge> g[MAXN];
int d[MAXN];
int min_dist[MAXN];

void dijkstra(int s) {
  for (int i = 0; i < MAXN; ++i) d[i] = 1<<30;

  priority_queue< edge, vector<edge>, greater<edge> > q;
  q.push(make_pair(0, s)); // dist, to
  d[s] = 0;
  
  while (q.size()) {
    int dist = q.top().first;
    int u = q.top().second; 
    q.pop();

    if (dist > d[u]) continue;

    for (int i = 0; i < g[u].size(); ++i) {
      int v = g[u][i].first;
      int weight = g[u][i].second;

      if (d[u] + weight < d[v]) {
        d[v] = d[u] + weight;
        q.push(make_pair(d[v], v));
      }
    }
  }
}

void clear_all() {
  for (int i = 0; i < MAXN; i++) {
    g[i].clear();
    intersections[i] = 0;
    min_dist[i] = 1<<30;
  }
}

int main() {
  int t, f, n;
  cin >> t;

  while (t--) {
    cin >> f >> n;
    clear_all();

    int fire_station;
    while (f--) {
      cin >> fire_station;
      intersections[fire_station-1] = 1;
    }

    string tmp;
    getline(cin, tmp); // read endline

    string line;
    while (getline(cin, line)) {
      if (line == "") break;
      stringstream ss(line);

      int from, to, w;
      ss >> from >> to >> w;
      from--; to--;

      g[from].push_back( edge(to, w) );
      g[to].push_back( edge(from, w) );
    }

    // find minimun distance from any house to the nearest fire station
    for (int i = 0; i < n; ++i) {
      if (intersections[i] == 1) { // if is fire station
        dijkstra(i);
        for (int j = 0; j < n; ++j) {
          min_dist[j] = min(min_dist[j], d[j]);
        }
      }
    }

    int max_total = (1<<30) + 1;
    int result = 0;

    for (int i = 0; i < n; ++i) {
      if (intersections[i] == 0) {
        dijkstra(i);
       
        int max_tmp = 0;
        for (int j = 0; j < n; ++j) {
          int min_i = min(d[j], min_dist[j]);
          max_tmp = max(min_i, max_tmp); 
        }

        if (max_tmp < max_total) { 
          max_total = max_tmp;
          result = i;
        }
      }
    }

    // plus 1 since is 0-bazed
    cout << result+1 << endl;
    if (t != 0) cout << endl;
  }
  return 0;
}
