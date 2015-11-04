#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAXN 100005

int main() {
  int t;
  ll n, num, ans, back;
  deque<ll> nums;
  map<ll, ll> pos;

  scanf("%llu", &t);

  while (t--) {
    nums.clear();
    pos.clear();
    ans = 0;

    scanf("%llu", &n);

    for (ll i = 1; i <=n; ++i) {
      scanf("%llu", &num);
      if (!pos[num]) {
        pos[num] = i;
        nums.push_front(num);
      }

      for (ll j = 0; j < nums.size(); ++j) {
        ll cur = __gcd(num, nums[j]);
        if (j > 0) cur = __gcd(cur, back);
        ans = max(ans, cur * (i - pos[nums[j]] + 1));
        back = cur;
      } 
    }

    cout << ans << endl;
  }

  return 0;
}
