#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

ll n, m , k, s, t, val, gd, gp;
ll d[200005], p[200005];
ll md[200005], mp[200005];
vii dv, pv;

bool verify(ll d) {
  REP(i, 0, k) {
    if (i > dv.size()) break;
    ll tot = 0;
    if (i - 1 >= 0) tot += dv[i - 1].first * md[d];
    if ((k-i-1) >= pv.size()) continue;
    if (k-i-1 >= 0 && (k-i-1) < pv.size()) tot += (pv[k - i - 1].first * mp[d]);
    if (tot <= s) { 
      gd = i, gp = k - i; 
      return true;
    }
  }
  return false;
}

ll min_search(ll l, ll r) {
  while (l < r) {
    ll m = (l + r) / 2;
    if (verify(m)) r = m;
    else l = m + 1;
  }
  return l;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> m >> k >> s; 

  REP(i, 0, n - 1) {
    cin >> d[i];
    md[i] = (i != 0) ? min(d[i], md[i - 1]) : d[i];
  }

  REP(i, 0, n - 1) {
    cin >> p[i];
    mp[i] = (i != 0) ? min(p[i], mp[i - 1]) : p[i];
  } 

  REP(i, 0, m - 1) {
    cin >> t >> val;
    if (t == 1) dv.push_back(make_pair(val, i + 1));
    else pv.push_back(make_pair(val, i + 1));
  }

  sort(dv.begin(), dv.end());
  sort(pv.begin(), pv.end());

  REP(i, 1, dv.size() - 1) dv[i].first += dv[i - 1].first;
  REP(i, 1, pv.size() - 1) pv[i].first += pv[i - 1].first;

  ll days = min_search(0, n);

  if (days >= n) {
    cout << -1 << endl;
  } else {
    cout << days + 1 << endl;

    verify(days);

    int mdd = 0, mdp = 0;
    REP(i, 1, days) {
      if (d[i] < d[mdd]) mdd = i;
      if (p[i] < p[mdp]) mdp = i;
    }

    REP(i, 0, gd - 1) cout << dv[i].second << " " << mdd + 1 << endl;
    REP(i, 0, gp - 1) cout << pv[i].second << " " << mdp + 1 << endl;
  }
  return 0;
}
