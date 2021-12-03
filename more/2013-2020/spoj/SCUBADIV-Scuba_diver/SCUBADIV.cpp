#include <bits/stdc++.h>

using namespace std;

#define MAXN 1002
#define MAX_O 23
#define MAX_N 81

int h20[MAXN];
int nitro[MAXN];
int w[MAXN];
int dp[MAXN][MAX_O][MAX_N];

void knapsack(int n, int size_o, int size_n) {
  for (int j = 0; j <= size_o; ++j) 
    for (int k = 0; k <= size_n; ++k) 
      dp[0][j][k] = 1<<30;

  dp[0][0][0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= size_o; ++j) {
      for (int k = 0; k <= size_n; ++k) {
        int no_taken = dp[i-1][j][k];
        int taken = 
          dp[i-1][max(0, j-h20[i])][max(0, k-nitro[i])] + w[i];

        dp[i][j][k] = min(no_taken, taken);
      }
    }
  }
}

int main() {
  int size_o, size_n, t, n;

  cin >> t;

  while (t--) {
    cin >> size_o >> size_n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
      cin >> h20[i] >> nitro[i] >> w[i];
    }
    
    knapsack(n, size_o, size_n);

    cout << dp[n][size_o][size_n] << endl;
  }
  return 0;
}
