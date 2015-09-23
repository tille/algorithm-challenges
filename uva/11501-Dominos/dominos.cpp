using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

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
  for (int i = 0; i < n+2; ++i) visited[i] = false;
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
  for (int i = 0; i < n+2; ++i) scc[i] = -1;

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

int dominos_count(int n, int number_of_components) {
  int result = 0;

  // initialize with true
  bool comp[number_of_components+1];
  for (int i = 0; i <= number_of_components; ++i) comp[i] = true; 

  for (int i = 0; i < n; ++i) {
    for (int j =0; j < g[i].size(); ++j) {
      int node = i,
          next = g[i][j];

      if (scc[node] != scc[next])
        comp[scc[next]] = false;
    }
  }

  for (int i = 0; i < number_of_components; ++i) {
    if (comp[i] == true)
      result++;
  }

  return result;
}

void clear_graph(int n) {
  while(--n > -1) {
    g[n].clear();
    rev_g[n].clear();
  }
}

int main() {
  int t, n, m, x, y, number_of_components;
  cin >> t;
  
  while (t--) {
    cin >> n >> m; 

    clear_graph(n);

    while (m--) {
      cin >> x >> y;
      g[x-1].push_back(y-1);    
    }

    // set data and apply kosaraju algorithm
    reverse_graph(n);
    topological_sort(n);
    number_of_components = kosaraju(n);

    // use g and scc to get number of dominos to knock
    cout << dominos_count(n, number_of_components) << endl;
  }

  return 0;
}
