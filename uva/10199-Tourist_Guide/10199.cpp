#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
vector<int> g[MAXN];
int parent[MAXN];
int low[MAXN];
int dis[MAXN];
bool visited[MAXN];
map<string, int> index_of;
set<string> results;
vector<string> locations;
int total;

void ap(int u) {
  visited[u] = true;
  int children = 0;
  low[u] = dis[u] = ++total;

  for (int i = 0; i < g[u].size(); ++i) {
    int next = g[u][i];
    
    if (!visited[next]) {
      children++;
      parent[next] = u;

      ap(next);

      if (parent[u] == -1 && children > 1) 
        results.insert(locations[u]);

      if (parent[u] != -1 && dis[u] <= low[next])
        results.insert(locations[u]);

      low[u] = min(low[u], low[next]); 
    } else if (parent[u] != next)
      low[u] = min(dis[next], low[u]);
  }
}

int main() {
  int n, r, test_case = 0;

  while (cin >> n && n) {
    int cpy_n = n;
    int node = 0;
    string location;

    test_case++;

    // reset all
    results.clear();
    locations.clear();
    for (int i = 0; i < n+2; ++i) {
      g[i].clear();
      parent[i] = -1;
      visited[i] = false;
      index_of.clear();
    }

    while (n--) {
      cin >> location;
      locations.push_back(location);
      index_of[location] = node++;
    }

    cin >> r;
    string from, to;

    while (r--) {
      cin >> from >> to;
      int node_a = index_of[from];
      int node_b = index_of[to];

      g[node_a].push_back(node_b);
    }
    
    total = 0;
    ap(0);

    set <string> :: iterator it;
    printf("City map #%d: %d camera(s) found\n", test_case, int(results.size()) );

    for (it = results.begin(); it != results.end(); ++it) {
      cout << *it << endl;
    }

    puts("");
  }
  return 0;
}
