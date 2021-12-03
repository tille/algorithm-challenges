#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAXN 100005

vector<pair<ll, ll> > g[2];

int main() {
  ll t, n, num;

  cin >> t;

  while (t--) {
    g[0].clear(); g[1].clear();

    cin >> n;
    ll k = 0;
    ll ans = 0;
    set<ll> visited;

    for (ll i = 0; i < n; ++i) {
      visited.clear();
      cin >> num;

      g[k].push_back(make_pair(num, i));
      g[(k+1)%2].clear(); //clear vector before fill it

      for (ll j = 0; j < g[k].size(); ++j) {
        ll cur_gcd = __gcd(g[k][j].first, num);

        if (!visited.count(cur_gcd)) {
          visited.insert(cur_gcd);
          g[(k+1)%2].push_back(make_pair(cur_gcd, g[k][j].second));
        }

        ans = max(ans, cur_gcd * (i - g[k][j].second + 1));
      }
      k = (k+1)%2;
    }

    cout << ans << endl;
  }

  return 0;
}
