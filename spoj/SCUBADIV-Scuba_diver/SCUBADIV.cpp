#include <bits/stdc++.h>

using namespace std;

int main() {
  int inf = 1<<30;
  int n;
  int W;
  int w[100];
  int v[100];

  cin >> W >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i] >> v[i];
  }

  int max_n, max_w; max_n = max_w = 100;

  int dp[max_n][max_w]; 

  dp[0][0] = 0;
  for (int i = 1; i <= W; ++i) dp[0][i] = inf;

  for (int i = 1;  i <= n; ++i) {
    for (int j = 0; j <= W; ++j) {
      dp[i][j] = dp[i-1][j];
      if (j-w[i] >= 0 && dp[i-1][j-w[i]] != inf) {
        dp[i][j] = min(dp[i][j], dp[i-1][j-w[i]] + v[i]);
      }
    }
  }

  cout << dp[n][W] << endl;
  return 0;
}
