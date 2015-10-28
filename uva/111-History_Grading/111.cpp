#include <bits/stdc++.h>

using namespace std;

#define MAXN 25

int a[MAXN];
int b[MAXN];
int dp[MAXN][MAXN];

int lcs(int size_s) {
  for (int i = 0; i <= size_s; ++i)
    dp[i][0] = dp[0][i] = 0;

  for (int i = 1; i <= size_s; ++i) {
    for (int j = 1; j <= size_s; ++j) {
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

      if (a[i] == b[j]) {
        dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
      }
    }
  }
}

int main() {
  int n, pos;
  string line;

  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> pos;
    a[pos] = i;
  }

  getline(cin, line); // read endline
  while (getline(cin, line) && line.size()) {
    stringstream ss(line);
    
    for (int i = 1; i <= n; ++i) {
      ss >> pos;
      b[pos] = i;
    }

    lcs(n);

    cout << dp[n][n] << endl;
  }

  return 0;
}
