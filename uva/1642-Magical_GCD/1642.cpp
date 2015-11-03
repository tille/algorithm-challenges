#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MAXN = 100005;

ll nums[MAXN];

ll calc(ll n) {
  ll ans = 0, cur, back;

  for (int i = 1; i <= n; ++i) {
    for (int j = i; j >= 1; --j) {
      cur = __gcd(nums[i], nums[j]);
      if (j < i) cur = __gcd(cur, back);

      ans = max(ans, cur * (i-j+1));
      back = cur;
    }
  }
  return ans;
}

int main() {
  int t;
  ll n;

  scanf("%llu", &t);

  while (t--) {
    scanf("%llu", &n);
    for (int i = 1; i <=n; ++i) {
      scanf("%llu", &nums[i]);
    }
    printf("%llu\n", calc(n));
  }

  return 0;
}
