#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define maxn 5005
#define K 1000000007

int memo[505][maxn];
int sieve[maxn];

void build_sieve() {
  memset(sieve, false, sizeof sieve);
  sieve[0] = sieve[1] = true;

  for (int i = 2; i * i < maxn; i++) {
    if (!sieve[i]) {
      for (int j = i * i; j < maxn; j += i) {
        sieve[j] = true;
      }
    }
  }
}

int isprime(int n) {
  int ans = (!sieve[n]) ? 1 : 0;
  return ans;
}

int calc(int c, int sum) {
  if (memo[c][sum] != -1) return memo[c][sum];
  if (!c) return memo[c][sum] = isprime(sum);

  int ans = 0;
  REP(i, 0, 9) ans = (ans + calc(c - 1, sum + i)) % K;
  return memo[c][sum] = ans;
}

int count(int c, string &num, int sum, bool include_last) {
  if (c == num.size()) return (include_last) ? isprime(sum) : 0;
  int ans = 0;
  for (int i = 0; i < num[c] - '0'; ++i) 
    ans = (ans + memo[num.size() - c - 1][sum + i]) % K;
  return (ans + count(c + 1, num, sum + num[c] - '0', include_last)) % K;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  string r, l;

  build_sieve();
  REP(i, 0, 504) REP(j, 0, 5004) memo[i][j] = -1;
  calc(500, 0);

  while (cin >> l >> r) {
    cout << (count(0, r, 0, 1) - count(0, l, 0, 0) + K) % K << endl;
  }
   
  return 0;
}

