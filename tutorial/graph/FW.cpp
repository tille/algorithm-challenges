int dp[MAXN][MAXN];

void clear_dp() {
  for (int i = 0; i < MAXN; ++i) {
    for (int j = 0; j < MAXN; ++j) {
      dp[i][j] = 1<<25; // take care with infinite value since 1<<30 causes overflow
    }
    dp[i][i] = 0;
  }
}

void floyd_warshall(int n) {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
}

// usage:
// nodes must be numbered 0-based
// fill base cases for APSP calling clear_dp()
// call floyd_washall passing nodes_count
// then dp[x][y] contains the minimun distance from node x to y
