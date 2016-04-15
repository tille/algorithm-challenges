#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
ll num, bit, used, ones;
vi indexes;

ll gen(ll n, ll k) {
  ll ans = 0;
  for (ll i = 0; i < (1 << k); ++i) {
    num = n;
    if (__builtin_popcountll(i) != ones) continue;

    for (ll j = 0; j < k; ++j) {
      bit = (i & (1 << j)) ? 1 : 0;
      used = (num & (1 << indexes[j])) ? 1 : 0;
      if (bit != used) num ^= (1 << indexes[j]);
    }
    if (num % 7 == 0) ans = max(ans, num);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  ll n, k;

  while (cin >> n) {
    cin >> k;
    ones = 0;
    indexes.clear();

    REP(j, 0, k - 1) {
      cin >> num; 
      indexes.push_back(num);
      if (n & (1 << num)) ones++;
    }

    cout << gen(n, k) << endl;
  }
   
  return 0;
}

