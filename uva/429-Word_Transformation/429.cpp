#include <bits/stdc++.h>

using namespace std;

#define MAXN 300

vector<string> words;
map<string, int> pos;
int dist[MAXN];
vector<int> g[MAXN];

int bfs(int start, int final) {
  dist[start] = 0;
  queue<int> q;
  q.push(start);

  while (q.size()) {
    int node = q.front();
    q.pop();

    for (int i = 0; i < g[node].size(); ++i) {
      int next = g[node][i];

      if (dist[next] == -1) {
        dist[next] = dist[node] + 1;
        // if (next == final) return;
        q.push(next);
      }
    }
  }

  return dist[final];
}

int dist_words(int i, int j) {
  string a = words[i];
  string b = words[j];

  if (a.size() != b.size()) return 0;

  int diff = 0;
  for (int u = 0; u < a.size(); u++) {
    if (a[u] != b[u]) diff++;
    if (diff > 1) return 0;
  }

  return diff; // diff is 1
}

void create_graph(int total) {
  for (int i = 0; i < total; ++i) {
    g[i].clear();
    for (int j = 0; j < total; ++j) {
      if (i == j) continue;

      if (dist_words(i, j) == 1) {
        g[i].push_back(j);
      }
    }
  }
}

int main() {
  int t;
  string tmp;

  cin >> t;
  getline(cin, tmp); // read endline
  getline(cin, tmp); // read blank line

  while (t--) {
    words.clear();
    pos.clear();

    int node = 0, total = 0;
    string str;
    while (cin >> str && str[0] != '*') {
      words.push_back(str);
      pos[str] = node;
      node++;
      total++;
    }

    create_graph(total);

    string line;
    getline(cin, tmp); // read * endline

    while (getline(cin, line) && line.size() > 0) {
      stringstream ss(line);
      string initial, final;

      ss >> initial >> final;

      for (int v = 0; v < MAXN; ++v) dist[v] = -1;

      int pos_i = pos[initial];
      int pos_f = pos[final];

      cout << initial << " " << final; 
      cout << " " << bfs(pos_i, pos_f) << endl;
    }

    if(t) puts("");
  }
  return 0;
}
