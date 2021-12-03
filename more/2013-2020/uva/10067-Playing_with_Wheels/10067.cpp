#include <bits/stdc++.h>

using namespace std;

#define MAXN 10005

int forbidden[MAXN];
vector<int> g[MAXN];
int dist[MAXN];

int bfs (int s, int final) {
  for (int i = 0; i < MAXN; ++i) dist[i] = -1;

  queue<int> q;
  q.push(s);
  dist[s] = 0;

  while (q.size()) {
    int node = q.front();
    q.pop();

    for (int i = 0; i < g[node].size(); ++i) {
      int next = g[node][i];

      if (!forbidden[next] && dist[next] == -1) {
        dist[next] = dist[node] + 1;
        q.push(next);
      }
    }
  }

  return dist[final];
}

// read a configuration and return it as integer
int read_conf() {
  int i = 0, num, result = 0;

  while (4 > i++) {
    cin >> num;
    result = (result * 10) + num;
  }
  return result;
}

int get_conf(int num, int digit, int carry) {
  vector<int> n(4);

  for (int i = 0; i < 4; ++i) {
    n[3-i] = num % 10;
    num /= 10;
  }

  n[digit] = (n[digit] + carry + 10) % 10;

  int ans = 0, i = 0;
  while (i < 4) {
    ans = ans * 10 + n[i];
    i++;
  }

  return ans;
}

void create_graph() {
  int next_conf;

  for (int i = 0; i < MAXN; ++i) {
    for (int digit = 0; digit < 4; ++digit) {
      next_conf = get_conf(i, digit, 1); 
      g[i].push_back( next_conf ); 

      next_conf = get_conf(i, digit, -1);
      g[i].push_back( next_conf );
    }
  }
}

void clear_forbidden() {
  int i = 0;
  while (MAXN > i++) {
    forbidden[i-1] = 0;
  }
}

int main() {
  int t, l;

  cin >> t;

  create_graph();

  while (t--) {
    clear_forbidden();

    int initial = read_conf();
    int final = read_conf();

    cin >> l;

    while (l--) {
      int forbidden_conf = read_conf();
      forbidden[ forbidden_conf ] = 1;
    }

    cout << bfs(initial, final) << endl;
  }

  return 0;
}
