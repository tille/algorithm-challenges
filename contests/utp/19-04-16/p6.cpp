#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

bool decimal_verify(ll n) {
  ll res = 0;
  while (n) {
    if ((n%10) > 0 && (n%10) % 7 == 0) res++;
    n/=10;
  }
  return res > 0;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  ll n, m, k;

  while (cin >> n >> m >> k && (n+m+k) != 0) {
    ll it = 0, it2 = 1;
    bool right = true;
    ll ans = 0;

    while (true) {
      if (right) it++;
      else it--;

      if (it == n) right = false;
      if (it == 1) right = true;

      if (it == m && ((it2 % 7) == 0 || decimal_verify(it2))) {
        ans++;
        if (ans == k) {
          cout << it2 << endl;
          break;
        }
      }
      // cout << it << " " << it2 << endl;
      it2++;
      if (it2 == 1000000) {
        cout << -1 << endl;
        break;
      }
    }
  }
  return 0;
}

