#include <bits/stdc++.h>

using namespace std;

#define MAXN 57
#define ll long long

string s; // binary representation of n

ll C[MAXN][MAXN];
ll dp[MAXN][MAXN];

int count_ones;

void binomial() {
  C[0][0] = 1;

  for(int i = 1; i <= MAXN; ++i) C[0][i] = 0;

  for (int i = 1; i <= MAXN; ++i){
    for (int j = 0; j <= MAXN; ++j) {
      C[i][j] = C[i-1][j];
      if (j > 0) C[i][j] += C[i-1][j-1];
    }
  }
}

void fill_dp(int n) {
  for (int i = 0; i <= n; ++i) dp[0][i] = dp[i][0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = (s[i] == '1') ? C[i-1][j] + dp[i-1][j-1] : dp[i-1][j];
    }
  }
}

void to_binary(ll n) {
  string result = " ";
  string binary_digit;
  count_ones = 0;

  if (!n) {
    s = "0";
    return ;
  }

  while (n) {
    if (n%2) {
      result += "1";
      count_ones++;
    } else {
      result += "0";
    }

    n /= 2;
  }

  s = result;
}

int main() {
  ll n, ans;
  binomial();

  while (cin >> n) {
    to_binary(n); 
    
    ans = 0;
    int i = s.size()-1;

    fill_dp(i); // apply bottom up

    for (int j = 3; j <= i; j += 3) {
      ans += dp[i][j];
    }

    if (count_ones && !(count_ones % 3)) ans++;

    printf("Day %llu: Level = %llu\n", n, ans);
  }
  return 0;
}
