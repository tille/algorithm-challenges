#include <bits/stdc++.h>

using namespace std;

#define MAXN 4005
int dp[MAXN];

int main() {
  int a, b, c, n;
  int w[3];

  cin >> n >> w[0] >> w[1] >> w[2];

  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = -1;
    for (int j = 0; j < 3; ++j) {
      if (i >= w[j] && dp[i-w[j]] != -1) {
        dp[i] = max(dp[i], dp[i-w[j]] + 1);
      }
    }
  }

  cout << dp[n] << endl;
  return 0;
}
