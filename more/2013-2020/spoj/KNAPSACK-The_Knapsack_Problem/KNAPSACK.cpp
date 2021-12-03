#include <bits/stdc++.h>

using namespace std;

#define MAXN 2005

int dp[MAXN][MAXN];
int w[MAXN];
int v[MAXN];

void knapsack(int n, int s) {
  for (int j = 0; j <= s; ++j) dp[0][j] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= s; ++j) {
      dp[i][j] = dp[i-1][j];

      if (j-w[i] >= 0) {
        dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
      }
    }
  }
}

int main() {
  int s, n;

  cin >> s >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> w[i] >> v[i];
  }

  knapsack(n, s);

  cout << dp[n][s] << endl; 

  return 0;
}
