#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

int dp[MAXN];

int calc(int n) {
  int x = n; int cont = 0;

  while (x != 1) {
    cont++;
    x = (x % 2) ? (x * 3) + 1 : x / 2;
  }
  
  return cont + 1;
}

int main() {
  int n, m, ans;

  memset(dp, -1, sizeof dp);

  while (scanf ("%d %d", &n, &m) != EOF) {
    ans = 0;

    for (int i = min(n, m); i <= max(n, m); ++i) {
      if (dp[i] == -1) dp[i] = calc(i);
      ans = max(ans, dp[i]);
    }

    printf("%d %d %d\n", n, m, ans);
  }
  return 0;
}
