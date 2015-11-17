#include <bits/stdc++.h>

using namespace std;

#define MAXN 105

int dp[MAXN][MAXN];

void clear_dp(int n) {
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = -1<<30;
    }
    dp[i][i] = 1<<30;
  }
}

void maximin(int n) {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = max(dp[i][j], min(dp[i][k], dp[k][j]));
      }
    }
  }
}

int main() {
  int n, e, p, to, from, u, v, c, testcase = 0;

  while (cin >> n >> e && n+e) {
    testcase++; clear_dp(n);

    while (e--) {
      cin >> u >> v >> c;
      dp[u][v] = dp[v][u] = c;
    }

    maximin(n);
    cin >> from >> to >> p; 

    // max passengers that can be take from starting node to destination, including guide.
    int max_cap = dp[from][to] - 1; 
    int ans = ceil(double(p)/max_cap);
    // int trips = (p + max_cap - 1) / max_cap;

    cout << "Scenario #" << testcase << endl;
    cout << "Minimum Number of Trips = " << ans << endl << endl; 
  }
  return 0;
}
