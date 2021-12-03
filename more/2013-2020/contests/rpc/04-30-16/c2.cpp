#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define maxn 1000005
#define K 1000000007

ll f[maxn], rf[maxn];

// m^n = (m^(n-1))*m if n is odd
// m^n = (m^(n/2))^2 si n es even

ll cpot(ll x, ll e) {
  if (e == 0) return 1;
  if (e == 1) return x;
  if (e == 2) return (x * x) % K;

  if (e % 2) return (cpot(x, e - 1) * x) % K;
  return cpot(cpot(x, e / 2), 2) % K;
}

ll NK(ll n, ll k) {
  if (k > n) return 0;
  return f[n] * rf[k] % K * rf[n - k] % K;
}

int main() {
  ll n, k;

  f[0] = rf[0] = 1;
  REP(i, 1, maxn - 1) {
    f[i] = (f[i - 1] * i) % K;
    rf[i] = cpot(f[i], K - 2);
  }
   
  while (cin >> n >> k) {
    cout << (2 * NK(n - 1, k)) % K << endl;
  }
  return 0;
}

