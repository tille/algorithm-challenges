#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
ll num, bit, used, ones;
vi indexes;

int n_size(ll num) {
  int res = 0;
  while (num) num /= 2, res++;
  return res;
}

ll gen(ll n, ll k) {
  ll ans = 0;
  int size1 = n_size(n);
  for (ll i = 0; i < (1LL << k); ++i) {
    num = n;
    if (__builtin_popcountll(i) != ones) continue;

    for (ll j = 0; j < k; ++j) {
      bit = (i & (1LL << j)) ? 1 : 0;
      used = (num & (1LL << indexes[j])) ? 1 : 0;
      if (bit != used) num ^= (1 << indexes[j]);
    }

    int size2 = n_size(num);
    if (num % 7 == 0 && size1 == size2) ans = max(ans, num);
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
      if (n & (1LL << num)) ones++;
    }

    cout << gen(n, k) << endl;
  }
   
  return 0;
}

