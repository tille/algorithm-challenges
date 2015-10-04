#include <bits/stdc++.h>

using namespace std;

#define MAXN 203

vector<int> g[MAXN];
int color[MAXN];

void clear_graph(int n) {
  for (int i = 0; i < n; ++i ) {
    color[i] = -1;
    g[i].clear();
  }
}

bool bfs(int s, int mark) {
  color[s] = mark;
  queue<int> q;
  q.push(s);

  while (q.size()) {
    int node = q.front();
    q.pop();
    
    for (int i = 0; i< g[node].size(); ++i) {
      int next = g[node][i];

      if (color[node] == color[next]) return false;

      if (color[next] == -1) {
        color[next] = 1 - color[node];
        q.push(next);
      }
    }
  }

  return true;
}

int main() {
  int n, l, a, b;

  while (cin >> n && n) {
    clear_graph(n);

    cin >> l;

    while (l--) {
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    if (bfs(0,0)) cout << "BICOLORABLE." << endl;
    else cout << "NOT BICOLORABLE." << endl;
  }

  return 0;
}
