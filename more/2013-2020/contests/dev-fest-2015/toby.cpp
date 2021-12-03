#include <bits/stdc++.h>

using namespace std;

const int MN = 5001;

int main() {
  vector<double> dp(MN);
  dp[0] = 0;

  for (int x = 1; x < MN; ++x) {
    int mj = min(x, 10);
    for (int j = 1; j  <= mj; ++j) {
      dp[x] += (dp[x - j] + 1) / double(mj);
    }
  }

  int tc; cin >> tc;

  for (int t = 0; t < tc; ++t) {
    int q;
    cin >> q;
    cout << fixed << setprecision(10) << dp[q] << endl;
  }
  return 0;
}

// https://www.hackerrank.com/contests/dev-fest/challenges/toby-and-the-frog
// probability + dp
// En realidad es promedio (average)
