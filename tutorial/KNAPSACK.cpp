int dp[MAXN][MAXN]; // f(i, j) -> max value with i items in a knapsack of size j
int w[MAXN]; // elements weight
int v[MAXN]; // elements value

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

/*  
 * usage:
 * n -> number of elements/items
 * s -> size of the knapsack
*/

knapsack(n, s);
cout << dp[n][s] << endl; 
