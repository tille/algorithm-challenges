#include <bits/stdc++.h>

using namespace std;

#define MAXN 105

map<int, int> m;
int dp[MAXN][MAXN];

void floyd_warshall(int n) {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
}

void clear_dp() {
  for (int i = 0; i < MAXN; ++i) {
    for (int j = 0; j < MAXN; ++j) {
      dp[i][j] = 1<<25;
    }
    dp[i][i] = 0;
  }
}

int main() {
  int u, v, testcase = 1;
  string line;

  while(getline(cin, line)) {
    stringstream ss(line);
    ss >> u; ss >> v;
    if (u+v == 0) break;

    int cont = 0; 
    m.clear(); clear_dp();

    while (u+v != 0) {
      if (m.count(u) == 0) m[u] = cont++;
      if (m.count(v) == 0) m[v] = cont++;

      dp[m[u]][m[v]] = 1;
      ss >> u; ss >> v;
    }

    floyd_warshall(cont);

    int ans = 0;
    for (int i = 0; i < cont; ++i) {
      for (int j = 0; j < cont; ++j) {
        ans += dp[i][j];
      }
    }
    double clicks = (double)ans / (cont*(cont-1));
    printf("Case %d: average length between pages = %.3f clicks\n", testcase++, clicks);
  }
  return 0;
}
